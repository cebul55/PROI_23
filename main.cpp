//
// Created by Bartosz Cybulski on 26.04.2017.
//
#include "MENU/menu.h"

int main() {
    /*Menu myMenu;
    int menu=1;
    while(menu==1){
        menu=myMenu.menu();
    }*/

    ContainerOfPopulations::getInstanceContainer().addPopulation();
    ContainerOfPopulations::getInstanceContainer().addPopulation();
    ContainerOfPopulations::getInstanceContainer().writePopulation();

    /*containter.populationBagpackContainer_[0].writePopulation();
    containter.populationBagpackContainer_[0].killPopulation();
    containter.populationBagpackContainer_[0].writePopulation();
    containter.populationBagpackContainer_[0].crossPopulation();
    containter.populationBagpackContainer_[0].writePopulation();*/


    /*BagpackUnit b;
    b.write();
    int maks = 0;
    for(int i = 0 ; i < 100 ; i++){
        BagpackUnit copy(b);
        if(copy.pushNote()>maks){
            maks = copy.pushNote();
            copy.writeSpecyficBagpack();
        }
    }*/

/*    int maks = 0;
    BagpackUnit b;
    BagpackUnit copy1(b);
    BagpackUnit copy2(b);*/

 /*   b.write();
    for(int i = 0 ; i < 1000 ; i++) {
        //copy1.write();
        //copy2.write();
        BagpackUnit child(copy1, copy2);
        if(child.pushNote()>maks) {
            maks = child.pushNote();
            child.write();
        }
    }*/

/*    BagpackUnit b;
    BagpackUnit b1 = new BagpackUnit(&b);
    b1.write();*/
/*    BagpackUnit sample;
    Population<BagpackUnit> bagpacks(&sample,100);*/
    /*for(int i = 0 ; i<10 ; i++){
        bagpacks.writeUnit(i);
    }*/

    return 0;
}