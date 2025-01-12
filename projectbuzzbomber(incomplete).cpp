#include<iostream>
#include <SFML/Graphics.hpp>
#include <SFML/Audio.hpp>
#include <SFML/System.hpp>
#include <cstdlib>//for random num generation for bees and for end function
using namespace std;
using namespace sf;

// Initializing Dimensions.
// resolutionX and resolutionY determine the rendering resolution.

const int resolutionX = 960;
const int resolutionY = 640;
const int boxPixelsX = 32;
const int boxPixelsY = 32;
const int gameRows = resolutionX / boxPixelsX; // Total rows on grid
const int gameColumns = resolutionY / boxPixelsY; // Total columns on grid

// Initializing GameGrid.
int gameGrid[gameRows][gameColumns] = {};

//menu functions
void drawmenu(RenderWindow& window,bool& menudisplay,Sprite& backgroundsprite,Text start,Text levelselect,Text exitgame,Text ent);

void chooseoption(Text& levelselect,Text& start,Text& exitgame,bool& menudisplay,bool& leveldisplay,bool& game,int& selector,Clock& optionclock);

//level functions
void drawlevelmenu(RenderWindow& window,bool leveldisplay, Sprite backgroundsprite,Text level1,Text level2,Text level3);

void chooselevel(Text& level1,Text& level2,Text& level3,bool& pl1,bool& pl2,bool& pl3,int& levelselector,Clock& levelclock,bool& leveldisplay);

//bee functions
void movebees(Clock& workerbeeclock,float workerbeex[][2],float workerbeey[],int num,int& ,int totalcollisions,float honeycombx[],float honeycomby[],int hivex[],int hivey[],int& hives);

void drawbees(RenderWindow& window,float workerbeex[][2],float workerbeey[],Sprite& workerbeesprite,int num,int& addedbees,bool alive[]);


//player functions
void moveplayer(float& player_x, Clock& playerclock);

void drawPlayer(RenderWindow& window, float& player_x, float& player_y, Sprite& playerSprite,Sprite& bulletsize);
//hummingbird

void drawbird(RenderWindow& window,float& birdx,float& birdy,Sprite& birdsprite,bool sick);
void movebird(Clock& birdclock,float& birdx,float& birdy,float honeycombx[],float honeycomby[],int& currentscore,float redhoneycombx[],float redhoneycomby[],int totalcollisions, int totalkillercollisions,bool sick);
void checkbeesick(Clock& sickclock,bool& sick,float& bullet_x,float& bullet_y,float& birdx,float& birdy);

//random honey combs
//collision forming honeycomb
void drawhoneycomb(RenderWindow& window,Sprite& honeycombsprite,Sprite& redhoneycombsprite,int totalkillercollisions,float redhoneycombx[],float redhoneycomby[], float& bullet_x, float& bullet_y,int totalcollisions,float honeycombx[],float honeycomby[],int gone[]);
//beehives
void drawbeehives(RenderWindow& window,Sprite& beehivesprite,int hivex[],int hivey[],int hives);
	

//bullet functions
void moveBullet(float& bullet_y, bool& bullet_exists, Clock& bulletClock);
void drawBullet(RenderWindow& window, float& bullet_x, float& bullet_y, Sprite& bulletSprite);

//collision checker/....
bool beehit(RenderWindow& window,Sprite& honeycombsprite,float bullet_x,float bullet_y,float workerbeex[][2],float workerbeey[],int& num,float honeycombx[25],float honeycomby[25],int& totalcollisions,bool bullet_exists,int& addedbees,Clock honeycombformed[]);
void honeycombcollision(float& bullet_x, float& bullet_y,float honeycombx[], float honeycomby[],bool alive[],int totalcollisions,Clock honeycombformed[]);
//flowers
void drawflowers(RenderWindow& window);
void won();
//killer bees
void movekiller(Clock& killerbeeclock,float killerbeex[][2],float killerbeey[],int killernum,int& addedkillerbees);

void drawkiller(RenderWindow& window,float killerbeex[][2],float killerbeey[],Sprite& killerbeesprite,int killernum,int addedkillerbees);

bool killerbeehit(RenderWindow& window,Sprite& redhoneycombsprite,float bullet_x, float bullet_y, float killerbeex[][2], float killerbeey[], int killernum, float redhoneycombx[], float redhoneycomby[], int& totalkillercollisions, bool bullet_exists, int& addedkillerbees,Clock redhoneycombformed[]);
//redhoneycomb
void redhoneycombcollision(float& bullet_x, float& bullet_y,float redhoneycombx[], float redhoneycomby[],int totalkillercollisions,Clock redhoneycombformed[]);
//main function
int main()
{
	srand(time(0));
	bool menudisplay=true,game=false,leveldisplay=false;
	int selector=0;
	
	cout<<"Press Enter to Select an Option...";

	// Declaring RenderWindow.
	RenderWindow window(VideoMode(resolutionX, resolutionY), "Buzz Bombers", Style::Close | Style::Titlebar);

	// Used to position your window on every launch. Use according to your needs.
	window.setPosition(Vector2i(500, 200));

	// Initializing Background Music.
	Music bgMusic;
	if (!bgMusic.openFromFile("Music/Music3.ogg")) {
    cout << "Error: Could not load music file!" << endl;
	}
	bgMusic.setVolume(0);
	bgMusic.setLoop(true);
	bgMusic.play();

	// Initializing Player and Player Sprites.
	float player_x = (gameRows / 2) * boxPixelsX;
	float player_y = (gameColumns - 4) * boxPixelsY;

	bool level1done=false,level2done=false,level3done=false;

	Clock playerclock;
	Texture playerTexture;
	Sprite playerSprite;
	playerTexture.loadFromFile("Textures/spray.png");
	playerSprite.setTexture(playerTexture);
	//	playerSprite.setTextureRect(IntRect(0, 0, boxPixelsX, boxPixelsY));

		// Initializing Bullet and Bullet Sprites
		// Data for bullet / Spray pellet

	float bullet_x = player_x;
	float bullet_y = player_y;
	bool bullet_exists = true;
	
	
	Clock bulletClock;
	Texture bulletTexture;
	Sprite bulletSprite;
	bulletTexture.loadFromFile("Textures/bullet.png");
	bulletSprite.setTexture(bulletTexture);
	bulletSprite.setScale(3, 3);
	bulletSprite.setTextureRect(sf::IntRect(0, 0, boxPixelsX, boxPixelsY));

	// The ground on which player moves

	RectangleShape groundRectangle(Vector2f(960, 64));
	groundRectangle.setPosition(0, (gameColumns - 2) * boxPixelsY);
	groundRectangle.setFillColor(Color::Green);
	
	//menu
	Font font;
	if(!font.loadFromFile("second.otf"))
		font.loadFromFile("SunfishOriginal.otf");
	// here we will assign attributes to the variable of type text like its size ,color,etc. Also the background is also made for menu pages
	Text start,levelselect,exitgame,ent;
	Texture backgroundtexture;
	backgroundtexture.loadFromFile("menu.jpeg");
	Sprite backgroundsprite;
	backgroundsprite.setTexture(backgroundtexture);
	start.setFont(font);
	start.setCharacterSize(40);
	start.setString("Start Game");
	start.setFillColor(Color::Green);
	start.setPosition(960/3.0f, 200);
	
	levelselect.setFont(font);
	levelselect.setCharacterSize(40);
	levelselect.setString("Level Select");
	levelselect.setFillColor(Color::Green);
	levelselect.setPosition(960/3.0f, 300);

	exitgame.setFont(font);
	exitgame.setCharacterSize(40);
	exitgame.setString("Exit Game");
	exitgame.setFillColor(Color::Green);
	exitgame.setPosition(960/3.0f,400);
	//enter command to enter
	
	ent.setFont(font);
	ent.setCharacterSize(10);
	ent.setString("press enter");
	ent.setFillColor(Color::Green);
	ent.setPosition(50,50);
	
	Clock optionclock;
	//level menu. Similar attributes given
	Text level1,level2,level3;
	int levelselector=0;
	Clock levelclock;
	bool pl1=false,pl2=false,pl3=false;//pl1 means play level 1
	
	level1.setFont(font);
	level1.setCharacterSize(40);
	level1.setString("Level 1");
	level1.setFillColor(Color::Green);
	level1.setPosition(960/3.0f, 200);
	
	level2.setFont(font);
	level2.setCharacterSize(40);
	level2.setString("Level 2");
	level2.setFillColor(Color::Green);
	level2.setPosition(960/3.0f, 300);

	level3.setFont(font);
	level3.setCharacterSize(40);
	level3.setString("Level 3");
	level3.setFillColor(Color::Green);
	level3.setPosition(960/3.0f,400);
	
	
	
	
	//bees
	
	bool alive[35];//see how many bees are alive
	for (int i=0;i<35;i++){
		alive[i]=true; // initiazlizing all as alive
	}
	int collisions=0;
	Clock workerbeeclock;
	Texture workerbeetexture;
	Sprite workerbeesprite;
	int addedbees=6;
	
	if(!workerbeetexture.loadFromFile("Textures/Regular_bee.png")) {
		cout<<"Error!"<<endl;
		return 0;
    	}
   	workerbeesprite.setTexture(workerbeetexture);
    	workerbeesprite.setScale(0.8f, 0.8f);
    	Clock honeycombformed[35];
	
	//to give x values and number of bees one time only
	
	float workerbeex[35][2],workerbeey[35];//beenum
	
	int num=0;
	for (int i=0;i<35;i++){
		workerbeex[i][0]=rand()%960;
		if(int(workerbeex[i][0])%2==0){
			workerbeex[i][1]=0;
			workerbeex[i][0]=960;
		}
		else {
			workerbeex[i][1]=1;
			workerbeex[i][0]=0;
		}
	honeycombformed[i].restart(); //to start timer for honeycomb collision
	workerbeey[i]=32;
	}
	
	
	
	//honeycombs formed after collision
	
	bool checkhoneycomb=false;//dont see honey comb collision and ignore it
	int totalcollisions=0;
	int gone[35]={0};
	int honeycombs=35;//max num of honeycombs formable
	float honeycombx[35]={0};//x coordinates
	float honeycomby[35]={0};// y
	Texture honeycombtexture;
	Sprite honeycombsprite;
	
	if(!honeycombtexture.loadFromFile("Textures/honeycomb.png")){
		cout<<"no such file";
		return 0;
	}
	honeycombsprite.setTexture(honeycombtexture);
	for (int i=0; i<honeycombs; i++) {
		// random x
		honeycombx[i]= rand() %(960-32); 
		// random y
		honeycomby[i]= rand() %(640-64);  
	}
	
	
	
	//hummingbird
	Texture birdtexture;
	Sprite birdsprite;
	birdtexture.loadFromFile("Textures/bird.png");
	birdsprite.setTexture(birdtexture);
	birdsprite.setTextureRect(IntRect(0, 0, 64, 64));
	float birdx=0,birdy=0; // x and y coordinates
	Clock birdclock;
	bool sick=false;
	Clock sickclock;// to make it alright again after some time
	
	
	//killerbees
	Texture killertexture;
	Sprite killerbeesprite;
	int killernum=15;
	int addedkillerbees=0;
	if(!killertexture.loadFromFile("Textures/killer.png")){
		cout<<"no such file";
		return 0;
	}
	killerbeesprite.setTexture(killertexture);
	Clock redhoneycombformed[10];//max
	// max number of bees
	Clock killerbeeclock;
	float killerbeex[10][2]={0},killerbeey[10]={0};
	for (int i=0;i<10;i++){
		killerbeex[i][0]=rand()%960;
		if(int(killerbeex[i][0])%2==0){
			killerbeex[i][1]=0;
			killerbeex[i][0]=960;
		}
		else {
			killerbeex[i][1]=1;
			killerbeex[i][0]=0;
		}
	redhoneycombformed[i].restart();
	killerbeey[i]=32;
	}
	//honeycombs for killer bees
	int totalkillercollisions=0;
	
	int redhoneycombs=10;//max num of honeycombs formable
	float redhoneycombx[10]={0};//x coordinates
	float redhoneycomby[10]={0};// y
	Texture redhoneycombtexture;
	Sprite redhoneycombsprite;
	
	if(!redhoneycombtexture.loadFromFile("Textures/honeycomb_red.png")){
		cout<<"no such file";
		return 0;
	}
	redhoneycombsprite.setTexture(redhoneycombtexture);
	//score
	int currentscore=0;
	Text score;
	score.setFont(font);
	score.setCharacterSize(40);
	score.setPosition(700,600);
	score.setFillColor(sf::Color::Black);
	
	//flowers
	Texture flowertexture;
	Sprite flowersprite;
	if(!flowertexture.loadFromFile("Textures/obstacles.png")){
		cout<<"no such file";
		return 0;
	}
	flowersprite.setTexture(flowertexture);
	
	// bullet and sprays

	float bulletx=player_x,bullety=player_y;
	int limit=56,left=2;
	double totalused=0,used=0;
	Texture mag;
	int width=30;
	int height=20;
	Sprite sprays;
	Texture spraystext;
	if(!spraystext.loadFromFile("Textures/spray.png")){
		cout<<"no such file";
		return 0;
	}
	
	sprays.setTexture(spraystext);
	

	Sprite bulletsize;
	if(!mag.loadFromFile("Textures/white.png")){
		cout<<"no such file:";
		return 0;
		}
	bulletsize.setTexture(mag);
	
	bulletsize.setTextureRect(IntRect(10,50,width,height));
	bulletsize.setScale(1.0f, 1.0f);
	bulletsize.setPosition(player_x, player_y);//same as the player
	
	//beehives
	int hives=0;
	int hivex[25]={0};
	int hivey[25]={0};
	Texture beehivetexture;
	Sprite beehivesprite;
	if(!beehivetexture.loadFromFile("Textures/hive.png")){
		cout<<"no such file:";
		return 0;
	}
	beehivesprite.setTexture(beehivetexture);
	
	
	
	bool playing=false;
	//Clock hitclock[25];// for interval between bee and honeycomb collision
	//int collisionDelay[25]={0};
	while (window.isOpen()) {
		Event e;
		while (window.pollEvent(e)) {
			if (e.type == Event::Closed) {
				return 0;
			}
		}
		//show main menu
		if (menudisplay==true){
			drawmenu(window,menudisplay, backgroundsprite,start,levelselect,exitgame,ent);
			chooseoption(levelselect,start,exitgame,menudisplay,leveldisplay,game,selector,optionclock);
		}
		//show level menu
		else if(leveldisplay==true){
		
		
			drawlevelmenu(window,leveldisplay, backgroundsprite,level1,level2,level3);
			
			chooselevel(level1,level2,level3,pl1,pl2,pl3,levelselector,levelclock,leveldisplay);
	    	
		
		}
		else if(game==true && playing==false){
			pl1=true;
			pl2=false;
			pl3=false;
		}if(pl1 && playing==false) {
			num=20; //level 1=20 bees
			game=true;// so that game runs
			
			playing=true;
			killernum=0;
			totalcollisions=3;
		}
		else if(pl2 && playing==false) {
			num=15; //level 2=15 bees
			game=true;
			totalcollisions=9;
			playing=true;
			killernum=5;
		} 
		else if(pl3==true && playing==false) {
			num=20; //level 3=20 bees
			game=true;
			totalcollisions=15;
			playing==true;
			killernum=10;
		}
		else if(pl3){
			game=true;
			
		}
		
		
		
		if (game==true){
					if(left<0){
						//lost
					}
					else if(num==0){
						
					}
				
		if(num>0){
			drawbees(window, workerbeex,workerbeey, workerbeesprite,num,addedbees,alive);
			movebees(workerbeeclock, workerbeex, workerbeey,num,addedbees,totalcollisions,
			honeycombx,honeycomby,hivex,hivey,hives);
			
		}
		
		
		moveplayer(player_x,playerclock);// move
		
		drawhoneycomb(window,honeycombsprite,redhoneycombsprite,totalkillercollisions,
		redhoneycombx,redhoneycomby, bullet_x,bullet_y,totalcollisions,honeycombx, honeycomby,gone);
		//beehive making
		drawbeehives(window, beehivesprite,hivex,hivey,hives);

			if(killernum>0){
				drawkiller(window,killerbeex,killerbeey, killerbeesprite,killernum,addedkillerbees);
				movekiller(killerbeeclock, killerbeex,killerbeey,killernum,addedkillerbees);
				}
			if(collisions<2){
				if(beehit(window,
				honeycombsprite,bullet_x,bullet_y,workerbeex,workerbeey,num,honeycombx, 
				honeycomby,totalcollisions,bullet_exists,addedbees, honeycombformed)==true){
					collisions++;
					currentscore+=100;
					checkhoneycomb=false;
		    			//sleep(milliseconds(200));
		    			
				}
				else{
					checkhoneycomb=true;
				}
			}
			
			else if (collisions>1){
				// to remove the bullets if collides 2 times
				bullet_exists=false;
			}
			
			honeycombcollision(bullet_x,bullet_y,honeycombx, honeycomby,
			alive,totalcollisions,honeycombformed);
			if (killerbeehit(window,redhoneycombsprite,bullet_x, bullet_y, killerbeex, killerbeey, 
			killernum,redhoneycombx, 
			redhoneycomby,totalkillercollisions,bullet_exists,addedkillerbees,redhoneycombformed)){
				currentscore+=1000;
			}
			redhoneycombcollision(bullet_x,bullet_y,redhoneycombx, 
			redhoneycomby,totalkillercollisions,redhoneycombformed);
			if(Keyboard::isKeyPressed(Keyboard::Space)){
				bullet_exists=true;
				collisions=0;
				
				}
				

				
			if (bullet_exists == true)
			{
				moveBullet(bullet_y, bullet_exists, bulletClock);
				drawBullet(window, bullet_x, bullet_y, bulletSprite);
				used+=((1/player_y)/2.182);// bcz fast fps so reduce accordingly the size of magazine
				//bullet reducing
				//2.182 based on calculation
				totalused+=used;
				if(used>=8){
					used=0;
					if(height>0)
						height-=4;
					bulletsize.setTextureRect(IntRect(10,50,width,height));
				}
				if(totalused>=56){
					totalused=0;
					//left--;
					
				}
				if (height<=5 && left>0){
					height=20;//orignial height as new spray
				    	bulletsize.setTextureRect(IntRect(10,50,width,height));
				    	left--;
				}
			}
			else
			{
				bullet_x = player_x;
				bullet_y = player_y;
			}
			
			drawPlayer(window, player_x, player_y, playerSprite, bulletsize);

			

			if (beehit(window,
			honeycombsprite,bullet_x,bullet_y,workerbeex,workerbeey,num,honeycombx,honeycomby, 
			totalcollisions,bullet_exists,addedbees, honeycombformed)==true){
				collisions++;
				currentscore+=100;
	    			checkhoneycomb=false;
			}
			else{
				checkhoneycomb=true;
			}
			
			checkbeesick(sickclock,sick,bullet_x, bullet_y, birdx, birdy);

			movebird(birdclock, birdx,birdy,honeycombx, honeycomby,currentscore, redhoneycombx, redhoneycomby, totalcollisions, totalkillercollisions,sick);
			drawbird(window,birdx,birdy, birdsprite,sick);
			
			window.draw(groundRectangle);
			score.setString(to_string(currentscore));  // Update the score display
			window.draw(score); 
			//printing sprays
			for(int i=0;i<left;i++){
				sprays.setPosition(40+i*50,570);
				window.draw(sprays);
			}
			if(currentscore==20000 || currentscore==40000 || currentscore==80000 || currentscore%80000==0){
				left+=0.001;//increasing lives
			}
			
			if(pl1==true && num==0){
				level1done=true;
				pl2=true;
				pl1=false;
				playing=false;
			}
			else if(pl2==true && num==0){
				level2done=true;
				pl3=true;
				pl2=false;
				playing=false;
				
			}
			else if(pl3==true && num==0){
				level3done=true;
				pl3=false;
				
		}
		}
		
		
		window.display();
		window.clear();
	}
}



//function declarations...

void drawPlayer(RenderWindow& window, float& player_x, float& player_y, Sprite& playerSprite,Sprite& bulletsize) {
	bulletsize.setPosition(player_x+17, player_y+28);
	window.draw(bulletsize);
	playerSprite.setPosition(player_x, player_y);
	window.draw(playerSprite);
	
}
void moveplayer(float& player_x, Clock& playerclock){
	 if (playerclock.getElapsedTime().asMilliseconds()<50) {
        return; // prevent rapid bullet  movement
    } // to stop fast movements as only one press needed
	if(Keyboard::isKeyPressed(Keyboard::Left)){
			if (player_x>0){ // so doesnt move left if at left edge
			player_x-=32;
			playerclock.restart();
			}
		}
	else if(Keyboard::isKeyPressed(Keyboard::Right)){
		if (player_x<(960-40)){ // so doesnt move right if at right edge
			player_x+=32;
			playerclock.restart();
			}
	}
	return;
}


void drawmenu(RenderWindow& window,bool& menudisplay,Sprite& backgroundsprite,Text start,Text levelselect,Text exitgame,Text ent){
	window.draw(backgroundsprite);
	window.draw(ent);
	window.draw(levelselect);
	window.draw(start);
	window.draw(exitgame);
}
void chooseoption(Text& levelselect,Text& start,Text& exitgame,bool& menudisplay,bool& leveldisplay,bool& game,int& selector,Clock& optionclock){
	if (optionclock.getElapsedTime().asMilliseconds()<100) {
        return; //controlling speed
	}
    	//hover color to blue 
    	//what will happen when enter is pressed
	if(selector==0){
		start.setFillColor(Color::Blue);
		levelselect.setFillColor(Color::Green);
		exitgame.setFillColor(Color::Green);
		if((Keyboard::isKeyPressed(Keyboard::Enter))){
			menudisplay=false;
			game=true;
			leveldisplay=false;
			sleep(milliseconds(200));
			return;
		}
	}
	else if(selector==1){
		levelselect.setFillColor(Color::Blue);
		start.setFillColor(Color::Green);
		exitgame.setFillColor(Color::Green);
		if((Keyboard::isKeyPressed(Keyboard::Enter))){
		cout<<"hllohd";
			leveldisplay=true;
			menudisplay=false;
			game=false;
			sleep(milliseconds(200));
			return;
		}
	}
	else if(selector==2){
		exitgame.setFillColor(Color::Blue);
		levelselect.setFillColor(Color::Green);
		start.setFillColor(Color::Green);
		if((Keyboard::isKeyPressed(Keyboard::Enter))){
			exit(0);
			return;
		}
	}
	
	if(Keyboard::isKeyPressed(Keyboard::Up)){
		selector--;
		optionclock.restart();
		}
	else if(Keyboard::isKeyPressed(Keyboard::Down)){
		selector++;
		optionclock.restart();
		}
		
		//max and min value
	if(selector>2){
		selector=2;
	}
	else if(selector<0){
		selector=0;
	}
	return ;
	
}
//level options menu
void drawlevelmenu(RenderWindow& window,bool leveldisplay, Sprite backgroundsprite,Text level1,Text level2,Text level3){
	
	window.draw(backgroundsprite);
	window.draw(level1);
	window.draw(level2);
	window.draw(level3);
}

void chooselevel(Text& level1,Text& level2,Text& level3,bool& pl1,bool& pl2,bool& pl3,int& levelselector,Clock& levelclock,bool& leveldisplay){
	if (levelclock.getElapsedTime().asMilliseconds()<200) {
		return; //controlling speed
	    }
	
	    	//hover color to blue 
	    	//what will happen when enter is pressed
		if(levelselector==0){
			level1.setFillColor(Color::Blue);
			level2.setFillColor(Color::Green);
			level3.setFillColor(Color::Green);
			if((Keyboard::isKeyPressed(Keyboard::Enter))){
				pl1=true;
				pl2=false;
				pl3=false;
				leveldisplay=false;
				levelclock.restart();
				return;
			}
		}
		else if(levelselector==1){
			level2.setFillColor(Color::Blue);
			level1.setFillColor(Color::Green);
			level3.setFillColor(Color::Green);
			if((Keyboard::isKeyPressed(Keyboard::Enter))){
				pl1=false;
				pl2=true;
				pl3=false;
				leveldisplay=false;
				levelclock.restart();
				return;
			}
		}
		else if(levelselector==2){
			level3.setFillColor(Color::Blue);
			level2.setFillColor(Color::Green);
			level1.setFillColor(Color::Green);
			if((Keyboard::isKeyPressed(Keyboard::Enter))){
				pl1=false;
				pl2=false;
				pl3=true;
				leveldisplay=false;
				levelclock.restart();
				return;
			}
		}
		
		if(Keyboard::isKeyPressed(Keyboard::Up)){
			levelselector--;
			levelclock.restart();
			}
		else if(Keyboard::isKeyPressed(Keyboard::Down)){
			levelselector++;
			levelclock.restart();
			}
			
		//max and min value
		if(levelselector>2){
			levelselector=2;
		}
		else if(levelselector<0){
			levelselector=0;
		}
	
}



void movebees(Clock& workerbeeclock,float workerbeex[][2],float workerbeey[],int num,int& addedbees,int totalcollisions,float honeycombx[],float honeycomby[],int hivex[],int hivey[],int& hives){
	 static Clock stopclock;
	 static Clock pausetime;
	 static bool paused=false;
	 static int randombee=-1;
	 if (pausetime.getElapsedTime().asSeconds()>=2) {
	 	
		randombee=rand()%addedbees;// to stop a random bee 
		// to stop a bee that exists and not honeycomb
		paused=true;
		pausetime.restart();
		
	 
	 }
	if (workerbeeclock.getElapsedTime().asMilliseconds()<80){ //adjusting movement using clock like other
        return;
        }
       
  	
       if(addedbees>num)addedbees=num;
       for(int i=0;i<addedbees;i++){
		//if (alive[i]==false) continue; //skip invalid bees
		 if (paused && i==randombee){
            		continue;//to keep the paused bee to its position
            	 }
		
		
       		if(workerbeex[i][1]>=0){
       			
	     		if (workerbeex[i][1]==0) {
	     			workerbeex[i][0]-=32;
	     			for(int j=0;j<totalcollisions;j++){
	       				if(workerbeex[i][0]<=honeycombx[j]+32 && workerbeex[i][0]>=honeycombx[j] && workerbeey[i]<=honeycomby[j]+32 && workerbeey[i]>=honeycomby[j]){
	       					workerbeex[i][1]= 1;
				    		workerbeey[i]+=32;
				    		for(int k=0;k<totalcollisions;k++){
				    		//to check if there is honeyxomb below for beehive
				    			if (honeycomby[k]==workerbeey[i]+32 && 
				    			honeycombx[k]==workerbeex[i][0]) {
				    			if(k==j)continue;
						        hivex[hives]=workerbeex[i][0];
						        hivey[hives]=workerbeey[i];
					  	        workerbeex[i][0]=-100;
					  	        workerbeex[i][1]=-1;
						        workerbeey[i]=-100;
						        hives++;
						        break;
						    }
						}
						    		break;
			       				}
			       				
			       			}
				
				if (workerbeex[i][0]<0 && workerbeex[i][0]>-100) {
				    workerbeex[i][1]= 1;
				    workerbeey[i]+=32;
				}
	       		}
	       		else if (workerbeex[i][1]==1){
	       			workerbeex[i][0]+=32;
	       			for(int j=0;j<totalcollisions;j++){
	       				if(workerbeex[i][0]<=honeycombx[j]+32 && workerbeex[i][0]>=honeycombx[j] && 
	       				workerbeey[i]<=honeycomby[j]+32 && workerbeey[i]>=honeycomby[j]){
	       					workerbeex[i][1]= 0;
				    		workerbeey[i]+=32;
				    		for(int k=0;k<totalcollisions;k++){
				    		
				    		//to check if there is honeyxomb below for beehive
				    			if (honeycomby[k]==workerbeey[i]+32 && 
				    			honeycombx[k]==workerbeex[i][0]) {
				    			if(k==j)continue;
						        hivex[hives]=workerbeex[i][0];
						        hivey[hives]=workerbeey[i];
					  	        workerbeex[i][0]=-100;
					  	        workerbeex[i][1]=-1;
						        workerbeey[i]=-100;
						        hives++;
						        break;
						    }
						}
				    		break;
	       				}
	       			}
				if (workerbeex[i][0]>=960-32) {
				    workerbeex[i][1]= 0;
				    workerbeey[i]+=32;
					}
	       			}
	       
	    		}
    		}
    		if (paused && pausetime.getElapsedTime().asSeconds() >= 1) {
			paused=false;
			randombee=-1;
		    }
    		if (stopclock.getElapsedTime().asSeconds()>= 2 && addedbees<num) {
		addedbees++;   //increase the number of bees on window
		stopclock.restart();//reset to start counting next 3 seconds
	    }
	workerbeeclock.restart();
   }

void drawbees(RenderWindow& window,float workerbeex[][2],float workerbeey[],Sprite& workerbeesprite,int num,int& addedbees,bool alive[]){
	if (addedbees>=num){
		addedbees=num;
		}
	else {
	for(int i=0;i<addedbees;i++){ //skip invalid bees
		if (workerbeex[i][1]>=0){
			workerbeesprite.setPosition(workerbeex[i][0],workerbeey[i]);
			window.draw(workerbeesprite);
		}
    	}
    }
    return;
}
void drawkiller(RenderWindow& window,float killerbeex[][2],float killerbeey[],Sprite& killerbeesprite,int killernum,int addedkillerbees){
	for(int i=0;i<killernum;i++){ //skip invalid bees
		if (killerbeex[i][1]!=-1){
			killerbeesprite.setPosition(killerbeex[i][0],killerbeey[i]);
			window.draw(killerbeesprite);
		}
}
return;
}
void movekiller(Clock& killerbeeclock,float killerbeex[][2],float killerbeey[],int killernum,int& addedkillerbees){
	static Clock stopclock1;
	
	if (killerbeeclock.getElapsedTime().asMilliseconds()<25){ //adjusting movement using clock like other
        return;
        }
	
	if(addedkillerbees>killernum)addedkillerbees=killernum;
        for(int i=0;i<addedkillerbees;i++){
		//if (alive[i]==false) continue; //skip invalid bees
       		if(killerbeex[i][1]>=0){
	     		if (killerbeex[i][1]==0) {
				killerbeex[i][0]-=32;
				if (killerbeex[i][0]<0) {
				    killerbeex[i][1]= 1;
				    killerbeey[i]+=32;
				}
	       		}
	       		else if (killerbeex[i][1]==1){
	       			killerbeex[i][0]+=32;
				if (killerbeex[i][0]>=960-32) {
				    killerbeex[i][1]= 0;
				    killerbeey[i]+=32;
					}
	       			}
	       
	    		}
    		}
    	if (stopclock1.getElapsedTime().asSeconds()>= 2 && addedkillerbees<killernum) {
		addedkillerbees++;   //increase the number of bees on window
		stopclock1.restart();//new bee will come in 3 seconds
	    }
	killerbeeclock.restart();
	
}




//draw honeycombs when collision
void drawhoneycomb(RenderWindow& window,Sprite& honeycombsprite,Sprite& redhoneycombsprite,int totalkillercollisions,float redhoneycombx[],float redhoneycomby[], float& bullet_x, float& bullet_y,int totalcollisions,float honeycombx[],float honeycomby[],int gone[]){
	for (int i=0; i<totalcollisions; i++) {
		if(honeycombx[i]>0){
			honeycombsprite.setPosition(honeycombx[i],honeycomby[i]);
			window.draw(honeycombsprite);
			//cout<<honeycombx[i];
			}
		}
	for (int i=0;i<totalkillercollisions;i++){
		//if(redhoneycombx[i]>0){
			redhoneycombsprite.setPosition(redhoneycombx[i],redhoneycomby[i]);
			window.draw(redhoneycombsprite);
			
			//}
		}
}

bool beehit(RenderWindow& window,Sprite& honeycombsprite,float bullet_x, float bullet_y, float workerbeex[][2], float workerbeey[], int& num, float honeycombx[], float honeycomby[], int& totalcollisions, bool bullet_exists, int& addedbees,Clock honeycombformed[]) {
	//if no bullet then return
	bool condition=false;
	if (!bullet_exists) {
        return false;
    }

    for(int i=0; i<num; i++) {
    	 //skip dead bees
       
        //collision checking with some margin left for less precision
        // ensuring the collision takes palce under one block of grid
        if (workerbeex[i][1]!=-1 && honeycombx[i]>=0)
        if ((bullet_x>=workerbeex[i][0]-32 && bullet_x<=workerbeex[i][0]+32) &&
            (bullet_y>=workerbeey[i]-32 && bullet_y<=workerbeey[i]+32)) {
            honeycombx[totalcollisions]=workerbeex[i][0];
            honeycomby[totalcollisions]=workerbeey[i];
           // drawhoneycomb(window,honeycombsprite,bullet_x, bullet_y);
      
            workerbeex[i][0]=-100;
            workerbeex[i][1]=-1;
            workerbeey[i]=-100;
            //alive[i]=false;
            honeycombformed[totalcollisions].restart();
            totalcollisions++;
            num--;
           
            
            condition=true; //collision detected
        }
    }
    if(condition==true)
    	return true;
   
    return false;
}

bool killerbeehit(RenderWindow& window,Sprite& redhoneycombsprite,float bullet_x, float bullet_y, float killerbeex[][2], float killerbeey[], int killernum, float redhoneycombx[], float redhoneycomby[], int& totalkillercollisions, bool bullet_exists, int& addedkillerbees,Clock redhoneycombformed[]){
	if (!bullet_exists) {
        return false;
    }

    for(int i=0; i<killernum; i++) {
    	 //skip dead bees
       
        //collision checking with some margin left for less precision
        // ensuring the collision takes palce under one block of grid
        if (killerbeex[i][1]!=-1)
        if ((bullet_x>=killerbeex[i][0]-32 && bullet_x<=killerbeex[i][0]+32) &&
            (bullet_y>=killerbeey[i]-32 && bullet_y<=killerbeey[i]+32)) {
            redhoneycombx[totalkillercollisions]=killerbeex[i][0];
            redhoneycomby[totalkillercollisions]=killerbeey[i];
           // drawhoneycomb(window,honeycombsprite,bullet_x, bullet_y);
            killerbeex[i][0]=-100;
            killerbeex[i][1]=-1;
            killerbeey[i]=-100;
            redhoneycombformed[i].restart();
            totalkillercollisions++;
            killernum--;
            
            
            return true; //collision detected
        }
    }
   
    return false;
}

void drawBullet(RenderWindow& window, float& bullet_x, float& bullet_y, Sprite& bulletSprite ) {
	bulletSprite.setPosition(bullet_x, bullet_y);
	
	window.draw(bulletSprite);
}
void honeycombcollision(float& bullet_x, float& bullet_y,float honeycombx[], float honeycomby[],bool alive[],int totalcollisions,Clock honeycombformed[]){
	for(int i=0;i<totalcollisions;i++){
		if(honeycombx[i]>=0 && honeycombformed[i].getElapsedTime().asMilliseconds()>500)
		if (bullet_x>=honeycombx[i]-32 && bullet_x<=honeycombx[i]+32 && bullet_y>=honeycomby[i]-32 && bullet_y<=honeycomby[i]+32){
		//removing the honey comb when shot
			
			honeycombx[i]=-100;
			honeycomby[i]=-100;
			
		}
	}
	
}
void redhoneycombcollision(float& bullet_x, float& bullet_y,float redhoneycombx[], float redhoneycomby[],int totalkillercollisions,Clock redhoneycombformed[]){
	for(int i=0;i<totalkillercollisions;i++){
		if(redhoneycombx[i]>=0 && redhoneycombformed[i].getElapsedTime().asMilliseconds()>500)
		if (bullet_x>=redhoneycombx[i]-32 && bullet_x<=redhoneycombx[i]+32 && bullet_y>=redhoneycomby[i]-32 && bullet_y<=redhoneycomby[i]+32){
		//removing the honey comb when shot
			
			redhoneycombx[i]=-100;
			redhoneycomby[i]=-100;
			
		}
	}
}

void drawbeehives(RenderWindow& window,Sprite& beehivesprite,int hivex[],int hivey[],int hives){
	window.draw(beehivesprite);
	for (int i=0;i<hives;i++){
		beehivesprite.setPosition(hivex[i],hivey[i]);
		window.draw(beehivesprite);
	}
}

//draw flowers
void drawflowers(RenderWindow& window){
	
}
void checkbeesick(Clock& birdsick,bool& sick,float& bullet_x,float& bullet_y,float& birdx,float& birdy){
	static int hits=0;
	
	if(hits>2){// 3 hits then will go off screen
		sick=true;
		birdsick.restart();
		birdx=-10;
		birdy=-10;
	}
	
	if(sick==true && birdsick.getElapsedTime().asSeconds()>=1){
	//now back at random place and hits =0
        sick=false;
        hits=0;
        birdx=rand()%960; 
        birdy=rand()%551;
        birdsick.restart();
    }

    //if bullet hit
    
    if(bullet_x>=birdx-32 && bullet_x<birdx+32 && bullet_y>=birdy-32 && bullet_y<=birdy+32) {
        hits++;
        birdsick.restart();
       
    }
	
}

void movebird(Clock& birdclock, float& birdx, float& birdy, float honeycombx[], float honeycomby[], 
              int& currentscore, float redhoneycombx[], float redhoneycomby[], int totalcollisions, 
              int totalkillercollisions, bool sick) {

    static int randx=0;//random x coordinate
    static int randy=0;//random y coordinate
    static bool turns=false;
    static int random=0;
    static int disty=0;
    static int distx=0;
    static bool motion=false;
    static Clock gap;

    if (sick) return;

    if (birdclock.getElapsedTime().asMilliseconds()<60 && gap.getElapsedTime().asSeconds()<1.5) {
        //speed and pause adjustment
        return; 
    }
    
    
    
    birdclock.restart();

    if (!motion) {
        if(!turns){  //random movement
            randx=rand() % 960;
            randy=rand()%551; //ground ignored
        } else{  //honeycomb is destination
            random=rand()%2;
            if (random==0 && totalkillercollisions>0) {
                random=rand()%totalkillercollisions;
                randx=redhoneycombx[random];
                randy=redhoneycomby[random];
            } else if(totalcollisions>0){
                random=rand()%totalcollisions;
                randx=honeycombx[random];
                randy=honeycomby[random];
            }
        }
        motion=true;
    }

    distx=randx-birdx;
    disty=randy-birdy;

    //movement
    if(distx>0)
    	birdx++;
    else if(distx<0)
    	birdx--;

    if(disty>0)
    	birdy++;
    else if(disty<0)
    	birdy--;

   //destination check
    if (turns==true) {
    	 // for red
        if (randx==redhoneycombx[random] && randy==redhoneycomby[random]) {
           
           if(redhoneycomby[random]>=0 && redhoneycomby[random]<=64){ // top 2 tiers
                	currentscore+=.2;
                }
                else if(redhoneycomby[random]>64 && redhoneycomby[random]<=160){
               		currentscore+=.18;
                }
                else{
                	currentscore+=.1500;
                }// as fast fps
            redhoneycombx[random]=-100;
            redhoneycomby[random]=-100;
        } //for yellow
        else if(randx==honeycombx[random] && randy==honeycomby[random]) {
       //decimal bcz of fast fps
       if(honeycomby[random]>=0 && honeycomby[random]<=64){ // top 2 tiers
                	currentscore+=0.1;
                }
                else if(honeycomby[random]>64 && honeycomby[random]<=160){
               		currentscore+=0.8;
                }
                else{
                	currentscore+=0.05;
                }
             
            honeycombx[random]=-100;
            honeycomby[random]=-100;
           }
    }
    if(birdx==randx && birdy==randy) {
        motion = false;
        turns = !turns;//switch movement
        gap.restart();
    }
}

void drawbird(RenderWindow& window,float& birdx,float& birdy,Sprite& birdsprite,bool sick){
	if(sick){
		birdsprite.setColor(Color::Green);
	}
	else{
		birdsprite.setColor(Color::Blue);
	}
	birdsprite.setPosition(birdx,birdy);
	window.draw(birdsprite);
}

void moveBullet(float& bullet_y, bool& bullet_exists, Clock& bulletClock) {
	if (bulletClock.getElapsedTime().asMilliseconds() < 20)
		return;

	bulletClock.restart();
	bullet_y -= 10;
	if (bullet_y < -32)
		bullet_exists = false;
}
