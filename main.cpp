#include <iostream>
#include <numeric>
#include "data_generation.h"
#include "sorting_utils.h"
#include "timing_utils.h"
#include "data_reporting.h"
#include "sorting_algorithms.h"

int main() {
    std::srand(std::time(nullptr));
    size_t dataSize = 100;
    int sampleCount = 5;
    data_t randomValues = generate_rand_data(dataSize);
    data_t ascendingValues = generate_ascending_data(dataSize);
    data_t descendingValues = generate_descending_data(dataSize);
    data_t sameValues = generate_same_value_data(dataSize, 3);
    std::vector<SortingResult> results;


    std::vector<double> samplesForStdDev;
    for (int i = 0; i < sampleCount; i++) {
        double timeTakenInsertionSort = measureSortingTime(insertionSort, randomValues);
        samplesForStdDev.push_back(timeTakenInsertionSort);
    }

    double averageTimeInsertionSort = std::accumulate(samplesForStdDev.begin(), samplesForStdDev.end(), 0.0) / sampleCount;
    double standardDeviationInsertionSort = calculateStandardDeviation(samplesForStdDev);

    results.emplace_back("insertionSort", dataSize, averageTimeInsertionSort, standardDeviationInsertionSort, sampleCount);

    printSortingResults(results);

    std::string outPutFileName = "sorting_results.csv";
    saveSortingResults(outPutFileName, results);

    return 0;
}




// insertion sort
// https://en.wikipedia.org/wiki/Insertion_sort#List_insertion_sort_code_in_C
//
//