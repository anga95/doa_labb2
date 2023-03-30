#include <iostream>
#include <numeric>
#include "data_generation.h"
#include "sorting_utils.h"
#include "timing_utils.h"
#include "data_reporting.h"
#include "sorting_algorithms.h"

int main() {
    std::srand(std::time(nullptr));
    int sampleCount = 5;

    std::vector<std::pair<std::string, std::function<void(data_t &)>>> sortingAlgorithms = {
            {"InsertionSort", insertionSort},
            {"SelectionSort", selectionSort},
            {"QuickSortRightPivot", [&](data_t &data){quick_sort(data, 0, data.size() - 1, partition_right);}},
            {"QuickSortMedianOfThree", [&](data_t &data){quick_sort(data, 0, data.size() - 1, partition_median_of_three);}}
    };

    std::vector<SortingResult> results;
    int dataSizeStart = 20000;
    int dataSizeEnd = 200000;
    int dataSizeStep = 20000;

    for (const auto& sortAlgorithm : sortingAlgorithms) {
        for (int dataSize = dataSizeStart; dataSize <= dataSizeEnd ; dataSize += dataSizeStep) {
            std::vector<std::pair<std::string, data_t>> dataVariants = {
                    {"random",     generate_random_data(dataSize)},
                    {"ascending",  generate_ascending_order_data(dataSize)},
                    {"descending", generate_descending_order_data(dataSize)},
                    {"constant",       generate_constant_value_data(dataSize)}
            };


            for (const auto& dataVariants : dataVariants) {
                std::vector<double> samplesForStdDev;
                for (int i = 0; i < sampleCount; i++) {
                    data_t dataCopy = dataVariants.second;
                    double timeTaken = measureSortingTime(sortAlgorithm.second, dataCopy);
                    samplesForStdDev.push_back(timeTaken);
                }

                double averageTime = std::accumulate(samplesForStdDev.begin(), samplesForStdDev.end(), 0.0) / sampleCount;
                double standardDeviation = calculateStandardDeviation(samplesForStdDev);

                results.emplace_back(sortAlgorithm.first, dataVariants.first, dataSize, averageTime, standardDeviation, sampleCount);
            }
        }
    }


    printSortingResults(results);
    std::string outPutFileName = "sorting_results.csv";
    saveSortingResults(outPutFileName, results);

    return 0;
}




// insertion sort
// https://en.wikipedia.org/wiki/Insertion_sort#List_insertion_sort_code_in_C
//
//
/*
set terminal pdf font ’cmr ’
set output ’image.pdf’
#set size 1,2
set key box
#set samples 50, 50
#set style data lines
set title _"Selection sort -- random series"
set xlabel "N elements"
set ylabel "t [{/Symbol m}s]"
 x = 0.0

plot "sel_sort.dat" title "Random input" with errorbars,
    "fit.dat" smooth csplines t "Fit k N^2"
#close output file
set output
set terminal pop
 */