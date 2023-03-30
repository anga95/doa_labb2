//
// Created by AnGa on 2022-05-05.
//
#include "datagenerate.h"
#ifndef LABB2_SORTING_H
#define LABB2_SORTING_H
using PartitionFunc = int(*)(data_t&, int, int);

void insertionSort(data_t &vector);
void selectionSort(data_t &vector);
int partition_right(data_t& data, int low, int high);
void quick_sort(data_t& data, int low, int high, PartitionFunc partition);
int partition_median_of_three(data_t& data, int low, int high);

#endif //LABB2_SORTING_H
