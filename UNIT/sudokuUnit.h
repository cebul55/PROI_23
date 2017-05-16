//
// Created by Bartosz Cybulski on 08.05.2017.
//

#ifndef PROI_23_SUDOKUUNIT_H
#define PROI_23_SUDOKUUNIT_H

#include "unit.h"

class SudokuUnit: public Unit{
    int maxSize_;
    int note_;
    std::vector < std::vector <int> > sudokuBoard_;
    int setMaxSize();
    void setSudokuBoard(int);
public:
    SudokuUnit(){
            maxSize_ = setMaxSize(),
            setSudokuBoard(maxSize_);
    }
    void writeSudokuBoard();
};

#endif //PROI_23_SUDOKUUNIT_H
