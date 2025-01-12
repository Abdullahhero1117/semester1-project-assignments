//abdullah malik 0872 D q2. traverse diagonally

#include <iostream>
using namespace std;
int main(){
    int size;
    int matrix[8][8]={ {0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0},{0,0,0,0,0,0,0,0} };
    //cout<<"enter size:";
    cin>>size;
    while(size<3  || size >8){
        cout<<"\nreenter size:";
        cin>>size;//n
    }
    //taking nxn values
     for (int r=0; r<size ;r++){ // rows
        for (int c=0; c<size; c++){
         //columns
            cin>>matrix[r][c];
            while(matrix[r][c]!=0 && matrix[r][c]!=1){
                cout<<"\nre enter value. it should be binary:";
                cin>>matrix[r][c];
            }
        }
       }
        
    //traverse
    int bit=matrix[0][0],x=0,y=0;
    // x is  row and y column
    
    int diagonal=0; 
    // to print diagonally and indexing each diagonal an index
    int condition=size*2-1; 
    // if diagonal even then upward diagonal else down. the condition is for the outer most loop that it run that 
    //many times
    
    unsigned long long num=0; 
    // to store decimal num
    int i=0; 
    // to help in printing bits of num
    
    if (bit==1){ // first value one then diagonal up
        diagonal=0;
        while(diagonal<condition){ 
            for (x=0; x<size; x++){
                for (y=0; y<size; y++){
                    if ((diagonal%2)==0){
                        if (x+y==diagonal){
                            num=(num<<1) | matrix[y][x]; // making a decimal num
                            i++;
                        }
                    }
                    else{
                        if (x+y==diagonal){
                            num=(num<<1) | matrix[x][y];
                            i++;
                        }
                    }
                }
            }
            diagonal++;
        }
    }
    else{ // to print in opposite diagonal
        diagonal=1;
        while(diagonal<=condition){
            for (x=0; x<size; x++){
                for ( y=0; y<size; y++){
                    if ((diagonal%2)==0){
                        if (x+y==diagonal-1){
                            num=(num<<1) | matrix[y][x];
                            i++;
                        }
                    }
                    else{
                        if (x+y==diagonal-1){
                            num=(num<<1) | matrix[x][y];
                            i++;
                        }
                    }
                    
                }
            }
            diagonal++;
        }
    }
        
        cout<<num<<endl;
    // to print bit form
    unsigned long long binnum; // to store bits;
    int logvalue=0;
    if (bit==0){
        i--; // to remove extra zero
    }
    for (int j=(i-1);j>=0;j--){
        binnum=0; 
        binnum=(num>>j) & 1;
        cout<<binnum;
        logvalue++; // counting bits for log formula alternative
        // print single bit at a time
    }
    cout<<endl<<logvalue;
    
    
return 0;
    
}

