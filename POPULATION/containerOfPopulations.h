//
// Created by Bartosz Cybulski on 10.05.2017.
//

#ifndef PROI_23_CONTAINEROFPOPULATIONS_H
#define PROI_23_CONTAINEROFPOPULATIONS_H

#include "population.h"

class ContainerOfPopulations{
private:
    int bagpackCount_;
    int sudokuCount_;
    //std::vector<Population <BagpackUnit>> populationBagpackContainer_;
    //std::vector<Population <SudokuUnit>> populationSudokuContainer;
    ContainerOfPopulations(){}
    ContainerOfPopulations(const ContainerOfPopulations &){}
    ContainerOfPopulations& operator=(const ContainerOfPopulations&);
    ~ContainerOfPopulations(){}
public:
    static ContainerOfPopulations & getInstanceContainer(){
        static ContainerOfPopulations container;
        return container;
    }
    std::vector<Population <BagpackUnit , FlyweightBagpackUnit> > populationBagpackContainer_;
    std::vector<Population <SudokuUnit , FlyweightSudokuUnit> > populationSudokuContainer_;
    void addPopulation();
    void makeBagpackPopulation();
    void makeSudokuPopulation();

    void writePopulation(){
        for(int i = 0 ; i<populationBagpackContainer_.size() ; i++) {
            std::cout<<"Number of Population: "<<i<<std::endl;
            populationBagpackContainer_[i].writePopulation();
            std::cout<<std::endl;
        }
    }
    int giveBagpackCount(){
        return bagpackCount_;
    }

};

#endif //PROI_23_CONTAINEROFPOPULATIONS_H
