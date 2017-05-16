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