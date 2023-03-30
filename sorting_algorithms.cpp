//
// Created by AnGa on 2023-03-30.
//

#include "sorting_algorithms.h"

void insertionSort(data_t &vector){
    int next = 1;
    while( next < vector.size()){
        int current = vector[next];
        int previous = next - 1;
        while (previous >= 0 && vector[previous] > current){
            vector[previous+1] = vector[previous];
            previous = previous - 1;
        }
        vector[previous + 1] = current;
        next++;
    }
}
void selectionSort(data_t &vector){
    for (int current = 0; current < vector.size()-1; ++current) {
        int minValue = current;

        for (int next = current + 1; next < vector.size(); next++) {
            if (vector[next] < vector[minValue]) {
                minValue = next;
            }
        }

        if (minValue != current){
            std::swap(vector[minValue], vector[current]);
        }
    }
}

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
        int partitionIndex = partition(data, low, high);
        quick_sort(data, low, partitionIndex - 1, partition);
        quick_sort(data, partitionIndex + 1, high, partition);
    }
}