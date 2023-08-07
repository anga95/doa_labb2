//
// Created by AnGa on 2023-03-30.
//

#ifndef LABB2_SORTING_ALGORITHMS_H
#define LABB2_SORTING_ALGORITHMS_H

#include <vector>
using data_t = std::vector<int>;

/**
 * A function pointer to a partition function
 */
using PartitionFunc = int(*)(data_t&, int, int);

/**
 * Sorts a vector using insertion sort
 * @param vector the vector to sort
 */
void insertionSort(data_t &vector);

/**
 * Sorts a vector using selection sort
 * @param vector the vector to sort
 */
void selectionSort(data_t &vector);

/**
 * Sorts a vector using quick sort
 * @param data the vector to sort
 * @param low the lowest index to sort
 * @param high the highest index to sort
 * @return the index of the pivot
 */
int partition_right(data_t& data, int low, int high);

/**
 * Sorts a vector using quick sort
 * @param data the vector to sort
 * @param low the lowest index to sort
 * @param high the highest index to sort
 * @param partition the partition function to use
 */
void quick_sort(data_t& data, int low, int high, PartitionFunc partition);

/**
 * Sorts a vector using quick sort
 * @param data the vector to sort
 * @param low the lowest index to sort
 * @param high the highest index to sort
 * @return the index of the pivot
 */
int partition_median_of_three(data_t& data, int low, int high);



#endif //LABB2_SORTING_ALGORITHMS_H
