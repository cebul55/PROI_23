//
// Created by Bartosz Cybulski on 07.05.2017.
//
#include "menu.h"

int Menu::menu(){
    int choice;
    system(CLEAR);
    std::cout<<"Welcome!\nWhich problem would you like to solve?"<<std::endl;
    std::cout<<"[1].Bagpack problem"<<std::endl;
    std::cout<<"[2].Sudoku problem"<<std::endl;
    std::cout<<"[0].Exit"<<std::endl;
    std::cin>>choice;
    switch(choice){
        case 1:{
            system(CLEAR);
            std::cout<<"Bagpack problem menu:"<<std::endl;
            std::cout<<"[1].Create new bagpack population"<<std::endl;
            std::cout<<"[2].Magage existing population of bagpacks"<<std::endl;
            std::cout<<"[0].Exit"<<std::endl;
            int choice1;
            std::cin>>choice1;
            switch (choice1){
                case 1: {
                    std::cout<<"tu cos bylo ale juz nie ma"<<std::endl;
                    break;
                }
                default:
                    break;
            }
            break;
        }
        case 2:{
            std::cout<<"Not working yet press any button";
            //container::getInstance*()
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

    //TODO add sudoku problem
    return 1;
}