//
// Created by Bartosz Cybulski on 07.05.2017.
//

#ifndef PROI_23_MENU_H
#define PROI_23_MENU_H

#include <iostream>
#include <cstdlib>

#include "random.h"

#ifdef _WIN32
#define CLEAR "cls"
#else
#define CLEAR "clear"
#endif

class Menu{
public:
    int menu();
};

#endif //PROI_23_MENU_H
