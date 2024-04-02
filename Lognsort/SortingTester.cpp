#include <iostream>
#include <vector>
#include <chrono>
#include <fstream>
#include <iomanip> 
#include "LognSort.h"
#include "MergeSort.h"
#include "SortingTester.h"

using namespace std;
using namespace std::chrono;

template <typename T>
std::string getTypeName(const T &)
{
    return typeid(T).name();
}

template class SortingTester<MergeSort>; // Instantiate SortingTester for MergeSort
template class SortingTester<LognSort>;  // Instantiate SortingTester for LognSort

template <typename SortingAlgorithm>
void SortingTester<SortingAlgorithm>::testSortingAlgorithm(const std::string &filename, int size)
{

    SortingAlgorithm sorter;            // Create an instance of the sorting algorithm class
    std::ofstream outputFile(filename); // Open the file for writing

    if (!outputFile.is_open())
    {
        std::cerr << "Error: Unable to open file " << filename << " for writing." << std::endl;
        return;
    }

    for (int iteration = 2; iteration <= size; iteration++)
    {
        cout << "Calculating Average Time for " << getTypeName(sorter) << " with " << iteration << " elements..." << endl;
        int64_t totalTime = 0;
        this->baseArray.clear();
        fillBaseArray(iteration);
        generatePermutations(baseArray, 0, baseArray.size() - 1);

        for (int i = 0; i < factorial(iteration); i++)
        {

            // Record start time
            auto start = std::chrono::high_resolution_clock::now();

            // Sort the array
            sorter.sort(permutations[i], 0, iteration - 1);

            // Record end time
            auto stop = std::chrono::high_resolution_clock::now();

            // Calculate the duration of sorting
            auto duration = std::chrono::duration_cast<std::chrono::microseconds>(stop - start);

            // add duration
            totalTime += duration.count();
        }
        // Calculate average time (using floating-point division)
        int iterationFactorial = factorial(iteration);
        double iterationAverageTime = static_cast<double>(totalTime) / factorial(iteration);
        this->iterationTimeAverage += iterationAverageTime;
        outputFile << "Size: " << iteration << endl;
        outputFile << "Average Time: " << iterationAverageTime << endl;

        // Clear Permutations
        this->permutations.clear();
    }

    double averageTime = iterationTimeAverage / (size - 1);
    cout << endl << "Overall Average Time: " << std::fixed << std::setprecision(3) << averageTime << endl << endl;    // Close File
    outputFile << endl << "Overall Average Time: " << std::fixed << std::setprecision(3) << averageTime << endl << endl;    // Close File
    iterationTimeAverage = 0;
    outputFile.close();
}

// Function to generate random elements for an array
template <typename SortingAlgorithm>
void SortingTester<SortingAlgorithm>::generateRandomArray(std::vector<int> &arr)
{
    for (int i = 0; i < arr.size(); i++)
    {
        arr[i] = rand() % 1000; // Generate random numbers between 0 and 999
    }
}

// generate base array for permutations
template <typename SortingAlgorithm>
void SortingTester<SortingAlgorithm>::fillBaseArray(int size)
{
    for (int i = 0; i < size; i++)
    {
        this->baseArray.push_back(i);
    }
}

// Function to swap two elements in an array
template <typename SortingAlgorithm>
void SortingTester<SortingAlgorithm>::swap(std::vector<int> &arr, int i, int j)
{
    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
}

// Function to permute an array
template <typename SortingAlgorithm>
void SortingTester<SortingAlgorithm>::generatePermutations(std::vector<int> &arr, int l, int r)
{
    if (l == r)
    {
        this->permutations.push_back(arr);
    }
    else
    {
        for (int i = l; i <= r; i++)
        {
            swap(arr, l, i);
            generatePermutations(arr, l + 1, r);
            swap(arr, l, i); // backtrack
        }
    }
}

// Function to calculate factorial
template <typename SortingAlgorithm>
int SortingTester<SortingAlgorithm>::factorial(int i)
{
    if (i == 1)
        return i;
    else
    {
        return i * factorial(i - 1);
    }
}

// print array
template <typename SortingAlgorithm>
string SortingTester<SortingAlgorithm>::getArrayString(int index)
{
    string result = "";
    vector<int> arr = this->permutations[index];
    for (int i = 0; i < arr.size(); i++)
    {
        if (i == 0)
            result += "[" + to_string(arr[i]) + ", ";
        else if (i == arr.size() - 1)
            result += to_string(arr[i]) + "]";
        else
            result += to_string(arr[i]) + ", ";
    }
    return result; // Add this return statement
}