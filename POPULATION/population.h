//
// Created by Bartosz Cybulski on 10.05.2017.
//

#ifndef PROI_23_POPULATION_H
#define PROI_23_POPULATION_H

#include "../UNIT/bagpackUnit.h"
#include "../UNIT/sudokuUnit.h"

template <class T>
class Population{
    int numberOfUnits_;
    int maxNote_;
    std::vector<T*> allUnits_;
    T *bestUnit_;

    void checkIfBest(T *unit) {
        if(unit->pushNote() > maxNote_){
            maxNote_ = unit->pushNote();
            bestUnit_ = unit;
        }
        return;
    }

public:
    Population(T *unit, int numberOfUnits):
            numberOfUnits_(numberOfUnits){
        maxNote_ = (-1);
        for (int i = 0 ; i < numberOfUnits_ ; i++){
            T *newUnit = new T(unit);
            assert(newUnit != NULL);
            this->checkIfBest(newUnit);
            allUnits_.push_back(newUnit);
        }
    }
    void writeUnit(int i){
        allUnits_[i]->write();
        return;
    }
    void writeBestUnit(){
            bestUnit_->write();
    };
};

#endif //PROI_23_POPULATION_H
