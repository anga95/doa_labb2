//
// Created by AnGa on 2022-05-05.
//
#include <vector>
#ifndef LABB2_DATAGENERATE_H
#define LABB2_DATAGENERATE_H

using data_t = std::vector<int>;

std::vector<int> generate_rand_data(size_t size);
data_t generate_ascending_data(size_t size);
data_t generate_descending_data(size_t size);
data_t generate_same_value_data(size_t size, int value);

#endif //LABB2_DATAGENERATE_H
