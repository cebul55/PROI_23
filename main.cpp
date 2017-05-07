//
// Created by Bartosz Cybulski on 26.04.2017.
//
#include "menu.h"
int main() {
    Random r1(500);
    r1.writeValue();
    int n;
    n = r1.setValue();
    std::cout<<n<<std::endl;
    r1.writeValue();
    return 0;
}