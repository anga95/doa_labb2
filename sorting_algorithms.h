//
// Created by AnGa on 2023-03-30.
//

#ifndef LABB2_SORTING_ALGORITHMS_H
#define LABB2_SORTING_ALGORITHMS_H

#include "datagenerate.h"

void insertionSort(data_t &vector);
void selectionSort(data_t &vector);
int partition_right(data_t& data, int low, int high);
void quick_sort(data_t& data, int low, int high, PartitionFunc partition);
int partition_median_of_three(data_t& data, int low, int high);



#endif //LABB2_SORTING_ALGORITHMS_H
