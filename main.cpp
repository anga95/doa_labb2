#include <iostream>
#include "datagenerate.h"
#include "sorting.h"
#include "sorting_utils.h"

int main() {
    std::srand(std::time(nullptr));
    size_t size = 100;
    data_t femtal = {3, 1, 4, 2, 5};
    data_t random = generate_rand_data(size);
    data_t ascending = generate_ascending_data(size);
    data_t descending = generate_descending_data(size);
    data_t consValue = generate_const_value_data(size, 3);

    runAllSortings(random);

    std::cout <<std::endl<< "Hello, World!" << std::endl;
    return 0;
}




// insertion sort
// https://en.wikipedia.org/wiki/Insertion_sort#List_insertion_sort_code_in_C
//
//