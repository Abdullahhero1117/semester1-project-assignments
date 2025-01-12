//abdullah malik 0872 bscsD( relationship between sea level and global warming
#include<iostream>
#include<cmath>
#include<iomanip>
using namespace std;

int main(){

  double t,T,C,searise,τ =50,β = 20, γ = 1, δ = 100,t0 = 30, T0 = 1, C0 = 400,A = 0.1, B = 0.05, ω = 0.5, α = 1.5;/* t: Time (in years since 2000)
T: Global average temperature anomaly (in °C)
C: Atmospheric CO2 concentration (in ppm)*/
   
   double pi=3.14159265358979;
  cout<<"input values for t(time since 2000):";
  cin>>t;
  cout<<"\nthen T(Global average temperature anomaly)";
  cin>>T;
  cout<<"then C(Atmospheric CO2 concentration)";
  cin>>C;
  
  searise=A*log(1+t/τ)*((sin(ω*T)+1)/2)*pow(C/C0,α)+B*((atan((t-t0)/β)/pi)+1/2)*((atan((T-T0)/γ)+pi/2)/pi)*exp((C-C0)/δ);//equation as mentioned in question
  cout<<"searise level is:"<<setprecision(12)<<searise;//will output 12 digit answer
  
  return 0;
  
}
  
