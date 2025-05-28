#include "fraction.h"

Fraction::Fraction(int num, int denom) : numerator(num), denominator(denom) {
    // TODO: Handle zero denominator
    // TODO: Simplify fraction
}

Fraction::Fraction(const Fraction& other) : numerator(other.numerator), denominator(other.denominator) {
    // TODO: Implement copy constructor
}

Fraction& Fraction::operator=(const Fraction& other) {
    // TODO: Implement assignment operator
    return *this;
}

Fraction::~Fraction() {
    // TODO: Implement destructor (if needed)
}

void Fraction::simplify() {
    // TODO: Implement fraction simplification using GCD
}

// Arithmetic operators: Fraction with Fraction
Fraction Fraction::operator+(const Fraction& other) const {
    // TODO: Implement addition
    return Fraction();
}

Fraction Fraction::operator-(const Fraction& other) const {
    // TODO: Implement subtraction
    return Fraction();
}

Fraction Fraction::operator*(const Fraction& other) const {
    // TODO: Implement multiplication
    return Fraction();
}

Fraction Fraction::operator/(const Fraction& other) const {
    // TODO: Implement division
    return Fraction();
}

// Arithmetic operators: Fraction with float
Fraction Fraction::operator+(float value) const {
    // TODO: Implement Fraction + float
    return Fraction();
}

Fraction Fraction::operator-(float value) const {
    // TODO: Implement Fraction - float
    return Fraction();
}

Fraction Fraction::operator*(float value) const {
    // TODO: Implement Fraction * float
    return Fraction();
}

Fraction Fraction::operator/(float value) const {
    // TODO: Implement Fraction / float
    return Fraction();
}

// Friend functions: float with Fraction
Fraction operator+(float value, const Fraction& frac) {
    // TODO: Implement float + Fraction
    return Fraction();
}

Fraction operator-(float value, const Fraction& frac) {
    // TODO: Implement float - Fraction
    return Fraction();
}

Fraction operator*(float value, const Fraction& frac) {
    // TODO: Implement float * Fraction
    return Fraction();
}

Fraction operator/(float value, const Fraction& frac) {
    // TODO: Implement float / Fraction
    return Fraction();
}

// Compound assignment operators: Fraction
Fraction& Fraction::operator+=(const Fraction& other) {
    // TODO: Implement += with Fraction
    return *this;
}

Fraction& Fraction::operator-=(const Fraction& other) {
    // TODO: Implement -= with Fraction
    return *this;
}

Fraction& Fraction::operator*=(const Fraction& other) {
    // TODO: Implement *= with Fraction
    return *this;
}

Fraction& Fraction::operator/=(const Fraction& other) {
    // TODO: Implement /= with Fraction
    return *this;
}

// Compound assignment operators: float
Fraction& Fraction::operator+=(float value) {
    // TODO: Implement += with float
    return *this;
}

Fraction& Fraction::operator-=(float value) {
    // TODO: Implement -= with float
    return *this;
}

Fraction& Fraction::operator*=(float value) {
    // TODO: Implement *= with float
    return *this;
}

Fraction& Fraction::operator/=(float value) {
    // TODO: Implement /= with float
    return *this;
}

std::ostream& operator<<(std::ostream& os, const Fraction& frac) {
    // TODO: Implement stream insertion
    return os;
}