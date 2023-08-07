//
// Created by AnGa on 2023-03-30.
//

#include "sorting_algorithms.h"

void insertionSort(data_t &vector){
    int nextPosition = 1;
    while(nextPosition < vector.size()){
        int valueToInsert = vector[nextPosition];
        int sortedPosition = nextPosition - 1;
        while (sortedPosition >= 0 && vector[sortedPosition] > valueToInsert){
            vector[sortedPosition + 1] = vector[sortedPosition];
            sortedPosition = sortedPosition - 1;
        }
        vector[sortedPosition + 1] = valueToInsert;
        nextPosition++;
    }
}
void selectionSort(data_t &vector){
    for (int currentPosition = 0; currentPosition < vector.size() - 1; ++currentPosition) {
        int minValuePosition = currentPosition;

        for (int nextPosition = currentPosition + 1; nextPosition < vector.size(); nextPosition++) {
            if (vector[nextPosition] < vector[minValuePosition]) {
                minValuePosition = nextPosition;
            }
        }

        if (minValuePosition != currentPosition){
            std::swap(vector[minValuePosition], vector[currentPosition]);
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