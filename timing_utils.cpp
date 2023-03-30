//
// Created by AnGa on 2023-03-30.
//

#include <numeric>
#include "timing_utils.h"

double measureSortingTime(const std::function<void (data_t&)>& sortingFunc, data_t &data){
    auto start = std::chrono::high_resolution_clock::now();
    sortingFunc(data);
    auto stop = std::chrono::high_resolution_clock::now();

    std::chrono::duration<double> duration = stop - start;
    return duration.count();
}

double calculateStandardDeviation(const std::vector<double>& samples){
    double sum = std::accumulate(samples.begin(), samples.end(), 0.0);
    double mean = sum / samples.size();

    double squardDifferenceSum = double();

    for (const double& sample : samples) {
        squardDifferenceSum += std::pow(sample - mean, 2);
    }

    double variance = squardDifferenceSum / samples.size();
    double standardDeviation = std::sqrt(variance);

    return standardDeviation;
}