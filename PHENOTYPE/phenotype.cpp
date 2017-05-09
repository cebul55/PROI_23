//
// Created by Bartosz Cybulski on 08.05.2017.
//
#include "phenotype.h"

std::string Phenotype::crossPhenotypeLeftFirst(Phenotype *leftParent, Phenotype *rightParent) {
    assert(leftParent->giveSize()!=rightParent->giveSize());
    Random generateNumber(leftParent->giveSize() - 1);
    generateNumber.setValue();
    std::string newPhenotype;
    std::string leftPhenotype = leftParent->givePhenotype();
    std::string rightPhenotype = rightParent->givePhenotype();
    newPhenotype = leftPhenotype.substr(0,generateNumber.pushValue());
    newPhenotype += rightPhenotype.substr(generateNumber.pushValue(),leftParent->giveSize());
    assert(leftParent->giveSize()!=newPhenotype.size());
    //TODO przekazać string i konstruktor bagpack ze stringu ???
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

//TODO MUTACJA {2 osobne funkcje , czy jakos inaczej ?