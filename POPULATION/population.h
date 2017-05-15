//
// Created by Bartosz Cybulski on 10.05.2017.
//

#ifndef PROI_23_POPULATION_H
#define PROI_23_POPULATION_H

#include "../FLYWEIGHT/flyweightBagpackUnit.h"
#include "../UNIT/sudokuUnit.h"

#define BAGPACK 1
#define SUDOKU 2

template <class T, class FlyweightT>
class Population{
    int name_;
    int numberOfUnits_;
    int maxNote_;
    std::vector<FlyweightT*> allUnits_;
    FlyweightT *bestUnit_;
    T *sampleUnit_;

    void checkIfBest(FlyweightT *unit) {
        if(unit->pushNote() > maxNote_){
            maxNote_ = unit->pushNote();
            bestUnit_ = unit;
        }
        return;
    }


public:
    Population(T *unit, int numberOfUnits , int name):
            sampleUnit_(unit),
            numberOfUnits_(numberOfUnits),
            name_(name){
        maxNote_ = (-1);
        for (int i = 0 ; i < numberOfUnits_ ; i++){
            addNewUnit(unit);
        }
    }
    void addNewUnit(T *unit){
        FlyweightT *newUnit = new FlyweightT(unit);
        assert(newUnit != NULL);
        this->checkIfBest(newUnit);
        allUnits_.push_back(newUnit);
    }
    void searchBest_(){
        for(int i = 0 ; i < allUnits_.size() ; i++){
            if(allUnits_[i]->pushNote()>maxNote_){
                maxNote_ = allUnits_[i]->pushNote();
                bestUnit_= allUnits_[i];
            }
        }
    }
    void kill(int n){
        if(n<numberOfUnits_){
            if(allUnits_[n]==bestUnit_){
                maxNote_ = 0 ;
                for(int i = 0 ; i < allUnits_.size() ; i++){
                    if(i != n)
                        this->checkIfBest(allUnits_[i]);
                }
            }
            delete allUnits_[n];
            numberOfUnits_--;
            allUnits_.erase(allUnits_.begin()+n);
        }
        else
            std::cout<<"Unit number "<<n<<" does not exist"<<std::endl;
    }
    void killRandom(){
        Random generateNumber(allUnits_.size());
        generateNumber.setValue();
        if(generateNumber.pushValue()<allUnits_.size())
            kill(generateNumber.pushValue());
        std::cout<<"Randomly picked unit no. "<<generateNumber.pushValue()<<" was killed"<<std::endl;
    }

    void killPopulation(){
        Random generateProcent(20);
        generateProcent.setValue();
        unsigned long n = allUnits_.size() *(generateProcent.pushValue() + 31)/100;//killing 30-50% of population
        unsigned long i = 0 ;
        while (i < n){
            Random generateUnit(allUnits_.size() - 1 );
            generateUnit.setValue();
            int unitToKill = generateUnit.pushValue();
            kill(unitToKill);
            i++;
        }
    }
    void crossPopulation(){
        Random generateProcent(20);
        generateProcent.setValue();
        unsigned long n = allUnits_.size() * (generateProcent.pushValue() +20 )/100;//crossing 20-40% of population
        unsigned long i = 0;
        while(i<n){
            Random generateUnit(allUnits_.size() - 1);
            generateUnit.setValue();
            unsigned left = generateUnit.pushValue();
            generateUnit.setValue();
            unsigned right = generateUnit.pushValue();
            int check = 0;
            while(left == right && check < 10){//checking if crossed units are different
                generateUnit.setValue();
                right = generateUnit.pushValue();
                check++;
            }
            FlyweightBagpackUnit *son = new FlyweightBagpackUnit(*allUnits_[left],*allUnits_[right],sampleUnit_);
            FlyweightBagpackUnit *daughter = new FlyweightBagpackUnit(*allUnits_[right],*allUnits_[left],sampleUnit_);
            allUnits_.push_back(son);
            allUnits_.push_back(daughter);
            this->checkIfBest(son);
            this->checkIfBest(daughter);
            numberOfUnits_ += 2;
            i++;
        }
        std::cout<<"Crossed "<<2*n<<" units. Size of population: "<<allUnits_.size()<<std::endl;
    }
    void writePopulation(){
        if(name_ == BAGPACK)
            std::cout<<"Type: Bagpack "<<std::endl;
        else
            std::cout<<"Sudoku "<<std::endl;
        std::cout<<"Number of Units : "<<numberOfUnits_<<std::endl;
        bestUnit_->write(sampleUnit_);
    }
    void writeUnit(int i){
        allUnits_[i]->write(sampleUnit_);
        return;
    }
    void writeBestUnit(){
        std::cout<<"BEST UNIT"<<std::endl;
            bestUnit_->write(sampleUnit_);
    };

    int giveNumberOfUnits(){
        return numberOfUnits_;
    }
};

#endif //PROI_23_POPULATION_H
