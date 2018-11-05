//
//  ComplexNumbers.cpp
//  ComplexNumbers
//
//  Created by Daria Timofte on 05/11/2018.
//  Copyright © 2018 Daria Timofte. All rights reserved.
//

#include "ComplexNumbers.hpp"
#include <iostream>
Complex::Complex()
{
    m_real=0;
    m_imag=0;
}

Complex::Complex(double m_r, double m_im)
{
    m_real = m_r;
    m_imag = m_im;
}

Complex::Complex(const Complex &c2) //Copy constructor
{
    m_real = c2.m_real;
    m_imag = c2.m_imag;
}

void Complex::setReal(double m_r)
{
    m_real = m_r;
}

double Complex::getReal()
{
    return m_real;
}

void Complex::setImag(double m_im)
{
    m_imag = m_im;
}

double Complex::getImag()
{
    return m_imag;
}

Complex& Complex::operator = (const Complex &c)
{
    if(this != &c)
    {
        m_real = c.m_real;
        m_imag = c.m_imag;
    }
    return *this;
}

Complex& Complex::operator = (const double &d)
{
        m_real = d;
        m_imag = 0;
    return *this;
}

Complex operator - (const Complex &a, const Complex &b)
{
    Complex rez(0,0);
    
    rez.m_real = a.m_real - b.m_real;
    rez.m_imag = a.m_imag - b.m_imag;
    
    return rez;
}

Complex operator + (const Complex &a, const Complex &b)
{
    Complex rez(0,0);
    
    rez.m_real = a.m_real + b.m_real;
    rez.m_imag = a.m_imag + b.m_imag;
    return rez;
}

Complex& Complex::operator += (const Complex &c)
{
    m_real += c.m_real;
    m_imag += c.m_imag;
    return *this;
}

Complex& Complex::operator += (const double &d)
{
    m_real += d;
    return *this;
}

bool operator == (const Complex &c, const Complex &c2) {
    
    if ((c.m_real == c2.m_real) && (c.m_imag == c2.m_imag))
        return true;
    else
        return false;
}

bool operator == (const Complex &c, double d) {
    
    if ((c.m_real == d) && (c.m_imag == 0))
        return true;
    else
        return false;
}

bool operator == (double d, const Complex &c){
    
    if ((c.m_real == d) && (c.m_imag == 0))
        return true;
    else
        return false;
}

bool operator != (const Complex &c, const Complex &c2) {
    
    if (c.m_real != c2.m_real || c.m_imag != c2.m_imag)
        return true;
    else
        return false;
}

bool operator != (const Complex &c, const double d){
    
    if (c.m_real != d || c.m_imag != 0)
        return true;
    else
        return false;
}

bool operator != (double d, const Complex &c) {
    
    if (c.m_real != d || c.m_imag != 0)
        return true;
    else
        return false;
}
