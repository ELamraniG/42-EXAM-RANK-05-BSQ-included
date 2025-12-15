#include "vect2.hpp"
#include <iostream>
#include <cassert>

void test_constructors() {
    std::cout << "=== Testing Constructors ===" << std::endl;
    vect2 v1;
    assert(v1.x == 0 && v1.y == 0);
    std::cout << "Default constructor: PASS" << std::endl;
    
    vect2 v2(5, 10);
    assert(v2.x == 5 && v2.y == 10);
    std::cout << "Parameterized constructor: PASS" << std::endl;
    
    vect2 v3(v2);
    assert(v3.x == 5 && v3.y == 10);
    std::cout << "Copy constructor: PASS" << std::endl;
}

void test_assignment() {
    std::cout << "\n=== Testing Assignment ===" << std::endl;
    vect2 v1(1, 2);
    vect2 v2;
    v2 = v1;
    assert(v2.x == 1 && v2.y == 2);
    std::cout << "Assignment operator: PASS" << std::endl;
    
    v2 = v2;
    assert(v2.x == 1 && v2.y == 2);
    std::cout << "Self-assignment: PASS" << std::endl;
}

void test_index_access() {
    std::cout << "\n=== Testing Index Access ===" << std::endl;
    vect2 v(3, 7);
    assert(v[0] == 3);
    assert(v[1] == 7);
    std::cout << "Const index access: PASS" << std::endl;
    
    v[0] = 10;
    v[1] = 20;
    assert(v.x == 10 && v.y == 20);
    std::cout << "Mutable index access: PASS" << std::endl;
    
    const vect2 cv(5, 15);
    assert(cv[0] == 5 && cv[1] == 15);
    std::cout << "Const object index access: PASS" << std::endl;
}

void test_arithmetic_operators() {
    std::cout << "\n=== Testing Arithmetic Operators ===" << std::endl;
    vect2 v1(2, 3);
    vect2 v2(4, 5);
    
    vect2 v3 = v1 + v2;
    assert(v3.x == 6 && v3.y == 8);
    std::cout << "Addition: PASS" << std::endl;
    
    vect2 v4 = v2 - v1;
    assert(v4.x == 2 && v4.y == 2);
    std::cout << "Subtraction: PASS" << std::endl;
    
    vect2 v5 = v1 * 3;
    assert(v5.x == 6 && v5.y == 9);
    std::cout << "Vector * scalar: PASS" << std::endl;
    
    vect2 v6 = 2 * v1;
    assert(v6.x == 4 && v6.y == 6);
    std::cout << "Scalar * vector: PASS" << std::endl;
}

void test_compound_assignment() {
    std::cout << "\n=== Testing Compound Assignment ===" << std::endl;
    vect2 v1(1, 2);
    vect2 v2(3, 4);
    
    v1 += v2;
    assert(v1.x == 4 && v1.y == 6);
    std::cout << "+= operator: PASS" << std::endl;
    
    vect2 v3(10, 15);
    vect2 v4(2, 3);
    v3 -= v4;
    assert(v3.x == 8 && v3.y == 12);
    std::cout << "-= operator: PASS" << std::endl;
    
    vect2 v5(2, 3);
    v5 *= 4;
    assert(v5.x == 8 && v5.y == 12);
    std::cout << "*= operator: PASS" << std::endl;
}

void test_increment_decrement() {
    std::cout << "\n=== Testing Increment/Decrement ===" << std::endl;
    vect2 v1(5, 10);
    
    vect2 v2 = ++v1;
    assert(v1.x == 6 && v1.y == 11);
    assert(v2.x == 6 && v2.y == 11);
    std::cout << "Pre-increment: PASS" << std::endl;
    
    vect2 v3 = v1++;
    assert(v1.x == 7 && v1.y == 12);
    assert(v3.x == 6 && v3.y == 11);
    std::cout << "Post-increment: PASS" << std::endl;
    
    vect2 v4 = --v1;
    assert(v1.x == 6 && v1.y == 11);
    assert(v4.x == 6 && v4.y == 11);
    std::cout << "Pre-decrement: PASS" << std::endl;
    
    vect2 v5 = v1--;
    assert(v1.x == 5 && v1.y == 10);
    assert(v5.x == 6 && v5.y == 11);
    std::cout << "Post-decrement: PASS" << std::endl;
}

void test_unary_operators() {
    std::cout << "\n=== Testing Unary Operators ===" << std::endl;
    vect2 v1(3, 4);
    
    vect2 v2 = -v1;
    assert(v2.x == -3 && v2.y == -4);
    std::cout << "Negation: PASS" << std::endl;
}

void test_comparison() {
    std::cout << "\n=== Testing Comparison ===" << std::endl;
    vect2 v1(5, 10);
    vect2 v2(5, 10);
    vect2 v3(3, 7);
    
    assert(v1 == v2);
    assert(!(v1 == v3));
    std::cout << "Equality: PASS" << std::endl;
    
    assert(v1 != v3);
    assert(!(v1 != v2));
    std::cout << "Inequality: PASS" << std::endl;
}

void test_complex_expressions() {
    std::cout << "\n=== Testing Complex Expressions ===" << std::endl;
    vect2 v1(1, 2);
    vect2 v2(3, 4);
    vect2 v3(2, 1);
    
    vect2 v4 = v1 + v2 * 2 - v3;
    assert(v4.x == 5 && v4.y == 9);
    std::cout << "Mixed arithmetic: PASS" << std::endl;
    
    vect2 v5(1, 1);
    v5 += v5 += v5;
    assert(v5.x == 4 && v5.y == 4);
    std::cout << "Chained +=: PASS" << std::endl;
    
    vect2 v6(0, 0);
    vect2 v7(5, 5);
    v6 = v6 - v7 + v7;
    assert(v6.x == 0 && v6.y == 0);
    std::cout << "Zero result: PASS" << std::endl;
}

void test_output() {
    std::cout << "\n=== Testing Output Operator ===" << std::endl;
    vect2 v(7, 13);
    std::cout << "Vector output: " << v << " (expected: {7, 13})" << std::endl;
}

void test_edge_cases() {
    std::cout << "\n=== Testing Edge Cases ===" << std::endl;
    vect2 v1(-5, -10);
    vect2 v2(-3, -4);
    
    vect2 v3 = v1 + v2;
    assert(v3.x == -8 && v3.y == -14);
    std::cout << "Negative vectors addition: PASS" << std::endl;
    
    vect2 v4 = v1 * -2;
    assert(v4.x == 10 && v4.y == 20);
    std::cout << "Negative scalar multiplication: PASS" << std::endl;
    
    vect2 v5(0, 0);
    vect2 v6 = v5 + v5;
    assert(v6.x == 0 && v6.y == 0);
    std::cout << "Zero vector operations: PASS" << std::endl;
    
    vect2 v7(1000, 2000);
    v7 *= 10;
    assert(v7.x == 10000 && v7.y == 20000);
    std::cout << "Large numbers: PASS" << std::endl;
}

int main() {
    try {
        test_constructors();
        test_assignment();
        test_index_access();
        test_arithmetic_operators();
        test_compound_assignment();
        test_increment_decrement();
        test_unary_operators();
        test_comparison();
        test_complex_expressions();
        test_output();
        test_edge_cases();
        
        std::cout << "\n" << std::string(50, '=') << std::endl;
        std::cout << "ALL TESTS PASSED! ✓" << std::endl;
        std::cout << std::string(50, '=') << std::endl;
        
        return 0;
    } catch (const std::exception& e) {
        std::cout << "TEST FAILED: " << e.what() << std::endl;
        return 1;
    }
}
