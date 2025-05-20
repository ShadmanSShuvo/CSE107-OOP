#ifndef FRACTIONMATRIX_H
#define FRACTIONMATRIX_H

#include "fractionvector.h"
#include <iostream>

class FractionMatrix {
private:
    FractionVector* rows;
    FractionVector* columns;
    int numRows;
    int numCols;

public:
    // Constructor
    FractionMatrix(int rows, int cols);

    // Copy constructor
    FractionMatrix(const FractionMatrix& other);

    // Assignment operator
    FractionMatrix& operator=(const FractionMatrix& other);

    // Destructor
    ~FractionMatrix();

    // Subscript operator
    FractionVector& operator[](int index);
    const FractionVector& operator[](int index) const;

    // Get column
    FractionVector getColumn(int index) const;

    // Matrix operations
    FractionMatrix operator+(const FractionMatrix& other) const;
    FractionMatrix operator-(const FractionMatrix& other) const;
    FractionMatrix operator*(const FractionMatrix& other) const; // Matrix multiplication
    FractionMatrix operator%(const FractionMatrix& other) const; // Hadamard product

    // Scalar operations
    FractionMatrix operator*(const Fraction& scalar) const;
    FractionMatrix operator/(const Fraction& scalar) const;

    // Friend function for scalar multiplication
    friend FractionMatrix operator*(const Fraction& scalar, const FractionMatrix& mat);

    // Transpose
    FractionMatrix transpose() const;

    // Stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const FractionMatrix& mat);
};

#endif