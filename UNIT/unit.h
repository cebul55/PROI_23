//
// Created by Bartosz Cybulski on 15.05.2017.
//

#ifndef PROI_23_UNIT_H
#define PROI_23_UNIT_H

#include <vector>
#include "../PHENOTYPE/binaryPhenotype.h"
#include "../PHENOTYPE/numericPhenotype.h"

class Unit{
    int maxSize_;
    int note_;
    std::string phenotype_;
public:
    virtual int setMaxSize(){
        int size = 0;
        return size;
    }
    virtual std::string pushPhenotype(){
        return  phenotype_;
    }
    virtual int pushMaxSize(){
        return  maxSize_;
    }
    virtual int pushNote(){
        return note_;
    }
};

#endif //PROI_23_UNIT_H
