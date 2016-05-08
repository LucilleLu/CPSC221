#include <iostream>
using namespace std;

int main () {
    
    int x = 5, y = 15;
    int *p1, *p2;
    
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    std::cout << &x << std::endl;
    std::cout << &y << std::endl;
    
    std::cout << "1======" << std::endl;
    
    p1 = &x;      // x contains 5 ; y contains 15
                  // p1 contains address of x; p2 contains 0x0;
    
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << p1 << std::endl;
    std::cout << *p1 << std::endl;
    std::cout << p2 << std::endl;
    
    std::cout << "2======" << std::endl;
    
    p2 = &y;      // x contains 5; y contains 15
                  // p1 contains address of x; p2 contains address of y
    
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    
    std::cout << "3======" << std::endl;
    
    
    *p1 = 6;      // x contains 6; y contains 15
                  // p1 contains address of x; p2 contains address of y
    
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    
    std::cout << "4======" << std::endl;
    
    
    *p1 = *p2;    // x contains 15; y contains 15
                  // p1 contains address of x; p2 contains address of y
    
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    
    std::cout << "5======" << std::endl;
    
    p2 = p1;      // x contains 15; y contains 25
                  // p1 contains address of x; p2 contains address of x
    
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    
    std::cout << "6======" << std::endl;
    
    
    *p1 = *p2+10; // x contains 25; y contains 15
                  // p1 contains address of x; p2 contains address of x
    
    std::cout << x << std::endl;
    std::cout << y << std::endl;
    std::cout << p1 << std::endl;
    std::cout << p2 << std::endl;
    
    std::cout << "======" << std::endl;
    
    return 0;
}