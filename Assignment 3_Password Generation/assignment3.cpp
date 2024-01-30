//Name- Anurag Haldey
//Roll no- 2215055
//Batch-B
/*A set S={1,3, a, s, t, i} represent alphanumeric characters. Write a program in C++ to

generate all possible passwords of length.*/





#include <iostream>

using namespace std;
class password
{
private:char a[9]={'A','r','f','a','t'};
int count=0,i,j,k,l;
public:void pass_gen();
};
void password::pass_gen(){

cout<<"Total combinations are :"<<endl;
for(i=0;i<7;i++){
    for(j=0;j<7;j++){
        for(k=0;k<7;k++){
            for(l=0;l<7;l++){
               for(int z=0;z<7;z++){

               
               
                cout<<a[i]<<a[j]<<a[k]<<a[l]<<a[z]<<"\t";
                count++;
       
            }
        }
    }
}
}

cout<<"\nTotal numner of combinations are:"<<count<<endl;
}

int main(){
    password p;
    p.pass_gen();
}

