//
// Created by Bartosz Cybulski on 26.04.2017.
//
#include "MENU/menu.h"

int main() {
    Menu myMenu;
    int menu=1;
    while(menu==1){
        menu=myMenu.menu();
    }

//todo FINAL : dokumentacja , obsługa pilików , 2 - 4 testy w plikach żeby ręcznie nie pisać

//    SudokuUnit *sudoku;
//    FlyweightSudokuUnit *flyweight = new FlyweightSudokuUnit(*sudoku);
//    flyweight->write(sudoku);


//    SudokuUnit *sample = new SudokuUnit;
//    Population<SudokuUnit , FlyweightSudokuUnit> sudokus(sample , 3 , 2);
//    sudokus.writeBestUnit();


/*    SudokuUnit *sudoku = new SudokuUnit;
    FlyweightSudokuUnit s = new FlyweightSudokuUnit(*sudoku);
    s->write(*sudoku);*/


//    SudokuUnit *sample = new SudokuUnit;
//    FlyweightSudokuUnit s(*sample);
//    std::cout<<s.pushNote();
    return 0;
}