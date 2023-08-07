//
// Created by AnGa on 2023-03-30.
//

#ifndef LABB2_DATA_REPORTING_H
#define LABB2_DATA_REPORTING_H


#include <string>
#include <vector>

/**
 * A struct to hold the results of a sorting algorithm
 * uses an explicit constructor to avoid implicit conversions
 */
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

/**
 * Saves the results of a sorting algorithm to a csv file
 * @param filename the name of the file to save to
 * @param results the results to save
 */
void saveSortingResults(const std::string& filename, const std::vector<SortingResult>& results);

/**
 * Prints the results of a sorting algorithm to the console
 * @param results the results to print
 */
void printSortingResults(const std::vector<SortingResult>& results);


#endif //LABB2_DATA_REPORTING_H
