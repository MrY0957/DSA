#include <iostream>
using namespace std;

int main() {
    int i,j,ls,lp;
    cout << "Enter array size(0-100): ";
    cin >> ls;
    cout << "Enter pattern size(0-100): ";
    cin >> lp;
    int max = ls-lp+1;
    int arr[ls], ptr[lp];
    for(i=0;i<ls;i++){
        cin>>arr[i];
    }
    for(j=0;j<lp;j++){
        cin>>ptr[j];
    }
    bool flag=true;
    for(i=0;i<max;i++){
         flag=true;
        for(j=0;j<lp&&flag==true;j++){
            if(arr[j+i-1]!=ptr[j]){
                flag=false;
            }
        }
        cout<<"not Found";
        if(flag==true){
            cout<<i<<endl;
        }
    }
  
    return 0;
}