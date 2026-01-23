#include<iostream>
using namespace std;

char UpperCase(char ch) {
    if (ch >= 'a' && ch <= 'z') {
        return ch - 32;
    }
    return ch;
}

int main() {
    char str[100], ptr[100];
    cout << "Enter string: ";
    cin.getline(str, 100);
    cout << "Enter pattern: ";
    cin.getline(ptr, 100);

    int ls = 0, lp = 0;
    while (str[ls] != '\0'){
        ls++;
    }
    while (ptr[lp] != '\0'){ 
        lp++;
    }
    bool flag = false;
    int max = ls - lp + 1;

    for (int i = 0; i < max; i++) {
        bool found = true;
        for (int j = 0; j < lp; j++) {
            char sChar = UpperCase(str[i + j]);
            char pChar = UpperCase(ptr[j]);
            if (sChar != pChar) {
                found = false;
                break;
            }
        }
        if (found) {
            cout << "Pattern found at index: " << i << endl;
            flag = true;
        }
    }

    if (!flag) {
        cout << "Not Found" << endl;
    }

    return 0;
}
