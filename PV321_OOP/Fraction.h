#pragma once
#include<iostream>

using namespace std;


class Fraction {

private:
    int numerator;
    int denominator;

public:
    Fraction(){}
    Fraction(int num) {}
    Fraction(int num, int denom) : numerator(num), denominator(denom) {
        simplify();
    }

    // ����������� ���������� �������� �������
    int gcd(int a, int b) {
        while (b) {
            int temp = b;
            b = a % b;
            a = temp;
        }
        return a;
    }

    // ��������� �����
    void simplify() {
        int common = gcd(numerator, denominator);
        numerator /= common;
        denominator /= common;
    }

    //����
    void display() {
        cout << numerator << '/' << denominator;
    }

    // ��������� 
    Fraction add(const Fraction& other) {
        int newNumerator = (numerator * other.denominator) + (other.numerator * denominator);
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    // ³������� 
    Fraction subtract(const Fraction& other) {
        int newNumerator = (numerator * other.denominator) - (other.numerator * denominator);
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    // �������� 
    Fraction multiply(const Fraction& other) {
        int newNumerator = numerator * other.numerator;
        int newDenominator = denominator * other.denominator;
        return Fraction(newNumerator, newDenominator);
    }

    // ĳ�����
    Fraction divide(const Fraction& other) {
        int newNumerator = numerator * other.denominator;
        int newDenominator = denominator * other.numerator;
        return Fraction(newNumerator, newDenominator);
    }

    friend Fraction operator+(Fraction f1, Fraction f2);
};


Fraction operator+(Fraction f1, Fraction f2)
{
    int newNumerator = (f1.numerator * f2.denominator) + (f2.numerator * f1.denominator);
    int newDenominator = f1.denominator * f2.denominator;
    return Fraction(newNumerator, newDenominator);
}