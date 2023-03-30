//
// Created by AnGa on 2023-03-30.
//

#ifndef LABB2_TIMING_UTILS_H
#define LABB2_TIMING_UTILS_H


#include "data_generation.h"

double measureSortingTime(const std::function<void (data_t&)>& sortingFunc, data_t &data);
double calculateStandardDeviation(const std::vector<double>& samples);

#endif //LABB2_TIMING_UTILS_H
