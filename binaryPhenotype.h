//
// Created by Bartosz Cybulski on 08.05.2017.
//

#ifndef PROI_23_BINARYPHENOTYPE_H
#define PROI_23_BINARYPHENOTYPE_H

#include "phenotype.h"

class BagpackUnit;

class BinaryPhenotype: public Phenotype{
    int maxSize_;
    std::string binaryPhenotype_;
    void generatePhenotype(int);
public:
    BinaryPhenotype(int maxSize):maxSize_(maxSize){
        generatePhenotype(maxSize_);
    }

    std::string pushBinaryPhenotype(){
        return binaryPhenotype_;
    }
 };

#endif //PROI_23_BINARYPHENOTYPE_H
