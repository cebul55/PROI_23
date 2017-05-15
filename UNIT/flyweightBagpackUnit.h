//
// Created by Bartosz Cybulski on 15.05.2017.
//

#ifndef PROI_23_FLYWEIGHTBAGPACKUNIT_H
#define PROI_23_FLYWEIGHTBAGPACKUNIT_H

#include "bagpackUnit.h"


class FlyweightBagpackUnit {
    int maxSize_;
    int numberOfItems_;
    int note_;
    std::string stringBagpack_;
    int setValueFlyweightBagpack(BagpackUnit , int , int , std::string);
public:
    FlyweightBagpackUnit(BagpackUnit bagpack):
            maxSize_(bagpack.pushMaxSize()),
            numberOfItems_(bagpack.pushNumberOfItems()){
        stringBagpack_ = bagpack.setStringBagpack(numberOfItems_);
        note_ = setValueFlyweightBagpack(bagpack , maxSize_ , numberOfItems_ , stringBagpack_);
    }
    void write(BagpackUnit);
};


#endif //PROI_23_FLYWEIGHTBAGPACKUNIT_H
