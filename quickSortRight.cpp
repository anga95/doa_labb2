//
// Created by AnGa on 2022-05-06.
//
#include "sorting.h"

int partition_right(data_t& data, int low, int high){
    int pivot = data[high];
    int index = (low - 1);

    for (int current = low; current <= high ; ++current) {
        if (data[current] < pivot){
            index++;
            std::swap(data[index], data[current]);
        }
    }
    std::swap(data[index+1], data[high]);
    return (index + 1);
}

// This function takes last element as pivot, places
// the pivot element at its correct position in sorted
// array, and places all smaller (smaller than pivot)
// to left of pivot and all greater elements to right
// of pivot
int partition_median_of_three(data_t& data, int low, int high){
    int mid = low + (high-low)/2;
    if (data[low] > data[high]){ std::swap(data[low], data[high]);}
    if (data[mid] > data[high]){ std::swap(data[mid], data[high]);}
    if (data[mid] > data[low]) { std::swap(data[mid], data[low]);}

    // Use the pivot value as a sentinel value to help with partitioning
    int pivot = data[low];
    // Index for maintaining the partition of the array
    int index = low+1;
    for (int i = low+1; i < high ; i++) {
        if (data[i] < pivot){
            std::swap(data[index], data[i]);
            index++;
        }
    }

    // Place the pivot at the partition index
    std::swap(data[low], data[index-1]);

    return index-1;
}

void quick_sort(data_t& data, int low, int high, PartitionFunc partition){
    if (low < high){
        //int partitionIndex = partition_right(data, low, high);
        int partitionIndex = partition(data, low, high);
        quick_sort(data, low, partitionIndex - 1, partition);
        quick_sort(data, partitionIndex + 1, high, partition);
    }
}

//https://stackoverflow.com/questions/55798026/how-do-i-implement-quicksort-correctly
