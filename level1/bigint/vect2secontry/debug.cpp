#include "vect2.hpp"
#include <iostream>

int main() {
    vect2 v1(1, 2);
    vect2 v2(3, 4);
    vect2 v3(2, 1);
    
    std::cout << "v1: " << v1 << std::endl;
    std::cout << "v2: " << v2 << std::endl;
    std::cout << "v3: " << v3 << std::endl;
    
    vect2 temp1 = v2 * 2;
    std::cout << "v2 * 2: " << temp1 << std::endl;
    
    vect2 temp2 = v1 + temp1;
    std::cout << "v1 + v2*2: " << temp2 << std::endl;
    
    vect2 v4 = v1 + v2 * 2 - v3;
    std::cout << "v1 + v2*2 - v3: " << v4 << std::endl;
    std::cout << "Expected: {4, 9}, Got: {" << v4.x << ", " << v4.y << "}" << std::endl;
    
    return 0;
}
