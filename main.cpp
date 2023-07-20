#include <iostream>
#include <numeric>
#include <sstream>
#include <iomanip>
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
            {"QuickSortMedianOfThree", [&](data_t &data){quick_sort(data, 0, data.size() - 1, partition_median_of_three);}},
            {"std::sort", [](data_t &data){std::sort(data.begin(), data.end());}}
    };

    int dataSizeStart = 20'000;
    int dataSizeEnd = 200'000;
    int dataSizeStep = 20'000;

    std::vector<std::pair<std::string, data_t>> maxDataVariants = {
            {"random", generate_random_data(dataSizeEnd)},
            {"ascending", generate_ascending_order_data(dataSizeEnd)},
            {"descending", generate_descending_order_data(dataSizeEnd)},
            {"constant", generate_constant_value_data(dataSizeEnd)}
    };

    std::vector<SortingResult> results;

    for (const auto& sortAlgorithm : sortingAlgorithms) {
        for (int dataSize = dataSizeStart; dataSize <= dataSizeEnd; dataSize += dataSizeStep) {
            for (const auto& maxDataVariant : maxDataVariants) {
                std::vector<double> samplesForStdDev;
                for (int i = 0; i < sampleCount; i++) {
                    data_t dataCopy(maxDataVariant.second.begin(), maxDataVariant.second.begin() + dataSize);
                    double timeTaken = measureSortingTime(sortAlgorithm.second, dataCopy);
                    samplesForStdDev.push_back(timeTaken);
                }

                double averageTime = std::accumulate(samplesForStdDev.begin(), samplesForStdDev.end(), 0.0) / sampleCount;
                double standardDeviation = calculateStandardDeviation(samplesForStdDev);

                results.emplace_back(sortAlgorithm.first, maxDataVariant.first, dataSize, averageTime, standardDeviation, sampleCount);
                std::cout << "Completed: Algorithm: " << sortAlgorithm.first << ", Data Variant: " << maxDataVariant.first << ", Size: " << dataSize << std::endl;
            }
        }
    }

    printSortingResults(results);
    auto now = std::chrono::system_clock::now();
    auto now_time_t = std::chrono::system_clock::to_time_t(now);
    std::tm now_tm = *std::localtime(&now_time_t);

    std::ostringstream outPutFileNameStream;
    outPutFileNameStream << "sorting_results_"
                         << std::put_time(&now_tm, "%Y-%m-%d_%H-%M-%S")
                         << ".csv";
    std::string outPutFileName = outPutFileNameStream.str();

    saveSortingResults(outPutFileName, results);
    std::system("afplay /System/Library/Sounds/Submarine.aiff -v 10;");
    return 0;
}
