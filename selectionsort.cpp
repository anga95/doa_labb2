//
// Created by AnGa on 2022-05-06.
//
#include "sorting.h"
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