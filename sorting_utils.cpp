//
// Created by AnGa on 2023-03-30.
//

#include "sorting_utils.h"
#include "sorting.h"
#include <iostream>


void runInsertionSort(data_t &vec){
    std::cout << "Insertion sort: "<< std::endl;
    print(vec);
    insertionSort(vec);
    print(vec);
    std::cout << std::endl;
}
void runSelectionSort(data_t &vec){
    std::cout << "Selection sort: "<< std::endl;
    print(vec);
    selectionSort(vec);
    print(vec);
    std::cout << std::endl;
}
void runQuickSortRightPivot(data_t &vec){
    std::cout << "Quick sort Right: "<< std::endl;
    print(vec);
    quick_sort(vec, 0, vec.size() - 1, partition_right);
    print(vec);
    std::cout << std::endl;
}
void runQuickSortMedianOfThreePivot(data_t &vec){
    std::cout << "Quick sort Mo3: "<< std::endl;
    print(vec);
    quick_sort(vec, 0, vec.size() - 1, partition_median_of_three);
    print(vec);
    std::cout << std::endl;
}

void runAllSortings(data_t &vec){
    data_t is = vec;
    data_t ss = vec;
    data_t qsr = vec;
    data_t qsm = vec;
    runInsertionSort(is);
    runSelectionSort(ss);
    runQuickSortRightPivot(qsr);
    runQuickSortMedianOfThreePivot(qsm);
}

void print(const data_t& vector){
    for (auto element: vector) {
        std::cout.width(3); std::cout <<std::left << element << " " ;
    }
    std::cout << std::endl;
}