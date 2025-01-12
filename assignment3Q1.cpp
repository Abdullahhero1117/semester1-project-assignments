//abdullah malik 0872 bscsD q1 superhero in game ASSIGNMENT 3
#include<iostream>

using namespace std;

void display();
void checkpowers();
void grant();
void revoke();
void improvestats();
void levelup();
unsigned long long int hero=0,powers,money,wisdom,level,strength,endurance,agility,speed,full,maxvalue=18446744073709551615ULL; // full is a variable with 8 bits active meaning value is 255
int power,choice,shift,task=1;;
int main(){
	cout<<"WELCOME TO HEROES OF COSMOS!!!\n";
	cout<<"Enter your player as a 64 bit integer\n";
	cin>>hero;	
	if (hero>maxvalue){
		return 0;
	}
	while (task>0){
		cout<<"\nEnter the number of your task you would like to perform:";
		cout<<endl<<"0 to exit menu\n";
		cout<<"1 to display stats\n";
		cout<<"2 to check powers\n";
		cout<<"3 to grant powers\n";
		cout<<"4 to revoke power\n";
		cout<<"5 to improve stats\n";
		cout<<"6 to level up";
		cin>>task;
		level=(hero & 255) ; // to remove any value before power bits
		money=(hero>>8) & 255;
		powers=(hero>>16) & 255;
		wisdom=(hero>>24) & 255;
		strength=(hero>>32) & 255;
		endurance=(hero>>40) & 255;
		agility=(hero>>48) & 255;
		speed=(hero>>56) & 255;
		switch (task){
			case 0:cout<<endl<<"exited..";
				break;
			case 1:display();
				break;
			case 2:checkpowers();
				break;
			case 3:{grant();
				cout<<endl<<"granted";}
				break;
			case 4:{revoke();
				cout<<endl<<"revoked";}
				break;
			case 5:{improvestats();
				cout<<endl<<"improved";}
				break;
			case 6:{levelup();
				cout<<endl<<"levelled up";}
				break;
			 default:{cout<<endl<<"incorrect or out of criteria input";}
			}
		
		}
}


void display(){
	cout<<endl<<"current experience level:"<<level;
	cout<<endl<<"money:"<<money;
	cout<<endl<<"active powers:\n";
	if ((powers & 1) == 1){
		cout<<endl<<"-sky soar";
		}
	if (((powers>>1) & 1) == 1){
		cout<<endl<<"-blade of eternity";
		}
	if (((powers>>2) & 1) == 1){
		cout<<endl<<"-shadow cloak";
		}
	if (((powers>>3) & 1) == 1){
		cout<<endl<<"-inferno burst";
		}
	if (((powers>>4) & 1) == 1){
		cout<<endl<<"-titan strength";
		}
	if (((powers>>5) & 1) == 1){
		cout<<endl<<"-photon dash";
		}
	if (((powers>>6) & 1) == 1){
		cout<<endl<<"-arcane arsenal";
		}
	if (((powers>>7) & 1) == 1){
		cout<<endl<<"-chrono freeze";
		}
	
	cout<<endl<<endl<<"wisdom level:"<<wisdom;
	cout<<endl<<"strength level:"<<strength;
	cout<<endl<<"endurance level:"<<endurance;
	cout<<endl<<"agility level:"<<agility;
	cout<<endl<<"speed level:"<<speed;
}
void checkpowers(){
	cout<<endl<<"input bit number to check if power active or not (1=sky soar, 2=blade of eternity, 3=shadow cloak, 4=inferno burst, 5=titan strength, 6= photon dash, 7=arcane arsenal, 8=chrono freeze):";
	cin>>power;
	if ((powers & (1<<(power-1)))==0){
		cout<<endl<<"power is inactive";
		}
	else{
		cout<<endl<<"it is active";
		}	
}

//revoke and grant are similar as they will add or subtract values accordingly


void grant(){
	cout<<endl<<"enter a num to activate a power..(1=sky soar, 2=blade of eternity, 3=shadow cloak, 4=inferno"<< 
	" burst, 5=titan strength, 6= photon dash, 7=arcane arsenal, 8=chrono freeze):";
	cin>>power;
	shift=power-1;// variable to know the number of shift to do
	powers|= 1<<shift;
	switch (power){
		case 1:{
		//if wisdom and speed value is greater than 253 , then it means that after adding 2 it will result 
		//in overflow bit as we need just 8 bit value
		wisdom>253?wisdom=255:wisdom+=2;
		speed>253?speed=255:speed+=2;
		 	}
		 	break;
		 case 2:{strength>252?strength=255:strength+=3;}
			 break;
		 case 3:{endurance>254?endurance=255:endurance+=1;}
		 	break;
		 case 4:{strength>252?strength=255:strength+=3;
		 endurance>252?endurance=255:endurance+=3;}
		 	break;
		 case 5:{strength>127?strength=255:strength<<=1;}
		 	break;
		 case 6:{speed>127?speed=255:speed<<=1;}
		 	break;
		 case 7:{agility>251?agility=255:agility+=4;}
		 	break;
		  case 8:{agility>252?agility=255:agility+=3;
		 endurance>252?endurance=255:endurance+=3;}
		 	break;
		 default:{cout<<endl<<"incorrect or out of criteria input";}
	}  
	//to update values in hero. the value of full will become its opposite and anded with hero to remove current bits in that particular range and then ORed with new values. 
	hero=((hero & ~full) | level);  
	hero=((hero & ~(full<<8)) | (money<<8));  
	hero=((hero & ~(full<<16)) | (powers<<16));  
	hero=((hero & ~(full<<24)) | (wisdom<<24));  
	hero=((hero & ~(full<<32)) | (strength<<32)); 
	hero=((hero & ~(full<<40)) | (endurance<<40)); 
	hero=((hero & ~(full<<48)) | (agility<<48)); 
	hero=((hero & ~(full<<56)) | (speed<<56)); 
	
}


void revoke(){
	cout<<endl<<"enter a num to de-activate a power..(1=sky soar, 2=blade of eternity, 3=shadow cloak, 4=inferno"
	"burst, 5=titan strength, 6= photon dash, 7=arcane arsenal, 8=chrono freeze):";
	cin>>power;
	shift=power-1;
	powers &= ~ (1 << shift);
	switch (power){
		case 1:{
		//if wisdom and speed value is smaller than 3 , then it means that after subtracting 2 it might 
		//result in an unwanted number as we need just 8 bit correct value
		wisdom<2?wisdom=0:wisdom-=2;
		speed<2?speed=0:speed-=2;
		 	}
			 break;
		 case 2:{strength<3?strength=0:strength-=3;}
			 break;
		 case 3:{endurance<1?endurance=0:endurance-=1;}
		 	break;
		 case 4:{strength<3?strength=0:strength-=3;
		 endurance<3?endurance=0:endurance-=3;}
		 	break;
		 case 5:{strength>>=1;}
		 	break;
		 case 6:{speed>>=1;}
		 	break;
		 case 7:{agility<4?agility=0:agility-=4;}
		 	break;
		  case 8:{agility<3?agility=0:agility-=3;
		 endurance<3?endurance=0:endurance-=3;}
		 	break;
	}
	//to update values in hero. the value of full will become its opposite and anded with hero to remove current bits in that particular range and then ORed with new values. 
	hero=((hero & ~full) | level);  
	hero=((hero & ~(full<<8)) | (money<<8));  
	hero=((hero & ~(full<<16)) | (powers<<16));  
	hero=((hero & ~(full<<24)) | (wisdom<<24));  
	hero=((hero & ~(full<<32)) | (strength<<32)); 
	hero=((hero & ~(full<<40)) | (endurance<<40)); 
	hero=((hero & ~(full<<48)) | (agility<<48)); 
	hero=((hero & ~(full<<56)) | (speed<<56));   
}


void levelup(){
	level+=1;
	if (powers==255){
		cout<<endl<<"all powers are already activated";
	}
	else{
	shift=0;
	if ((powers & (1<<shift))==0){
		powers|= 1<<shift;
		}
	else if ((powers & (1<<(shift+=1)))==0){
		powers|= 1<<shift;
		}
	else if ((powers & (1<<(shift+=1)))==0){
		powers|= 1<<shift;
		}
	else if ((powers & (1<<(shift+=1)))==0){
		powers|= 1<<shift;
		}
	else if ((powers & (1<<(shift+=1)))==0){
		powers|= 1<<shift;
		}
	else if ((powers & (1<<(shift+=1)))==0){
		powers|= 1<<shift;
		}
	else if ((powers & (1<<(shift+=1)))==0){
		powers|= 1<<shift;
		}
	else if ((powers & (1<<(shift+=1)))==0){
		powers|= 1<<shift;
		}
	}
	//to update values in hero. the value of full will become its opposite and anded with hero to remove current bits in that particular range and then ORed with new values. 
	hero=((hero & ~full) | level);  
	hero=((hero & ~(full<<8)) | (money<<8));  
	hero=((hero & ~(full<<16)) | (powers<<16));  
	hero=((hero & ~(full<<24)) | (wisdom<<24));  
	hero=((hero & ~(full<<32)) | (strength<<32)); 
	hero=((hero & ~(full<<40)) | (endurance<<40)); 
	hero=((hero & ~(full<<48)) | (agility<<48)); 
	hero=((hero & ~(full<<56)) | (speed<<56)); 

}
//improvestats will increment the attributes
void improvestats(){
	if (money<5){
		cout<<endl<<"not sufficient money available..";
		}
	else {
		money-=5;
		cout<<endl<<"which attribute do you want to improve? 1=wisdom,2=strength,3=endurance,4=agility,5=speed:";
		cin>>choice;
		switch (choice){
		case 1:{wisdom>254?wisdom=255:wisdom+=1;}
			break;
		case 2:{strength>254?strength=255:strength+=1;}
			break;
		case 3:{endurance>254?endurance=255:endurance+=1;}
			break;
		case 4:{agility>254?agility=255:agility+=1;}
			break;
		case 5:{speed>254?speed=255:speed+=1;}
			break;
		}
	//to update values in hero. the value of full will become its opposite and anded with hero to remove current bits in that particular range and then ORed with new values. 
	hero=((hero & ~full) | level);  
	hero=((hero & ~(full<<8)) | (money<<8));  
	hero=((hero & ~(full<<16)) | (powers<<16));  
	hero=((hero & ~(full<<24)) | (wisdom<<24));  
	hero=((hero & ~(full<<32)) | (strength<<32)); 
	hero=((hero & ~(full<<40)) | (endurance<<40)); 
	hero=((hero & ~(full<<48)) | (agility<<48)); 
	hero=((hero & ~(full<<56)) | (speed<<56)); 
	}
  }
