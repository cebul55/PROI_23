//
// Created by Bartosz Cybulski on 08.05.2017.
//

#ifndef PROI_23_SUDOKUUNIT_H
#define PROI_23_SUDOKUUNIT_H

#include "unit.h"

class SudokuUnit: public Unit{
    int maxSize_;
    int note_;
    std::vector<std::string> phenotype_;
    std::vector < std::vector <int> > sudokuBoard_;
    int setMaxSize();
    void setSudokuBoard(int);
public:
    SudokuUnit(){
            maxSize_ = setMaxSize(),
            setSudokuBoard(maxSize_);
            NumericPhenotype phenotype(sudokuBoard_, maxSize_);
            phenotype_ = phenotype.giveNumericPhenotype();
    }
    void writePhenotype(){
        for( int i = 0 ; i < maxSize_; i++){
            for ( int j = 0 ; j < phenotype_[i].size() ; j++){
                std::cout<<phenotype_[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
    }
    void writeSudokuBoard();
    //TODO algorithm setNote()
};

#endif //PROI_23_SUDOKUUNIT_H
