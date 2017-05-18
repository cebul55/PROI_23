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
            for(int  i = 0 ; i < ContainerOfPopulations::getInstanceContainer().populationBagpackContainer_.size() ; i++){
                std::cout<<std::endl<<"POPULATION NO."<<i<<std::endl;
                ContainerOfPopulations::getInstanceContainer().populationBagpackContainer_[i].writePopulation();
            }
            std::cout<<"Choose number of population"<<std::endl;
            int number;
            std::cin >> number;
            assert(number<ContainerOfPopulations::getInstanceContainer().populationBagpackContainer_.size());
            system(CLEAR);
            std::cout<<"[1].Do 100 steps {kill , cross ...}"<<std::endl;
            std::cout<<"[2].Kill random"<<std::endl;
            std::cout<<"[3].Kill aproximetly half of population"<<std::endl;
            std::cout<<"[4].Cross population"<<std::endl;
            std::cout<<"[5].Write best unit"<<std::endl;
            int choice1;
            std::cin>>choice1;
            switch(choice1){
                case 1:{
                    for(int i = 0 ; i < 100 ; i++){
                        ContainerOfPopulations::getInstanceContainer().populationBagpackContainer_[number].killPopulation();
                        ContainerOfPopulations::getInstanceContainer().populationBagpackContainer_[number].crossPopulation();
                        ContainerOfPopulations::getInstanceContainer().populationBagpackContainer_[number].writeBestUnit();
                    }
                    int numberOfUnits = ContainerOfPopulations::getInstanceContainer().populationBagpackContainer_[number].giveNumberOfUnits();
                    std::cout<<"Success ! New number of units:"<<numberOfUnits<<std::endl;
                    break;
                }
                case 2:{
                    ContainerOfPopulations::getInstanceContainer().populationBagpackContainer_[number].killRandom();
                    int numberOfUnits = ContainerOfPopulations::getInstanceContainer().populationBagpackContainer_[number].giveNumberOfUnits();
                    std::cout<<"Success ! New number of units:"<<numberOfUnits<<std::endl;
                    break;
                }
                case 3:{
                    ContainerOfPopulations::getInstanceContainer().populationBagpackContainer_[number].killPopulation();
                    int numberOfUnits = ContainerOfPopulations::getInstanceContainer().populationBagpackContainer_[number].giveNumberOfUnits();
                    std::cout<<"Success ! New number of units:"<<numberOfUnits<<std::endl;
                    break;
                }
                case 4:{
                    ContainerOfPopulations::getInstanceContainer().populationBagpackContainer_[number].crossPopulation();
                    int numberOfUnits = ContainerOfPopulations::getInstanceContainer().populationBagpackContainer_[number].giveNumberOfUnits();
                    std::cout<<"Success ! New number of units:"<<numberOfUnits<<std::endl;
                    break;
                }
                case 5:{
                    ContainerOfPopulations::getInstanceContainer().populationBagpackContainer_[number].writeBestUnit();
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case 2:{
            std::cout<<"Not working yet press any button"<<std::endl;
            //container::getInstance*()
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

