#pragma once
#include<iostream>

using namespace std;


class Fraction {

private:
    int numerator;
    int denominator;

public:
    Fraction() : Fraction(0){}
    Fraction(int num) : Fraction(num, 1) {}
    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        simplify();
        cout << "Ctor F" << endl;
    }

    ~Fraction()
    {
        cout << "Destr F" << endl;
    }

    // знаходження найбільшого спільного дільника
    int gcd(int a, int b) {
        while (b) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // спрощення дробу
    void simplify() {
        int common = gcd(abs(numerator), abs(denominator));
        numerator /= common;
        denominator /= common;
    }

    //вивід
    void display() {
        cout << this << " " << numerator << '/' << denominator << endl;
    }

    // Додавання 
    Fraction operator + (const Fraction& other) {
        int newNumerator = (numerator * other.denominator) + (other.numerator * denominator);
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    // Віднімання 
    Fraction operator - (const Fraction& other) {
        int newNumerator = (numerator * other.denominator) - (other.numerator * denominator);
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    // Множення 
    Fraction operator * (const Fraction& other) {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    // Ділення
    Fraction operator / (const Fraction& other) {
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.numerator;
        return Fraction(newNumerator, newDenominator);
    }

    Fraction operator -()
    {
        return Fraction(-numerator, denominator);
    }

    Fraction operator++() // prefix
    {
        numerator += denominator;
        return *this;
    }

    Fraction operator++(int) // postfix
    {
        Fraction temp = *this;
        numerator += denominator;
        return temp;
    }

    void operator += (const Fraction& other)
    {
        *this = *this + other;
    }

    void operator -= (const Fraction& other)
    {

    }

    void operator *= (const Fraction& other)
    {

    }

    void operator /= (const Fraction& other)
    {

    }

    auto operator<=>(const Fraction& other)
    {
        return (float)numerator / denominator <=> (float)other.numerator / other.denominator;
    }

    /*bool operator > (const Fraction& other)
    {
        return (float)numerator / denominator > (float)other.numerator / other.denominator;
    }

    bool operator < (const Fraction& other)
    {
        return (float)numerator / denominator < (float)other.numerator / other.denominator;
    }

    bool operator == (const Fraction& other)
    {
        return false;
    }

    bool operator != (const Fraction& other)
    {
        return false;
    }*/

    operator float()
    {
        return (float)numerator / denominator;
    }

    operator double()
    {
        return (double)numerator / denominator;
    }

    operator Student()
    {
        return Student("numerator", denominator, numerator);
    }

    friend Fraction operator+(int n, Fraction f2);

    void operator()(int n, int d)
    {
        numerator = n;
        denominator = d;
    }

    friend ostream& operator<<(ostream& out, const Fraction& f);

    friend istream& operator>>(istream& in, Fraction& f);
};


//Fraction operator+(Fraction f1, Fraction f2)
//{
//    int newNumerator = (f1.numerator * f2.denominator) + (f2.numerator * f1.denominator);
//    int newDenominator = f1.denominator * f2.denominator;
//    return Fraction(newNumerator, newDenominator);
//}

Fraction operator+(int n, Fraction f2)
{
    return Fraction(n * f2.denominator + f2.numerator, f2.denominator);
}

ostream& operator<<(ostream& out, const Fraction& f)
{
    out << f.numerator << '/' << f.denominator;
    return out;
}

istream& operator>>(istream& in, Fraction& f)
{
    cout << "Numerator   : ";
    in >> f.numerator;
    cout << "Denominator : ";
    in >> f.denominator;
    f.simplify();
    return in;
}
