//abdullah malik 0872 D q6 convert uppercase to lower. return polar opposite of number
#include<iostream>
#include<iomanip>
using namespace std;
int main(){
//part A
char ch;
cout<<"enter an uppercase character:";
cin>>ch;
ch=ch+32;
cout<<ch<<endl<<endl;






//part B
int num,polaropposite;
 cout<<"enter a number between 1 and 9 to get its polar opposite:";
 cin>>num;
 polaropposite=10-num;
 cout<<"polar opposite:"<<polaropposite;
 
 return 0;
 }
