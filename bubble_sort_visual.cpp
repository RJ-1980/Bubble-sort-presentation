#include <iostream>
using namespace std;

void printArray(int arr[], int n, string message) {
    cout << message;
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

void bubbleSortVisual(int arr[], int n) {
    cout << "\n=== Bubble Sort Step-by-Step ===" << endl;
    printArray(arr, n, "Starting array: ");
    
    for (int i = 0; i < n - 1; i++) {
        cout << "\n--- Pass " << (i + 1) << " ---" << endl;
        bool swapped = false;
        
        for (int j = 0; j < n - i - 1; j++) {
            cout << "Comparing " << arr[j] << " and " << arr[j + 1];
            
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
                cout << " -> SWAP" << endl;
            } else {
                cout << " -> no swap" << endl;
            }
        }
        
        printArray(arr, n, "After pass " + to_string(i + 1) + ": ");
        
        if (!swapped) {
            cout << "No swaps made. Array is sorted!" << endl;
            break;
        }
    }
}

int main() {
    int arr[] = {5, 2, 8, 1, 9};
    int n = sizeof(arr) / sizeof(arr[0]);
    
    bubbleSortVisual(arr, n);
    
    cout << "\n=== Final Result ===" << endl;
    printArray(arr, n, "Sorted array: ");
    
    return 0;
}
