//Name- Anurag Haldey
//Roll no- 2215055
//Batch-B
/*Write C++ program forstoring matrix. Write functions for

i. Check whether given matrix is upper triangular or not
ii. Compute summation of diagonal elements
iii. Compute transpose of matrix*/




#include <iostream>
using namespace std;
class ut
{
    int mat[10][10],i,j,row,col,min,max,sum=0,flag=0,flagg=0;
    public:
    ut()
    {
        i=j=row=col=0;
        min=max=0;
    }
    void getdata();
    void showmat();

};
void ut::getdata()
{
    cout<<"\n Enter How Many Rows in matrix :";
    cin>>row;
    cout<<"\n Enter How Many cols in matrix :";
    cin>>col;
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            cout<<"Entert the elemnet["<<i<<"]["<<j<<"]:";
            cin>>mat[i][j];
        }
    }
    
}
void ut::showmat()
{
    cout<<"The Transpose of matrix are as follow:\n";
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            cout<<"\t"<<mat[j][i];
        }
        cout<<"\n";
    }
    cout<<"---------------------------------------------------\n";
    cout<<"Addition of dioganl:";
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(i==j)
            {
                sum=sum+mat[i][j];
            }
        }
    }
    cout<<"addition :"<<sum;
    cout<<"---------------------------------------------------\n";
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(i>j)
            {
                if(mat[i][j]!=0)
                {
                    flag=1;
                }
            }
        }
    }
    if(flag==0)
    {
        cout<<"The given matrix is upper Tringular Matrix.\n";
    }
    else
    {
      cout<<"The given matrix is Not upper Tringular Matrix.\n";  
    }

    cout<<"---------------------------------------------------\n";
    for(i=0;i<row;i++)
    {
        for(j=0;j<col;j++)
        {
            if(j>i)
            {
                if(mat[i][j]!=0)
                {
                    flagg=1;
                }
            }
        }
    }
    if(flagg==0)
    {
        cout<<"The given matrix is Lower Tringular Matrix.\n";
    }
    else
    {
      cout<<"The given matrix is Not Lower Tringular Matrix.\n";  
    }
   // cout<<"\n";
}
int main()
{
    ut hell;
    hell.getdata();
    hell.showmat();
    return 0;
}
//05-09-2022