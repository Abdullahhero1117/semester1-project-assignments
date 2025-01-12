// abdullah malik 0872 D rat maze q3
#include <iostream>
using namespace std;
int main() {
      const int n=3,m=3;
   int reachrow=3,reachcol=3,i=0;
   int matrix[n][m]={{1,1,1},{1,0,0},{0,0,0}},visited[n][m]={0};
   bool reached=0,path;
   int row=0,col=0;
   int data[3][m*n]={0};
   // cooridnates of mouse
   data[0][0]=0; 
   data[1][0]=0;
   //meaning 1st index is already visited 
   visited[row][col]=1;
   while(i>=0 && i<m*n && reached==0 ){
         path=false; // to check for need of move back cuz of dead end
       //if reached at point
       if(reachrow-1==row && col==reachcol-1){
           reached=true;
           data[0][i]=row;
           data[1][i]=col;
           data[2][i]='*'; // stopped
           path=true;
           break;
       }
       // if want to go right
       else if(col+1<m && matrix[row][col+1]==1 && visited[row][col+1]==0 ){
  //storing in 1st index of data some history of coordinates as we move on
        data[0][i]=row; 
        data[1][i]=col;
        data[2][i]='R';
        col++; // moved on on next col index as condition true
        visited[row][col]=1; // we here now so visited
        path=true; 
       }
       // if want to go down
       else if(row+1<n  && matrix[row+1][col]==1 &&  visited[row+1][col]==0){
        //similar logic as others
        data[0][i]=row;
        data[1][i]=col;
        data[2][i]='D';
        row++;
        visited[row][col]=1;
        path=true;
        }
        //if want to go left
         else if(col-1>=0 && matrix[row][col-1]==1 &&  visited[row][col-1]==0){
          //similar logic as others
        data[0][i]=row;
        data[1][i]=col;
        data[2][i]='L';
       col--;
        visited[row][col]=1;
        path=true;
        }
        //if want to go up
         else if(row-1>=0 && matrix[row-1][col]==1 &&  visited[row-1][col]==0){
         //similar logic as others
            data[0][i]=row;
            data[1][i]=col;
            data[2][i]='U';
            row--;
            visited[row][col]=1;
            path=true;
            }
            // we met dead end -(and)or couldnt move in opposite direction as it ws already visited and we didnt want an infinite loop in switching positions
        if(path==false){
            visited[row][col]=1;
            matrix[row][col]=0;
            row=data[0][i-1];
            col=data[1][i-1];
            data[0][i]=0;
            data[1][i]=0;
            data[2][i]=0;
            i--;
        }
        else{
        //move on
            i++;
        }
   }
   
   cout<<endl<<i<<endl;
   // making whole matrix 0
   int count = 0;
   bool done;// we need to print only one needed from count loop and prevent printing of wrong data
if (reached==true) {
    for (int k=0;k<n;k++) {
        cout<<'[';
        for (int j=0;j<m;j++) {
            done=false;
           for (count=0;count<=i;count++){
               if(data[0][count]==k && data[1][count]==j){ // meeting coordinates
                   if(data[2][count]=='R' || data[2][count]=='L' && done==false){
                       cout<<'-';// indicated by this symbol
                   }
                   else if(data[2][count]=='U' || data[2][count]=='D'){
                       cout<<'|';
                   }
                   else if(data[2][count]=='*'){
                       cout<<'*';
                   }
                   done=true;
               }
           }
           if(done==false){
               cout<<'X';
           }
        }
        cout<<"]\n";
    }
} else {
    cout << "no path"; // no available path
}

    
   return 0;
   
}
