//
// Created by Bartosz Cybulski on 10.05.2017.
//

#include "containerOfPopulations.h"

void ContainerOfPopulations::addPopulation() {
    system(CLEAR);
    std::cout<<"Which population do you want to add?"<<std::endl;
    std::cout<<"[1].Bagpack population"<<std::endl;
    std::cout<<"[2].Sudoku population"<<std::endl;
    std::cout<<"[0].Exit"<<std::endl;
    int choice;
    std::cin>>choice;
    switch(choice){
        case 1:
            this->makeBagpackPopulation();
            break;
        case 2:
            std::cout<<"added but not connected function"<<std::endl;
            break;
        default:
            break;
    }
}

void ContainerOfPopulations::makeBagpackPopulation() {
    system(CLEAR);
    std::cout<<"How many bagpack units do you want to create?"<<std::endl;
    int n , name;
    std::cin>>n;
    assert(n>0);
    name = BAGPACK;
    BagpackUnit *sample = new BagpackUnit;
    Population<BagpackUnit , FlyweightBagpackUnit> backpacks(sample , n , name);
    bagpackCount_++;
    populationBagpackContainer_.push_back(backpacks);
    return;
}
void ContainerOfPopulations::makeSudokuPopulation(){
    system(CLEAR);
    std::cout<<"How many Sudoku units do you want to create?"<<std::endl;
    int n , name;
    std::cin>>n;
    assert(n>0);
    name = SUDOKU;
    SudokuUnit *sample = new SudokuUnit;
    Population<SudokuUnit , FlyweightSudokuUnit> sudokus(sample , n , name);
    sudokuCount_++;
    populationSudokuContainer_.push_back(sudokus);
    return;
}
