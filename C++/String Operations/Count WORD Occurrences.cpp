#include <iostream>          
#include <limits>                // use for  numeric_limits to buffer clear 
using namespace std;           

int findWord(char line[], char word[]) {   
    int count=0;                           
    int n=0, m=0;                          
    while(line[n] != '\0') n++;            
    while(word[m] != '\0') m++;            
    for(int i=0; i<=n-m; i++) {            
        int j=0;
        while(j<m && line[i+j]==word[j]) j++; 
        if(j==m) count++;                 
    }
    return count;                         
}

int main() {
    char LINE[100][81], WORD[20];
    int N, C=0;                       

    cout<<"Enter number of lines: ";       
    cin >> N;                            
    cin.ignore(numeric_limits<streamsize>::max(), '\n'); // newline buffer clear 

    cout<<"Enter "<<N<<" lines:"<<endl;   
    for(int i=0; i<N; i++) {               
        cin.getline(LINE[i], 81);       
    }

    cout<<"Enter word to search: ";       
    cin.getline(WORD, 20);               

    for(int i=0; i<N; i++) {               
        C += findWord(LINE[i], WORD);  
    }

    cout << "WORD occurs " << C << " times" << endl; 
    return 0;                              
}
