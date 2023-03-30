//
// Created by AnGa on 2023-03-30.
//

#ifndef LABB2_DATA_REPORTING_H
#define LABB2_DATA_REPORTING_H


#include <string>
#include <vector>

struct SortingResult{
    std::string algorithmName;
    std::string dataPattern;
    size_t dataSize;
    double timeTaken;
    double standardDeviation;
    int sampleCount;
    SortingResult(const std::string& algorithmName, const std::string& dataPattern, size_t dataSize, double timeTaken, double standardDeviation, int sampleCount)
            : algorithmName(algorithmName), dataPattern(dataPattern), dataSize(dataSize), timeTaken(timeTaken), standardDeviation(standardDeviation), sampleCount(sampleCount) {}
};

void saveSortingResults(const std::string& filename, const std::vector<SortingResult>& results);
void printSortingResults(const std::vector<SortingResult>& results);


#endif //LABB2_DATA_REPORTING_H
