//
// Created by Bartosz Cybulski on 08.05.2017.
//
#include "phenotype.h"


std::string Phenotype::crossPhenotypeLeftFirst(Phenotype *leftParent, Phenotype *rightParent) {
    assert(leftParent->giveSize()==rightParent->giveSize());
    Random generateNumber(leftParent->giveSize() - 1);
    generateNumber.setValue();
    std::string newPhenotype;
    std::string leftPhenotype = leftParent->givePhenotype();
    std::string rightPhenotype = rightParent->givePhenotype();
    //generateNumber.writeValue();
    newPhenotype = leftPhenotype.substr(0,generateNumber.pushValue());
    newPhenotype += rightPhenotype.substr(generateNumber.pushValue(),leftParent->giveSize());
    assert(leftParent->giveSize()==newPhenotype.size());
    return newPhenotype;
}


std::string Phenotype::crossPhenotypeRigthFirst(Phenotype *leftParent, Phenotype *rightParent) {
    assert(leftParent->giveSize()!=rightParent->giveSize());
    Random generateNumber(leftParent->giveSize() - 1);
    generateNumber.setValue();
    std::string newPhenotype;
    std::string leftPhenotype = leftParent->givePhenotype();
    std::string rightPhenotype = rightParent->givePhenotype();
    newPhenotype = rightPhenotype.substr(0,generateNumber.pushValue());
    newPhenotype += leftPhenotype.substr(generateNumber.pushValue(),leftParent->giveSize());
    return newPhenotype;
}
