//
// Created by Bartosz Cybulski on 15.05.2017.
//

#include "flyweightSudokuUnit.h"
void FlyweightSudokuUnit::crossFlyweightSudokuUnit(FlyweightSudokuUnit &sudokuUnit1, FlyweightSudokuUnit &sudokuUnit2) {
    std::vector<std::string> left = sudokuUnit1.pushNumericPhenotype();
    std::vector<std::string> right = sudokuUnit1.pushNumericPhenotype();
    NumericPhenotype numericPhenotype;
    for( int  i = 0 ; i < sudokuUnit1.maxSize_ ; i++){
        phenotype_ = (numericPhenotype.crossPhenotype(left , right , sudokuUnit1.maxSize_));
        decodePhenotype();
        setNote();
    }
}