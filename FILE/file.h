//
// Created by Bartosz Cybulski on 25.05.2017.
//

#ifndef PROI_23_FILE_H
#define PROI_23_FILE_H

#include <fstream>
#include <vector>
#include <assert.h>

//#include "../POPULATION/containerOfPopulations.h"

class File{
private:
    File(){}
    File(const File&){}
    File& operator=(const File&);
    ~File(){}
    //std::fstream sudoku_;
    std::fstream bagpack_;
public:
    std::fstream sudoku_;
    static File & getInstanceFile(){
        static File file;
        return file;
    }
    void openSudokuFile() {
        sudoku_.open("sudoku.txt");
        assert(sudoku_.is_open()!= 0);
        //sudoku_.open("sudoku.txt" , std::fstream::in | std::fstream::out );
    }
    void openBagpackFile(){
        bagpack_.open("bagpack.txt" , std::fstream::in | std::fstream::out );
    }
    void closeSudokuFile(){
        sudoku_.close();
    }
    void closeBagpackFIle(){
        bagpack_.close();
    }
    int isOpenSudoku(){
        if(sudoku_.is_open()== true)
            return 1;
        else
            return 0;
    }
    std::vector<std::vector<int> > readSudokuBoard(int);
    int readBoardSize();
    int readSizeOfSudokuPopulation();
    void writeSudokuPopulation(int);
};

#endif //PROI_23_FILE_H
