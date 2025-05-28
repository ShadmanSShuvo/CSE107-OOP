#ifndef FRACTIONVECTOR_H
#define FRACTIONVECTOR_H

#include "fraction.h"
#include <iostream>

class FractionVector {
private:
    Fraction* elements;
    int size;

public:
    // Constructor
    FractionVector(int size);

    // Copy constructor
    FractionVector(const FractionVector& other);

    // Assignment operator
    FractionVector& operator=(const FractionVector& other);

    // Destructor
    ~FractionVector();

    // Subscript operator
    Fraction& operator[](int index);
    const Fraction& operator[](int index) const;

    // Vector operations
    FractionVector operator+(const FractionVector& other) const;
    FractionVector operator-(const FractionVector& other) const;
    Fraction operator*(const FractionVector& other) const; // Dot product

    // Scalar operations
    FractionVector operator*(const Fraction& scalar) const;
    FractionVector operator/(const Fraction& scalar) const;

    // Friend functions for scalar operations
    friend FractionVector operator*(const Fraction& scalar, const FractionVector& vec);

    // Magnitude
    double value() const;

    // Stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const FractionVector& vec);
};

#endif