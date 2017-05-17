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
    std::vector <std::string> generatedSudokuBoard_;
    int setMaxSize();
    void setSudokuBoard(int);
    void setNote();
public:
    SudokuUnit(){
            maxSize_ = setMaxSize(),
            setSudokuBoard(maxSize_);
            NumericPhenotype phenotype(sudokuBoard_, maxSize_);
            phenotype_ = phenotype.giveNumericPhenotype();
            decodePhenotype();
            setNote();
    }
    void decodePhenotype();
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
