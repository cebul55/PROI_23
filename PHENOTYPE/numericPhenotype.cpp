//
// Created by Bartosz Cybulski on 08.05.2017.
//

#include "numericPhenotype.h"
void NumericPhenotype::generatePhenotype(std::vector<std::vector<int> > sudokuBoard, int size) {
    Random generateNumber(size);
    int sizeOfSubgrid = sqrt(size);
    std::vector<std::vector<int> > lackingNumbers = generateHelpBoard(sudokuBoard , size);
    for(int i = 0 ; i < size ; i++){
        numericPhenotype_.push_back("");
    }
    int subgridIterator;
    for ( int i = 0 ; i < size ; i++){
        for(int j = 0 ; j < size ; j++){
            subgridIterator = j/sizeOfSubgrid +sizeOfSubgrid*(i/sizeOfSubgrid);

            if(sudokuBoard[i][j] == 0 ){
                generateNumber.setValue();
                int whichNumberAdd;
                if( lackingNumbers[subgridIterator].size() == 0)
                    whichNumberAdd = 0;
                else
                    whichNumberAdd = generateNumber.pushValue() % lackingNumbers[subgridIterator].size();
                numericPhenotype_[subgridIterator]+=insertNumberInPhenotype(lackingNumbers[subgridIterator][whichNumberAdd]);
                lackingNumbers[subgridIterator].erase(lackingNumbers[subgridIterator].begin()+whichNumberAdd);
            } else
                numericPhenotype_[subgridIterator] += insertNumberInPhenotype(sudokuBoard[i][j]);
        }
    }

}

std::vector<std::vector<int> > NumericPhenotype::generateHelpBoard(std::vector<std::vector<int> > sudokuBoard, int size){
    int sizeOfSubgrid = sqrt(size);
    std::vector<std::vector<int> > helpBoard;

    for( int  i = 0 ; i < size ; i+=sizeOfSubgrid){
        for(int j = 0 ; j < size; j+=sizeOfSubgrid){
            std::vector<int> subgrid;
            for(int ii = i ; ii < i+sizeOfSubgrid ; ii++){
                for(int jj = j ; jj< j+sizeOfSubgrid ; jj++){
                    if(sudokuBoard[ii][jj]!= 0){
                        subgrid.push_back(sudokuBoard[ii][jj]);
                    }
                }
            }
            helpBoard.push_back(subgrid);
        }
    }
    std::vector<std::vector<int> > lackingNumbers;
    for ( int i = 0 ; i < size ; i++){
        std::vector<int> row;
        for( int j = 0 ; j < size ; j++){
            row.push_back(j+1);
        }
        lackingNumbers.push_back(row);
    }
    for ( int i = 0 ; i < size; i++){
        for ( int j = 0 ; j<helpBoard.size() ; j++){
            if(helpBoard[i].size() != 0) {
                int n = helpBoard[i][j];
                for (int k = 0; k < lackingNumbers[i].size(); k++) {
                    if (lackingNumbers[i][k] == n) {
                        lackingNumbers[i].erase(lackingNumbers[i].begin() + k);
                    }
                }
            }
        }
    }
    return lackingNumbers;
}

std::string NumericPhenotype::insertNumberInPhenotype(int n) {
    std::string character;
    while(n>0){
        std::string add;
        add = n%10+48;
        character = add+character;
        n = n/10;
    }
    character += "|";
    return character;
}

std::vector<std::string> NumericPhenotype::crossPhenotype(std::vector<std::string> left, std::vector<std::string> right , int maxSize) {
    std::vector<std::string> phenotype;
    std::string row;
    Random generateNumber(maxSize);
    for(int i = 0 ; i < maxSize; i++ ){
        row = "";
        generateNumber.setValue();
//        for( int j = 0 ; j < generateNumber.pushValue() ; j++){
//            row += (left[i][j]);
//        }
//        for( int k = generateNumber.pushValue() ; k < left.size() ; k++){
//            row += (right[i][k]);
//        }
        int j = 0 , k = generateNumber.pushValue() , l = 0;
        while(j < generateNumber.pushValue()){
            if(left[i][l] == '|')
                j++;
            row += (left[i][l]);
            l++;
        }
        while(k < left.size()){
            if(right[i][l] == '|')
                k++;
            row += right[i][l];
            l++;
        }
        phenotype.push_back(row);
    }
    return  phenotype;
}
