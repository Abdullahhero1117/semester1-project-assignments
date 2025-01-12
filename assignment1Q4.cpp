//abdullah malik 0872 D q4 fee challan
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
  float hrs,price,additional,tuitionfee,unifee,totalmoney,totaltax,govttax1,govttax2,togovt,tobank=.02,wealthtax=.1;
  int sf=2000,uf=3000,flag;//student fund and university fund. flag will indicate true or false but didnt use boolean cuz of my logic
  cout<<"enter number of credit hours:";
  cin>>hrs;
  cout<<endl<<"enter price per hour:";
  cin>>price;
  additional=sf+uf;
  tuitionfee=hrs*price;
  unifee=additional+tuitionfee;
  flag=bool(int(unifee/150001));/* so what this flag will do is that when we divide an integer by 150000 and use bool(int()), it will either give 0 or 1. if it gives 1 it means that unifee is greater THAN 150000 so 1 will be used to activate govttax2 and wealth tax and 1-1= 0 0*-1 =0 and so govttax1 is 0. if unifee is lesser than 150000 than flag=0, 0-1=-1 -1*-1=1 so govttax1 is activated and other one is multiplied with flag,which is 0.*/
  govttax1=((flag-1)*-1)*unifee*.18;
  govttax2=(150000*.18+.25*(unifee-150000))*(flag);
  wealthtax=(flag)*(unifee*wealthtax);
  togovt=govttax1+govttax2+wealthtax;
  tobank=tobank*unifee;
  totaltax=togovt+tobank;
  totalmoney=totaltax+unifee;
  
  cout<<endl<<"tuition fee:"<<int(tuitionfee)<<endl;
  cout<<"additional charges:"<<int(additional)<<endl;
  cout<<"total university fee:"<<int(unifee)<<endl;
  cout<<"tax to be paid to govt(wealth tax included) :"<<int(togovt)<<endl;
  cout<<"wealth tax(if any):"<<int(wealthtax)<<endl;
  cout<<"tax to be paid to bank:"<<int(tobank)<<endl;
  cout<<"total additional tax:"<<int(totaltax)<<endl;
  cout<<"total money to be paid:"<<int(totalmoney);// i made them int in end bcz a huge value like 4000000 was not in this form. and float datatype at first so that any decimal number could also be input or assigned
  
  return 0;
}
  
  

