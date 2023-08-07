//
// Created by AnGa on 2023-03-30.
//

#ifndef LABB2_TIMING_UTILS_H
#define LABB2_TIMING_UTILS_H


#include <functional>
#include "data_generation.h"

/**
 * Measures the time it takes to sort a vector
 * @param sortingFunc the sorting function to use
 * @param data the data to sort
 * @return the time it took to sort the vector
 */
double measureSortingTime(const std::function<void (data_t&)>& sortingFunc, data_t &data);

/**
 * Measures the time it takes to sort a vector
 * @param samples the samples to calculate the standard deviation of
 * @return the standard deviation of the samples
 */
double calculateStandardDeviation(const std::vector<double>& samples);

#endif //LABB2_TIMING_UTILS_H
