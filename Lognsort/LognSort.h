#ifndef LOGNSORT_H
#define LOGNSORT_H
#include <vector>
using namespace std;

class LognSort {
public:
    void mergeSortedSubarrays(std::vector<int>& arr, int start1, int end1, int start2, int end2);
    void sort(std::vector<int>& arr, int l, int r);
};

#endif