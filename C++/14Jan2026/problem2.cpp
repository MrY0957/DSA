#include<iostream>
using namespace std;

int main(){
int n,count=0,zero=0;
cout<<"Enter a number (0 to n): ";
cin>>n;
if(n==0){
    cout<<"The Number is Zero"<<endl;
    cout<<"No. of digit 1"<<endl;
    return 0;
}else{
    if(n>0){
        cout<<"Positive"<<endl;
            if(n%2==0){
                cout<<"Even";
            }else{
                cout<<"Odd";
        }
    }else if(n<0){
        cout<<"Negative"<<endl;
            if(n%2==0){
                cout<<"Even";
            }else{
                cout<<"Odd";
        }
    }
    cout<<endl;
    while(n<0 || n>0){
        n=n/10;
        count++;
        }
    cout<<"No. of digit "<<count<<endl;
    }
return 0;
}


