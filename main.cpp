#include <iostream>
#include <random>
#include <vector>

int main() {
    std::random_device generator;
    std::uniform_int_distribution<int> distribution(1,6);
    int dice_roll = distribution(generator);
    //auto dice = std::bind(distribution, generator);
    int w ;
    int t[10];
    for(int i = 0 ; i < 100 ; i++){
        w = distribution(generator);
        t[w]++;
        //std::cout<<w<<std::endl;
    }
    for (int i = 1 ;i < 6 ; i++) {
        std::cout<<t[i]<<" ";
    }
    std::cout << "Hello, World!" << std::endl;
    return 0;
}