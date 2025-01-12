//abdullah malik 0872 bscs D q 4 30 by 30 grid
#include<iostream>
#include<unistd.h>
#include<fstream>
using namespace std;

int main(){
	int length,gen,neighbours,population=0;
	char file[20],grid[30][30]={0},temp[30][30]={0}; // temp is to store cells
	cout<<"Enter file name:";
	//validating input data
	do {
		length=0;
	 	cin>>file;
	 	//calculating length of array data
	 	while(file[length]!=0){
	 		length++;
	 		}
	 	if(length>20)
	 	cout<<"\nre enter,as its long\n";
	 }
	 while(length>20); //verifying
	cout<<"\nEnter number of Generations:";
	cin>>gen;
	ifstream in(file); //in will read from file ignoring spaces
	// taking data in file
	if(!in){
		cout<<"Error. file not found!";
		return 0;
	}
	for(int i=0;i<30;i++){
		for(int j=0;j<30;j++){
			in>>grid[i][j];
		}
	}
	in.close();//closing file for read
	for(int i=0;i<30;i++){
			for(int j=0;j<30;j++){
				cout<<grid[i][j]<<' ';
			}	
			cout<<endl;
		}
		//cout<<"\npopulationis:"<<population;
	
	
	bool live; // to check if alive or dead
	//checking for neighbors and living or dead cell accordingly
	for(int k=0;k<=gen;k++){
		system("clear");
		population=0; //resetting for each generation
		if (k==0){
			cout<<"\nInitial state:"<<endl;
		}
		else{
			cout<<"\nGeneration:"<<k<<endl;
		}
		for(int i=0;i<30;i++){
			for(int j=0;j<30;j++){
				neighbours=0; //resettin neighbours for each coordinate to be checked upon
				temp[i][j]=grid[i][j]; //storing in temp array to store back in original later
				if(grid[i][j]=='1'){
					cout<<'0';
					population+=1;
					live=1;
					}
				else if(grid[i][j]=='0' ){
					cout<<'.';
					live=0;
				}
				cout<<' ';
				
				if(j+1<30 && grid[i][j+1]=='1'){ // right 
					neighbours+=1;	
				}
				if(i+1<30 && j+1<30 && grid[i+1][j+1]=='1'){ //right and below
					neighbours+=1;
				}
				if(i-1>=0 && grid[i-1][j]=='1'){ //above row
					neighbours++;
				}
				if(i-1>=0 && j+1<30 && grid[i-1][j+1]=='1'){ //above and right
					neighbours++;
				}
				if(i+1<30 && grid[i+1][j]=='1' ){ //below
					neighbours++;
				}
				if(i+1<30 && j-1>=0 && grid[i+1][j-1]=='1'){ //below and left
					neighbours++;
				}
				if(j-1>=0 && grid[i][j-1]=='1'){
					neighbours++;
				}
				if(i-1>=0 && j-1>=0 && grid[i-1][j-1]=='1'){ //above and left
					neighbours++;
				}
				//conditions for live or dead cell separate
				if(live==1){
					if(neighbours<2 || neighbours>3){
						temp[i][j]='0';
					}
					else if(neighbours==2 || neighbours==3){
						temp[i][j]='1';
					}	
				}
				else{
					if(neighbours==3){
						temp[i][j]='1';
					}
				}
				
				
				}
		
			cout<<endl;
			}
		cout<<"POPULATION:"<<population<<endl;
		usleep(500000);
		
		//opening for overwriitng
		ofstream out(file);
		for(int i=0;i<30;i++){
			for(int j=0;j<30;j++){
				grid[i][j]=temp[i][j]; //shifting all new values in original grid
				out<<grid[i][j]<<' ';//overwriting the file
			}
		out<<endl;
		}
		out.close();//closing file for write
	}
	
	
return 0;
  }
