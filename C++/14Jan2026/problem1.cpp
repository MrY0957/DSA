#include<iostream>
using namespace std;

int main(){
int i,n,sum=0;
cout<<"Enter array size"<<endl;
cin>>n;
int arr[n];
cout<<"Array elements are: ";
for(i=0;i<n;i++){
    cin>>arr[i];
}
cout<<"Array: ";
for(i=0;i<n;i++){
    cout<<arr[i]<<" ";
}
cout<<endl;
for(i=0;i<n;i++){
    sum+=arr[i];
}
int min=arr[0];
for(i=0;i<n;i++){
   if(min>arr[i]){
    min=arr[i];
   }
}
int max=arr[0];
for(i=0;i<n;i++){
   if(max<arr[i]){
    max=arr[i];
   }
}
  cout<<"sum of elements:"<<sum<<endl;
  float avg = (float)sum/n;
  cout<<"average:"<<avg<<endl;
    cout<<"minimum: "<<min<<endl;
return 0;
}

