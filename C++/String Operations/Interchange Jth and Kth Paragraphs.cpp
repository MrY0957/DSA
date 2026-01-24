#include <iostream>
using namespace std;

int main() {
    char LINE[100][81];
    int N, J, K;
    cout<<"Enter number of lines, J, K: "<<endl;
    cin >> N >> J >> K;
    cin.ignore();
    cout<<"Enter lines: "<<endl;
    for(int i=0; i<N; i++) cin.getline(LINE[i], 81);
    char temp[81];
    int j=0;
    while(LINE[J-1][j] != '\0') { 
        temp[j]=LINE[J-1][j]; j++; 
    }
    temp[j]='\0';
    j=0;
    while(LINE[K-1][j] != '\0') { 
        LINE[J-1][j]=LINE[K-1][j]; j++; 
    }
    LINE[J-1][j]='\0';
    j=0;
    while(temp[j] != '\0') { 
        LINE[K-1][j]=temp[j]; j++; 
    }
    LINE[K-1][j]='\0';
    cout<<"Resulting lines: "<<endl;
    for(int i=0; i<N; i++) cout <<LINE[i] << endl;
}
