//
// Created by AnGa on 2022-05-05.
//
#include <vector>
#ifndef LABB2_DATAGENERATE_H
#define LABB2_DATAGENERATE_H

using data_t = std::vector<int>;

std::vector<int> generate_random_data(size_t size);
data_t generate_ascending_order_data(size_t size);
data_t generate_descending_order_data(size_t size);
data_t generate_constant_value_data(size_t size);

#endif //LABB2_DATAGENERATE_H
