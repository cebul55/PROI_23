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

void SudokuUnit::writeGeneratedSudokuBoard(){
    for(int i = 0 ; i < maxSize_ ; i++){
        for(int j = 0 ; j < maxSize_ ; j++){
            std::cout<<generatedSudokuBoard_[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

void SudokuUnit::decodePhenotype() {
    int sizeOfSubgrid = sqrt(maxSize_);
    int lineIterator;
    std::vector<int> row;
    for(int i = 0 ; i < maxSize_ ; i++){
        generatedSudokuBoard_.push_back(row);
    }
    for(int i = 0 ; i < maxSize_ ; i++){
        int j = 0 , k = 0 , number;
        while ( j < maxSize_){
            lineIterator = j/sizeOfSubgrid +sizeOfSubgrid*(i/sizeOfSubgrid);
            std::string numberString;
            while(phenotype_[i][k] != '|'){
                numberString += phenotype_[i][k];
                k++;
            }
            number = takeNumberFromPhenotype(numberString);
            generatedSudokuBoard_[lineIterator].push_back(number);
            k++ ; j++;
        }
    }
}

int SudokuUnit::setNote() {
    int note = 0 , maxNumberOfRepetitions;
    int row[300];
    int column[300];
    maxNumberOfRepetitions = 2*(maxSize_ - 1)*maxSize_;
    for(int i = 0 ; i < maxSize_ ; i++){
        for( int j = 0 ; j <= maxSize_ ; j++)
            row[j] = 0;
        for(int j = 0 ; j < maxSize_ ; j++){
            row[generatedSudokuBoard_[i][j]]++;
            if(row[generatedSudokuBoard_[i][j]] > 1){
                note++;
            }
        }
    }
    for(int i = 0 ; i < maxSize_ ; i++){
        for( int k = 0 ; k <= maxSize_ ; k++)
            column[k] = 0;
        for(int j = 0 ; j < maxSize_ ; j++){
            column[generatedSudokuBoard_[j][i]]++;
            if(column[generatedSudokuBoard_[j][i]] > 1){
                note++;
            }
        }
    }
    return maxNumberOfRepetitions - note;
}

void SudokuUnit::crossSudokuUnit(SudokuUnit &sudokuUnit1, SudokuUnit &sudokuUnit2 , int maxSize) {
    std::vector<std::string> left = sudokuUnit1.pushNumericPhenotype();
    std::vector<std::string> right = sudokuUnit2.pushNumericPhenotype();
    NumericPhenotype numericPhenotype;
    phenotype_ = (numericPhenotype.crossPhenotype(left , right , maxSize));
}
int SudokuUnit::takeNumberFromPhenotype(std::string numberString) {
    int number = 0 , i = numberString.size()-1 , powerOfTen = 1;
    while( i >= 0){
        int add = numberString[i] - 48;
        number = number + powerOfTen*add;
        i--;
        powerOfTen *= 10;
    }
    return number;
}
