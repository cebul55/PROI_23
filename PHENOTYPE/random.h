//
// Created by Bartosz Cybulski on 26.04.2017.
//

#ifndef PROI_23_RANDOM_H
#define PROI_23_RANDOM_H

#include <iostream>
#include <string>
#include <random>
#include <cstdlib>
#include <cassert>

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

#define MAX_RAND 2
#define INITIAL_VALUE 0



class Random{
    int value_;
    int maxRandValue_;
public:
    Random() : maxRandValue_(MAX_RAND),
               value_(INITIAL_VALUE){};

    Random(int maxRandValue): maxRandValue_(maxRandValue),
                              value_(INITIAL_VALUE){};

    int setValue();

    void writeValue(){
        std::cout<<value_<<std::endl;
    }

    int pushValue(){
        return value_;
    }




};

#endif //PROI_23_RANDOM_H
