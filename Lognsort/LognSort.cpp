#include <iostream>
#include <vector>
#include "LognSort.h"

using namespace std;

    void LognSort::mergeSortedSubarrays(std::vector<int>& arr, int start1, int end1, int start2, int end2) {
        std::vector<int> merged(end2 - start1 + 1);
        int i = start1, j = start2, k = 0;

        while (i <= end1 && j <= end2) {
            if (arr[i] <= arr[j]) {
                merged[k++] = arr[i++];
            } else {
                merged[k++] = arr[j++];
            }
        }

        while (i <= end1) {
            merged[k++] = arr[i++];
        }

        while (j <= end2) {
            merged[k++] = arr[j++];
        }

        for (int idx = start1; idx <= end2; ++idx) {
            arr[idx] = merged[idx - start1];
        }
    }

    void LognSort::sort(std::vector<int>& arr, int l, int r) {
        if (l < r) {
            int i = l;
            while (i < r && arr[i] <= arr[i + 1]) {
                i++;
            }

            if (i < r) { // If there is an out-of-order element
                sort(arr, i + 1, r); // Sort the right portion
                mergeSortedSubarrays(arr, l, i, i + 1, r); // Merge the sorted portions
            }
        }
    }
