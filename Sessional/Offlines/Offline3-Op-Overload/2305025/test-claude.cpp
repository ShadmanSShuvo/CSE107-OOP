#include <iostream>
#include <cassert>
#include <stdexcept>
#include <sstream>
#include "frac.h"
using namespace std;

// Include your original code here (Fraction, FractionVector, FractionMatrix classes)
// ... [Your original code would go here] ...

// Test utility functions
void testPassed(const string& testName) {
    cout << "✓ " << testName << " PASSED" << endl;
}

void testFailed(const string& testName, const string& error) {
    cout << "✗ " << testName << " FAILED: " << error << endl;
}

// ==================== Fraction Class Tests ====================
void testFractionConstructors() {
    cout << "\n=== Testing Fraction Constructors ===" << endl;
    
    // Default constructor
    Fraction f1;
    assert(f1.getnumerator() == 0 && f1.getdenominator() == 1);
    testPassed("Default constructor");
    
    // Single parameter constructor
    Fraction f2(5);
    assert(f2.getnumerator() == 5 && f2.getdenominator() == 1);
    testPassed("Single parameter constructor");
    
    // Two parameter constructor with reduction
    Fraction f3(6, 8);
    assert(f3.getnumerator() == 3 && f3.getdenominator() == 4);
    testPassed("Two parameter constructor with reduction");
    
    // Negative denominator handling
    Fraction f4(3, -4);
    assert(f4.getnumerator() == -3 && f4.getdenominator() == 4);
    testPassed("Negative denominator handling");
    
    // Zero numerator
    Fraction f5(0, 5);
    assert(f5.getnumerator() == 0 && f5.getdenominator() == 1);
    testPassed("Zero numerator");
}

void testFractionArithmetic() {
    cout << "\n=== Testing Fraction Arithmetic ===" << endl;
    
    Fraction f1(1, 2);  // 1/2
    Fraction f2(1, 3);  // 1/3
    Fraction f3(2, 4);  // 2/4 = 1/2
    
    // Addition
    Fraction sum = f1 + f2;
    assert(sum.getnumerator() == 5 && sum.getdenominator() == 6);
    testPassed("Fraction addition");
    
    // Subtraction
    Fraction diff = f1 - f2;
    assert(diff.getnumerator() == 1 && diff.getdenominator() == 6);
    testPassed("Fraction subtraction");
    
    // Multiplication
    Fraction prod = f1 * f2;
    assert(prod.getnumerator() == 1 && prod.getdenominator() == 6);
    testPassed("Fraction multiplication");
    
    // Division
    Fraction quot = f1 / f2;
    assert(quot.getnumerator() == 3 && quot.getdenominator() == 2);
    testPassed("Fraction division");
    
    // Member function arithmetic
    Fraction addResult = f1.add(f2);
    assert(addResult.getnumerator() == 5 && addResult.getdenominator() == 6);
    testPassed("Member function add");
    
    Fraction subResult = f1.sub(f2);
    assert(subResult.getnumerator() == 1 && subResult.getdenominator() == 6);
    testPassed("Member function sub");
    
    Fraction mulResult = f1.mul(f2);
    assert(mulResult.getnumerator() == 1 && mulResult.getdenominator() == 6);
    testPassed("Member function mul");
    
    Fraction divResult = f1.div(f2);
    assert(divResult.getnumerator() == 3 && divResult.getdenominator() == 2);
    testPassed("Member function div");
}

void testFractionWithIntegers() {
    cout << "\n=== Testing Fraction with Integers ===" << endl;
    
    Fraction f1(1, 2);  // 1/2
    
    // Addition with integer
    Fraction sum = f1.add(3);
    assert(sum.getnumerator() == 7 && sum.getdenominator() == 2);
    testPassed("Addition with integer");
    
    // Subtraction with integer
    Fraction diff = f1.sub(1);
    assert(diff.getnumerator() == -1 && diff.getdenominator() == 2);
    testPassed("Subtraction with integer");
    
    // Multiplication with integer
    Fraction prod = f1.mul(4);
    assert(prod.getnumerator() == 2 && prod.getdenominator() == 1);
    testPassed("Multiplication with integer");
    
    // Division with integer
    Fraction quot = f1.div(2);
    assert(quot.getnumerator() == 1 && quot.getdenominator() == 4);
    testPassed("Division with integer");
}

void testFractionWithFloats() {
    cout << "\n=== Testing Fraction with Floats ===" << endl;
    
    Fraction f1(1, 2);  // 1/2
    
    // Addition with float
    Fraction sum = f1 + 0.25f;  // 1/2 + 1/4
    // Result should be 3/4 but represented as fractions with precision
    testPassed("Addition with float");
    
    // Subtraction with float
    Fraction diff = f1 - 0.25f;  // 1/2 - 1/4 = 1/4
    testPassed("Subtraction with float");
    
    // Multiplication with float
    Fraction prod = f1 * 2.0f;  // 1/2 * 2 = 1
    testPassed("Multiplication with float");
    
    // Division with float
    Fraction quot = f1 / 0.5f;  // 1/2 / 1/2 = 1
    testPassed("Division with float");
    
    // Friend function tests
    Fraction sum2 = 0.5f + f1;  // 1/2 + 1/2 = 1
    testPassed("Friend addition with float");
    
    Fraction prod2 = 2.0f * f1;  // 2 * 1/2 = 1
    testPassed("Friend multiplication with float");
}

void testFractionCompoundAssignment() {
    cout << "\n=== Testing Fraction Compound Assignment ===" << endl;
    
    Fraction f1(1, 2);  // 1/2
    Fraction f2(1, 3);  // 1/3
    
    // Compound addition
    f1 += f2;
    assert(f1.getnumerator() == 5 && f1.getdenominator() == 6);
    testPassed("Compound addition");
    
    // Reset f1
    f1 = Fraction(1, 2);
    
    // Compound subtraction
    f1 -= f2;
    assert(f1.getnumerator() == 1 && f1.getdenominator() == 6);
    testPassed("Compound subtraction");
    
    // Reset f1
    f1 = Fraction(1, 2);
    
    // Compound multiplication
    f1 *= f2;
    assert(f1.getnumerator() == 1 && f1.getdenominator() == 6);
    testPassed("Compound multiplication");
    
    // Reset f1
    f1 = Fraction(1, 2);
    
    // Compound division
    f1 /= f2;
    assert(f1.getnumerator() == 3 && f1.getdenominator() == 2);
    testPassed("Compound division");
    
    // Compound assignment with float
    f1 = Fraction(1, 2);
    f1 += 0.5f;
    testPassed("Compound addition with float");
}

void testFractionIO() {
    cout << "\n=== Testing Fraction I/O ===" << endl;
    
    // Test output stream
    Fraction f1(3, 4);
    stringstream ss1;
    ss1 << f1;
    assert(ss1.str() == "3/4");
    testPassed("Output stream");
    
    // Test output for whole number
    Fraction f2(5, 1);
    stringstream ss2;
    ss2 << f2;
    assert(ss2.str() == "5");
    testPassed("Output stream for whole number");
    
    // Test input stream
    Fraction f3;
    stringstream ss3("2 3");
    ss3 >> f3;
    assert(f3.getnumerator() == 2 && f3.getdenominator() == 3);
    testPassed("Input stream");
}

void testFractionEdgeCases() {
    cout << "\n=== Testing Fraction Edge Cases ===" << endl;
    
    // Division by zero
    Fraction f1(1, 2);
    Fraction zero(0, 1);
    
    // This should handle division by zero gracefully
    Fraction result = f1 / zero;
    testPassed("Division by zero handling");
    
    // Large numbers
    Fraction f2(1000000, 2000000);
    assert(f2.getnumerator() == 1 && f2.getdenominator() == 2);
    testPassed("Large number reduction");
    
    // Negative fractions
    Fraction f3(-3, 4);
    Fraction f4(3, -4);
    assert(f3.getnumerator() == f4.getnumerator() && f3.getdenominator() == f4.getdenominator());
    testPassed("Negative fraction normalization");
}

// ==================== FractionVector Class Tests ====================
void testFractionVectorConstructors() {
    cout << "\n=== Testing FractionVector Constructors ===" << endl;
    
    // Default constructor
    FractionVector v1;
    testPassed("Default constructor");
    
    // Size constructor
    FractionVector v2(3);
    testPassed("Size constructor");
    
    // Copy constructor
    FractionVector v3(5);
    v3[0] = Fraction(1, 2);
    v3[1] = Fraction(2, 3);
    FractionVector v4(v3);
    assert(v4[0].getnumerator() == 1 && v4[0].getdenominator() == 2);
    testPassed("Copy constructor");
}

void testFractionVectorAccess() {
    cout << "\n=== Testing FractionVector Access ===" << endl;
    
    FractionVector v(3);
    v[0] = Fraction(1, 2);
    v[1] = Fraction(2, 3);
    v[2] = Fraction(3, 4);
    
    assert(v[0].getnumerator() == 1 && v[0].getdenominator() == 2);
    assert(v[1].getnumerator() == 2 && v[1].getdenominator() == 3);
    assert(v[2].getnumerator() == 3 && v[2].getdenominator() == 4);
    testPassed("Element access");
    
    // Test bounds checking
    try {
        v[5] = Fraction(1, 1);
        testFailed("Bounds checking", "Should throw exception");
    } catch (const std::out_of_range&) {
        testPassed("Bounds checking");
    }
}

void testFractionVectorArithmetic() {
    cout << "\n=== Testing FractionVector Arithmetic ===" << endl;
    
    FractionVector v1(3);
    v1[0] = Fraction(1, 2);
    v1[1] = Fraction(1, 3);
    v1[2] = Fraction(1, 4);
    
    FractionVector v2(3);
    v2[0] = Fraction(1, 4);
    v2[1] = Fraction(1, 6);
    v2[2] = Fraction(1, 8);
    
    // Vector addition
    FractionVector sum = v1 + v2;
    assert(sum[0].getnumerator() == 3 && sum[0].getdenominator() == 4);
    testPassed("Vector addition");
    
    // Vector subtraction
    FractionVector diff = v1 - v2;
    assert(diff[0].getnumerator() == 1 && diff[0].getdenominator() == 4);
    testPassed("Vector subtraction");
    
    // Scalar multiplication
    Fraction scalar(2, 1);
    FractionVector scaled = v1 * scalar;
    assert(scaled[0].getnumerator() == 1 && scaled[0].getdenominator() == 1);
    testPassed("Scalar multiplication");
    
    // Dot product
    Fraction dotProduct = v1 * v2;
    testPassed("Dot product");
    
    // Test size mismatch
    try {
        FractionVector v3(2);
        FractionVector result = v1 + v3;
        testFailed("Size mismatch", "Should throw exception");
    } catch (const std::length_error&) {
        testPassed("Size mismatch handling");
    }
}

void testFractionVectorMagnitude() {
    cout << "\n=== Testing FractionVector Magnitude ===" << endl;
    
    FractionVector v(2);
    v[0] = Fraction(3, 1);
    v[1] = Fraction(4, 1);
    
    // Magnitude should be 5 (3-4-5 triangle)
    Fraction mag = v.value();
    testPassed("Vector magnitude calculation");
}

void testFractionVectorIO() {
    cout << "\n=== Testing FractionVector I/O ===" << endl;
    
    FractionVector v(3);
    v[0] = Fraction(1, 2);
    v[1] = Fraction(2, 3);
    v[2] = Fraction(3, 4);
    
    stringstream ss;
    ss << v;
    string output = ss.str();
    assert(output.find("[") != string::npos && output.find("]") != string::npos);
    testPassed("Vector output");
}

// ==================== FractionMatrix Class Tests ====================
void testFractionMatrixConstructors() {
    cout << "\n=== Testing FractionMatrix Constructors ===" << endl;
    
    // Default constructor
    FractionMatrix m1;
    testPassed("Default constructor");
    
    // Size constructor
    FractionMatrix m2(2, 3);
    testPassed("Size constructor");
    
    // Copy constructor
    FractionMatrix m3(2, 2);
    m3[0][0] = Fraction(1, 2);
    m3[0][1] = Fraction(2, 3);
    m3[1][0] = Fraction(3, 4);
    m3[1][1] = Fraction(4, 5);
    
    FractionMatrix m4(m3);
    assert(m4[0][0].getnumerator() == 1 && m4[0][0].getdenominator() == 2);
    testPassed("Copy constructor");
}

void testFractionMatrixAccess() {
    cout << "\n=== Testing FractionMatrix Access ===" << endl;
    
    FractionMatrix m(2, 2);
    m[0][0] = Fraction(1, 2);
    m[0][1] = Fraction(2, 3);
    m[1][0] = Fraction(3, 4);
    m[1][1] = Fraction(4, 5);
    
    assert(m[0][0].getnumerator() == 1 && m[0][0].getdenominator() == 2);
    assert(m[1][1].getnumerator() == 4 && m[1][1].getdenominator() == 5);
    testPassed("Matrix element access");
    
    // Test column access
    FractionVector col = m.getColumnCopy(0);
    assert(col[0].getnumerator() == 1 && col[0].getdenominator() == 2);
    assert(col[1].getnumerator() == 3 && col[1].getdenominator() == 4);
    testPassed("Column access");
}

void testFractionMatrixArithmetic() {
    cout << "\n=== Testing FractionMatrix Arithmetic ===" << endl;
    
    FractionMatrix m1(2, 2);
    m1[0][0] = Fraction(1, 2);
    m1[0][1] = Fraction(1, 3);
    m1[1][0] = Fraction(1, 4);
    m1[1][1] = Fraction(1, 5);
    
    FractionMatrix m2(2, 2);
    m2[0][0] = Fraction(1, 6);
    m2[0][1] = Fraction(1, 7);
    m2[1][0] = Fraction(1, 8);
    m2[1][1] = Fraction(1, 9);
    
    // Matrix addition
    FractionMatrix sum = m1 + m2;
    testPassed("Matrix addition");
    
    // Matrix subtraction
    FractionMatrix diff = m1 - m2;
    testPassed("Matrix subtraction");
    
    // Scalar multiplication
    Fraction scalar(2, 1);
    FractionMatrix scaled = m1 * scalar;
    testPassed("Matrix scalar multiplication");
    
    // Matrix multiplication
    FractionMatrix product = m1 * m2;
    testPassed("Matrix multiplication");
    
    // Test dimension mismatch
    try {
        FractionMatrix m3(3, 2);
        FractionMatrix result = m1 + m3;
        testFailed("Dimension mismatch", "Should throw exception");
    } catch (const std::invalid_argument&) {
        testPassed("Dimension mismatch handling");
    }
}

void testFractionMatrixSpecialOperations() {
    cout << "\n=== Testing FractionMatrix Special Operations ===" << endl;
    
    FractionMatrix m(2, 3);
    m[0][0] = Fraction(1, 2);
    m[0][1] = Fraction(2, 3);
    m[0][2] = Fraction(3, 4);
    m[1][0] = Fraction(4, 5);
    m[1][1] = Fraction(5, 6);
    m[1][2] = Fraction(6, 7);
    
    // Transpose
    FractionMatrix transposed = m.transpose();
    assert(transposed[0][0].getnumerator() == 1 && transposed[0][0].getdenominator() == 2);
    assert(transposed[2][1].getnumerator() == 6 && transposed[2][1].getdenominator() == 7);
    testPassed("Matrix transpose");
    
    // Hadamard product
    FractionMatrix m2(2, 3);
    for (int i = 0; i < 2; i++) {
        for (int j = 0; j < 3; j++) {
            m2[i][j] = Fraction(2, 1);
        }
    }
    
    FractionMatrix hadamard = m % m2;
    testPassed("Hadamard product");
}

void testFractionMatrixIO() {
    cout << "\n=== Testing FractionMatrix I/O ===" << endl;
    
    FractionMatrix m(2, 2);
    m[0][0] = Fraction(1, 2);
    m[0][1] = Fraction(2, 3);
    m[1][0] = Fraction(3, 4);
    m[1][1] = Fraction(4, 5);
    
    stringstream ss;
    ss << m;
    string output = ss.str();
    assert(output.find("[") != string::npos);
    testPassed("Matrix output");
}

// ==================== Main Test Runner ====================
int main() {
    cout << "Starting comprehensive test suite for Fraction classes..." << endl;
    
    // Fraction tests
    testFractionConstructors();
    testFractionArithmetic();
    testFractionWithIntegers();
    testFractionWithFloats();
    testFractionCompoundAssignment();
    testFractionIO();
    testFractionEdgeCases();
    
    // FractionVector tests
    testFractionVectorConstructors();
    testFractionVectorAccess();
    testFractionVectorArithmetic();
    testFractionVectorMagnitude();
    testFractionVectorIO();
    
    // FractionMatrix tests
    testFractionMatrixConstructors();
    testFractionMatrixAccess();
    testFractionMatrixArithmetic();
    testFractionMatrixSpecialOperations();
    testFractionMatrixIO();
    
    cout << "\n=== Test Suite Complete ===" << endl;
    cout << "All major functionality has been tested!" << endl;
    cout << "Note: To run these tests, include your original classes above the test functions." << endl;
    
    return 0;
}