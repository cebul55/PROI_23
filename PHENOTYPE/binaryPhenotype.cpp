//
// Created by Bartosz Cybulski on 08.05.2017.
//

#include "binaryPhenotype.h"

void BinaryPhenotype::generatePhenotype(int n) {
    Random generateBinary(2);
    for(int i = 0 ; i < n ; i++){
        generateBinary.setValue();
        int binaryValue = generateBinary.pushValue();
        switch (binaryValue) {
            case 1:
                binaryPhenotype_ = binaryPhenotype_ + "0";
                break;
            case 2:
                binaryPhenotype_ = binaryPhenotype_ + "1";
                break;
            default:
                break;
        }
    }
    return;
}

void BinaryPhenotype::mutatePhenotype() {
    Random generateNumber(maxSize_);
    generateNumber.setValue();
    int n = generateNumber.pushValue();
    if (binaryPhenotype_[n] == '0') {
        binaryPhenotype_[n] = '1';
    } else
        binaryPhenotype_[n] = '0';
    return ;
}

std::string BinaryPhenotype::crossPhenotypeLeftFirst(BinaryPhenotype *leftParent, BinaryPhenotype *rightParent) {
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