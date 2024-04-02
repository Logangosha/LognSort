#ifndef MERGESORT_H
#define MERGESORT_H
#include <vector>
using namespace std;

class MergeSort {
public:
    // Merge two sorted subarrays arr[l..m] and arr[m+1..r]
    void merge(vector<int>& arr, int l, int m, int r);

    // Merge sort function
    void sort(vector<int>& arr, int l, int r);
};

#endif