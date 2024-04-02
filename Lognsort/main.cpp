#include <iostream>
#include <vector>
#include <chrono>
#include <fstream> 
#include "MergeSort.h"
#include "LognSort.h"
#include "SortingTester.h"

using namespace std;
using namespace std::chrono;

int main() {

    int size = 12;
    // Create an instance of SortingTester class with MergeSort algorithm
    SortingTester<MergeSort> mergesort;
    mergesort.testSortingAlgorithm("mergeSorting_statistics.txt", size);

    // Create an instance of SortingTester class with Lognsort algorithm
    SortingTester<LognSort> lognsort;
    lognsort.testSortingAlgorithm("lognSorting_statistics.txt", size);

    return 0;
}