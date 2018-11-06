//
//  main.cpp
//  ComplexNumbers
//
//  Created by Daria Timofte on 05/11/2018.
//  Copyright © 2018 Daria Timofte. All rights reserved.
//

#include <iostream>
#include "ComplexNumbers.hpp"
int main() {
    
    Complex complex(4, 2);
    Complex c("a+bi");
    
    complex = Complex(c);
    
    Complex c1(0,0);
    c1.setReal(2);
    c1.setImag(3);
    
    c1.getReal();
    c1.getImag();
    
    Complex sum = complex + c1;
    Complex diff = complex - c1;
    Complex div = complex / c1;
    Complex mult = complex * c1;
    Complex exp = complex ^ 2;
    
    double b = 2.0;
    Complex sum1 = complex + b;
    Complex diff1 = complex - b;
    Complex div1 = complex / b;
    Complex mult1 = complex * b;
    
    std::cout << sum << diff << div << mult << exp;
    std::cout << sum1 << diff1 << div1 << mult1;
    
    std::cout << c.toString();
    std::cout << complex.Conjugate();
    std::cout << complex.modulus();
    std::cout << complex.squareRoot(c1, 2);
    
    c.operator+();
    c.operator-();
    
    complex.operator*=(c1);
    complex.operator*=(3.0);
    complex.operator=(c1);
    complex.operator=(2.0);
    complex.operator+=(c);
    complex.operator+=(4.0);
    complex.operator-=(c);
    complex.operator-=(3.0);
    complex.operator/=(c1);
    complex.operator/=(2.0);
    
    return 0;
}
