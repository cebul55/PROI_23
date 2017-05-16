//
// Created by Bartosz Cybulski on 08.05.2017.
//

#ifndef PROI_23_BINARYPHENOTYPE_H
#define PROI_23_BINARYPHENOTYPE_H

#include "phenotype.h"


class BinaryPhenotype: public Phenotype{
    int maxSize_;
    std::string binaryPhenotype_;
    void generatePhenotype(int);
public:
    BinaryPhenotype(std::string phenotype):
        binaryPhenotype_(phenotype){
        maxSize_ = phenotype.size();
    }

    BinaryPhenotype(int maxSize): maxSize_(maxSize){
        generatePhenotype(maxSize_);
    }

    std::string pushBinaryPhenotype(){
        return binaryPhenotype_;
    }

    virtual void writePhenotype(){
        std::cout<<binaryPhenotype_<<std::endl;
    }

    virtual void writeSize(){
        std::cout<<maxSize_<<std::endl;
    }

    virtual int giveSize(){
        return maxSize_;
    }

    std::string givePhenotype(){
        return binaryPhenotype_;
    };

    void mutatePhenotype();

 };

#endif //PROI_23_BINARYPHENOTYPE_H
