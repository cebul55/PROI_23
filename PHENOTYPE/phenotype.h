//
// Created by Bartosz Cybulski on 08.05.2017.
//

#ifndef PROI_23_PHENOTYPE_H
#define PROI_23_PHENOTYPE_H

#include "random.h"

class Phenotype{
    std::string phenotype_;
    int size_;
public:
    //TODO - krzyzowanie(binary proste , numeric n krzyzowan prostych , funkcja template?), konstruktor , destruktor,

    virtual void writePhenotype(){
        std::cout<<phenotype_<<std::endl;
        return;
    }

    virtual void writeSize(){
        std::cout<<size_<<std::endl;
    }
};

#endif //PROI_23_PHENOTYPE_H
