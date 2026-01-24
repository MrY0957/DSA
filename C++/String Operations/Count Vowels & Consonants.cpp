#include <iostream>
using namespace std;

int isAlpha(char c) {
    return ( (c>='A' && c<='Z') || (c>='a' && c<='z') );
}
int isVowel(char c) {
    char d = (c>='A' && c<='Z') ? c+32 : c; // tolower
    return (d=='a'||d=='e'||d=='i'||d=='o'||d=='u');
}

int main() {
    char STR[100];
    cout<<"Enter a string: ";
    cin.getline(STR, 100);
    int v=0, c=0;
    for(int i=0; STR[i]!='\0'; i++) {
        if(isAlpha(STR[i])) {
            if(isVowel(STR[i])) v++;
            else c++;
        }
    }
    cout << "Vowels=" << v << ", Consonants=" << c << endl;
}
