#include<iostream>
using namespace std;
class Search{
    int i,Arr[10],n,flag=0,key;
public: void Linearsearch(){
    cout<<"ENTER THE NUMBER OF ELEMENTS: "<<endl;
    cin>>n;
    cout<<"ENTER YOUR ELEMENTS: "<<endl;
    for(i=0;i<n;i++){
        cin>>Arr[i];
    }cout<<"ENTER THE ELEMENT TO BE SEARCHED: "<<endl;
    cin>>key;
    for(i=0;i<n;i++){
        if(Arr[i]==key){
            cout<<"THE ELEMENT IS PRESENT AT LOCATION: "<<i+1<<endl;
            flag=1;
            break;
        }
    }if(flag==0){
        cout<<"ELEMENT NOT PRESENT. "<<endl;
    }
}
};
int main(){
Search s;
s.Linearsearch();
}