// Header file for the dynamic array class
#ifndef DYNAMICARRAY_H
#define DYNAMICARRAY_H

#include <iostream>

template <typename T>
class DynamicArray
{
public:
    DynamicArray(int initialCapacity = 10); // Constructor with optional initial capacity
    ~DynamicArray();                        // Destructor to free memory, these are use to deallocate memory when,  when the object is no longer in use. This prevents memory leaks,
    // which can significantly impact your program's performance and stability.

    void insert(const T &value, int index = -1);        // Insert element at specified index (default: end)
    void remove(int index);                             // Remove element at specified index
    int getLargestElement() const;                      // Find the largest element
    int getSecondLargestElement() const;                // Find the second largest element (may not always be possible)
    bool isSorted() const;                              // Check if the array is sorted
    void reverse();                                     // Reverse the array elements
    int maxDiff(bool orderMatters = true) const;        // Maximum difference with optional order constraint
    void findFrequencies(std::vector<int> &freq) const; // Find frequencies in a sorted array (using vector for efficiency)
    int maxSubarraySum() const;                         // Maximum subarray sum
    int maxCircularSubarraySum() const;                 // Maximum circular subarray sum (Kadane's algorithm with modification)
    int longestEvenOddSubarray() const;                 // Longest even-odd subarray length (brute-force approach)

    // Utility functions for capacity management
    void resize(int newCapacity); // Resize the underlying array if needed

private:
    T *data;      // Pointer to the dynamically allocated array storage
    int capacity; // Current capacity of the array
    int size;     // Number of elements currently stored

    // Helper functions for specific functionalities
    int findLargestIndex() const;
    int findSecondLargestIndex() const;
    bool isEven(int num) const;
};

#endif