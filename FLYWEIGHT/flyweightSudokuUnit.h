//
// Created by Bartosz Cybulski on 15.05.2017.
//

#ifndef PROI_23_FLYWEIGHTSUDOKUUNIT_H
#define PROI_23_FLYWEIGHTSUDOKUUNIT_H

#include "../UNIT/sudokuUnit.h"

class FlyweightSudokuUnit{
    int maxSize_;
    int note_;
    std::vector<std::string> phenotype_;
    std::vector<std::vector<int> > generatedSudokuBoard_;
    std::vector<std::string> generatePhenotype(SudokuUnit , int);
public:

    FlyweightSudokuUnit(SudokuUnit sudokuUnit1):
            maxSize_(sudokuUnit1.pushMaxSize()){
//        NumericPhenotype phenotype(sudokuUnit1.pushSudokuBoard(), sudokuUnit1.pushMaxSize());
//        //phenotype_ = phenotype->giveNumericPhenotype();
//        for( int  i = 0 ; i < maxSize_ ; i++){
//            phenotype_.push_back(phenotype.giveRowOfNumericPhenotype(i));
//        }
        phenotype_ = generatePhenotype(sudokuUnit1 , maxSize_);
        assert(&phenotype_ != NULL);
        decodePhenotype();
        note_ = setNote();
    }

   FlyweightSudokuUnit(FlyweightSudokuUnit left ,  FlyweightSudokuUnit right , SudokuUnit *sudokuUnit):
        maxSize_(left.maxSize_){
       crossFlyweightSudokuUnit(left , right);
       decodePhenotype();
       note_ = setNote();
    }

    void crossFlyweightSudokuUnit( FlyweightSudokuUnit &sudokuUnit1 , FlyweightSudokuUnit &sudokuUnit2);
    void write(SudokuUnit&);
    int takeNumberFromPhenotype(std::string numberString);
    void decodePhenotype();
    int setNote();
    std::vector<std::string> pushNumericPhenotype(){
        return phenotype_;
    }
    int pushNote(){
            return note_;
    };
    void writeGeneratedSudokuBoard();
};

#endif //PROI_23_FLYWEIGHTSUDOKUUNIT_H
