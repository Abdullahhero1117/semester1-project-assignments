//abdullah malik 0872 D ASSIGNMENT 2 Q4 date and triangle
#include<iostream>
using namespace std;
int main(){
//part a
	unsigned int day,month,year;
	bool leapyear=0,valid=1;
	cout<<"enter day:";
	cin>>day;
	cout<<endl<<"enter month:";
	cin>>month;
	cout<<endl<<"enter year:";
	cin>>year;
	if (year%4==0 && year>0){
		if (year%100!=0){
			leapyear=1;
			cout<<endl<<"it is a leap year\n";
			}
		else {
			if (year%400==0){
				leapyear=1;
				cout<<endl<<"it is a leap year\n";
				}
			else {
				leapyear=0;
				cout<<endl<<"it is not a leap year\n";
				}	
			}
		}
	else {
		leapyear=0;
		cout<<endl<<"it is not a leap year\n";
		}
	if (leapyear==0){
		if (month==2){
			if (day>=29){
				valid=0;
				}
		}
	}
	if (valid==1){
		if (month>12 || month==0){
			valid=0;
			}
		else {
			if (month==1 || month==3 || month==5 || month==7 || month==8 || month==10 || 
			month==12){
				if (day==0 || day>31){
					valid=0;
					}
				}
			else {
				if (day==0 || day>30){
					valid=0;
					}
				}
			}
		}
	if (valid==0){
		cout<<endl<<"date is invalid";
		}
	else {
		cout<<day<<"th ";
		month==1?cout<<"january "<<year:month==2?cout<<"february "<<year:month==3?cout<<"march "<<year:month==4?cout<<"april "<<year:month==5?cout<<"may "<<year:month==6?cout<<"june "<<year:month==7?cout<<"july "<<year:month==8?cout<<"august "<<year:month==9?cout<<"september "<<year:month==10?cout<<"october "<<year:month==11?cout<<"november "<<year:cout<<"december "<<year;
		}
	//part b
	int angle112,angle113,angle123,l11,l12,l13,angle212,angle213,angle223,l21,l22,l23;// l12 means triangle 1 side 2....angle123 means angle between l1 and l2 of triangle 1
	bool congruent=0,SSS=0,SAS=0,ASA=0,RHS=0,AAS=0;
	cout<<endl<<"triangle 1 length 1:";
	cin>>l11;
	cout<<endl<<"triangle 1 length 2:";
	cin>>l12;
	cout<<endl<<"triangle 1 length 3:";
	cin>>l13;
	cout<<endl<<"triangle 1 angle between side1 and side2:";
	cin>>angle112;
	cout<<endl<<"triangle 1 angle between side2 and side3:";
	cin>>angle123;
	cout<<endl<<"triangle 1 angle between side1 and side3:";
	cin>>angle113;
	cout<<endl<<"triangle 2 length 1:";
	cin>>l21;
	cout<<endl<<"triangle 2 length 2:";
	cin>>l22;
	cout<<endl<<"triangle 2 length 3:";
	cin>>l23;
	cout<<endl<<"triangle 2 angle between side1 and side2:";
	cin>>angle212;
	cout<<endl<<"triangle 2 angle between side2 and side3:";
	cin>>angle223;
	cout<<endl<<"triangle 2 angle between side1 and side3:";
	cin>>angle213;

	if ((l11==l21 && l12==l22 && l13==l23 )){
		SSS=1;
		}
	if ((l11==l21 && l12==l22 && angle112==angle212) && (l12==l22 && l23==l23 && angle123==angle223) &&
	 (l11==l21 && l13==l23 && angle123==angle223)){
		SAS=1;
		}
	
	if ((angle112==angle212 && angle123==angle223 && l12==l22) && (angle113==angle213 && angle112==angle212 && l11==l21) &&
	 (angle113==angle213 && angle123==angle223 && l13==l23)){
		ASA=1;
		}
	
	if ((l12==l22 && (angle123==angle223 || angle112==angle212) && angle113==angle213) && (l13==l23 && 
	(angle113==angle213 || angle123==angle223) && 
	angle112==angle212) && (l11==l21 && (angle112==angle212 || angle113==angle213) && angle123==angle223)){
		
		AAS=1; //checking aas condition
		}
	if (SSS==1 && AAS==1 && ASA==1 && SAS)// if all criterias are true then triangles are congruent
		cout<<endl<<"triangles are congruent in reality";
	else
		cout<<endl<<"they are not congruent in reality.";
	
	
	
	if (l11==l12 && l12==l13){
		cout<<endl<<"triangle 1 is equilateral";
		}
	else if(l11==l12 || l11==l13 || l12==l13){
		cout<<endl<<"triangle 1 is isosceles";
		}
	else{
		cout<<endl<<"triangle 1 is scalene";
		}
	
	if (l21==l22 && l22==l23){
		cout<<endl<<"triangle 2 is equilateral";
		}
	else if(l21==l22 || l21==l23 || l22==l23){
		cout<<endl<<"triangle 2 is isosceles";
		}
	else{
		cout<<endl<<"triangle 2 is scalene";
		}
return 0;
}
				
	
		
	
