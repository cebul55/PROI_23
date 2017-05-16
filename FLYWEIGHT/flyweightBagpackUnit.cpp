//
// Created by Bartosz Cybulski on 15.05.2017.
//

#include "flyweightBagpackUnit.h"
#define ONEPROCENT 100

int FlyweightBagpackUnit::setValueFlyweightBagpack(BagpackUnit bagpack, int maxSize , int  numberOfItems, std::string phenotype) {
    int size = 0 , value = 0 ;
    for (int i = 0 ; i < numberOfItems ;i++){
        if(phenotype[i] == '1'){
            size += bagpack.items_[i];
            value += bagpack.values_[i];
        }
    }
    if(size <= maxSize)
        return value;
    else
        return 0;

}

void FlyweightBagpackUnit::write(BagpackUnit bagpack) {
    std::cout<<"Bagpack maximum size : "<< maxSize_<<std::endl;
    for(int i = 0 ; i<numberOfItems_;i++){
        std::cout<<"no. "<<i<<" size: "<<bagpack.items_[i]<<" value: "<<bagpack.values_[i]<<std::endl;
    }
    std::cout<<"Phenotype "<<stringBagpack_<<std::endl;
    std::cout<<"Note: "<<note_<<std::endl;
    return;
}

void FlyweightBagpackUnit::crossMutateFlyweightBagpack(FlyweightBagpackUnit &flyweight1, FlyweightBagpackUnit &flyweight2) {
    BinaryPhenotype left(flyweight1.pushPhenotype());
    BinaryPhenotype right(flyweight1.pushPhenotype());
    stringBagpack_=left.crossPhenotypeLeftFirst(&left, &right);
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

