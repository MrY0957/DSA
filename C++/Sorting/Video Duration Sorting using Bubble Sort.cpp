#include<iostream>
using namespace std;

void bubleSorted(int arr[], int n){
    int i,j,count=0;
     for(i=0;i<n;i++){  //outer loop
            bool checked = true; //for checking swap!
        for(j=0;j<n-1-i;j++){   //inner loop
            if(arr[j+1]>arr[j]){ //descending order
                swap(arr[j],arr[j+1]);
                checked = false;
            }
        }
        count++; //i=pass Counter
        cout<<"Pass "<<count<<": ";
        for(j=0; j<n; j++){
           cout<<arr[j]<<" ";
        }
        cout<<endl;
        if(checked){
            break;
        }
    }
    cout<<"Total Passes: "<<count<<endl; // #pass = outer loop

}
int main(){
    int i, j, n=5;
    int arr[n]={12, 8, 5, 3, 10};
    bubleSorted(arr,n);
    cout<<"\n Buble Sorted Array:";
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
