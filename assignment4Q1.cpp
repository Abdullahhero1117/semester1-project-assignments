//abdullah malik 0872 D q1 patterns
#include <iostream>
using namespace std;
int main(){
	//diagram A
	int n=11; // num of rows
	// space 1 is spaces before 1st V
	//space2 is spaces between first V lines
	//space 3 is spaces between 2 V's
	int space2=n,space3=0,temp=n;
	int space4=n; // this is for spaces between second V lines
    int temp1=n; // for second V
	for (int i=1; i<=n ; i++){ // counter for rows
		for (int space1=1; space1<i ; space1++){
			cout<<' '; //counter for spaces
		}
	
	    	if (i<=n){
	    		cout<<"* "; //* will print all the way
	    		}
	    	if (i<=(n-2)){
	    		cout<<"- "; // will print 2 rows before ending
	    		}
	    	if (i<=(n-4)){ // will print 4 rows before ending
	    		cout<<"+ ";
	    		}
	    	for (space2;space2>1;space2--){
	    		cout<<' ';
	    	}
	    	temp-=2; // used to reduce spaces for each row
	    	space2=temp;
	    	// similar logic for second line but end is not included
	    	if (i<(n-4)){
	    		cout<<"+ ";
	    		}
	    	if (i<(n-2)){
	    	cout<<"- ";
	    	}
	    	if (i<n){
	    		cout<<"* ";
	    		}
	    	for (int j=1; j<=space3 ; j++){
	    	    cout<<' '; // space betwwen 2 Vs
	    	}
	    	
	    	// similar logic for second V
	    	space3+=2;
	    		if (i<=n){
	    		cout<<"* ";
	    		}
	    	if (i<=(n-2)){
	    		cout<<"- ";
	    		}
	    	if (i<=(n-4)){
	    		cout<<"+ ";
	    		}
	    	for (space4;space4>1;space4--){
	    	cout<<' ';
	    	}
	    	temp1-=2;
	    	space4=temp1;
	    	if (i<(n-4)){
	    		cout<<"+ ";
	    		}
	    	if (i<(n-2)){
	    	cout<<"- ";
	    	}
	    	if (i<n){
	    		cout<<"* ";
	    		}
	    	
	    
	    	
		
		
		cout<<endl;
	}
	cout<<endl;
	
	
	// diagram B
	int spaces1=11,spaces2=0; //spaces1 is before upper part and spaces 2 is spaces in middle of upper part
	int un=11; // rows for upper triangle part
	for (int i =1; i<=un; i++){
	    for (int j=spaces1; j>1; j--){
	        cout<<' ';
	    }
	    spaces1-=1;
	   
    	if (i>0){
    		cout<<"* ";
    		}
    	
    	if (i>2){
    	cout<<"- ";
    	}
    	if (i>4){
    	cout<<"+ ";
    	}
    	if (i>=6){
    	    for (int k =1; k<=spaces2; k++){
    	        cout<<' ';
    	    }
    	    spaces2+=2;
    	}
    	
    	if (i>5){ // will print 4 rows before ending
    	cout<<"+ ";
    	}
    if (i>3){
    	cout<<"- "; // will print 2 rows before ending
    	}
	if (i>1){
    	cout<<"* "; //* will print all the way
    	}
    	
    		cout<<endl;
	}
	
// lower part
    int ln=10; //lower rows or lower num
    space2=n;
    space3=0;
    temp=n;
    for (int i=1; i<=ln;i++){
        for (int space1=1;space1<=i;space1++){
            cout<<' ';
        }
        if (i<=ln){
    		cout<<"* "; //* will print all the way
    		}
    	if (i<=(ln-2)){
    		cout<<"- "; // will print 2 rows before ending
    		}
    	if (i<=(ln-4)){ // will print 4 rows before ending
    		cout<<"+ ";
    		}
    	for (space2;space2>3;space2--){
    		cout<<' ';
    	}
    	temp-=2; // used to reduce spaces for each row
    	space2=temp;
    	// similar logic for second line but end is not included
    	if (i<(ln-4)){
    		cout<<"+ ";
    		}
    	if (i<(ln-2)){
    	cout<<"- ";
    	}
    	if (i<ln){
    		cout<<"* ";
    		}
    	cout<<endl;
    }
    cout<<endl<<endl;
    
    
    // diagram C
    // left spaces is spaces between 1st 2 diamonds and right is between next 2 diamonds
    //upperparts
    int leftspaces=19,rightspaces=19,rows=10;
    for (int i=0;i<10; i++){ //all rows
        for (int j=0;j<=i ; j++){ // first diamond upper
            cout<<i;
        }
        for (int k=1; k<=leftspaces; k++){
            cout<<' '; //middle triangle spaces
        }
        leftspaces-=2;
        int middle; //formula to print middle upper diamond
        middle=(i+1)*2;
        for (int l=1; l<=middle; l++){
            cout<<i; // middle diamond upper part
        }
        for (int k=1; k<=rightspaces; k++){
            cout<<' '; // gap
        }
        rightspaces-=2;
        for (int j=0;j<=i ; j++){
            cout<<i; // last triangle on right
        }
        cout<<endl;
        }
        // minus 2 so print 8 rows lower
        leftspaces=3;
        rightspaces=3; // as both are now starting from 3 in 11th row, (88888..)
        for (int i=rows-2; i>=0; i--){
            for (int j=0;j<=i; j++){
                cout<<i;
            }
            for (int k=1; k<=leftspaces; k++){
                cout<<' ';
            }
            leftspaces+=2;
            // similar formula for lower mid diamond
            int middle=(i+1)*2;
            for (int l=1; l<=middle; l++){
                cout<<i; // middle diamond lower part
            }
            // right most lower diamond/triangle and spaces before it
            for (int k=1; k<=rightspaces; k++){
                cout<<' ';
            }
            rightspaces+=2;
            for (int j=0;j<=i; j++){
                cout<<i;
            }
            cout<<endl;
        }
    
    //second part
    // upper part
    int upperrows=10,spaces=20,letters;
    for (int i=0; i<10;i++){// rows
        letters=i*2; // to print multiples of 2
        for (int s=1; s<=spaces; s++){ // print spaces
            cout<<' ';
        }
        // spaces reducing by 2
        spaces-=2;
        for (int j=1; j<=letters; j++){ 
            cout<<"\033[32m*"; // printing of stars
        }
        cout<<"\033[35m|"; // middle stick
        for (int j=1; j<=letters; j++){
            cout<<"\033[31m+"; // of pluses
        }
        cout<<endl;
    }
    // printing middle dashline
    for( int j=0; j<41; j++){
        cout<<"\033[35m-";
    }
    cout<<endl;
    //printing middle box
    int midrows=10;
    int digit3=1; // for 3s
    for (int i=0; i<10; i++){
        for (int j=1 ;j<=i; j++ ){
            cout<<"\033[37m1"; //printing 1s
        }
        cout<<"\033[35m\\"; // automatically rightly printed for each row
        for (int k=1; k<=2*(midrows-1-i); k++){
            cout<<"\033[36m2"; // printing 2s
        }
        cout<<"\033[35m/"; 
        
        for (int j=1; j<=digit3; j++){
            cout<<"\033[33m3"; // to print 3s
        }
        digit3+=2; // increasing by 2 each row
        cout<<"\033[35m\\";
        
        for (int k=1; k<=2*(midrows-1-i); k++){
            cout<<"\033[32m4"; // printing 4s
        }
        cout<<"\033[35m/"; 
        for (int j=1 ;j<=i; j++ ){
            cout<<"\033[34m5"; //printing 5s
        }
        
        cout<<endl;
    }
    // lower part of diagram
    // printing lower middle dashline
    for( int j=0; j<41; j++){
        cout<<"\033[35m-";
    }
    cout<<endl;
    //spaces before lower part
    spaces+=2;// did this to get precise diagram as it was a bit left
    for ( int i=9; i>=0;i--){
        letters=i*2;
        for (int s=1; s<=spaces; s++){
            cout<<' ';
        }
        spaces+=2;
        
        for (int j=1; j<=letters; j++){ 
                cout<<"\033[33m*"; // printing of stars
        }
        cout<<"\033[35m|"; // middle stick
        for (int j=1; j<=letters; j++){
            cout<<"\033[34m+"; // of pluses
        }
        cout<<endl;
        
    }
        
    
    
return 0;
}


