//Name- Anurag Haldey
//Roll no- 2215055
//Batch-B
/*A matrix of m x n order is said to have a saddle point; if some entry at a[i][j] is the

smallest value in row i and the largest value in j. Write C++ function that determines
the location of a saddle point if it exists.*/





#include <iostream>
using namespace std;
class saddlepoint{
public: int r,c,i,j,a[50][50];
void get();
void put();
void min();
};
void saddlepoint::get(){
    cout<<"Enter number of rows and columns for matrix a:"<<endl;
    cin>>r>>c;
    cout<<"Enter the elements of matrix a:"<<endl;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cin>>a[i][j];
        }
    }
   
 }
void saddlepoint::put(){
    cout<<"Matrix a :"<<endl;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cout<<"\t"<<a[i][j];
        }
        cout<<"\n";
    }
   
}
void saddlepoint::min(){
    int min,col=0;
    for(i=0;i<r;i++){
        min=a[i][0];
            for(j=1;j<c;j++){
                 if(min>a[i][j]){
                    min=a[i][j];
                    col=j;
                 }
                 
             }
             
         
         
    }
    int k;
    for(k=0;k<r;k++)
    if(min<a[k][col])
    break;
    if(k==r){
        cout<<"\nSaddle point is: "<<min;
    }
}


   



int main(){
    saddlepoint s;
    s.get();
    s.put();
    s.min();
   
}
