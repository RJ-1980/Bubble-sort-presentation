#include <iostream>
using namespace std;

void bubbleSortOptimized(int arr[], int n) {
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;  // Flag to detect if any swap happened
        
        for (int j = 0; j < n - i - 1; j++) {
            if (arr[j] > arr[j + 1]) {
                // Swap elements
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swapped = true;
            }
        }
        
        // If no swaps were made, array is already sorted
        if (!swapped) {
            cout << "Array sorted early! Stopped after pass " << (i + 1) << endl;
            break;
        }
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    // Test with nearly sorted array
    int arr1[] = {1, 2, 3, 5, 4, 6, 7};
    int n1 = sizeof(arr1) / sizeof(arr1[0]);
    
    cout << "=== Optimized Bubble Sort ===" << endl;
    cout << "Original array: ";
    printArray(arr1, n1);
    
    bubbleSortOptimized(arr1, n1);
    
    cout << "Sorted array: ";
    printArray(arr1, n1);
    
    cout << "\n--- Testing with already sorted array ---" << endl;
    int arr2[] = {1, 2, 3, 4, 5};
    int n2 = sizeof(arr2) / sizeof(arr2[0]);
    
    cout << "Array: ";
    printArray(arr2, n2);
    bubbleSortOptimized(arr2, n2);
    cout << "Result: ";
    printArray(arr2, n2);
    
    return 0;
}