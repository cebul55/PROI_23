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
    std::vector <std::vector<int> > generatedSudokuBoard_;
    int setMaxSize();
    void setSudokuBoard(int);
    int takeNumberFromPhenotype(std::string);

public:
    SudokuUnit(){
            maxSize_ = setMaxSize(),
            setSudokuBoard(maxSize_);
            NumericPhenotype phenotype(sudokuBoard_, maxSize_);
            phenotype_ = phenotype.giveNumericPhenotype();
            decodePhenotype();
            note_ = setNote();
    }
    SudokuUnit(std::vector<std::vector<int> > board , int maxSize ):
    maxSize_(maxSize),
    sudokuBoard_(board){
        NumericPhenotype phenotype(sudokuBoard_ , maxSize_);
        phenotype_ = phenotype.giveNumericPhenotype();
        decodePhenotype();
        note_ = setNote();
    }
    SudokuUnit(std::vector<std::string> phenotype):
    phenotype_(phenotype),
    maxSize_(phenotype[0].size()){
        decodePhenotype();
        note_ = setNote();
    }
    SudokuUnit(SudokuUnit const &sudoku){
        maxSize_ = sudoku.maxSize_;
        note_ = sudoku.note_;
        phenotype_ = sudoku.phenotype_;
        sudokuBoard_ = sudoku.sudokuBoard_;
        generatedSudokuBoard_ = sudoku.generatedSudokuBoard_;
    }
    SudokuUnit(SudokuUnit left , SudokuUnit right ){
        maxSize_ = left.pushMaxSize();
        crossSudokuUnit(left , right , left.maxSize_);
        decodePhenotype();
        note_ = setNote();
    }

    std::vector <std::vector<int> > pushGeneratedSudoku(){
        return generatedSudokuBoard_;
    }
    std::vector < std::vector <int> > pushSudokuBoard(){
        return sudokuBoard_;
    }
    int setNote();
    void decodePhenotype();
    void writePhenotype(){
        for( int i = 0 ; i < maxSize_; i++){
            for ( int j = 0 ; j < phenotype_[i].size() ; j++){
                std::cout<<phenotype_[i][j]<<" ";
            }
            std::cout<<std::endl;

        }
    }
    std::vector<std::string> pushNumericPhenotype(){
        return phenotype_;
    }
    void writeSudokuBoard();
    void writeGeneratedSudokuBoard();
    void crossSudokuUnit( SudokuUnit &sudokuUnit1 , SudokuUnit &sudokuUnit2 , int);
    virtual int pushMaxSize(){
        return maxSize_;
    }
    virtual int pushNote(){
        return  note_;
    }
};

#endif //PROI_23_SUDOKUUNIT_H
