//
// Created by Bartosz Cybulski on 08.05.2017.
//

#include "bagpackUnit.h"
#define ONEPROCENT 100

int BagpackUnit::setNumberOfItems() {
    system(CLEAR);
    int numberOfItems;
    std::cout<<"How many items you want to add:"<<std::endl;
    std::cin>>numberOfItems;
    return numberOfItems;
}

int BagpackUnit::setMaxSize() {
    system(CLEAR);
    int maxSize;
    std::cout<<"Set maximum size of bagpack"<<std::endl;
    std::cin>>maxSize;
    return maxSize;
}

void BagpackUnit::setSizeValueOfItems(int n) {
    system(CLEAR);
    std::cout<<"Set size and value of an elements:"<<std::endl;
    int s , v;
    for(int i = 0 ; i<n ; i++){
        std::cin>>s>>v;
        items_.push_back(s);
        this->values_.push_back(v);
    }
    return;
}

void BagpackUnit::writeBagpack() {
    system(CLEAR);
    std::cout<<"Bagpack size : "<< maxSize_<<std::endl;
    for(int i = 0 ; i<numberOfItems_;i++){
        std::cout<<"no. "<<i<<" size: "<<items_[i]<<" value: "<<values_[i]<<std::endl;
    }
    std::cout<<"Phenotype "<<stringBagpack_<<std::endl;
    std::cout<<"Note: "<<note_<<std::endl;
    return;
}

std::string BagpackUnit::setStringBagpack(int n) {
    BinaryPhenotype phenotype(n);
    return phenotype.pushBinaryPhenotype();
}

int BagpackUnit::setValue(int maxSize,int numberOfItems , std::string phenotype, std::vector<int> items, std::vector<int> values) {
    int value = 0 ;
    int size = 0;
    for (int i = 0 ; i < numberOfItems ;i++){
        if(phenotype[i] == '1'){
            size += items[i];
            value += values[i];
        }
    }
    if(size <= maxSize)
        return value;
    else
        return 0;

}

void BagpackUnit::writeSpecyficBagpack() {
        std::cout<<"Bagpack size : "<< maxSize_<<std::endl;
        for(int i = 0 ; i<numberOfItems_;i++){
            if(stringBagpack_[i] == '1')
            std::cout<<"no. "<<i<<" size: "<<items_[i]<<" value: "<<values_[i]<<std::endl;
        }
        std::cout<<"Phenotype "<<stringBagpack_<<std::endl;
        std::cout<<"Note: "<<note_<<std::endl;
        return;
}

void BagpackUnit::crossMutateBagpack(BagpackUnit &bagpack1 , BagpackUnit &bagpack2){
    BinaryPhenotype left(bagpack1.pushPhenotype());
    BinaryPhenotype right(bagpack2.pushPhenotype());
    stringBagpack_=left.crossPhenotypeLeftFirst(&left, &right);
    note_ = setValue(maxSize_, numberOfItems_ ,stringBagpack_ , items_ , values_);
    //MUTATE
    Random generateNumber(ONEPROCENT);
    generateNumber.setValue();
    if(generateNumber.pushValue()==ONEPROCENT){
        BinaryPhenotype mutate(stringBagpack_);
        mutate.mutatePhenotype();
        stringBagpack_= mutate.givePhenotype();
        std::cout<<"MUTATED"<<std::endl;
    }
     return;
}