//abdullah malik 0872 bscsD q2 data corruption check ASSIGNMENT 3
#include<iostream>
using namespace std;

void verifydata();
void reporting();
unsigned long long int num,parity,temp,digit,even=0,odd=0,checksum,ogchecksum,oguniquenum,uniquenum,previous,after,tdata;// temp is temporary variable to for needed use
int count,ones;
bool paritycheck=0,checksumcheck=0,uniquenumcheck=0,primecheck=0;
int main(){
	cout<<endl<<"enter a 64 bit integer number:";
	cin>>num;
	tdata=num & 281474976710655; // to remove 1s on left on needed data
	cout<<endl<<"transaction data is:"<<tdata;
	verifydata();
	reporting();
  
  return 0;
  }
  
void verifydata(){
	// parity checking
	parity=num >> 63;
	count=0;
	while (count<=47){
		temp=tdata >> count;
		if ((temp & 1ull)==1){
			ones+=1;
			}
		count+=1;
		}
	cout<<endl<<"parity bit in input data:"<<parity; 
	ones=~ones;
	ones &=1;
	if (ones==parity){
		paritycheck=1;
		cout<<"\n parity same";
		}
		
		
	// checksum. it will XOR the 2 groups and when 1 occurs in both, it clears the bits
	count=0;
	while (count<=47){
		if ((count==0) || (count&1)==0){
			even=even | (tdata & (1ull<<count));
			}
		else{
			odd=odd | (tdata & (1ull<<count));
			}
		count+=1;
		}
	checksum=even ^ odd; // XOR
	checksum=checksum>>1; // RIGHT SHIFT
	checksum &=255; //AND
	ogchecksum=(num>>48) & 255; // OG MEANS ORIGINAL WHICH WAS RECEIVED IN 64 BITS DATA
	cout<<endl<<"checksum value in input data:"<<ogchecksum;
	if (checksum==ogchecksum){
		checksumcheck=1;
		}
		
		
	// secret unique number
	oguniquenum=(num>>56) & 127;
	uniquenum=0;
	tdata= ~tdata;
	tdata= tdata & 281474976710655; // so all extra bits on left of 48 bits are removed
	count=0;
	while (count<=45){
		previous=tdata & (1ull<<count);
		previous=(previous>>(count)) & 1ull;
		after=tdata & (1ull<<(count+1));
		after=(after>>(count+1)) & 1ull;
		if (previous==after){
			uniquenum+=1;
			uniquenum=uniquenum<<1;
			}
		count+=1;
		}
	uniquenum=uniquenum & 127;
	uniquenum=~uniquenum;
	uniquenum=uniquenum & 127; // WE JUST WANT 7 BITS
	if (uniquenum==oguniquenum){
		uniquenumcheck=1;
		}	
		
		
	//prime number check.
	// simplified version is that if it is an odd number only then it can be a meezan prime because if its not then it will be divisible by 2 or even 4 or....
	tdata=~tdata; // WE WANT ORIGNAL  TDATA NOW BACK
	if ((tdata & 1ull)==1){
		primecheck=1;
		cout<<endl<<"it is a meezan prime";
		}
	else {
		cout<<endl<<"it is not a meezan prime";
		primecheck=0;
		}
			
}
void reporting(){
	if (primecheck==1 && uniquenumcheck==1 && paritycheck==1 && checksumcheck==1){
		cout<<endl<<"CONGRATS..  IT IS ERROR FREE";
		}
	else {
		cout<<endl<<"RETRANSMIT DATA BECAUSE...";
		cout<<endl<<"data corruption detected..\n";
		if (parity==ones){
			cout<<endl<<"parity check passed";
			}
		else {
			cout<<endl<<"parity check failed. expected :"<<ones<<" received:"<<parity;
			}
		if (checksumcheck==1){
			cout<<endl<<"checksum check passed";
			}
		else {
			cout<<endl<<"checksum check failed. expected :"<<checksum<<" received:"<<ogchecksum;
			}
		if (uniquenumcheck==1){
			cout<<endl<<"unique number check passed";
			}
		else {
			cout<<endl<<"unique number check failed. expected :"<<uniquenum<<" received:"<<oguniquenum;
			}
		if (primecheck==1){
			cout<<endl<<"prime number check passed";
			}
		else {
			cout<<endl<<"prime number check failed";
			}
		}
}
