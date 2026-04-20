#include<iostream>
using namespace std;

// Case Sensitive Pattern Count
int main(){
    char str[100], ptr[100];
    cout<<"Enter string: ";
    cin.getline(str,100);
    cout<<"Enter pattern: ";
    cin.getline(ptr,100);

    int ls=0, lp=0;
    while(str[ls]!='\0') ls++;
    while(ptr[lp]!='\0') lp++;

    int i,j,count=0,max = ls-lp+1;
    bool flag=false;

    for(i=0;i<max;i++){
        bool found=true;
        for(j=0;j<lp;j++){
            if(str[i+j]!=ptr[j]){
                found=false;
                break;
            }
        }
        if(found){
            cout<<"Pattern found at index: "<<i<<endl;
            flag=true;
            count++;
        }
    }
    if(!flag){
        cout<<"Not Found"<<endl;
    }
    cout<<"Repeat times: "<<count<<endl;
    return 0;
}
