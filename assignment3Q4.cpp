//abdullah malik 0872 bscs D q 4 full adder ASSIGNMENT 3
#include<iostream>
using namespace std;
//n1 is for num1 , c is to use for carry so c is left shifted and then added in carry for right value
unsigned short num1,num2,n1,n2,carry1,carry2,carry,carryin=0,i=0,realsum=0,realcarry=0;
unsigned long sum;
bool overflow=0;
int main(){
	cout<<"enter a number:";
	cin>>num1;
	cout<<endl<<"enter a second number:";
	cin>>num2;
	cout<<endl<<"... half adder carrying task..";
	// performing half adder on input data it is taking single bits turn wise then xoring and anding it to get sums and carrys. the carry in is calculated by ORing the carrys from 2 half adders. the sum is filled with data till 16 bits and rest is ignored and considered overflow
	while (i<16){
	n1=(num1>>i) & 1u;
	n2=(num2>>i) & 1u;
	sum=n1 ^ n2; // SUM
	carry1=n1 & n2; // FIRST CARRY
	carry2=sum & carryin; // SECOND CARRY
	sum=sum ^ carryin; // OTHER SUM
	carryin=carry1 | carry2; // CARRY IN TO BE USED IN OTHER ROUND
	carry=carry1 & carry2; 
	realcarry=realcarry | (carry<<i); //CARRY IS ALTERED TO BE REALCARRY FOR RIGHT OUTPUT
	realsum=realsum | (sum<<i);
	i++;
	}
	if ((carryin<<i) >= 65535){
		overflow=1;
		}
	if (overflow==1){
		cout<<endl<<"overflow occured";
		}
	else{
		cout<<endl<<"overflow did not occur";
		}
	cout<<endl<<"sum in 16 bits :"<<realsum;
	
	
	
	
  
  return 0;
  }
