#include<iostream>
using namespace std;

int main(){
int n,i;
cout<<"Enter array size: ";
cin>>n;
cout<<"Enter array elements"<<endl;
int arr[n];

for(i=0;i<n;i++){
    cin>>arr[i];
}
for(i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
cout<<"Reverse array"<<endl;
for(i=n-1;i>=0;i--){
    cout<<arr[i]<<" ";
}
return 0;
}
