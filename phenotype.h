//
// Created by Bartosz Cybulski on 08.05.2017.
//

#ifndef PROI_23_PHENOTYPE_H
#define PROI_23_PHENOTYPE_H

#include "random.h"

class Phenotype{
    std::string phenotype_;
    int note_;
public:
    //TODO - krzyzowanie(binary proste , numeric n krzyzowan prostych , funkcja template?), konstruktor , destruktor,

    void writeNote(){
        std::cout<<note_<<std::endl;
        return;
    }
};

#endif //PROI_23_PHENOTYPE_H
