//
// Created by Bartosz Cybulski on 08.05.2017.
//

#ifndef PROI_23_BAGPACKUNIT_H
#define PROI_23_BAGPACKUNIT_H

#include <vector>
#include "unit.h"

class BagpackUnit{
    int maxSize_;
    int numberOfItems_;
    int note_;
    std::string stringBagpack_;
    std::vector<int> items_;
    std::vector<int> values_;
    int setMaxSize();
    int setNumberOfItems();
    void setSizeValueOfItems(int);
    std::string setStringBagpack(int);
    int setValue(int , int , std::string , std::vector<int> , std::vector<int> );
public:
    BagpackUnit(int maxSize ,int numberOfItems, std::vector<int> items , std::vector<int> values) :
            numberOfItems_(numberOfItems),
            maxSize_(maxSize),
            items_(items),
            values_(values){
            stringBagpack_ = setStringBagpack(numberOfItems_),
            note_ = setValue(maxSize_, numberOfItems_, stringBagpack_ , items_ , values_);
    }

    BagpackUnit():
            numberOfItems_(setNumberOfItems()),
            maxSize_(setMaxSize()){
            setSizeValueOfItems(numberOfItems_);
            stringBagpack_ = setStringBagpack(numberOfItems_);
            note_ = setValue(maxSize_, numberOfItems_ ,stringBagpack_ , items_ , values_);
    }

    BagpackUnit(BagpackUnit &bagpack){
            maxSize_ = bagpack.maxSize_,
            numberOfItems_ = bagpack.numberOfItems_,
            items_ = bagpack.items_,
            values_ = bagpack.values_,
            stringBagpack_ = setStringBagpack(numberOfItems_),
            note_ = setValue(maxSize_, numberOfItems_ ,stringBagpack_ , items_ , values_);
    }

    void writeBagpack();
    int pushNote(){
        return note_;
    }
    void writeSpecyficBagpack();
    void writeNote(){
        std::cout<<note_<<std::endl;
    }
};

#endif //PROI_23_BAGPACKUNIT_H
