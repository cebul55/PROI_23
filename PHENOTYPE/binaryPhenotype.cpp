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