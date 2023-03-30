//
// Created by AnGa on 2023-03-30.
//

#ifndef LABB2_SORTING_UTILS_H
#define LABB2_SORTING_UTILS_H

#include <vector>
using data_t = std::vector<int>;

void print(const data_t& vector);
void runAllSortings( data_t &vec);
void runInsertionSort(data_t &vec);
void runSelectionSort(data_t &vec);
void runQuickSortRightPivot(data_t &vec);
void runQuickSortMedianOfThreePivot(data_t &vec);


#endif //LABB2_SORTING_UTILS_H
