//
// Created by Bartosz Cybulski on 07.05.2017.
//
#include "menu.h"

int Menu::menu(){
    int choice;
    std::cout<<"Welcome!\nWhich problem would you like to solve?"<<std::endl;
    std::cout<<"[1].Bagpack problem"<<std::endl;
    std::cout<<"[2].Sudoku problem"<<std::endl;
    std::cout<<"[3].Add population"<<std::endl;
    std::cout<<"[0].Exit"<<std::endl;
    std::cin>>choice;
    switch(choice){
        case 1:{
            for(int  i = 0 ; i < ContainerOfPopulations::getInstanceContainer().pushBagpackCount() ; i++){
                std::cout<<std::endl<<"POPULATION NO."<<i<<std::endl;
                ContainerOfPopulations::getInstanceContainer().writeBagpackPopulationContainer(i) ;
            }
            std::cout<<"Choose number of population"<<std::endl;
            int number;
            std::cin >> number;
            assert(number<ContainerOfPopulations::getInstanceContainer().pushBagpackCount());
            system(CLEAR);
            std::cout<<"[1].Do 20 steps {kill , cross ...}"<<std::endl;
            std::cout<<"[2].Kill random"<<std::endl;
            std::cout<<"[3].Kill aproximetly half of population"<<std::endl;
            std::cout<<"[4].Cross population"<<std::endl;
            std::cout<<"[5].Write best unit"<<std::endl;
            int choice1;
            std::cin>>choice1;
            switch(choice1){
                case 1:{
                    for(int i = 0 ; i < 20 ; i++){
                        ContainerOfPopulations::getInstanceContainer().killBagpackContainer(number);
                        ContainerOfPopulations::getInstanceContainer().crossBagpackContainer(number);
                        ContainerOfPopulations::getInstanceContainer().writeBestBagpackUnitContainer(number);
                    }
                    int numberOfUnits = ContainerOfPopulations::getInstanceContainer().pushNumberBagpackUnitsContainer(number);
                    std::cout<<"Success ! New number of units:"<<numberOfUnits<<std::endl;
                    break;
                }
                case 2:{
                    ContainerOfPopulations::getInstanceContainer().killRandomBagpackContainer(number);
                    int numberOfUnits = ContainerOfPopulations::getInstanceContainer().pushNumberBagpackUnitsContainer(number);
                    std::cout<<"Success ! New number of units:"<<numberOfUnits<<std::endl;
                    break;
                }
                case 3:{
                    ContainerOfPopulations::getInstanceContainer().killBagpackContainer(number);
                    int numberOfUnits = ContainerOfPopulations::getInstanceContainer().pushNumberBagpackUnitsContainer(number);
                    std::cout<<"Success ! New number of units:"<<numberOfUnits<<std::endl;
                    break;
                }
                case 4:{
                    ContainerOfPopulations::getInstanceContainer().crossBagpackContainer(number);
                    int numberOfUnits = ContainerOfPopulations::getInstanceContainer().pushNumberBagpackUnitsContainer(number);
                    std::cout<<"Success ! New number of units:"<<numberOfUnits<<std::endl;
                    break;
                }
                case 5:{
                    ContainerOfPopulations::getInstanceContainer().writeBestBagpackUnitContainer(number);
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case 2:{
            for(int i = 0 ; i < ContainerOfPopulations::getInstanceContainer().pushSudokuCount() ; i++){
                std::cout<<std::endl<<"POPULATION NO. "<< i << std::endl;
                ContainerOfPopulations::getInstanceContainer().writeSudokuPopulationContainer(i);
            }
            std::cout<<"Choose number of population"<<std::endl;
            int number;
            std::cin>>number;
            assert(number<ContainerOfPopulations::getInstanceContainer().pushSudokuCount());
            system(CLEAR);
            std::cout<<"[1].Do 20 steps {kill , cross ...}"<<std::endl;
            std::cout<<"[2].Kill random"<<std::endl;
            std::cout<<"[3].Kill aproximetly half of population"<<std::endl;
            std::cout<<"[4].Cross population"<<std::endl;
            std::cout<<"[5].Write best unit"<<std::endl;
            int choice2;
            std::cin>>choice2;
            switch(choice2){
                case 1:{
                    for(int i = 0 ; i < 20 ; i++){
                        ContainerOfPopulations::getInstanceContainer().killSudokuContainer(number);
                        ContainerOfPopulations::getInstanceContainer().crossSudokuContainer(number);
                        ContainerOfPopulations::getInstanceContainer().writeBestSudokuUnitContainer(number);
                    }
                    int numberOfUnits = ContainerOfPopulations::getInstanceContainer().pushNumberSudokuUnitsContainer(number);
                    std::cout<<"Success ! New number of units:"<<numberOfUnits<<std::endl;
                    break;
                }
                case 2:{
                    ContainerOfPopulations::getInstanceContainer().killRandomSudokuContainer(number);
                    int numberOfUnits = ContainerOfPopulations::getInstanceContainer().pushNumberSudokuUnitsContainer(number);
                    std::cout<<"Success ! New number of units:"<<numberOfUnits<<std::endl;
                    break;
                }
                case 3:{
                    ContainerOfPopulations::getInstanceContainer().killSudokuContainer(number);
                    int numberOfUnits = ContainerOfPopulations::getInstanceContainer().pushNumberSudokuUnitsContainer(number);
                    std::cout<<"Success ! New number of units:"<<numberOfUnits<<std::endl;
                    break;
                }
                case 4:{
                    ContainerOfPopulations::getInstanceContainer().crossSudokuContainer(number);
                    int numberOfUnits = ContainerOfPopulations::getInstanceContainer().pushNumberSudokuUnitsContainer(number);
                    std::cout<<"Success ! New number of units:"<<numberOfUnits<<std::endl;
                    break;
                }
                case 5 :{
                    ContainerOfPopulations::getInstanceContainer().writeBestSudokuUnitContainer(number);
                    break;
                }
                default:
                    break;
            }

            break;
        }
        case 3:{
            ContainerOfPopulations::getInstanceContainer().addPopulation();
            break;
        }
        case 0:{
            system(CLEAR);
            std::cout<<"Do you want to leave?\npress [y] - yes\npress [n] - no"<<std::endl;
            char c;
            while((c=getchar())){
                if(c=='y')
                    return 0;
                if(c=='n')
                    return 1;
            }
            break;
        }
        default:
            break;
    }

    return 1;
}

void Menu::fileTest() {
    std::cout<<"Which example do you want to solve?"<<std::endl;
    std::cout<<"[1].Bagpack"<<std::endl;
    std::cout<<"[2].Sudoku"<<std::endl;
    std::cout<<"[0].Exit"<<std::endl;
    int choice ;
    std::cin >> choice;
    switch (choice){
        case 1:{
            //File::getInstanceFile().openBagpackFile();
           break;
        }
        case 2:{
            File::getInstanceFile().openSudokuFile();
            int maxSize = File::getInstanceFile().readBoardSize();
            std::vector< std::vector <int> > board ;
            board = File::getInstanceFile().readSudokuBoard(maxSize);
            SudokuUnit *sample = new SudokuUnit(board , maxSize);
            sample->writeGeneratedSudokuBoard();
            break;
        }
        default:
            break;
    }
}

