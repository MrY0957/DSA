#include <iostream>
using namespace std;

void reverse(char s[]) {
    int n=0;
    while(s[n] != '\0') n++;
    for(int i=0; i<n/2; i++) {
        char temp = s[i];
        s[i] = s[n-1-i];
        s[n-1-i] = temp;
    }
}

int main() {
    char STR[100];
    cout<<"Enter a string: ";
    cin.getline(STR, 100);
    reverse(STR);
    cout << "Reversed: " << STR << endl;
}
