#include <iostream>
using namespace std;

int main() {
    char LINE[100][81]; // 80 chars per line
    int N, NUM=0;
    cout<<"Enter number of lines: ";
    cin >> N;
    cin.ignore();
    cout<<"Enter lines of text:\n";
    for(int i=0; i<N; i++) {
        cin.getline(LINE[i], 81);
        // check first 5 chars are blanks
        int flag=1;
        for(int j=0; j<5; j++) {
            if(LINE[i][j] != ' ') { flag=0; break; }
        }
        if(flag) NUM++;
    }
    cout << "Paragraphs = " << NUM << endl;
}

