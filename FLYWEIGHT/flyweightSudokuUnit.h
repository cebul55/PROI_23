//
// Created by Bartosz Cybulski on 15.05.2017.
//

#ifndef PROI_23_FLYWEIGHTSUDOKUUNIT_H
#define PROI_23_FLYWEIGHTSUDOKUUNIT_H

#include "../UNIT/sudokuUnit.h"

class FlyweightSudokuUnit:public SudokuUnit {
    int maxSize_;
    int note_;
    std::vector<std::string> phenotype_;
    std::vector<std::vector<int> > generatedSudokuBoard_;
public:

    FlyweightSudokuUnit(SudokuUnit *sudokuUnit1):
            maxSize_(sudokuUnit1->pushMaxSize()){
        NumericPhenotype phenotype(sudokuUnit1->pushSudokuBoard(), maxSize_);
        phenotype_ = phenotype.giveNumericPhenotype();
        decodePhenotype();
        setNote();
    }



   FlyweightSudokuUnit(FlyweightSudokuUnit left ,  FlyweightSudokuUnit right):
        maxSize_(left.maxSize_){
        crossFlyweightSudokuUnit(left , right);
    }
    void crossFlyweightSudokuUnit( FlyweightSudokuUnit &sudokuUnit1 , FlyweightSudokuUnit &sudokuUnit2);
    void write(SudokuUnit);
};

#endif //PROI_23_FLYWEIGHTSUDOKUUNIT_H
