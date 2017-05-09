//
// Created by Bartosz Cybulski on 26.04.2017.
//

#include "random.h"

int Random::setValue() {
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(1,maxRandValue_);
    value_ = distribution(generator);
    return value_;
}