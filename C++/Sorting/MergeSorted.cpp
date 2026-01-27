#include<iostream>
using namespace std;

void Merge(int arr[], int low, int mid, int high){
    int i,j,k;
    int n1 = mid - low + 1;
    int n2 = high - mid;

    int L[n1], R[n2];

    for(i=0; i<n1; i++){
        L[i] = arr[low+i]; 
    }
    for(j=0; j<n2; j++){
        R[j] = arr[mid+1+j];
    }
        i=0, j=0, k=low;
    while (i<n1 && j<n2){
        if(L[i]<R[j]){
            arr[k] = L[i];
            i++;
        }else{arr[k]=R[j]; j++;
        }
        k++;
    }
    while(i<n1){
        arr[k] = L[i];
        i++;
        k++;
    }
    while(j<n2){
        arr[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int arr[], int low, int high){
    if(low<high){
        int mid = (low+high)/2;
        MergeSort(arr, low, mid);
        MergeSort(arr, mid+1, high);
        Merge(arr, low, mid, high);
    }
}

int main(){
    int i,j,n;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the elements of array: ";
    int arr[n];
    for(i=0; i<n; i++){
        cin>>arr[i];
    }
    MergeSort(arr, 0, n-1);
    cout<<"Sorted array is: ";
    for(i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
