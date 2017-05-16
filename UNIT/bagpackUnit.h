//
// Created by Bartosz Cybulski on 08.05.2017.
//

#ifndef PROI_23_BAGPACKUNIT_H
#define PROI_23_BAGPACKUNIT_H

#include "unit.h"

class BagpackUnit: public Unit{
    int maxSize_;
    int numberOfItems_;
    int note_;
    std::string phenotype_;
    virtual int setMaxSize();
    int setNumberOfItems();
    void setSizeValueOfItems(int);
    virtual int setValue(int , int , std::string , std::vector<int> , std::vector<int> );
public:
    std::vector<int> items_;
    std::vector<int> values_;

    BagpackUnit(int maxSize ,int numberOfItems, std::vector<int> items , std::vector<int> values) :
            numberOfItems_(numberOfItems),
            maxSize_(maxSize),
            items_(items),
            values_(values){
            phenotype_ = setStringBagpack(numberOfItems_),
            note_ = setValue(maxSize_, numberOfItems_, phenotype_ , items_ , values_);
    }

    BagpackUnit():
            numberOfItems_(setNumberOfItems()),
            maxSize_(setMaxSize()){
            setSizeValueOfItems(numberOfItems_);
            phenotype_ = setStringBagpack(numberOfItems_);
            note_ = setValue(maxSize_, numberOfItems_ ,phenotype_ , items_ , values_);
    }

    BagpackUnit(BagpackUnit *bagpack){
            maxSize_ = bagpack->maxSize_,
            numberOfItems_ = bagpack->numberOfItems_,
            items_ = bagpack->items_,
            values_ = bagpack->values_,
            phenotype_ = setStringBagpack(numberOfItems_),
            note_ = setValue(maxSize_, numberOfItems_ ,phenotype_ , items_ , values_);
    }
//crossing konstructor
    BagpackUnit(BagpackUnit &bagpack1 , BagpackUnit &bagpack2):
            maxSize_(bagpack1.maxSize_),
            numberOfItems_(bagpack1.numberOfItems_),
            items_(bagpack1.items_),
            values_(bagpack1.values_){
            crossMutateBagpack(bagpack1 , bagpack2);
    }
    int pushMaxSize(){
        return maxSize_;
    }
    int pushNumberOfItems(){
        return numberOfItems_;
    }
    virtual std::string pushPhenotype(){
        return phenotype_;
    }
    void write();
    int pushNote(){
        return note_;
    }
    void writeSpecyficBagpack();
    void writeNote(){
        std::cout<<note_<<std::endl;
    }
    std::string setStringBagpack(int);
    void crossMutateBagpack(BagpackUnit &bagpack1 , BagpackUnit &bagpack2);
};

#endif //PROI_23_BAGPACKUNIT_H
