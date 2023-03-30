//
// Created by AnGa on 2023-03-30.
//

#include <fstream>
#include <iostream>
#include "data_reporting.h"

void saveSortingResults(const std::string& filename, const std::vector<SortingResult>& results){
    std::ofstream outPutFile(filename);

    outPutFile << "Algorithm,Data size,Time taken(ms),Stdev(ms),Samples,datapattern" << std::endl;
    for (const SortingResult& result : results) {
        outPutFile << result.algorithmName << ","
                    << result.dataSize << ","
                    << result.timeTaken * 1000.0<< ","
                    << result.standardDeviation * 1000.0 << ","
                    << result.sampleCount << ","
                    << result.dataPattern
                    << std::endl;
    }
    outPutFile.close();
    std::cout << "results saved to: " << filename << std::endl;
}


void printSortingResults(const std::vector<SortingResult>& results) {
    std::cout << std::left << std::setw(25) << "Algorithm"
              << std::setw(12) << "Data size"
              << std::setw(18) << "Time taken[ms]"
              << std::setw(15) << "Stdev[ms]"
              << std::setw(10) << "Samples" << std::endl;

    for (const SortingResult& result : results) {
        std::cout << std::left << std::setw(25) << result.algorithmName
                  << std::setw(12) << result.dataSize
                  << std::setw(18) << result.timeTaken * 1000.0
                  << std::setw(15) << result.standardDeviation * 1000.0
                  << std::setw(10) << result.sampleCount
                  << std::setw(12) << result.dataPattern << std::endl;
    }
}