//
// Created by AnGa on 2022-05-05.
//

#include "datagenerate.h"
#include <algorithm>

data_t generate_rand_data(size_t size){
    data_t vector;
    for (size_t value = 0; value < size; value++) {
        vector.push_back(rand() % size + 1);
    }
    return vector;
}

data_t generate_ascending_data(size_t size){
    data_t vector;
    for (size_t value = 0; value < size; value++) { vector.push_back(value); }
    return vector;
}
// ÖSNAG ELRRA HAKUP ELLIN LKAID TEIOF TFENN AMRTÄ YHNKK GILGT
// OUNOT RENNN CSPDK ELERS DVOAV MDFSM ÄAGTA SNTCE PÖDDO RYEROG SHT
data_t generate_descending_data(size_t size){
    data_t vector = generate_ascending_data(size);
    std::reverse(vector.begin(), vector.end());
    return vector;
}

data_t generate_const_value_data(size_t size, int value){
    return data_t(size,value);
}