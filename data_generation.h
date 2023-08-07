//
// Created by AnGa on 2022-05-05.
//
#include <vector>
#ifndef LABB2_DATAGENERATE_H
#define LABB2_DATAGENERATE_H

using data_t = std::vector<int>;

/**
 * Generates random data
 * @param size size of the data
 * @return a vector of random data
 */
std::vector<int> generate_random_data(size_t size);

/**
 * Generates data in ascending order
 * @param size size of the data
 * @return a vector of data in ascending order
 */
data_t generate_ascending_order_data(size_t size);

/**
 * Generates data in descending order
 * @param size size of the data
 * @return a vector of data in descending order
 */
data_t generate_descending_order_data(size_t size);

/**
 * Generates data with constant value
 * @param size size of the data
 * @return a vector of data with constant value
 */
data_t generate_constant_value_data(size_t size);

#endif //LABB2_DATAGENERATE_H
