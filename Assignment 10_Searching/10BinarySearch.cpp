#include<iostream>
using namespace std;
class Search{
    int a[100],low,mid,high,n,i,key;
public: void BinarySearch(){
    cout<<"ENTER THE NUMBER OF ELEMENTS: "<<endl;
    cin>>n;
    cout<<"ENTER THE ELEMENTS: "<<endl;
    for(i=0;i<n;i++){
        cin>>a[i];
    }
   low=0;
   high=n-1;
   cout<<"ENTER THE ELEMENT YOU WANT TO SEARCH: "<<endl;
   cin>>key;

   while(low<=high){
    mid=(low+high)/2;
    if(a[mid]==key){
        cout<<"THE ELEMENT IS FOUND AT LOCATION: "<<mid+1<<endl;
        exit(0);
    }else if(a[mid]<key){
        low=mid+1;
    }else if(a[mid]>key){
        high=mid-1;
    }
   }cout<<"ELEMENT NOT FOUND "<<endl;


}
};

int main(){
Search s;
s.BinarySearch();
}