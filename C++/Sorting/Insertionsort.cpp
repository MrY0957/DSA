#include<iostream>
using namespace std;

int main() {
    int i,n,j,cur_min;
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
    cout<<endl; //main pseudocode
    for(i=0;i<n;i++){
        cur_min =i;
        for(j=i+1;j<n;j++){
            if(arr[j]<arr[cur_min]){
                cur_min =j;
            }
        }
        if(cur_min != i){
            swap(arr[i],arr[cur_min]);
        }
    }
    cout<<"Insertion Sorted array: ";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
