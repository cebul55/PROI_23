//
// Created by Bartosz Cybulski on 15.05.2017.
//

#include "flyweightSudokuUnit.h"
void FlyweightSudokuUnit::crossFlyweightSudokuUnit(FlyweightSudokuUnit &sudokuUnit1, FlyweightSudokuUnit &sudokuUnit2) {
    std::vector<std::string> left = sudokuUnit1.pushNumericPhenotype();
    std::vector<std::string> right = sudokuUnit1.pushNumericPhenotype();
    NumericPhenotype numericPhenotype;
    phenotype_ = (numericPhenotype.crossPhenotype(left , right , sudokuUnit1.maxSize_));
}

void FlyweightSudokuUnit::write(SudokuUnit &sudoku) {
    if(File::getInstanceFile().isOpenSudoku() == 1 ){
        File::getInstanceFile().sudoku_<<"Sudoku maximum size : "<< maxSize_<<std::endl;
        writeGeneratedSudokuBoard();
        File::getInstanceFile().sudoku_<<"Note: "<<note_<<std::endl;
    }
    else{
        std::cout<<"Sudoku maximum size : "<< maxSize_<<std::endl;
        writeGeneratedSudokuBoard();
        std::cout<<std::endl<<"Note: "<<note_<<std::endl;
        sudoku.writeSudokuBoard();
    }
    return;
}

void FlyweightSudokuUnit::decodePhenotype() {
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

int FlyweightSudokuUnit::setNote() {
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

void FlyweightSudokuUnit::writeGeneratedSudokuBoard() {
    if(File::getInstanceFile().isOpenSudoku() == 1){
        for(int i = 0 ; i < maxSize_ ; i++){
            for(int j = 0 ; j < maxSize_ ; j++){
                File::getInstanceFile().sudoku_<<generatedSudokuBoard_[i][j]<<" ";
            }
            File::getInstanceFile().sudoku_<<std::endl;
        }
    }
    for(int i = 0 ; i < maxSize_ ; i++){
        for(int j = 0 ; j < maxSize_ ; j++){
            std::cout<<generatedSudokuBoard_[i][j]<<" ";
        }
        std::cout<<std::endl;
    }
}

int FlyweightSudokuUnit::takeNumberFromPhenotype(std::string numberString) {
    int number = 0 , i = numberString.size() - 1 , powerOfTen = 1;
    while( i >= 0){
        int add = numberString[i] - 48;
        number = number + powerOfTen*add;
        i--;
        powerOfTen *= 10;
    }
    return number;
}

std::vector<std::string> FlyweightSudokuUnit::generatePhenotype(SudokuUnit sudokuUnit, int maxSize) {
    NumericPhenotype *phenotype = new NumericPhenotype(sudokuUnit.pushSudokuBoard(), maxSize);
    return phenotype->giveNumericPhenotype();
}
