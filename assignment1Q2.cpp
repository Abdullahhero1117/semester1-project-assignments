//abdullah malik 0872 D encryption algorithm and decryption algorithm
#include <iostream>
#include<iomanip>
using namespace std;
int main(){
   int n,rolln=40872,mod,num;
   cout<<"enter a num:";
   cin>>n;
   mod=rolln%11;
   num=mod+200;
   n=n*num;
   num=n/mod;
   n=num*17-5;
   n=n/(rolln%9);
   n+=3;
   cout<<"encrypted message:"<<n<<endl<<endl;
   
   cout<<"now the decrypted message..."<<endl;
   int mod1=rolln%11;
   int mod2=rolln%9;
   num=mod1+200;
   n=n-3;
   n=n*(mod2);
   n=(n+5);
   n=n*mod1;
   n=n/(num*17);
   n++;//bcz the calculated value is getting rounded down
   cout<<"decrypted number is:"<<n;
   //btw did the calculation of register by inverse of function method
   
   return 0;
}
   


   
   
   
   
   

