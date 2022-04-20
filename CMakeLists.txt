cmake_minimum_required(VERSION 3.22)
project(ee205_lab_08d_animal_farm_1_to_clion)

set(CMAKE_CXX_STANDARD 14)

add_executable(ee205_lab_08d_animal_farm_1_to_clion main.cpp addCats.cpp addCats.h config.h catDatabase.cpp catDatabase.h reportCats.cpp reportCats.h deleteCats.cpp deleteCats.h Cats.cpp Cats.h Weight.cpp Weight.h Gender.h Color.h Node.cpp Node.h List.cpp List.h)
