//Name- Anurag Haldey
//Roll no- 2215055
//Batch-B
/*Write a program in C++ to perform matrix operations like add_matrix(),

sub_matrix(),multi_mutrix() using appropriate data structure. Also write how to
determine time complexity and space complexity of your program.*/



#include<iostream>
using namespace std;
 class matrix{
    public:int a[20][20],b[20][20],sum[20][20],sub[20][20],mul[20][20],i,j,k,r,c,n,m;
    void get();
    void put();
    void mat_sum();
    void mat_sub();
    void mat_mul();
    void transpose();

 };
 void matrix::get(){
    cout<<"Enter number of rows and columns for matrix a:"<<endl;
    cin>>r>>c;
    cout<<"Enter the elements of matrix a:"<<endl;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cin>>a[i][j];
        }
    }
    cout<<"Enter the elements of matrix b:"<<endl;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cin>>b[i][j];
        }
       
    }
 }
void matrix::put(){
    cout<<"Matrix a :"<<endl;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cout<<"\t"<<a[i][j];
        }
        cout<<"\n";
    }
    cout<<"Matrix b :"<<endl;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cout<<"\t"<<b[i][j];
        }
        cout<<"\n";
    }
}
 void matrix::mat_sum(){

    cout<<"Sum of both matrices is: "<<endl;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            sum[i][j]=a[i][j]+b[i][j];

        }
    }
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cout<<"\t"<<sum[i][j];
        }
        cout<<"\n";
    }


 }
 void matrix::mat_sub(){
  cout<<"Subtraction of both matirces is: "<<endl;
  for(i=0;i<r;i++){
    for(j=0;j<c;j++){
        sub[i][j]=a[i][j]-b[i][j];
    }
  }
  for(i=0;i<r;i++){
    for(j=0;j<c;j++){
        cout<<"\t"<<sub[i][j];
    }
    cout<<"\n";
  }
 }
 void matrix::transpose(){
    char ch;
    cout<<"Choose matrix for transpose opertaion:(a or b)"<<endl;
    cin>>ch;
    if(ch=='a'){
        for(i=0;i<c;i++){
            for(j=0;j<r;j++){
              cout<<"\t"<<a[j][i];
            }
            cout<<"\n";
        }
    }
    else{
   
            for(i=0;i<c;i++){
                for(j=0;j<r;j++){
                    cout<<"\t"<<b[i][j];

                }
                cout<<"\n";
            }
       
    }

 }
 void matrix::mat_mul(){
    cout<<"Enter number of rows and columns in matrix a:"<<endl;
    cin>>r>>c;
    cout<<"Enter number fo rows and columns in matrix b:"<<endl;
    cin>>n>>m;
    if(c==n){
    cout<<"Enter elements of matrix a:"<<endl;
    for(i=0;i<r;i++){
        for(j=0;j<c;j++){
            cin>>a[i][j];
        }
    }
    cout<<"Enter elements of matrix b:"<<endl;
    for(i=0;i<n;i++){
        for(j=0;j<m;j++){
            cin>>b[i][j];
        }
    }
 
   cout<<"Multiplication of both matrices:"<<endl;
   for(i=0;i<r;i++){
    for(j=0;j<m;j++){
        mul[i][j]=0;
        for(k=0;k<c;k++){
            mul[i][j]+=a[i][k]*b[k][j];
        }
    }
    }
   
   for(i=0;i<r;i++){
    for(j=0;j<m;j++){
        cout<<mul[i][j]<<"\t";

    }
    cout<<"\n";
   }
 }
 else{
    cout<<"Multiplication cannot be done"<<endl;
 }
 }

 int main(){
    matrix m;
    m.get();
    m.put();
    m.mat_sum();
    m.mat_sub();
    m.transpose();
    m.mat_mul();
 }
