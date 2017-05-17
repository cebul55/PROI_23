//
// Created by Bartosz Cybulski on 15.05.2017.
//

#ifndef PROI_23_FLYWEIGHTSUDOKUUNIT_H
#define PROI_23_FLYWEIGHTSUDOKUUNIT_H

#include "../UNIT/sudokuUnit.h"

class FlyweightSudokuUnit:public SudokuUnit{
    int maxSize_;
    int note_;
    std::vector<std::string> phenotype_;
    std::vector <std::string> generatedSudokuBoard_;
public:

    FlyweightSudokuUnit(SudokuUnit *sudokuUnit):
            maxSize_(sudokuUnit->pushMaxSize()),
            phenotype_(sudokuUnit->pushNumericPhenotype()),
            note_(sudokuUnit->pushNote()),
            generatedSudokuBoard_(sudokuUnit->pushGeneratedSudoku()){}

    FlyweightSudokuUnit(FlyweightSudokuUnit left ,  FlyweightSudokuUnit right):
        maxSize_(left.maxSize_){
        crossFlyweightSudokuUnit(left , right);
    }
    void crossFlyweightSudokuUnit( FlyweightSudokuUnit &sudokuUnit1 , FlyweightSudokuUnit &sudokuUnit2);
};

#endif //PROI_23_FLYWEIGHTSUDOKUUNIT_H
