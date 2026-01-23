#include <iostream>
using namespace std;

int main() {
    int n;
    cout << "Enter array size(0-100): ";
    cin >> n;

    int arr[n];
    cout << "Enter array elements: ";
    for (int i = 0; i < n; i++) {
        cin >> arr[i];
    }
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }

    cout << "\nFrequency of elements:\n";
    for (int i = 0; i < n; i++) {
        int count = 1;
        bool checked = false;

        for (int j = 0; j < i; j++) {
            if (arr[i] == arr[j]) {
                checked = true;
                break;
            }
        }

        if (!checked) {
            for (int k = i + 1; k < n; k++) {
                if (arr[i] == arr[k]) {
                    count++;
                }
            }
            cout << arr[i] << " -> " << count << " times" << endl;
        }
    }
    return 0;
}
