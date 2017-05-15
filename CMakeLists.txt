cmake_minimum_required(VERSION 3.6)
project(PROI_23)

set(CMAKE_CXX_STANDARD 11)

set(SOURCE_FILES main.cpp PHENOTYPE/random.cpp PHENOTYPE/random.h MENU/menu.cpp MENU/menu.h PHENOTYPE/phenotype.cpp PHENOTYPE/phenotype.h PHENOTYPE/binaryPhenotype.cpp PHENOTYPE/binaryPhenotype.h PHENOTYPE/numericPhenotype.cpp PHENOTYPE/numericPhenotype.h UNIT/bagpackUnit.cpp UNIT/bagpackUnit.h UNIT/sudokuUnit.cpp UNIT/sudokuUnit.h POPULATION/population.h POPULATION/containerOfPopulations.cpp POPULATION/containerOfPopulations.h PHENOTYPE/file.cpp PHENOTYPE/file.h UNIT/flyweightBagpackUnit.cpp UNIT/flyweightBagpackUnit.h)
add_executable(PROI_23 ${SOURCE_FILES})