#include <iostream>
#include <chrono>
using namespace std;
using namespace chrono;

void bubbleSort(int arr[], int n, int& comparisons, int& swaps) {
    comparisons = 0;
    swaps = 0;
    
    for (int i = 0; i < n - 1; i++) {
        bool swapped = false;
        for (int j = 0; j < n - i - 1; j++) {
            comparisons++;
            if (arr[j] > arr[j + 1]) {
                int temp = arr[j];
                arr[j] = arr[j + 1];
                arr[j + 1] = temp;
                swaps++;
                swapped = true;
            }
        }
        if (!swapped) break;
    }
}

void printArray(int arr[], int n) {
    for (int i = 0; i < n; i++) {
        cout << arr[i] << " ";
    }
    cout << endl;
}

int main() {
    cout << "=== Bubble Sort Performance Comparison ===" << endl;
    
    // Best Case: Already sorted
    cout << "\n1. BEST CASE (Already Sorted):" << endl;
    int best[] = {1, 2, 3, 4, 5, 6, 7, 8};
    int n = sizeof(best) / sizeof(best[0]);
    int comparisons, swaps;
    
    cout << "Array: ";
    printArray(best, n);
    
    auto start = high_resolution_clock::now();
    bubbleSort(best, n, comparisons, swaps);
    auto stop = high_resolution_clock::now();
    auto duration = duration_cast<microseconds>(stop - start);
    
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
    cout << "Time: " << duration.count() << " microseconds" << endl;
    
    // Worst Case: Reverse sorted
    cout << "\n2. WORST CASE (Reverse Sorted):" << endl;
    int worst[] = {8, 7, 6, 5, 4, 3, 2, 1};
    
    cout << "Array: ";
    printArray(worst, n);
    
    start = high_resolution_clock::now();
    bubbleSort(worst, n, comparisons, swaps);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
    cout << "Time: " << duration.count() << " microseconds" << endl;
    
    // Average Case: Random order
    cout << "\n3. AVERAGE CASE (Random Order):" << endl;
    int avg[] = {5, 2, 8, 1, 9, 3, 7, 4};
    
    cout << "Array: ";
    printArray(avg, n);
    
    start = high_resolution_clock::now();
    bubbleSort(avg, n, comparisons, swaps);
    stop = high_resolution_clock::now();
    duration = duration_cast<microseconds>(stop - start);
    
    cout << "Comparisons: " << comparisons << endl;
    cout << "Swaps: " << swaps << endl;
    cout << "Time: " << duration.count() << " microseconds" << endl;
    
    cout << "\n=== Summary ===" << endl;
    cout << "Best Case: O(n) - Few comparisons, no swaps" << endl;
    cout << "Worst Case: O(n²) - Many comparisons and swaps" << endl;
    cout << "Average Case: O(n²) - Moderate comparisons and swaps" << endl;
    
    return 0;
}
