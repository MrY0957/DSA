#include<iostream>
using namespace std;

int partition(int arr[], int low, int high);
void QuickSort(int arr[], int low, int high){
    if(low<high){
        int pi = partition(arr, low, high);
        QuickSort(arr, low, pi-1);
        QuickSort(arr, pi+1, high);
    }
}

int partition(int arr[], int low, int high){ 
    int mid = low + (high - low) / 2; 
    swap(arr[mid], arr[high]);
    int pivot = arr[high];
    int i = (low - 1); 
    for(int j = low; j <= high - 1; j++){ 
        if(arr[j] < pivot){ i++; 
            swap(arr[i], arr[j]); 
        } 
    } 
    swap(arr[i+1], arr[high]); 
    return (i+1); 
}

int main(){
    int i,n;
    cout<<"Enter the size of array: ";
    cin>>n;
    cout<<"Enter the elements of array: ";
    int arr[n];
    for(i=0; i<n; i++){
        cin>>arr[i];
    }
    for(i=0;i<n;i++){
        cout<<arr[i]<<" ";
    }
    cout<<endl;
    QuickSort(arr, 0, n-1);
    for(i=0; i<n; i++){
        cout<<arr[i]<<" ";
    }
    return 0;
}
