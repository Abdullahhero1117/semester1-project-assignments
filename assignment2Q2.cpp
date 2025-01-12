//ABDULLAH MALIK 0872 D ASSIGNMENT 2 Q2
#include<iostream>
#include<string>
using namespace std;
	void applycream();// to apply cream 
	void subdue();// to subdue
	void blooddrip();//to add drip of blood to patient
	void findpatient();//to look for patient
	void injectoxygen();//to inject oxygen
	void comfortpatient();//to comfort patient
	void operate();//to operate and remove extra limbs
	void removing();//removing organs for donation
	void discharge();//to discharge  patient
	void admit();//to admit him for observation
	void defibrillate();//to defibrillate
	void massage();//massage scalp
	void lasereye();//laser eye removal operation
	void sequence();//sequence genome
	void autopsy();//performing autopsy
	void cauterize();//cauterize
	void inspect();//inspecting skeleton
	
	
	bool creamapplied;
int main(){
	string name,blood,scream,saturation,presence,comfort,vitamind,fluid,color,bloodloss,missing;
	int pulserate,limbs,painlevel;
	bool changed,healthy=0,battery;
	cout<<"drawing blood...";
	cout<<endl<<"record patients name:";
	cin>>name;
	cout<<endl<<"measuring height and weight...";
	cout<<endl<<"consulting standard weight and height chart and adjusting patient posture accordingly...";
	cout<<endl<<"is patient coughing blood(yes or no):";
	cin>>blood;
	if (blood=="yes"){
		blooddrip();
		}
	else if(blood=="no"){
		cout<<endl<<"is patient still here(yes or no):";
		cin>>presence;
		if (presence=="yes"){
			cout<<endl<<"he is here ";
			}
		else if ( presence=="no"){
			cout<<endl<<"he is not here...";
			findpatient();
			cout<<endl<<"patient found and is here now";
			}
		}
	cout<<endl<<"record pulse rate:";
	cin>>pulserate;
	cout<<endl<<"is patient screaming(yes or no):";
	cin>>scream;
	if (scream=="yes"){
		cout<<endl<<"he is screaming...";
		cout<<endl<<"calming him down...";
		}
	else {
		cout<<endl<<"he is not ";}
	cout<<endl<<"is blood saturation <50 % (yes or no):";
	cin>>saturation;
	
	if (saturation=="yes"){
		cout<<endl<<"saturation is less than 50, checking saturation....";
		injectoxygen();
		comfortpatient();
		cout<<endl<<"is patient comforted:";
		cin>>comfort;
		if (comfort=="yes"){
			cout<<endl<<"review medical history...";
			cout<<endl<<"skin grafts";
			cout<<endl<<"counting number of limbs....(enter value)";
			cin>>limbs;
			if (limbs>4){
				operate();
				cout<<endl<<"removing extra limbs..";
				subdue();
				applycream();
				creamapplied=1;
				}
			else {
				cout<<endl<<"measuring vitamin D....(enter if good or bad)";
				cin>>vitamind;
				if (vitamind=="bad"){
					cout<<endl<<"checking blood loss...(enter if substantial or minor)";
					cin>>bloodloss;
					if (bloodloss=="substantial"){
						applycream();
						creamapplied=1;
						}
					else if (bloodloss=="minor"){
						cout<<endl<<"is patient address changed (true or false):";
						cin>>changed;
						if (changed==true){
							cout<<endl<<"request organ donation...";
							cout<<endl<<"removing organs for donation...";
							removing();
							discharge();
							}
						else if (changed==false){
							cout<<endl<<"patient is healthy";
							healthy=true;
							admit();
							cout<<endl<<"admitted for observation.";
							}
						}
					}
				else if (vitamind=="good"){
					cout<<endl<<"check whether environment is fine..";
					cout<<endl<<"provided patient with saline solution to rinse...";
					cout<<endl<<"is phone battery low(true or false):";
					cin>>battery;
					if (battery==true){
						defibrillate();
						}
					else{
						cout<<endl<<"syncing photos...";
						cout<<endl<<"administering general anesthesia...";
						discharge();
						}
					
						
						
					}
				}
			}
		
		else if ( comfort=="no"){
			subdue();
			applycream();
			creamapplied=1;
			}
		}
	else if (saturation=="no"){
		inspect();
		cout<<endl<<"inspecting skeleton...";
		cout<<endl<<"are some bones missing (yes or no):";
		cin>>missing;
		if (missing=="yes"){
			cout<<endl<<"consult requested with doctor...";
			cout<<endl<<"dissection and operation going....";
			discharge();
			}
		else if (missing=="no"){
			cout<<endl<<"is fluid coming out of body(yes or no):";
			cin>>fluid;
			if (fluid=="no"){
				cout<<endl<<"squeeze for precise test...";
				fluid="yes";
				}
			else if (fluid=="yes"){
				cout<<endl<<"what color? (green,yellow,red or black):";
				cin>>color;
				if (color=="yellow"){
					cout<<endl<<"squeezing.."<<endl;
					cout<<"fluid of what color now?(red,black,green):";
					cin>>color;
					}
				else if (color=="green"){
					cauterize();
					cout<<endl<<"cauterizing...";
					}
				else if( color=="black"){
					cout<<endl<<"cleaning up with water or sprinklers..";
					subdue();
					applycream();
					creamapplied=1;
					}
				}
				}
			}
	if (fluid=="red" || fluid=="green" || creamapplied==1 || healthy==true){
		cout<<endl<<"enter level of pain :";
		cin>>painlevel;
		if (painlevel==9){
			admit();
			cout<<endl<<"admitted... enter level of pain :";
			cin>>painlevel;
			}
		if (painlevel==10){
			lasereye();
			cout<<endl<<"laser eye..";
			admit();
			cout<<endl<<"admitted..enter level of pain :";
			cin>>painlevel;
			}
		if (painlevel>=0 && painlevel<=8){
			massage();
			cout<<endl<<"patient is healthy";
			admit();
			}
		sequence();
		cout<<endl<<"applying tourniquet...";
		autopsy();
			}
		
return 0;
	}
	
void applycream(){
 cout<<"applying cream";

 }
 void subdue(){
 cout<<"subduing patient";
 
 }
 void findpatient(){
 cout<<"..";
 
 }
void blooddrip(){
 cout<<"applying blood drip";
 }
 void injectoxygen(){
 cout<<"injecting oxygen";
 
 }	
void operate(){
 cout<<"operating";

 }	
void comfortpatient(){
 cout<<"comforting patient";
 
 }
void removing(){
 cout<<"removing organs for donation";

 }
 void discharge(){
 cout<<"patient discharged";

 }		
void defibrillate(){
	cout<<"defibrillating";

 }
void admit(){
 cout<<"admitted";

 }	
void massage(){
cout<<"massaging..";

 }	
void lasereye(){
cout<<"laser eye going on..";
 
 } //laser eye removal operation
void sequence(){
cout<<"sequencing...";

 }	//sequence genome
void autopsy(){
cout<<"performing autopsy..";
 }	//performing autopsy	
void inspect(){
	cout<<"inspecting...";
 
 }					
void cauterize(){
	cout<<"cauterizing...";
 }				
				
					
				
		
	
	
			
			
	
