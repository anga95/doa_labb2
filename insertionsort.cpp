//
// Created by AnGa on 2022-05-05.
//

#include "sorting.h"

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