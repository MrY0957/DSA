#include <iostream>
using namespace std;

// Function to check prime
int isPrime(int n) {
    if (n <= 1) return 0; // not prime
    for (int i = 2; i * i <= n; i++) {
        if (n % i == 0) return 0; // divisible, not prime
    }
    return 1; // prime
}

int main() {
    int n;
    cout << "Enter a number: ";
    cin >> n;

    cout << "Prime numbers from 1 to " << n << " are: " << endl;
    for (int i = 1; i <= n; i++) {
        if (isPrime(i)) {
            cout << i << " ";
        }
    }
    cout << endl;
    return 0;
}