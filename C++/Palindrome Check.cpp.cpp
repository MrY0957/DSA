#include <iostream>
using namespace std;

int main() {
    char STR[100];
    cout<<"Enter a string: ";
    cin.getline(STR, 100);
    int n=0;
    while(STR[n] != '\0') n++;
    int flag=1;
    for(int i=0; i<n/2; i++) {
        if(STR[i] != STR[n-1-i]) { 
            flag=0; 
            break; 
        }
    }
    if(flag) cout << "Palindrome" << endl;
    else cout << "Not Palindrome" << endl;
}
