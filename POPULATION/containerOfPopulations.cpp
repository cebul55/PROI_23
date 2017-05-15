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
    BagpackUnit sample;
    Population<BagpackUnit> backpacks(&sample , n , name);
    bagpackCount_++;
    populationBagpackContainer_.push_back(backpacks);
    return;
}
//TODO wzorce dekorator , most , fabryka ??? , nie behawioralne a obiektowe  , STRATEGIA , SINGLETON, FASADA
//TODO wzorzec strategii może być uzyty do sprawdzania czy podana klasa trafia do contenera <bagpack> czy <sudoku>