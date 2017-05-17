//
// Created by Bartosz Cybulski on 08.05.2017.
//

#include "sudokuUnit.h"

int SudokuUnit::setMaxSize() {
    system(CLEAR);
    int maxSize;
    std::cout<<"Set maximum size of sudoku board.\nIt has to be from collection : <2,16>"<<std::endl;
    std::cin>>maxSize;
    while(maxSize > 16 || maxSize < 2 ){
        std::cout<<"Wrong maximum size. Choose number from <2,16>"<<std::endl;
        std::cin>>maxSize;
    }
    maxSize *= maxSize;
    std::cout<<"Grid size is "<<maxSize << "x" <<maxSize<<std::endl;
    return maxSize;
}

void SudokuUnit::setSudokuBoard(int size) {
    std::cout<<"Write sudoku board, size "<<maxSize_ << "x" <<maxSize_<<std::endl;
    std::cout<<"If cell must be empty type 0.\nIf you type number over maximum board size it will be changed to 0"<<std::endl;
    int n ;
    for(int i = 0 ; i < size ; i++){
        std::vector<int> row;
        for ( int j = 0 ; j < size ; j++){
            std::cin>>n;
            if(n > size || n < 0)
                row.push_back(0);
            else
                row.push_back(n);
        }
        sudokuBoard_.push_back(row);
    }
    return;
}

void SudokuUnit::writeSudokuBoard(){
    for(int i = 0 ; i < maxSize_ ; i++){
        for(int j = 0 ; j < maxSize_ ; j++){
            std::cout<<sudokuBoard_[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

void SudokuUnit::decodePhenotype() {
    int sizeOfSubgrid = sqrt(maxSize_);
    int subgridIterator;
    for(int i = 0 ; i < maxSize_ ; i++){
        generatedSudokuBoard_.push_back("");
    }
    for ( int i = 0 ; i < maxSize_ ; i++){
        std::string row;
        for( int j = 0 ; j < 2*sizeOfSubgrid ; j++){
            row.push_back(phenotype_[i][j]);
        }
        generatedSudokuBoard_[i] += row;
    }
    //TODO not working decoding phenotype and coding phenotype is not fully working
}

void SudokuUnit::setNote() {
    for(int i = 0 ; i < maxSize_ ; i++){
        int row[300];
        for(int j = 0 ; j < maxSize_ ; j++){
            row[generatedSudokuBoard_[i][j]]++;
            if(row[generatedSudokuBoard_[i][j]] > 1){
                note_++;
            }
        }
    }
    for(int i = 0 ; i < maxSize_ ; i++){
        int coulumn[300];
        for(int j = 0 ; j < maxSize_ ; j++){
            coulumn[generatedSudokuBoard_[j][i]]++;
            if(coulumn[generatedSudokuBoard_[j][i]] > 1){
                note_++;
            }
        }
    }

}

void SudokuUnit::crossSudokuUnit(SudokuUnit &sudokuUnit1, SudokuUnit &sudokuUnit2) {
    std::vector<std::string> left = sudokuUnit1.pushNumericPhenotype();
    std::vector<std::string> right = sudokuUnit1.pushNumericPhenotype();
    NumericPhenotype numericPhenotype;
    for( int  i = 0 ; i < sudokuUnit1.maxSize_ ; i++){
        phenotype_ = (numericPhenotype.crossPhenotype(left , right));
        decodePhenotype();
        setNote();
    }
}
