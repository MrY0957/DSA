#include<iostream>
using namespace std;

int main() {
    int i,n,j;
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
    for(i=1;i<n;i++){
        j=i;
        while(j>0 && arr[j]<arr[j-1]){
            swap(arr[j],arr[j-1]);
            j--;
        }
    }

    cout<<"Selected Sorted array: ";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
