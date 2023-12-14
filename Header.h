#pragma once
#include <iostream>
#include <string>
using namespace std;

int NOD(int a, int b) {
    while (b > 0) {
        int c = a % b;
        a = b;
        b = c;
    }
    return a;
}

int NOK(int a, int b) {
    return a * b / NOD(a, b);
}

class Fraction {
private:
    // Числитель
    int _numerator;
    // Знаменатель
    int _denominator;
    // Cокращение дроби
    void reduce() {
        int nod = NOD(abs(_numerator), _denominator);
        if (nod != 1) {
            _numerator = _numerator / nod;
            _denominator = _denominator / nod;
        }
    }
public:
    //Конструктор
    Fraction(int numerator, int denominator) {
        if (denominator < 0)
            denominator = abs(denominator);
        else if (denominator == 0) {
            _denominator = 1;
            _numerator = numerator;
        }
        else {
            _numerator = numerator;
            _denominator = denominator;
        }
        reduce();
    }

    int getNumerator() {
        return _numerator;
    }
    int getDenominator() {
        return _denominator;
    }
    string toString() {

        string str;
        str = to_string(getNumerator()) + "/" + to_string(getDenominator());
        return str;
    }
    
    Fraction& operator +(Fraction& fraction) {
        Fraction temp(_numerator, _denominator);
        int generalDenominator = NOK(temp._denominator, fraction.getDenominator());
        int numerator1 = temp.getNumerator() * (generalDenominator / temp.getDenominator());
        int numerator2 = fraction.getNumerator() * (generalDenominator / fraction.getDenominator());
        temp._numerator = numerator1 + numerator2;
        temp._denominator = generalDenominator;
        reduce();
        return temp;
    }
    Fraction& operator +(int number) {
        Fraction temp(_numerator, _denominator);
        temp._numerator = (number * temp._denominator) + temp._numerator;
        reduce();
        return temp;
    }
    Fraction& operator +=(Fraction& fraction) {
        int generalDenominator = NOK(_denominator, fraction.getDenominator());
        int numerator1 = _numerator * (generalDenominator / _denominator);
        int numerator2 = fraction.getNumerator() * (generalDenominator / fraction.getDenominator());
        _numerator = numerator1 + numerator2;
        _denominator = generalDenominator;
        reduce();
        return *this;
    }
    Fraction& operator +=(int number) {
        _numerator += (number * _denominator);
        reduce();
        return *this;
    }

    Fraction& operator -(Fraction& fraction) {
        Fraction temp(_numerator, _denominator);
        int generalDenominator = NOK(_denominator, fraction.getDenominator());
        int numerator1 = temp.getNumerator() * (generalDenominator / temp.getDenominator());
        int numerator2 = fraction.getNumerator() * (generalDenominator / fraction.getDenominator());
        temp._numerator = numerator1 - numerator2;
        temp._denominator = generalDenominator;
        reduce();
        return temp;
    }
    Fraction& operator -(int number) {
        Fraction temp(_numerator, _denominator);
        temp._numerator = temp._numerator - (number * temp._denominator) ;
        reduce();
        return temp;
    }
    Fraction& operator -=(Fraction& fraction) {
        int generalDenominator = NOK(_denominator, fraction.getDenominator());
        int numerator1 = _numerator * (generalDenominator / _denominator);
        int numerator2 = fraction.getNumerator() * (generalDenominator / fraction.getDenominator());
        _numerator = numerator1 - numerator2;
        _denominator = NOK(_denominator, fraction.getDenominator());
        reduce();
        return *this;
    }
    Fraction& operator -=(int number) {
        _numerator -= number * _denominator;
        reduce();
        return *this;
    }

    Fraction& operator *(Fraction& fraction) {
        Fraction temp(_numerator, _denominator);
        temp._numerator = temp._numerator * fraction.getNumerator();
        temp._denominator = temp._denominator * fraction.getDenominator();
        reduce();
        return temp;
    }
    Fraction& operator *(int number) {
        Fraction temp(_numerator, _denominator);
        temp._numerator = temp._numerator * number;
        temp._denominator = temp._denominator * number;
        reduce();
        return temp;
    }
    Fraction& operator *=(Fraction& fraction) {
        _numerator *= fraction.getNumerator();
        _denominator *= fraction.getDenominator();
        reduce();
        return *this;
    }
    Fraction& operator *=(int number) {
        _numerator *= number;
        _denominator *= number;
        reduce();
        return *this;
    }

    Fraction& operator /(Fraction& fraction) {
        Fraction temp(_numerator, _denominator);
        temp._numerator = temp._numerator * fraction.getDenominator();
        temp._denominator = temp._denominator * abs(fraction.getNumerator());
        reduce();
        return temp;
    }
    Fraction& operator /(int number) {
        Fraction temp(_numerator, _denominator);
        if (number == 0)
            number = 1;
        if (number < 0 && _numerator < 0)
            temp._numerator *= -1;
        temp._denominator = temp._denominator * abs(number);
        reduce();
        return *this;
    }
    Fraction& operator /=(Fraction& fraction) {
        _numerator *= fraction.getDenominator();
        _denominator *= abs(fraction.getNumerator());
        reduce();
        return *this;
    }
    Fraction& operator /=(int number) {
        if (number == 0)
            number = 1;
        if (number < 0 && _numerator < 0)
            _numerator *= -1;
        _denominator *= abs(number);
        reduce();
        return *this;
    }

    Fraction& operator -- () {
        Fraction temp = *this;
        _numerator -= _denominator;
        reduce();
        return temp;
    }
    Fraction& operator -- (int) {
        _numerator -= _denominator;
        reduce();
        return *this;
    }

    Fraction& operator ++ () {
        Fraction temp = *this;
        _numerator += _denominator;
        reduce();
        return temp;
    }
    Fraction& operator ++ (int) {
        _numerator += _denominator;
        reduce();
        return *this;
    }

    bool operator < (Fraction& fraction) {
        int generalDenominator = NOK(_denominator, fraction.getDenominator());
        int numerator1 = _numerator * (generalDenominator / _denominator);
        int numerator2 = fraction.getNumerator() * (generalDenominator / fraction.getDenominator());
        return (numerator1 < numerator2);
    }
    bool operator < (int number) {
        return (_numerator < (number * _denominator));
    }
    bool operator <= (Fraction& fraction) {
        int generalDenominator = NOK(_denominator, fraction.getDenominator());
        int numerator1 = _numerator * (generalDenominator / _denominator);
        int numerator2 = fraction.getNumerator() * (generalDenominator / fraction.getDenominator());
        return (numerator1 <= numerator2);
    }
    bool operator <= (int number) {
        return (_numerator <= (number * _denominator));
    }
    bool operator > (Fraction& fraction) {
        int generalDenominator = NOK(_denominator, fraction.getDenominator());
        int numerator1 = _numerator * (generalDenominator / _denominator);
        int numerator2 = fraction.getNumerator() * (generalDenominator / fraction.getDenominator());
        return (numerator1 > numerator2);
    }
    bool operator > (int number) {
        return (_numerator > (number * _denominator));
    }
    bool operator >= (Fraction& fraction) {
        int generalDenominator = NOK(_denominator, fraction.getDenominator());
        int numerator1 = _numerator * (generalDenominator / _denominator);
        int numerator2 = fraction.getNumerator() * (generalDenominator / fraction.getDenominator());
        return (numerator1 >= numerator2);
    }
    bool operator >= (int number) {
        return (_numerator >= (number * _denominator));
    }
};

int toInt(Fraction fraction) {
    return (fraction.getNumerator() / fraction.getDenominator());
}

double toDouble(Fraction fraction) {
    double result = (double)fraction.getNumerator() / fraction.getDenominator();
    return result;
}
