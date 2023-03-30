//
// Created by AnGa on 2022-05-05.
//

#include "data_generation.h"
#include <algorithm>

data_t generate_rand_data(size_t size){
    data_t vector;
    for (size_t value = 0; value < size; value++) {
        vector.push_back(rand() % size + 1);
    }
    return vector;
}

data_t generate_ascending_data(size_t size){
    data_t vector;
    for (size_t value = 0; value < size; value++) { vector.push_back(value); }
    return vector;
}

data_t generate_descending_data(size_t size){
    data_t vector = generate_ascending_data(size);
    std::reverse(vector.begin(), vector.end());
    return vector;
}

data_t generate_same_value_data(size_t size, int value){
    return data_t(size,value);
}