//abdullah malik 0872 D ASSIGNMENT 2 psl match ticket
#include<iostream>
#include<string>
#include<cstdlib>
using namespace std;
int main(){
	string IK="IMRAN KHAN",SA="SHOAIB AKHTAR",ST="SOHAIL TANVEER",JA="JAVED AKHTAR",AM="AZHAR MEHMOOD",MB="MIRAN BUKSH",YA="YASIR ARAFAT",JM="JAVED MIANDAD",VIP1="LEFT BLACK VIP",VIP2="RIGHT BLACK VIP",enclosure;
	int match,cnic,adultcnic,adults,children,totaltickets,surcharge=1,perhead,ik,jm,ja,sa,st,am,mb,vip1,
	vip2,ya,under5,under10,temp;//adult cnic is cnic of purchaser
	double childamount=0.0,adultamount,totalamount,discount=0.0,rebate;// child amount is total amount charged on child....
	char ticket;
	bool familycriteria=0,individualcriteria=0,childcondition=0,available=0;// child condition is a bool variable used to see if the inputs for 2 different child ages are less than or equal to the original number of children entered before to not cause error
	
	cout<<"1. 27 Feb 2024 – Islamabad United v Quetta Gladiators (Night Match)"<<endl;
	cout<<"2. 28 Feb 2024 – Peshawar Zalmi v Lahore Qalandars (Night Match)"<<endl;
	cout<<"3. 29 Feb 2024 – Islamabad United v Peshawar Zalmi (Night Match)"<<endl;
	cout<<"4. 1 Mar 2024 – Islamabad United v Karachi Kings (Night Match)"<<endl;
	cout<<"5. 2 Mar 2024 – Peshawar Zalmi v Karachi Kings (Night Match)"<<endl;
	cout<<"6. 5 Mar 2024 – Peshawar Zalmi v Quetta Gladiators (Night Match)"<<endl;
	cout<<"7. 7 Mar 2024 – Peshawar Zalmi v Islamabad United (Day Match)"<<endl;
	cout<<"8. 8 Mar 2024 – Multan Sultans v Islamabad United (Day Match)"<<endl;
	cout<<"choose from 1-8:";
	cin>>match;
	if (match>=1 && match<=6){
		cout<<endl<<"NIGHT MATCHES (7-10:15 PM):"
		<<endl<<"VIP: Rs. 3000"
		<<endl<<"Premium: Rs. 1500"
		<<endl<<"First-class: Rs. 1000"
		<<endl<<"General: Rs. 500";
		}
	else if (match==7 || match==8){
		cout<<endl<<"Day Matches (2 pm - 5:15 pm):"
		<<endl<<"VIP: Rs. 2000"
		<<endl<<"Premium: Rs. 1000"
		<<endl<<"First-class: Rs. 500"
		<<endl<<"General: Rs. 250";
		}
	
	cout<<endl<<"Enclosures:"<<endl<<IK<<"  seats available:"<<(ik = 1+(rand() % 1001))
	<<endl<<JM<<"  seats available:"<<(jm = 1+(rand() % 1001))
	<<endl<<AM<<"  seats available:"<<(am = 1+(rand() % 1001))
	<<endl<<JA<<"  seats available:"<<(ja = 1+(rand() % 1001))
	<<endl<<YA<<"  seats available:"<<(ya = 1+(rand() % 2501))
	<<endl<<MB<<"  seats available:"<<(mb = 1+(rand() % 2501))
	<<endl<<SA<<"  seats available:"<<(sa = 1+(rand() % 2001))
	<<endl<<ST<<"  seats available:"<<(st = 1+(rand() % 2001))
	<<endl<<VIP1<<"  seats available:"<<(vip1 = 1+(rand() % 251))
	<<endl<<VIP2<<"  seats available:"<<(vip2 = 1+(rand() % 251))
	<<endl<<"choose your enclosure (capital letter of first name and second name, or VIP1 or VIP2 for vip)";
	cin>>enclosure;
	cout<<endl<<"enter your choice( F=family ticket or I=individual ticket):";
	cin>>ticket;
	if (ticket=='F'){
		cout<<endl<<"enter number of adults (upto 4):";
		cin>>adults;
		cout<<endl<<"enter number of children (upto 5):";
		cin>>children;
		totaltickets=adults+children;
		
		if (adults>0 && children>1 && adults<=4 && children<=5){
			familycriteria=1;
			
			}
		else{
			cout<<endl<<"input doesnt meet criteria.";
			}
		}
	else if (ticket=='I'){
		cout<<endl<<"enter number of adults (upto 8):";
		cin>>adults;
		totaltickets=adults;
		
		if (adults<=8 && adults>0){
			individualcriteria=1;
			}

			}
		else {
		cout<<endl<<"input doesnt meet criteria.";
		}
	switch (totaltickets){
	case 1:{cout<<endl<<"enter cnic:";
		cin>>cnic;}
		break;
	case 2:{cout<<endl<<"enter cnic of purchaser:";
		cin>>adultcnic;
		cout<<endl<<"enter cnic 2:";
		cin>>cnic;}
		break;
	case 3:{cout<<endl<<"enter cnic of purchaser:";
		cin>>adultcnic;
		cout<<endl<<"enter cnic 2:";
		cin>>cnic;
		cout<<endl<<"enter cnic 3:";
		cin>>cnic;}
		break;
	case 4:{cout<<endl<<"enter cnic of purchaser:";
		cin>>adultcnic;
		cout<<endl<<"enter cnic 2:";
		cin>>cnic;
		cout<<endl<<"enter cnic 3:";
		cin>>cnic;
		cout<<endl<<"enter cnic 4:";
		cin>>cnic;
		}
		break;
	case 5:{cout<<endl<<"enter cnic of purchaser:";
		cin>>adultcnic;
		cout<<endl<<"enter cnic 2:";
		cin>>cnic;
		cout<<endl<<"enter cnic 3:";
		cin>>cnic;
		cout<<endl<<"enter cnic 4:";
		cin>>cnic;
		cout<<endl<<"enter cnic 5:";
		cin>>cnic;}
		break;
	case 6:{cout<<endl<<"enter cnic of purchaser:";
		cin>>adultcnic;
		cout<<endl<<"enter cnic 2:";
		cin>>cnic;
		cout<<endl<<"enter cnic 3:";
		cin>>cnic;
		cout<<endl<<"enter cnic 4:";
		cin>>cnic;
		cout<<endl<<"enter cnic 5:";
		cin>>cnic;
		cout<<endl<<"enter cnic 6:";
		cin>>cnic;}
		break;
	case 7:{cout<<endl<<"enter cnic of purchaser:";
		cin>>adultcnic;
		cout<<endl<<"enter cnic 2:";
		cin>>cnic;
		cout<<endl<<"enter cnic 3:";
		cin>>cnic;
		cout<<endl<<"enter cnic 4:";
		cin>>cnic;
		cout<<endl<<"enter cnic 5:";
		cin>>cnic;
		cout<<endl<<"enter cnic 6:";
		cin>>cnic;
		cout<<endl<<"enter cnic 7:";
		cin>>cnic;}
		break;
	case 8:{cout<<endl<<"enter cnic of purchaser:";
		cin>>adultcnic;
		cout<<endl<<"enter cnic 2:";
		cin>>cnic;
		cout<<endl<<"enter cnic 3:";
		cin>>cnic;
		cout<<endl<<"enter cnic 4:";
		cin>>cnic;
		cout<<endl<<"enter cnic 5:";
		cin>>cnic;
		cout<<endl<<"enter cnic 6:";
		cin>>cnic;
		cout<<endl<<"enter cnic 7:";
		cin>>cnic;
		cout<<endl<<"enter cnic 8:";
		cin>>cnic;}
		break;
	case 9:{cout<<endl<<"enter cnic of purchaser:";
		cin>>adultcnic;
		cout<<endl<<"enter cnic 2:";
		cin>>cnic;
		cout<<endl<<"enter cnic 3:";
		cin>>cnic;
		cout<<endl<<"enter cnic 4:";
		cin>>cnic;
		cout<<endl<<"enter cnic 5:";
		cin>>cnic;
		cout<<endl<<"enter cnic 6:";
		cin>>cnic;
		cout<<endl<<"enter cnic 7:";
		cin>>cnic;
		cout<<endl<<"enter cnic 8:";
		cin>>cnic;
		cout<<endl<<"enter cnic 9:";
		cin>>cnic;}
		break;
	default:
		cout<<"not under criteria..";
		break;
	
	}
	if ((enclosure=="IK" && totaltickets<=ik) || (enclosure=="JM" && totaltickets<=jm) ||  (enclosure=="AM" && 
	totaltickets<=am) ||  (enclosure=="JA" && totaltickets<=ja) ||  (enclosure=="YA" && totaltickets<=ya) ||  
	(enclosure=="MB" && totaltickets<=mb) ||  (enclosure=="SA" && totaltickets<=sa) ||  (enclosure=="ST" && 
	totaltickets<=st) ||  (enclosure=="VIP1" && totaltickets<=vip1) ||  (enclosure=="VIP2" && 
	totaltickets<=vip2)){
		available=1;
		}
	
	else {
		cout<<endl<<"number of tickets larger than available seats..";
		}
		//ended the program here if condition doesnot suffice as other 2 options are either loop for efficient program or repeating the program from line 52 to 75 in this else statement.
	
	
	if ((individualcriteria==1 || familycriteria==1) && available==1){
		if (enclosure=="VIP1" || enclosure=="VIP2"){
			if(familycriteria==1){
				totaltickets<=5?discount=0:discount=5;

				}
			if (adults>5){
				discount=2*(adults-5);
				
					
				}
			
			}
		else if (enclosure=="IK" || enclosure=="JM" || enclosure=="JA" || enclosure=="AM" ){
			if (familycriteria==1){
				discount=10;
				rebate=20;
				
				
			}
			if (adults>4){
				discount+=12;
				
				}
			
			}
		else if (enclosure=="SA" || enclosure=="ST" || enclosure=="YA" || enclosure=="MB" ){
			if (totaltickets>=3 && totaltickets<=5){
				discount=5;
				}
			else if (totaltickets>=6 && totaltickets<=8){
				discount=10;

				}
			else if(totaltickets>8){
				discount=15;
				
				}
			}
		if (totaltickets>6 && familycriteria==1){
			discount=discount+5;
			
			}
		if (familycriteria==1){
			cout<<endl<<"enter number of children under 5 : ";
			cin>>under5;
			cout<<"\n enter number of children between age 5-10 :";
			cin>>under10;
			if (children<under10+under5){
				cout<<"\n re enter child number under ages as it exceeds total children..";
				cout<<endl<<"enter number of children under 5 : ";
				cin>>under5;
				cout<<"\n enter number of children between age 5-10 :";
				cin>>under10;
				}
			childcondition=1;
			}
		if (match==1 || match==3){
			surcharge=10;
				}
		if ((match==7 || match==8) && totaltickets>8){
			discount+=5;
				}
		
		if (match>=1 && match<=6){
			if (enclosure=="VIP1" || enclosure=="VIP2"){
				perhead=3000;
				}
			else if (enclosure=="IK" || enclosure=="JM" || enclosure=="AM" || enclosure=="JA"){
				perhead=1500;
			 	}
			else if (enclosure=="SA" || enclosure=="ST" ){
				perhead=1000;
				}
			else if (enclosure=="YA" || enclosure=="MB" ){
				perhead=500;
				}
			}
		else if (match==7 || match==8){ 
			if (enclosure=="VIP1" || enclosure=="VIP2"){
				perhead=2000;
				}
			else if (enclosure=="IK" || enclosure=="JM" || enclosure=="AM" || enclosure=="JA"){
				perhead=1000;
			 	}
			else if (enclosure=="SA" || enclosure=="ST" ){
				perhead=500;
				}
			else if (enclosure=="YA" || enclosure=="MB" ){
				perhead=250;
				}
			}
		temp=perhead;// so that we can get our original value of perhead back after running the foloowing condition
		if (childcondition==1){
			if (enclosure=="IK" || enclosure=="JM" || enclosure=="JA" || enclosure=="AM" ){ 
				perhead=(1-(rebate/100))*perhead;
				}
			childamount=(perhead*under5*.7)+(perhead*under10*.75)+(perhead*(children-under5-under10));
			perhead=temp;
			}
		discount=1-(discount/100);
		adultamount=perhead*adults;
		totalamount=discount*(childamount+adultamount);
			
		cout<<"\n total amount:"<<totalamount;
		cout<<endl<<"total tickets:"<<totaltickets;
		cout<<endl<<"cnic of purchaser:"<<adultcnic;
		cout<<endl<<"selected match:";
		switch (match){
		case 1:cout<<"1. 27 Feb 2024 – Islamabad United v Quetta Gladiators (Night Match)"<<endl;
			break;
		case 2:cout<<"2. 28 Feb 2024 – Peshawar Zalmi v Lahore Qalandars (Night Match)"<<endl;
			break;
		case 3:cout<<"3. 29 Feb 2024 – Islamabad United v Peshawar Zalmi (Night Match)"<<endl;
			break;
		case 4:cout<<"4. 1 Mar 2024 – Islamabad United v Karachi Kings (Night Match)"<<endl;
			break;
		case 5:cout<<"5. 2 Mar 2024 – Peshawar Zalmi v Karachi Kings (Night Match)"<<endl;
			break;
		case 6:cout<<"6. 5 Mar 2024 – Peshawar Zalmi v Quetta Gladiators (Night Match)"<<endl;
			break;
		case 7:cout<<"7. 7 Mar 2024 – Peshawar Zalmi v Islamabad United (Day Match)"<<endl;
			break;
		case 8:cout<<"8. 8 Mar 2024 – Multan Sultans v Islamabad United (Day Match)"<<endl;
			break;
		default:cout<<"\nvalue entered out of criteria..";
		}
		if (enclosure=="IK"){ 
			cout<<"enclosure: IMRAN KHAN";
			cout<<endl<<"ticket type: Premium";
			}
		else if (enclosure=="JA"){ 
			cout<<"enclosure: JAVED AKHTAR";
			cout<<endl<<"ticket type: Premium";
			}
		else if (enclosure=="AM"){ 
			cout<<"enclosure: AZHAR MEHMOOD";
			cout<<endl<<"ticket type: Premium";
			}
		else if (enclosure=="JM"){ 
			cout<<"enclosure: JAVED MIANDAD";
			cout<<endl<<"ticket type: Premium";
			}
		else if (enclosure=="SA"){ 
			cout<<"enclosure: SHOAIB AKHTAR";
			cout<<endl<<"ticket type: First class";
			}
		else if (enclosure=="ST"){ 
			cout<<"enclosure: SOHAIL TANVIR";
			cout<<endl<<"ticket type: First class";
			}
		else if (enclosure=="VIP1"){ 
			cout<<"enclosure: LEFT BLACK VIP";
			cout<<endl<<"ticket type: VIP";
			}
		else if (enclosure=="VIP2"){ 
			cout<<"enclosure: RIGHT BLACK VIP ";
			cout<<endl<<"ticket type: VIP";
			}
		else if (enclosure=="MB"){ 
			cout<<"enclosure: MIRAN BUKSH";
			cout<<endl<<"ticket type: General";
			}
		else if (enclosure=="YA"){ 
			cout<<"enclosure: YASIR ARAFAT";
			cout<<endl<<"ticket type: General";
			}
		
		cout<<endl<<(1-discount)*100;
		
		
	}
	else {
		cout<<endl<<"doesnt meet criteria";
		}
		
	
		

		
	



return 0;
}
	
	
	
