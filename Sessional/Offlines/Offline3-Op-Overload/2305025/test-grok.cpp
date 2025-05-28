#include <cassert>
#include <sstream>
#include <string>
#include "frac.h" // Assume the provided code is in fraction.h

using namespace std;

// Helper function to capture cout output
string captureOutput(const function<void()>& func) {
    stringstream buffer;
    streambuf* old = cout.rdbuf(buffer.rdbuf());
    func();
    cout.rdbuf(old);
    return buffer.str();
}

// Test cases for Fraction class
void testFraction() {
    cout << "Testing Fraction class...\n";

    // Test default constructor
    Fraction f1;
    assert(f1.getnumerator() == 0 && f1.getdenominator() == 1 && "Default constructor failed");

    // Test single integer constructor
    Fraction f2(5);
    assert(f2.getnumerator() == 5 && f2.getdenominator() == 1 && "Single integer constructor failed");

    // Test numerator/denominator constructor
    Fraction f3(6, 8);
    assert(f3.getnumerator() == 3 && f3.getdenominator() == 4 && "Constructor with reduction failed");

    // Test zero denominator
    auto testZeroDenom = []() { Fraction f(1, 0); };
    string output = captureOutput(testZeroDenom);
    assert(output.find("Denominator cannot be zero") != string::npos && "Zero denominator handling failed");

    // Test negative denominator
    Fraction f4(2, -3);
    assert(f4.getnumerator() == -2 && f4.getdenominator() == 3 && "Negative denominator handling failed");

    // Test arithmetic operations (method-based)
    Fraction f5(1, 2), f6(1, 3);
    Fraction sum = f5.add(f6);
    assert(sum.getnumerator() == 5 && sum.getdenominator() == 6 && "Fraction add method failed");

    Fraction diff = f5.sub(f6);
    assert(diff.getnumerator() == 1 && diff.getdenominator() == 6 && "Fraction subtract method failed");

    Fraction prod = f5.mul(f6);
    assert(prod.getnumerator() == 1 && prod.getdenominator() == 6 && "Fraction multiply method failed");

    Fraction quot = f5.div(f6);
    assert(quot.getnumerator() == 3 && quot.getdenominator() == 2 && "Fraction divide method failed");

    // Test arithmetic with integer
    Fraction f7 = f5.add(1);
    assert(f7.getnumerator() == 3 && f7.getdenominator() == 2 && "Fraction add integer failed");

    // Test division by zero
    auto testDivZero = [&]() { f5.div(0); };
    output = captureOutput(testDivZero);
    assert(output.find("Can not divide by 0") != string::npos && "Division by zero handling failed");

    // Test operator overloading
    Fraction f8 = f5 + f6;
    assert(f8.getnumerator() == 5 && f8.getdenominator() == 6 && "Operator + failed");

    Fraction f9 = f5 * 2.0f;
    assert(f9.getnumerator() == 100 && f9.getdenominator() == 100 && "Operator * float failed");

    // Test compound assignment
    Fraction f10(1, 2);
    f10 += f6;
    assert(f10.getnumerator() == 5 && f10.getdenominator() == 6 && "Operator += failed");

    // Test stream output
    stringstream ss;
    ss << f5;
    assert(ss.str() == "1/2" && "Stream output failed");

    cout << "Fraction class tests passed!\n";
}

// Test cases for FractionVector class
void testFractionVector() {
    cout << "Testing FractionVector class...\n";

    // Test constructor
    FractionVector v1(3);
    assert(v1[0].getnumerator() == 0 && v1[0].getdenominator() == 1 && "Vector constructor failed");

    // Test index operator
    v1[0] = Fraction(1, 2);
    assert(v1[0].getnumerator() == 1 && v1[0].getdenominator() == 2 && "Index operator failed");

    // Test out-of-bounds access
    try {
        v1[3] = Fraction(1, 1);
        assert(false && "Out-of-bounds access not caught");
    } catch (const out_of_range&) {
        assert(true);
    }

    // Test copy constructor
    FractionVector v2(v1);
    assert(v2[0].getnumerator() == 1 && v2[0].getdenominator() == 2 && "Copy constructor failed");

    // Test assignment operator
    FractionVector v3;
    v3 = v1;
    assert(v3[0].getnumerator() == 1 && v3[0].getdenominator() == 2 && "Assignment operator failed");

    // Test vector addition
    FractionVector v4(2), v5(2);
    v4[0] = Fraction(1, 2); v4[1] = Fraction(1, 3);
    v5[0] = Fraction(1, 3); v5[1] = Fraction(1, 4);
    FractionVector sum = v4 + v5;
    assert(sum[0].getnumerator() == 5 && sum[0].getdenominator() == 6 && "Vector addition failed");

    // Test vector subtraction
    FractionVector diff = v4 - v5;
    assert(diff[0].getnumerator() == 1 && diff[0].getdenominator() == 6 && "Vector subtraction failed");

    // Test scalar multiplication
    Fraction scalar(2, 1);
    FractionVector prod = v4 * scalar;
    assert(prod[0].getnumerator() == 1 && prod[0].getdenominator() == 1 && "Scalar multiplication failed");

    // Test dot product
    Fraction dot = v4 * v5;
    assert(dot.getnumerator() == 11 && dot.getdenominator() == 36 && "Dot product failed");

    // Test magnitude
    FractionVector v6(2);
    v6[0] = Fraction(3, 1); v6[1] = Fraction(4, 1);
    Fraction mag = v6.value();
    assert(mag.getnumerator() == 500 && mag.getdenominator() == 100 && "Magnitude failed");

    // Test size mismatch
    FractionVector v7(3);
    try {
        v4 + v7;
        assert(false && "Size mismatch not caught");
    } catch (const length_error&) {
        assert(true);
    }

    cout << "FractionVector class tests passed!\n";
}

// Test cases for FractionMatrix class
void testFractionMatrix() {
    cout << "Testing FractionMatrix class...\n";

    // Test constructor
    FractionMatrix m1(2, 3);
    assert(m1[0][0].getnumerator() == 0 && m1[0][0].getdenominator() == 1 && "Matrix constructor failed");

    // Test row access
    m1[0][0] = Fraction(1, 2);
    assert(m1[0][0].getnumerator() == 1 && m1[0][0].getdenominator() == 2 && "Row access failed");

    // Test column access
    FractionVector col = m1.getColumnCopy(0);
    assert(col[0].getnumerator() == 1 && col[0].getdenominator() == 2 && "Column access failed");

    // Test out-of-bounds row access
    try {
        m1[2][0] = Fraction(1, 1);
        assert(false && "Row out-of-bounds not caught");
    } catch (const out_of_range&) {
        assert(true);
    }

    // Test matrix addition
    FractionMatrix m2(2, 2), m3(2, 2);
    m2[0][0] = Fraction(1, 2); m2[0][1] = Fraction(1, 3);
    m2[1][0] = Fraction(1, 4); m2[1][1] = Fraction(1, 5);
    m3[0][0] = Fraction(1, 3); m3[0][1] = Fraction(1, 4);
    m3[1][0] = Fraction(1, 5); m3[1][1] = Fraction(1, 6);
    FractionMatrix sum = m2 + m3;
    assert(sum[0][0].getnumerator() == 5 && sum[0][0].getdenominator() == 6 && "Matrix addition failed");

    // Test matrix multiplication
    FractionMatrix m4(2, 3), m5(3, 2);
    m4[0][0] = Fraction(1, 1); m4[0][1] = Fraction(2, 1); m4[0][2] = Fraction(3, 1);
    m4[1][0] = Fraction(4, 1); m4[1][1] = Fraction(5, 1); m4[1][2] = Fraction(6, 1);
    m5[0][0] = Fraction(7, 1); m5[0][1] = Fraction(8, 1);
    m5[1][0] = Fraction(9, 1); m5[1][1] = Fraction(10, 1);
    m5[2][0] = Fraction(11, 1); m5[2][1] = Fraction(12, 1);
    FractionMatrix prod = m4 * m5;
    assert(prod[0][0].getnumerator() == 58 && prod[0][0].getdenominator() == 1 && "Matrix multiplication failed");

    // Test Hadamard product
    FractionMatrix hprod = m2 % m3;
    assert(hprod[0][0].getnumerator() == 1 && hprod[0][0].getdenominator() == 6 && "Hadamard product failed");

    // Test transpose
    FractionMatrix trans = m4.transpose();
    assert(trans[0][0].getnumerator() == 1 && trans[0][0].getdenominator() == 1 && "Transpose failed");

    // Test dimension mismatch
    try {
        m2 + m4;
        assert(false && "Matrix dimension mismatch not caught");
    } catch (const invalid_argument&) {
        assert(true);
    }

    cout << "FractionMatrix class tests passed!\n";
}

int main() {
    testFraction();
    testFractionVector();
    testFractionMatrix();
    cout << "All tests passed successfully!\n";
    return 0;
}