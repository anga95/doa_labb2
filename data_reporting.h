//
// Created by AnGa on 2023-03-30.
//

#ifndef LABB2_DATA_REPORTING_H
#define LABB2_DATA_REPORTING_H


#include <string>
#include <vector>

struct SortingResult{
    std::string algorithmName;
    size_t dataSize;
    double timeTaken;
    double standardDeviation;
    int numberOfSamples;
    explicit SortingResult(std::string algorithmName, size_t dataSize, double timeTaken, double standardDeviation, int numberOfSamples)
            : algorithmName(std::move(algorithmName)), dataSize(dataSize), timeTaken(timeTaken), standardDeviation(standardDeviation), numberOfSamples(numberOfSamples) {};
};

void saveSortingResults(const std::string& filename, const std::vector<SortingResult>& results);
void printSortingResults(const std::vector<SortingResult>& results);


#endif //LABB2_DATA_REPORTING_H
