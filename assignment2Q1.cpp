//abdullah malik 0872 D ASSIGNMENT 2. this is question 1 about interstaller trading system
#include<iostream>
using namespace std;
int main(){
	char volatility,planet,experience;
	int tradevalue,successful,age;
	bool rare,sanction,eligible=0;// rare  means rare resources flag
	float quota,discount,bonus=0,taxamount,taxrate;
	cout<<"enter home planet. E for earth, J for jupiter,M for mars:";
	cin>>planet;
	cout<<endl<<"enter experience level.N for novice, I for intermediate, E for expert:";
	cin>>experience;
	cout<<endl<<"enter market volatility. L for low, M for medium, H for high: ";
	cin>>volatility;
	cout<<endl<<"enter trade value:";
	cin>>tradevalue;
	cout<<endl<<"enter number of successul trades:";
	cin>>successful;
	cout<<endl<<"enter if trade involves rare resources. 1 for true and 0 for false:";
	cin>>rare;
	cout<<endl<<"enter the percentage value representing how much of their trade quota is used:";
	cin>>quota;
	cout<<endl<<"enter age of trader:";
	cin>>age;
	cout<<endl<<"enter if earth is under sanctions or not. 1 or 0:";
	cin>>sanction;
	
	//part 1 if trader is eligible to trade
	if (planet=='M'){
		if ((successful>=10) || (tradevalue>15000 && volatility!='L')){
			eligible=1;
			}
		}
	else if (planet=='J'){
		if (experience=='E' && rare==1 && quota<80){
			eligible=1;
			}
		}
	else if (planet=='E'){
		if (sanction!=1){
			eligible=1;
			}
		}
	//part 2 WILL calculate tax according to given conditions
	if (eligible==1){
		if (planet=='E'){
			taxrate=5;
			}
		else if (planet=='J'){
			volatility=='M'?taxrate=12-5:taxrate=12;
			}
		else if (planet=='M'){
			taxrate=8;
			}
		
		experience=='N'?taxrate+=2:experience=='E'?taxrate-=1:taxrate=taxrate;
		tradevalue>50000?taxrate+=3:taxrate=taxrate;
		successful>20?taxrate-=2:taxrate=taxrate;
		volatility=='H'?taxrate+=4:taxrate=taxrate;
		age>60?taxrate-=2:taxrate=taxrate;
		taxrate<0?taxrate=0:taxrate=taxrate;
		}
	//part 3 will apply bonus after checking if eligible
	if ((eligible==1) && ((rare==1 && volatility=='H') || (experience=='E' && successful>30 && tradevalue>100000))){
		if (planet=='E' || planet=='M'){
			bonus=.05*tradevalue;
			}
		else {  
			bonus=0.8*tradevalue;
			}
		}
		
	//part 4 will output
	taxamount=(taxrate/100)*tradevalue;
	if (eligible==1){
		cout<<endl<<"trade is approved";
		cout<<endl<<"the final tax rate:"<<taxrate<<'%';
		cout<<endl<<"tax amount:"<<taxamount;
		bonus>0?cout<<endl<<"bonus is awarded:"<<bonus:cout<<endl<<"no bonus awarded";
		}
	else {
		cout<<endl<<"trade denied"<<endl;
		if (planet=='M'){
			if (tradevalue<=15000 && successful<10){
				cout<<"ineligible because trade value is smaller than what is criteria and successful is smaller than 10";
				}
			else if ((successful<10) || (tradevalue<=15000 && volatility=='L')){
				cout<<"successful smaller than 10 plus tradevalue not meeting criteria plus volatility is low";
				}
			else{
				cout<<"successful smaller than 10 and volatility is low";
				}
			}
		else if (planet=='E'){
			cout<<"sanction imposed thats why";
				}
		else if (planet=='J'){
			experience!='E'?(rare==0?(quota>=80?cout<<"no condition matched":
			cout<<"experience is not expert and no rare resources involved"):(quota>=80?
			cout<<"experience is not expert and quota doesnt match criteria":
			cout<<"experience is not expert")):(rare==0?(quota>=80?cout<<"no rare resources and quota is not below 80":cout<<"no rare resources"):cout<<"quota is not below 80 percent");
		}
	}
			
			
	
return 0;
}
