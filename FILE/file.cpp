//
// Created by Bartosz Cybulski on 25.05.2017.
//

#include "file.h"

int File::readBoardSize(){
    int maxSize;
    sudoku_ >> maxSize;
    return maxSize*maxSize;
}

std::vector<std::vector<int> > File::readSudokuBoard(int size) {
    std::vector<std::vector<int> > board;
    for(int i = 0 ; i < size; i++){
        std::vector<int> row;
        for(int j = 0 ; j < size ; j++){
            int number;
            sudoku_>>number;
            row.push_back(number);
        }
        board.push_back(row);
    }
    return board ;
}

int File::readSizeOfSudokuPopulation() {
    int sizeOfPoulation;
    sudoku_ >> sizeOfPoulation;
    return sizeOfPoulation;
}

void File::writeSudokuPopulation(int number) {
    sudoku_<<"Number of Population: "<<number<<std::endl;
    //int sudokuCount = ContainerOfPopulations::getInstanceContainer().pushNumberSudokuUnitsContainer(number);

}
