//abdullah malik 0872 bscsD q3  ASSIGNMENT 3
#include<iostream>
using namespace std;


	
int main(){
	unsigned long long num=0,vaults,n,tempvaults,testcases=0,agent,i=0,c,k,count,counter;// vaults and num includes all vault states
	num=~num; // all are unlocked
	//ENTER TESTCASES  (HAD TO REMOVE COUT STATEMENTS BCZ OF HACKERRANK AS DIDNT ACCEPT EXTRA OUTPUT)
  	cin>>testcases;
  	bool prime=1;
  	while (i<testcases){
  		vaults=num;
  		agent=1;
  		// ENTER n
  		cin>>n;
  		while (agent<=n){
  			   k=agent;
  			  while (k<=n){
  			  	vaults^=1ull<<(k-1);
  			  	k+=agent;
  			  	}
  			agent++;
  			}
  		// to check prime indices	
  	 count=1;
  	while (count<=n){
  		prime=1;
  		counter=2;
  		if (count==1){
  			prime=0; // 1 is ignored
  		}
  		else if (count==2){
  			vaults=vaults ^ (1ull<<(count-1));// 2 is a prime num
  			}
  		else{
	  		while ((counter * counter) <= count ){    // basically checking with square root of count 
	  			if (count % counter == 0){
	  				prime=0;// meaning not prime
	  				break;
	  			}
	  	
	  			counter++;
	  			}
	  			
	  		
  		
  		if (prime==1){
	  			vaults=vaults ^ (1ull<<(count-1));
	  			}
	  	}
  	count++;
  	
  	}
  	c=0;
  	while (c<n) {
	    tempvaults=vaults;
	    tempvaults &= (1<<c);  // mask the bit 1 at position c
	    tempvaults >>= c;  //shift it to 1st bit
	    cout<<bool(tempvaults & 1ull);
	    c++;
	   }
	cout<<endl;
  	i++;
  	}
  	
  return 0;
  }
