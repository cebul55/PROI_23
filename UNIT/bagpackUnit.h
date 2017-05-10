//
// Created by Bartosz Cybulski on 08.05.2017.
//

#ifndef PROI_23_BAGPACKUNIT_H
#define PROI_23_BAGPACKUNIT_H

#include <vector>
#include "../PHENOTYPE/binaryPhenotype.h"

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

    BagpackUnit(BagpackUnit *bagpack){
            maxSize_ = bagpack->maxSize_,
            numberOfItems_ = bagpack->numberOfItems_,
            items_ = bagpack->items_,
            values_ = bagpack->values_,
            stringBagpack_ = setStringBagpack(numberOfItems_),
            note_ = setValue(maxSize_, numberOfItems_ ,stringBagpack_ , items_ , values_);
    }
//crossing konstructor
    BagpackUnit(BagpackUnit &bagpack1 , BagpackUnit &bagpack2):
            maxSize_(bagpack1.maxSize_),
            numberOfItems_(bagpack1.numberOfItems_),
            items_(bagpack1.items_),
            values_(bagpack1.values_){
            crossMutateBagpack(bagpack1 , bagpack2);
    }

    std::string pushPhenotype(){
        return stringBagpack_;
    }
    void write();
    int pushNote(){
        return note_;
    }
    void writeSpecyficBagpack();
    void writeNote(){
        std::cout<<note_<<std::endl;
    }
    void crossMutateBagpack(BagpackUnit &bagpack1 , BagpackUnit &bagpack2);
};

#endif //PROI_23_BAGPACKUNIT_H
