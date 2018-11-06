//
//  ComplexNumbers.cpp
//  ComplexNumbers
//
//  Created by Daria Timofte on 05/11/2018.
//  Copyright © 2018 Daria Timofte. All rights reserved.
//

#include "ComplexNumbers.hpp"
#include <iostream>
#include <math.h>

// Constructors

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

Complex::Complex(std::string str)
{
    m_real = 0;
    m_imag = 0;
    int sign = 1;
    bool hasReal = true, hasSign = false, hasImag = false;
    if (str[0] == '-')
    {
        sign = -1;
        hasSign = true;
    }
    if (str[0] == 'i' || str[1] == 'i')
    {
        hasReal = false;
        hasImag = true;
    }
    unsigned long int start = 0;
    unsigned long end = 0;
    if (hasReal == true)
    {
        if (hasSign)
            start = 1;
            else
                start = 0;
        
                end = str.length();
                for (int i = start + 1; i < str.length(); i++)
                {
                    if (strchr("0123456789.", str[i]) == NULL)
                    {
                        end = i;
                        break;
                    }
                }
        
        m_real = sign * std::stod(str.substr(start, end - start));
        
    }

    if (hasReal && end < str.length())
    {
        if (str[end] == '-')
            sign = -1;
            else
                sign = 1;
                hasImag = true;
                }

    if (hasImag)
    {
        if (!hasReal)
        {
            if (hasSign)
                start = 3;
                else
                    start = 2;
                    }
        else
            start = end + 3;
            m_imag = sign * std::stod(str.substr(start, str.length()-start));
            }


    }

Complex::Complex(const Complex &c2) //Copy constructor
{
    m_real = c2.m_real;
    m_imag = c2.m_imag;
}

// Getters and setters

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

// Unary overloaded operators

Complex Complex::operator + ()
{
    return *this;
}

Complex Complex::operator - ()
{
    this->m_real = m_real * (-1);
    this->m_imag = m_imag * (-1);
    
    return *this;
}

// Binary overloaded operators

Complex operator - (const Complex &a, const Complex &b)
{
    Complex rez(0,0);
    
    rez.m_real = a.m_real - b.m_real;
    rez.m_imag = a.m_imag - b.m_imag;
    
    return rez;
}

Complex operator - (const Complex &a, const double &b)
{
    Complex rez(0,0);
    
    rez = (a.m_real - b) + a.m_imag;
    
    return rez;
}

Complex operator - (const double &a, const Complex &b)
{
    Complex rez(0,0);
    
    rez = (a - b.m_real) + b.m_imag;
    
    return rez;
} 

Complex operator + (const Complex &a, const Complex &b)
{
    Complex rez(0,0);
    
    rez.m_real = a.m_real + b.m_real;
    rez.m_imag = a.m_imag + b.m_imag;
    
    return rez;
}

Complex operator + (const Complex &a, const double &b)
{
    Complex rez(0,0);
    
    rez = (a.m_real + b) + a.m_imag;
    
    return rez;
}

Complex operator + (const double &a, const Complex &b)
{
    Complex rez(0,0);
    
    rez = (a + b.m_real) + b.m_imag;
    
    return rez;
}

Complex operator * (const Complex &a, const Complex &b)
{
    Complex rez(0,0);
    
    rez.m_real = a.m_real * b.m_real;
    rez.m_imag = a.m_imag * b.m_imag;
    
    return rez;
}

Complex operator * (const Complex &a, const double &b)
{
    Complex rez(0,0);
    
    rez = (a.m_real * b) + a.m_imag;
    
    return rez;
}

Complex operator * (const double &a, const Complex &b)
{
    Complex rez(0,0);
    
    rez = (a * b.m_real) +b.m_imag;
    
    return rez;
}

Complex operator / (const Complex &a, const Complex &b)
{
    Complex rez(0,0);
    
    rez.m_real = a.m_real / b.m_real;
    rez.m_imag = b.m_imag / b.m_imag;
    
    return rez;
}

Complex operator / (const Complex &a, const double &b)
{
    Complex rez(0,0);
    
    rez = (a.m_real / b) + a.m_imag;
    
    return rez;
}

Complex operator / (const double &a, const Complex &b)
{
    Complex rez(0,0);
    
    rez = (a / b.m_real) + b.m_imag;
    
    return rez;
}

Complex operator ^ (const Complex& a, int n)
{
    if(n==0)
    {
        Complex rez(1,0);
        return rez;
    }
    Complex rez(a);
    if (n == 1) {
        return rez;
    }
    
    for(int i=2;i<=n;i++)
    {
        rez *= a;
    }
    return rez;
}

// Composed overloaded operators

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

Complex& Complex::operator -= (const Complex &c)
{
    m_real -= c.m_real;
    m_imag -= c.m_imag;
    return *this;
}

Complex& Complex::operator -= (const double &d)
{
    m_real -= d;
    return *this;
}

Complex& Complex::operator *= (const Complex &c)
{
    m_real *= c.m_real;
    m_imag *= c.m_imag;
    return *this;
}

Complex& Complex::operator *= (const double &d)
{
    m_real *= d;
    return *this;
}

Complex& Complex::operator /= (const Complex &c)
{
    *this = *this / c;
    return *this;
}

Complex& Complex::operator /= (const double &d)
{
    this->m_real /= d;
    this->m_imag /= d;
    return *this;
}

//Relational operators

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

// toString

std::string Complex::toString()
{
    std::string s ="";
    if(this->m_real != 0)
    {
        s += std::to_string(this->m_real);
    }
    if(this->m_imag != 0)
    {
        if(this->m_imag > 0)
        {
            if(this->m_real != 0)
            {
                s += "+i";
            }
            else
            {
                s += "-i";
            }
            s += std::to_string(this->m_imag);
        }
        else
        {
            s += "-i";
            s += std::to_string(abs(this->m_imag));
        }
    }
    return s;
}

// std::string overloading

Complex::operator std::string() const
{
    Complex c(*this);
    return c.toString();
}


// Conjugate

Complex& Complex::Conjugate()
{
    Complex c(*this);
    
    c.m_imag = - c.m_imag;
    
    return c;
}

// Modulus

double Complex::modulus()
{
    return sqrt(this->m_real * this->m_real + this->m_imag * this->m_imag);
}

// Square root

Complex& Complex::squareRoot(const Complex &c, int n)
{
    Complex c1(c);
    
    double phi = atan(c.m_imag / c.m_real), r = c1.modulus();
    
    Complex c2(0,0);
    c2.m_real = sqrt(r) * cos((phi + 2 * n * M_PI) / 2);
    c2.m_imag = sqrt(r) * sin((phi + 2 * n * M_PI) / 2);
    
    return c2;
}

std::istream& operator >> (std::istream &in, Complex &c) 
{
    std::string s;
    char ch;
    in.get(ch);
    while (ch != '\n' && !in.eof()) {
        s += ch;
        in.get(ch);
    }
    Complex aux(s); //aux = temporary variable
    c.m_real = aux.m_real;
    c.m_imag = aux.m_imag;
    
    return in;
}

std::ostream & operator<<(std::ostream &out, const Complex &c)
{
    Complex aux(c);
    out << aux.toString(); //aux = temporary variable
    return out;
}






