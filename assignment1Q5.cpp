#include<iostream>
#include<iomanip>
//abdullah malik 0872 bscsD pattern with setw q 5 logic is entering number of bars dots symbols in a single column
using namespace std;
int main(){
  int vbars,dots,msymbols,space1,space2,lines;/*space 1 means between verical bar and symbol and space 2 means space between vertical bar and full stop m symbol means number of * */
  char line='-',dot='.',bar='|',star='*',space=' ';
  cout<<"enter number of vertical lines in a column:";
  cin>>vbars;
  cout<<"enter number of multiplication symbols in a column:";
  cin>>msymbols;
  cout<<"enter number of dots in a column:";
  cin>>dots;
  cout<<"enter number of spaces between vertical bar and multiplication symbol:";
  cin>>space1;
  cout<<"enter number of spaces between vertical bar and full stop:";
  cin>>space2;
  lines=4*vbars+4*space1+2*msymbols+2*space2+dots;//it means that the number of - lines is an addition of all other characters like space,bar dot etc.
  cout<<setfill(line)<<setw(lines)<<'-'<<endl;
  cout<<setfill(line)<<setw(lines)<<'-'<<endl;//will print 2 lines
  cout<<setfill(bar)<<setw(vbars)<<'|'<<setfill(space)<<setw(space1)<<space<<setfill(star)<<setw(msymbols)<<star<<setfill(space)<<setw(space1)<<space<<setfill(bar)<<setw(vbars)<<bar<<setfill(space)<<setw(space2)<<space<<setfill(dot)<<setw(dots)<<dot//3rd line
  <<setfill(space)<<setw(space2)<<space<<setfill(bar)<<setw(vbars)<<'|'<<setfill(space)<<setw(space1)<<space<<setfill(star)<<setw(msymbols)<<star<<setfill(space)<<setw(space1)<<space<<setfill(bar)<<setw(vbars)<<bar<<endl;// 4th line
cout<<setfill(bar)<<setw(vbars)<<'|'<<setfill(space)<<setw(space1)<<space<<setfill(star)<<setw(msymbols)<<star<<setfill(space)<<setw(space1)<<space<<setfill(bar)<<setw(vbars)<<bar<<setfill(space)<<setw(space2)<<space<<setfill(dot)<<setw(dots)<<dot
  <<setfill(space)<<setw(space2)<<space<<setfill(bar)<<setw(vbars)<<'|'<<setfill(space)<<setw(space1)<<space<<setfill(star)<<setw(msymbols)<<star<<setfill(space)<<setw(space1)<<space<<setfill(bar)<<setw(vbars)<<bar<<endl;//5th line
cout<<setfill(bar)<<setw(vbars)<<'|'<<setfill(space)<<setw(space1)<<space<<setfill(star)<<setw(msymbols)<<star<<setfill(space)<<setw(space1)<<space<<setfill(bar)<<setw(vbars)<<bar<<setfill(space)<<setw(space2)<<space<<setfill(dot)<<setw(dots)<<dot
  <<setfill(space)<<setw(space2)<<space<<setfill(bar)<<setw(vbars)<<'|'<<setfill(space)<<setw(space1)<<space<<setfill(star)<<setw(msymbols)<<star<<setfill(space)<<setw(space1)<<space<<setfill(bar)<<setw(vbars)<<bar<<endl;
  cout<<setfill(line)<<setw(lines)<<'-'<<endl;//6th line
cout<<setfill(bar)<<setw(vbars)<<'|'<<setfill(space)<<setw(space1)<<space<<setfill(star)<<setw(msymbols)<<star<<setfill(space)<<setw(space1)<<space<<setfill(bar)<<setw(vbars)<<bar<<setfill(space)<<setw(space2)<<space<<setfill(dot)<<setw(dots)<<dot
  <<setfill(space)<<setw(space2)<<space<<setfill(bar)<<setw(vbars)<<'|'<<setfill(space)<<setw(space1)<<space<<setfill(star)<<setw(msymbols)<<star<<setfill(space)<<setw(space1)<<space<<setfill(bar)<<setw(vbars)<<bar<<endl;//7th line
  cout<<setfill(bar)<<setw(vbars)<<'|'<<setfill(space)<<setw(space1)<<space<<setfill(star)<<setw(msymbols)<<star<<setfill(space)<<setw(space1)<<space<<setfill(bar)<<setw(vbars)<<bar<<setfill(space)<<setw(space2)<<space<<setfill(dot)<<setw(dots)<<dot
  <<setfill(space)<<setw(space2)<<space<<setfill(bar)<<setw(vbars)<<'|'<<setfill(space)<<setw(space1)<<space<<setfill(star)<<setw(msymbols)<<star<<setfill(space)<<setw(space1)<<space<<setfill(bar)<<setw(vbars)<<bar<<endl;//8th line
  cout<<setfill(bar)<<setw(vbars)<<'|'<<setfill(space)<<setw(space1)<<space<<setfill(star)<<setw(msymbols)<<star<<setfill(space)<<setw(space1)<<space<<setfill(bar)<<setw(vbars)<<bar<<setfill(space)<<setw(space2)<<space<<setfill(dot)<<setw(dots)<<dot
  <<setfill(space)<<setw(space2)<<space<<setfill(bar)<<setw(vbars)<<'|'<<setfill(space)<<setw(space1)<<space<<setfill(star)<<setw(msymbols)<<star<<setfill(space)<<setw(space1)<<space<<setfill(bar)<<setw(vbars)<<bar<<endl;//9th line
cout<<setfill(line)<<setw(lines)<<'-'<<endl;//10th line
cout<<setfill(line)<<setw(lines)<<'-'<<endl;//11th line
  
  
  return 0;
  }
  

  

  
