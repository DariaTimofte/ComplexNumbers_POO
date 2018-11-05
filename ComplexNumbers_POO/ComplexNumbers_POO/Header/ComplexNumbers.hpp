#include <iostream>

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
    
    Complex& operator = (const Complex &);
    Complex& operator = (const double &);
    
    Complex& operator += (const Complex &);
    Complex& operator += (const double &);
    
    friend bool operator == (const Complex&, const Complex&);
    friend bool operator == (const Complex&, double);
    friend bool operator == (double, const Complex&);
    
    friend bool operator != (const Complex&, const Complex&);
    friend bool operator != (const Complex&, double );
    friend bool operator != (double , const Complex&);
    
    friend Complex operator + (const Complex &a, const Complex &b);
    friend Complex operator - (const Complex &a, const Complex &b);
    
    
    friend std::istream& operator >> (std::istream &cin, Complex &c){
        cin >> c.m_real >> c.m_imag;
        return cin;
    }
    friend std::ostream& operator << (std::ostream &cout, Complex &c){
        cout << c.m_real << c.m_imag;
        return cout;
    }
    
    
};
