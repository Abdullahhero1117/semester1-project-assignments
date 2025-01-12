//abdullah malik 0872 D q5 pattern
// Online C++ compiler to run C++ program online
#include <iostream>
using namespace std;
int main() {
    for (int y=56;y>=0;y--){  // for y coordinates
        for(int x=-20;x<=20;x++){ // for x coordinates
            //first horizontal line
            if(y==56 && (x>=-8 && x<=8)){
              if(x==-8 || x==8)
              cout<<'*';
              else if(x<8 && x>-8)
              cout<<'|';
            }
            // big lines 
            else if(y==2*x || y==-2*x){
                cout<<'/';
            } 
            //black line on graph
            else if((y==2*x+48 || y==-2*x+48) && ((x<=-12 && x>=-16) ||
             (x>=12 && x<=16))){
                cout<<'[';
            }
            //straight lines vertical
            else if((x==20 || x==-20) && (y>=28 && y<=40)){
                cout<<'|';
            }// purple lines on edges
            else if((y==-3*x-32 || y==3*x-32) && (x<=-16 || x>=16) && y>=16){
                cout<<']';
            }// purple lines forming a triangle with first line
           
            //2 red lines connected with green ones and top one
            else if(((x>=-16 && x<=-8) || (x>=8 && x<=16)) && (y==-3*x+80
             || y==3*x+80)){
                cout<<'*';
            }// triangle lines with horizontal on top
            else if((y==-2*x+40 && x>=-8 && x<=0)){
            cout<<'|';
            }
            else if((y==2*x+40 && x>=0 && x<=8)){
            cout<<'|';
            } 
             // both green lines
            else if((y==x/2 +50) && (x<=-12)){
            cout<<'|';
            }
            else if((y==-x/2 +50) && x>=12){
            	cout<<'|';
            }
           
            //smiley face
            
            else if((x==-2 || x==2) && y==52){
            	cout<<'0';
            }
            else if(x==0 && y==50){
            	cout<<'|';
            }
            else if((x==-2 && y==47) ||(x==-1 && y==46)){
            	cout<<'\\';
            }
            else if((x==2 && y==47) ||(x==1 && y==46)){
            	cout<<'/';
            }// if no condition true than space
            else{
            	cout<<' ';
            }
        }
         //next line
         cout<<endl;
    }

return 0;
    }
