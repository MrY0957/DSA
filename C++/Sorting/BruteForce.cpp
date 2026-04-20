#include<iostream>
using namespace std;
int main(){
    char str[100],ptr[100];
    cout<<"enter string:";
    cin.getline(str,100);
    cout<<"enter pattern:";
    cin.getline(ptr,100);
    int ls=0,lp=0;
    while(str[ls]!='\0'){
        ls++;
    }
    while(ptr[lp]!='\0'){
        lp++;
    }
    int i,j, max = ls-lp+1;
    bool found=false;
    bool flag=false;
    for(i=0;i<max;i++){
       found=true;
        for(j=0;j<lp;j++){
            if(str[j+i-1]!=ptr[j]){
                found=false;
                break;
            }
        }
        if(found==true){
            cout<<"Pattern found at index: "<<i<<endl;
            flag=true;
        }
    } 
    if(flag==false){
            cout<<"not Found"<<endl;
        }
return 0;
}
