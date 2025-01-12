//abdullah mallik 0872 D q6
#include<iostream>
using namespace std;
int main(){
	char symbol1,symbol2;
	int rows;
	cout<<"Enter first symbol:";
	cin>>symbol1;
	cout<<"\nEnter second symbol:";
	cin>>symbol2;
	bool alter=1;//to keep on changing the symbols
	cout<<"\nEnter number of rows:";
	cin>>rows;
	//validation for rows to be >=5
	while(rows<5){
		cout<<"RE ENTER (>=5):";
		cin>>rows;
	}
	int upper,spaces; //rows for upper triangle
	upper=rows/3;
	spaces=upper;
	int col=(rows/3)*2;
	int inner,s=1,spacetri=1;
	if(rows<=10){
		inner=-1;
	}
	else{
		inner=(rows-1)/10 -1;
	}
	//upper part
	for(int i=0;i<upper;i++){
		alter=!alter;
		for(int j=0;j<spaces;j++){
			cout<<' ';
		}
		spaces--;
		if (i==0){
        cout<<symbol2; // Print only the second symbol
    } else{
        if(alter) {
            cout<<symbol1;
        } else{
            cout<<symbol2;
        }
        alter=!alter;
		
		
		//to print below single dot
		if (i>=1){
		//meaning double layer
			if(inner>=0){
			// if first line of inner boundary
				if (inner+1==i){
					for(int k=0;k<inner;k++){
						cout<<' ';
					}
					if(alter){
						cout<<symbol1;
					}
					else{
						cout<<symbol2;
					}
					alter=!alter;
					for(int k=0;k<inner;k++){
						cout<<' ';
					}
				}
				else{
					//mini triangle of spaces
					if(inner>=i){
						for(int k=0;k<s;k++){
							cout<<' ';
						}
						s+=2;
					}
					//constant gaps
					else if(inner+1<i){
						for (int k=0;k<inner;k++)
						{
						cout<<' ';
						}
						if(alter){
						cout<<symbol1;
						}
						else{
							cout<<symbol2;
						}
						alter=!alter;
					//it diverges as now an inner triangle will form of hollow
					if(i>inner+1){
						for(int k=0;k<spacetri;k++){
						cout<<' ';
						}
						spacetri+=2;
						if(alter){
							cout<<symbol1;
						}
						else{
							cout<<symbol2;
						}
						alter=!alter;
					
					}
					//printing spaces between the 2 boundaries
					for(int k=0;k<inner;k++){
						cout<<' ';
					}
					}
				}
			}
		}
		//if no need of an inner boundary as only one diamond shape upper part
		if(inner<0){
			for(int k=0;k<spacetri;k++){
			cout<<' ';
			}
			spacetri+=2;
		}
		if(alter){
							cout<<symbol1;
						}
						else{
							cout<<symbol2;
						}
						alter=!alter;
		}
		// next line
	cout<<endl;
	}
	//middle part
	int boxlen;//length of middle box
	int middle,totalgap;// for middle rows
	//totalgap is gap b/w outer 2 boundaries
	totalgap=2*upper-1;
	int innergap;//gap b/w inner boundaries in total
	innergap=totalgap-(inner*2)-2;
	middle=rows-(2*upper);// as 1 third is for middle but we want accurate rows
	boxlen=middle-2;
	//as we ignore the first and last line as it directly connects through spaces
	int boxheight=boxlen;//height of box remains what it is
	if (boxlen%2==0)
		boxlen-1;// as there is not middle for an even num
	int withbox;//spaces that are with the box and with the inner border
	withbox=(innergap-boxlen)/2;
	//middle of box height
	int midbox=boxheight/2;
	if (midbox%2==1)
		midbox++;//as we will need one extra row for odd
	int sym1,num1,num,is,sp;//this is to print symbol1 in the box
	//'is' is for space in the box
	//num1 is for printing second num triangle
	sp=boxheight/3;
	if (boxheight%2==0)
		sp--;
	sym1=boxlen/2;
	int sym2=1;
	int down=boxheight/2;// for downward triangle
	
	for(int i=0;i<middle;i++){
		alter=!alter;
		if(alter){
			cout<<symbol1;
		}
		else{
			cout<<symbol2;
		}
		alter=!alter;
		//if rows <10
		if(rows==5 || rows==6){
		// as will have sam gap b/w outer 2 borders as the upper diamond has rows
			for(int k=0;k<upper;k++){
				cout<<' ';
			}
			if(alter){
				cout<<symbol1;
			}
			else{
				cout<<symbol2;
			}
				alter=!alter;
		}
		else if(rows<=10){
		// first and last row in middle for max 10
			if(i==0 || i==middle-1){
				for(int j=0;j<totalgap;j++){
					cout<<' ';
				}
			}
			else{
				for(int j=0;j<(totalgap-1)/2;j++){
					cout<<' ';
				}
				cout<<1;
				for(int j=0;j<(totalgap-1)/2;j++){
					cout<<' ';
				}
				
			}
			if(alter){
				cout<<symbol1;
			}
			else{
				cout<<symbol2;
			}
			alter=!alter;
		}
		else{
		//spaces in between borders if any
			for(int j=0;j<inner;j++){
				cout<<' ';
			}
			if(alter){
				cout<<symbol1;
			}
			else{
				cout<<symbol2;
			}
			alter=!alter;
			if(i==0 || i==middle-1){
				for(int j=0;j<innergap;j++){
					cout<<' ';
				}
				if(alter){
				cout<<symbol1;
				}
				else{
					cout<<symbol2;
				}
				alter=!alter;
				
				for(int j=0;j<inner;j++){
					cout<<' ';
				}
				if(alter){
				cout<<symbol1;
				}
				else{
					cout<<symbol2;
				}
				alter=!alter;
				}
			
			else {
				for(int j=0;j<withbox;j++){
					cout<<' ';
				}
				//middle box(square) till mid
				if(i<=boxheight){
					for(int j=0;j<boxlen;j++){
						cout<<symbol1;
					}
					
					//printing next spaces
					for(int j=0;j<withbox;j++){
						cout<<' ';
					}
					if(alter){
						cout<<symbol1;
					}
					else{
						cout<<symbol2;
					}
					alter=!alter;
					
					//printing spaces in between
					for(int j=0;j<inner;j++){
						cout<<' ';
					}
					//outer most border
					if(alter){
						cout<<symbol1;
					}
					else{
						cout<<symbol2;
					}
					alter=!alter;
				
				
			}	
			
			}
			
		
		}
		cout<<endl;
	}
	
	
	
	
	
	

return 0;
}
