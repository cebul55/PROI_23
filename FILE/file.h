//
// Created by Bartosz Cybulski on 25.05.2017.
//

#ifndef PROI_23_FILE_H
#define PROI_23_FILE_H

#include <fstream>
#include <vector>

class File{
private:
    File(){}
    File(const File&){}
    File& operator=(const File&);
    ~File(){}
    std::fstream sudoku_;
    std::fstream bagpack_;
public:
    static File & getInstanceFile(){
        static File file;
        return file;
    }
    void openSudokuFile() {
        sudoku_.open("sudoku.txt" , std::fstream::in | std::fstream::out);
    }
    void openBagpackFile(){
        bagpack_.open("bagpack.txt" , std::ios::in | std::ios::out | std::ios::app);
    }
    void closeSudokuFile(){
        sudoku_.close();
    }
    void closeBagpackFIle(){
        bagpack_.close();
    }
    std::vector<std::vector<int> > readSudokuBoard(int);
    int readBoardSize();
};

#endif //PROI_23_FILE_H
