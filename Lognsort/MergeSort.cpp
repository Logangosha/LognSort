#include <vector>
#include "MergeSort.h"

using namespace std;

    // Merge two sorted subarrays arr[l..m] and arr[m+1..r]
    void MergeSort::merge(vector<int>& arr, int l, int m, int r) {
        int n1 = m - l + 1; // Size of left subarray
        int n2 = r - m;     // Size of right subarray

        // Create temporary arrays to hold the left and right subarrays
        vector<int> L(n1), R(n2);

        // Copy data from the original array to the temporary arrays
        for (int i = 0; i < n1; i++)
            L[i] = arr[l + i]; // Copy elements from l to m into L
        for (int j = 0; j < n2; j++)
            R[j] = arr[m + 1 + j]; // Copy elements from m+1 to r into R

        // Merge the temporary arrays back into arr[l..r]
        int i = 0, j = 0, k = l; // Initialize indices for merging
        while (i < n1 && j < n2) {
            // Compare elements from the left and right subarrays
            if (L[i] <= R[j]) {
                arr[k] = L[i]; // Place smaller element from L into arr
                i++;
            } else {
                arr[k] = R[j]; // Place smaller element from R into arr
                j++;
            }
            k++; // Move to the next position in arr
        }

        // Copy the remaining elements of L[], if any
        while (i < n1) {
            arr[k] = L[i];
            i++;
            k++;
        }

        // Copy the remaining elements of R[], if any
        while (j < n2) {
            arr[k] = R[j];
            j++;
            k++;
        }
    }

    // Merge sort function
    void MergeSort::sort(vector<int>& arr, int l, int r) {
        if (l >= r) return; // Base case: if l >= r, the array is already sorted

        // Find the middle point to divide the array into two halves
        int m = l + (r - l) / 2;

        // Recursively sort the first and second halves
        sort(arr, l, m);     // Sort the left half
        sort(arr, m + 1, r); // Sort the right half

        // Merge the sorted halves
        merge(arr, l, m, r);
    }
