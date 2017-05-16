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
    for(int i = 0 ; i < size ; i += sizeOfSubgrid){
        for(int j = 0 ; j < size ; j += sizeOfSubgrid){
            for( int ii = i ; ii < i + sizeOfSubgrid ; ii++){
                //numericPhenotype_.push_back("");
                for( int jj = j ; jj < j+sizeOfSubgrid ; jj++){
                    if(sudokuBoard[ii][jj] == 0){
                        generateNumber.setValue();
                        int whichNumberAdd;
                        if(generateNumber.pushValue() % lackingNumbers[ii].size() == 0)
                            whichNumberAdd = 0;
                        else
                            whichNumberAdd = generateNumber.pushValue() % lackingNumbers[ii].size();
                        numericPhenotype_[ii]+=insertNumberInPhenotype(lackingNumbers[ii][whichNumberAdd]);
                        lackingNumbers[ii].erase(lackingNumbers[ii].begin()+whichNumberAdd);
                    }
                    else{
                        std::string add = insertNumberInPhenotype(sudokuBoard[ii][jj]);
                        numericPhenotype_[ii] += add;
                    }
                        //phenotype_[ii]+insertNumberInPhenotype(sudokuBoard[ii][jj]);
                        //phenotype_[ii].push_back(insertNumberInPhenotype(sudokuBoard[ii][jj]));
                }
            }
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
    switch(n){
        case 1:
            character = "1";
            break;
        case 2:
            character = "2";
            break;
        case 3:
            character = "3";
            break;
        case 4:
            character = "4";
            break;
        case 5:
            character = "5";
            break;
        case 6:
            character = "6";
            break;
        case 7:
            character = "7";
            break;
        case 8:
            character = "8";
            break;
        case 9:
            character = "9";
            break;
        case 10:
            character = "A";
            break;
        case 11:
            character = "B";
            break;
        case 12:
            character = "C";
            break;
        case 13:
            character = "D";
            break;
        case 14:
            character = "E";
            break;
        case 15:
            character = "F";
            break;
        case 16:
            character = "G";
            break;
        default:
            break;
        }
    return character;
}