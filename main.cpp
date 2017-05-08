//
// Created by Bartosz Cybulski on 26.04.2017.
//
#include "menu.h"
#include "numericPhenotype.h"
#include "bagpackUnit.h"

int main() {
    Random r1(500);
    r1.writeValue();
    int n;
    n = r1.setValue();
    std::cout<<n<<std::endl;
    r1.writeValue();
    BagpackUnit b;
    b.writeBagpack();
    int maks = 0;
    for(int i = 0 ; i < 100 ; i++){
        BagpackUnit copy(b);
        if(copy.pushNote()>maks){
            maks = copy.pushNote();
            copy.writeSpecyficBagpack();
        }
    }

    return 0;
}