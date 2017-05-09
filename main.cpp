//
// Created by Bartosz Cybulski on 26.04.2017.
//
#include "MENU/menu.h"
#include "PHENOTYPE/numericPhenotype.h"
#include "UNIT/bagpackUnit.h"

int main() {
    /*Menu myMenu;
    int menu=1;
    while(menu==1){
        menu=myMenu.menu();
    }*/

    /*BagpackUnit b;
    b.writeBagpack();
    int maks = 0;
    for(int i = 0 ; i < 100 ; i++){
        BagpackUnit copy(b);
        if(copy.pushNote()>maks){
            maks = copy.pushNote();
            copy.writeSpecyficBagpack();
        }
    }*/

    int maks = 0;
    BagpackUnit b;
    BagpackUnit copy1(b);
    BagpackUnit copy2(b);

    b.writeBagpack();
    for(int i = 0 ; i < 1000 ; i++) {
        //copy1.writeBagpack();
        //copy2.writeBagpack();
        BagpackUnit child(copy1, copy2);
        if(child.pushNote()>maks) {
            maks = child.pushNote();
            child.writeBagpack();
        }
    }
    return 0;
}