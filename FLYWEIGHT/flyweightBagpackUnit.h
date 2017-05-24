//
// Created by Bartosz Cybulski on 15.05.2017.
//

#ifndef PROI_23_FLYWEIGHTBAGPACKUNIT_H
#define PROI_23_FLYWEIGHTBAGPACKUNIT_H

#include "../Unit/bagpackUnit.h"


class FlyweightBagpackUnit{
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
    FlyweightBagpackUnit(FlyweightBagpackUnit flyweight1 , FlyweightBagpackUnit flyweight2 , BagpackUnit bagpack):
    maxSize_(flyweight1.maxSize_),
    numberOfItems_(flyweight1.numberOfItems_){
        crossMutateFlyweightBagpack(flyweight1 , flyweight2);
        note_ = setValueFlyweightBagpack(bagpack , maxSize_ , numberOfItems_ , stringBagpack_);
    }
    void crossMutateFlyweightBagpack(FlyweightBagpackUnit &bagpack1 , FlyweightBagpackUnit &bagpack2);
    int pushNote(){
        return note_;
    }
    std::string pushPhenotype(){
        return stringBagpack_;
    }
    void write(BagpackUnit);
};


#endif //PROI_23_FLYWEIGHTBAGPACKUNIT_H
