//
// Created by Bartosz Cybulski on 26.04.2017.
//
#include "MENU/menu.h"

int main() {
//    Menu myMenu;
//    int menu=1;
//    while(menu==1){
//        menu=myMenu.menu();
//    }


//    SudokuUnit *sudoku;
//    FlyweightSudokuUnit *flyweight = new FlyweightSudokuUnit(*sudoku);
//    flyweight->write(sudoku);


//    SudokuUnit *sample = new SudokuUnit;
//    Population<SudokuUnit , FlyweightSudokuUnit> sudokus(sample , 10 , 2);
//    sudokus.writeBestUnit();

    SudokuUnit *sudoku;
    FlyweightSudokuUnit s(sudoku);
    s.writeGeneratedSudokuBoard();
    return 0;
}