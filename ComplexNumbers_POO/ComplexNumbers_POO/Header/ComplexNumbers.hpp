#include <iostream>
#include <string>
#include <cstring>

class Complex
{
private:
    double m_real, m_imag;
    
public:
   
    Complex();
    Complex(double m_r = 0, double m_im = 0);
    Complex(const Complex &);
    
    void setReal(double);
    double getReal();
    void setImag(double);
    double getImag ();
    
    // Composed overloaded operators
    
    Complex& operator = (const Complex &);
    Complex& operator = (const double &);
    
    Complex& operator += (const Complex &);
    Complex& operator += (const double &);
    
    Complex& operator -= (const Complex &);
    Complex& operator -= (const double &);
    
    Complex& operator *= (const Complex &);
    Complex& operator *= (const double &);
    
    Complex& operator /= (const Complex &);
    Complex& operator /= (const double &);
    
    // Relational operators
    
    friend bool operator == (const Complex&, const Complex&);
    friend bool operator == (const Complex&, double);
    friend bool operator == (double, const Complex&);
    
    friend bool operator != (const Complex&, const Complex&);
    friend bool operator != (const Complex&, double );
    friend bool operator != (double , const Complex&);
    
    // Binary overloaded operators
    
    friend Complex operator + (const Complex &, const Complex &);
    friend Complex operator + (const Complex &, const double &);
    friend Complex operator + (const double &, const Complex &);
    
    friend Complex operator - (const Complex &, const Complex &);
    friend Complex operator - (const Complex &, const double &);
    friend Complex operator - (const double &, const Complex &);
    
    friend Complex operator * (const Complex &, const Complex &);
    friend Complex operator * (const Complex &, const double &);
    friend Complex operator * (const double &, const Complex &);
    
    friend Complex operator / (const Complex &, const Complex &);
    friend Complex operator / (const Complex &, const double &);
    friend Complex operator / (const double &, const Complex &);
    
    friend Complex operator ^ (const Complex& , int &);
    
    // Unary overloaded operators
    
    Complex operator + ();
    Complex operator - ();
    
    // toString
    
    std::string toString();
    
    // std::string overloading
    
    operator std::string() const;
    
    // Conjugate
    
    Complex& Conjugate();
    
    friend std::istream& operator >> (std::istream &cin, Complex &c){
        cin >> c.m_real >> c.m_imag;
        return cin;
    }
    friend std::ostream& operator << (std::ostream &cout, Complex &c){
        cout << c.m_real << c.m_imag;
        return cout;
    }
    
    // Modulus
    
    double modulus();
    
    // Square root
    
    Complex& squareRoot(const Complex &, int);
};
