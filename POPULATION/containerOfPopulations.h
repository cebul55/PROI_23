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
    std::vector<Population <BagpackUnit , FlyweightBagpackUnit > > populationBagpackContainer_;
    std::vector<Population <SudokuUnit , FlyweightSudokuUnit > > populationSudokuContainer_;
    ContainerOfPopulations(){}
    ContainerOfPopulations(const ContainerOfPopulations &){}
    ContainerOfPopulations& operator=(const ContainerOfPopulations&);
    ~ContainerOfPopulations(){}
public:
    static ContainerOfPopulations & getInstanceContainer(){
        static ContainerOfPopulations container;
        return container;
    }
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
    int pushBagpackCount(){
        return bagpackCount_;
    }
    int pushSudokuCount(){
        return sudokuCount_;
    }
    void killBagpackContainer(int n){
        populationBagpackContainer_[n].killPopulation();
    }
    void killSudokuContainer(int n){
        populationSudokuContainer_[n].killPopulation();
    }
    void crossBagpackContainer(int n){
        populationBagpackContainer_[n].crossPopulation();
    }
    void crossSudokuContainer(int n){
        populationSudokuContainer_[n].crossPopulation();
    }
    void writeBestBagpackUnitContainer(int n){
        populationBagpackContainer_[n].writeBestUnit();
    }
    void writeBestSudokuUnitContainer(int n){
        populationSudokuContainer_[n].writeBestUnit();
    }
    void writeBagpackPopulationContainer(int n){
        populationBagpackContainer_[n].writePopulation();
    }
    void writeSudokuPopulationContainer(int n){
        populationSudokuContainer_[n].writePopulation();
    }
    int pushNumberBagpackUnitsContainer(int n){
        return populationBagpackContainer_[n].giveNumberOfUnits();
    }
    int pushNumberSudokuUnitsContainer(int n){
        return populationSudokuContainer_[n].giveNumberOfUnits();
    }
    void killRandomBagpackContainer(int n){
        populationBagpackContainer_[n].killRandom();
    }
    void killRandomSudokuContainer(int n){
        populationSudokuContainer_[n].killRandom();
    }
    long pushSizeBagpackPopulationContainer(){
        return populationBagpackContainer_.size();
    }
    long pushSizeSudokuPopulationContainer(){
        return populationSudokuContainer_.size();
    }
};

#endif //PROI_23_CONTAINEROFPOPULATIONS_H
