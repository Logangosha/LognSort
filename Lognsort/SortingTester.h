#ifndef SORTING_TESTER_H
#define SORTING_TESTER_H

#include <iostream>
#include <vector>
#include <chrono>
#include <fstream> 
#include "LognSort.h"
#include "MergeSort.h"

using namespace std;
using namespace std::chrono;

template<typename SortingAlgorithm> 
class SortingTester {
public:
    // Array to base permutations on
    vector<int> baseArray;

    // List of permutations for base array
    vector<vector<int>> permutations;

    // Average Time
     double iterationTimeAverage = 0;

    // Function to test the sorting algorithm with arrays of varying sizes
    void testSortingAlgorithm(const std::string& filename, int size);

private:
    // Function to generate random elements for an array
    void generateRandomArray(std::vector<int>& arr);
    
    // generate base array for permutations
    void fillBaseArray(int size);

    // Function to swap two elements in an array
    void swap(std::vector<int>& arr, int i, int j);

    // Function to permute an array
    void generatePermutations(std::vector<int>& arr, int l, int r);

    // Function to calculate factorial
    int factorial(int i);

    // print array
    string getArrayString(int index);
};
#endif
