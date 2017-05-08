cmake_minimum_required(VERSION 3.6)
project(PROI_23)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp random.cpp random.h menu.cpp menu.h phenotype.cpp phenotype.h binaryPhenotype.cpp binaryPhenotype.h numericPhenotype.cpp numericPhenotype.h unit.cpp unit.h bagpackUnit.cpp bagpackUnit.h sudokuUnit.cpp sudokuUnit.h)
add_executable(PROI_23 ${SOURCE_FILES})