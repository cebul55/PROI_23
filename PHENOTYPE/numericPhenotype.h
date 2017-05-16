//
// Created by Bartosz Cybulski on 08.05.2017.
//

#ifndef PROI_23_NUMERICPHENOTYPE_H
#define PROI_23_NUMERICPHENOTYPE_H

#include "phenotype.h"

class NumericPhenotype : public Phenotype{
    int maxSize_;
    std::vector<std::string> numericPhenotype_;
    int note_;
    void generatePhenotype(std::vector<std::vector<int> > , int size);
    std::string insertNumberInPhenotype(int);
    std::vector<std::vector<int> > generateHelpBoard(std::vector<std::vector<int> > , int size);
public:
    NumericPhenotype(std::vector<std::vector<int> > sudokuBoard , int maxSize ):
            maxSize_(maxSize){
        generatePhenotype(sudokuBoard , maxSize);
    }
    void write(){
        for( int i = 0 ; i < maxSize_; i++){
            for ( int j = 0 ; j < numericPhenotype_[i].size() ; j++){
                std::cout<<numericPhenotype_[i][j]<<" ";
            }
            std::cout<<std::endl;
        }
    }
    std::vector<std::string> giveNumericPhenotype(){
        return numericPhenotype_;
    }
};

#endif //PROI_23_NUMERICPHENOTYPE_H
