//
// Created by Bartosz Cybulski on 08.05.2017.
//

#ifndef PROI_23_NUMERICPHENOTYPE_H
#define PROI_23_NUMERICPHENOTYPE_H

#include "phenotype.h"

class NumericPhenotype : public Phenotype{
    std::vector<std::string> phenotype_;
    int note_;
    void generatePhenotype(std::vector<std::vector<int> >* , int size);
public:
//TODO sudoku phenotype methods vector stringów ???
    NumericPhenotype(std::vector<std::vector<int> > *sudokuBoard , int maxSize ){
        generatePhenotype(sudokuBoard , maxSize);
    }
};

#endif //PROI_23_NUMERICPHENOTYPE_H
