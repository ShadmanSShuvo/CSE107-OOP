#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>

class Fraction {
private:
    int numerator;
    int denominator;

    // Helper function to reduce fraction to lowest terms
    void simplify();

public:
    // Constructor
    Fraction(int num = 0, int denom = 1);

    // Copy constructor
    Fraction(const Fraction& other);

    // Assignment operator
    Fraction& operator=(const Fraction& other);

    // Destructor
    ~Fraction();

    // Arithmetic operators: Fraction with Fraction
    Fraction operator+(const Fraction& other) const;
    Fraction operator-(const Fraction& other) const;
    Fraction operator*(const Fraction& other) const;
    Fraction operator/(const Fraction& other) const;

    // Arithmetic operators: Fraction with float
    Fraction operator+(float value) const;
    Fraction operator-(float value) const;
    Fraction operator*(float value) const;
    Fraction operator/(float value) const;

    // Friend functions for float with Fraction
    friend Fraction operator+(float value, const Fraction& frac);
    friend Fraction operator-(float value, const Fraction& frac);
    friend Fraction operator*(float value, const Fraction& frac);
    friend Fraction operator/(float value, const Fraction& frac);

    // Compound assignment operators: Fraction
    Fraction& operator+=(const Fraction& other);
    Fraction& operator-=(const Fraction& other);
    Fraction& operator*=(const Fraction& other);
    Fraction& operator/=(const Fraction& other);

    // Compound assignment operators: float
    Fraction& operator+=(float value);
    Fraction& operator-=(float value);
    Fraction& operator*=(float value);
    Fraction& operator/=(float value);

    // Stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac);
};

#endif