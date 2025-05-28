#include <iostream>
#include <cmath>
#include <stdexcept>
#define precision 100
using namespace std;

// Helper function to compute greatest common divisor
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

// ==================== Fraction Class ====================
class Fraction
{
  private:
    int numerator;
    int denominator;
    void reduce()
    {
        int g = gcd(abs(numerator), abs(denominator));
        numerator /= g;
        denominator /= g;
    }

  public:
    int getnumerator() const { return numerator; }
    int getdenominator() const { return denominator; }
    void setnumerator(int n) { numerator = n; }
    void setdenominator(int d) { denominator = d; }

    Fraction()
    {
        setnumerator(0);
        setdenominator(1);
    }
    Fraction(int n)
    {
        setnumerator(n);
        setdenominator(1);
    }
    Fraction(int num, int denom)
    {
        setnumerator(num);
        setdenominator(denom);
        if (denominator == 0)
        {
            cout << "Denominator cannot be zero" << endl;
            denominator = 1;
        }
        if (denominator < 0)
        {
            numerator = -numerator;
            denominator = -denominator;
        }
        reduce();
    }

    Fraction add(const Fraction &f)
    {
        Fraction result;
        result.numerator = (numerator * f.denominator) + (denominator * f.numerator);
        result.denominator = denominator * f.denominator;
        result.reduce();
        return result;
    }
    Fraction add(const int n)
    {
        Fraction result;
        result.setnumerator((numerator) + (denominator * n));
        result.setdenominator(denominator);
        result.reduce();
        return result;
    }
    Fraction sub(const Fraction &f)
    {
        Fraction result;
        result.setnumerator((numerator * f.denominator) - (denominator * f.numerator));
        result.setdenominator(denominator * f.denominator);
        result.reduce();
        return result;
    }
    Fraction sub(const int n)
    {
        Fraction result((numerator) - (denominator * n), denominator);
        result.reduce();
        return result;
    }
    Fraction mul(const Fraction &f)
    {
        Fraction result;
        result.numerator = numerator * f.numerator;
        result.denominator = denominator * f.denominator;
        result.reduce();
        return result;
    }
    Fraction mul(const int n)
    {
        Fraction result;
        result.numerator = numerator * n;
        result.denominator = denominator;
        result.reduce();
        return result;
    }
    Fraction div(const Fraction &f)
    {
        Fraction result;
        result.numerator = numerator * f.denominator;
        result.denominator = denominator * f.numerator;
        result.reduce();
        return result;
    }
    Fraction div(const int n)
    {
        Fraction result;
        if (n == 0)
        {
            cout << "Can not divide by 0" << endl;
            result.numerator = numerator;
            result.denominator = denominator;
            return result;
        }
        result.numerator = numerator;
        result.denominator = denominator * n;
        result.reduce();
        return result;
    }

    // Arithmetic operators: Fraction with Fraction
    Fraction operator+(const Fraction &other) const
    {
        Fraction temp((numerator * other.denominator + denominator * other.numerator),
                      (denominator * other.denominator));
        return temp;
    }
    Fraction operator-(const Fraction &other) const
    {
        Fraction temp((numerator * other.denominator - denominator * other.numerator),
                      (denominator * other.denominator));
        return temp;
    }
    Fraction operator*(const Fraction &other) const
    {
        Fraction temp((numerator * other.numerator), denominator * other.denominator);
        return temp;
    }
    Fraction operator/(const Fraction &other) const
    {
        if (other.numerator == 0)
        {
            cout << "cannot divide by zero\n";
            return Fraction(numerator, denominator);
        }
        Fraction temp((numerator * other.denominator), (denominator * other.numerator));
        return temp;
    }

    // Arithmetic operators: Fraction with float
    Fraction operator+(float value) const
    {
        int num = value * precision;
        Fraction temp((precision * numerator + num * denominator), (precision * denominator));
        return temp;
    }
    Fraction operator-(float value) const
    {
        int num = value * precision;
        Fraction temp((precision * numerator - num * denominator), (precision * denominator));
        return temp;
    }
    Fraction operator*(float value) const
    {
        int num = value * precision;
        Fraction temp((numerator * num), (precision * denominator));
        return temp;
    }
    Fraction operator/(float value) const
    {
        if (value == 0)
        {
            cout << "cannot divide by zero\n";
            return Fraction(numerator, denominator);
        }

        int num = value * precision;
        Fraction temp((numerator * precision), (num * denominator));
        return temp;
    }

    // Friend functions for float with Fraction
    friend Fraction operator+(float value, const Fraction &frac)
    {
        int num = value * precision;
        Fraction temp((precision * frac.numerator + num * frac.denominator), (precision * frac.denominator));
        return temp;
    }
    friend Fraction operator-(float value, const Fraction &frac)
    {
        int num = value * precision;
        Fraction temp((precision * frac.numerator - num * frac.denominator), (precision * frac.denominator));
        return temp;
    }
    friend Fraction operator*(float value, const Fraction &frac)
    {
        int num = value * precision;
        Fraction temp((frac.numerator * num), (precision * frac.denominator));
        return temp;
    }
    friend Fraction operator/(float value, const Fraction &frac)
    {
        if (frac.numerator == 0)
        {
            cout << "cannot divide by zero\n";
            return Fraction(frac.numerator, frac.denominator);
        }

        int num = value * precision;
        Fraction temp((frac.numerator * precision), (num * frac.denominator));
        return temp;
    }

    // Compound assignment operators: Fraction
    Fraction &operator+=(const Fraction &other)
    {
        numerator = (numerator * other.denominator + denominator * other.numerator);
        denominator = (denominator * other.denominator);
        reduce();
        return *this;
    }
    Fraction &operator-=(const Fraction &other)
    {
        numerator = (numerator * other.denominator - denominator * other.numerator);
        denominator = (denominator * other.denominator);
        reduce();
        return *this;
    }
    Fraction &operator*=(const Fraction &other)
    {
        numerator = (numerator * other.numerator);
        denominator = denominator * other.denominator;
        reduce();
        return *this;
    }
    Fraction &operator/=(const Fraction &other)
    {
        if (other.numerator == 0)
        {
            cout << "cannot divide by zero\n";
            return *this;
        }
        numerator = (numerator * other.denominator);
        denominator = (denominator * other.numerator);
        reduce();
        return *this;
    }

    // Compound assignment operators: float
    Fraction &operator+=(float value)
    {
        int num = value * precision;
        numerator = numerator * precision + denominator * num;
        denominator = precision * denominator;
        reduce();
        return *this;
    }
    Fraction &operator-=(float value)
    {
        int num = value * precision;
        numerator = numerator * precision - denominator * num;
        denominator = precision * denominator;
        reduce();
        return *this;
    }
    Fraction &operator*=(float value)
    {
        int num = value * precision;
        numerator = numerator * num;
        denominator = precision * denominator;
        reduce();
        return *this;
    }
    Fraction &operator/=(float value)
    {
        int num = value * precision;
        numerator = numerator * precision;
        denominator = num * denominator;
        reduce();
        return *this;
    }

    // Stream insertion operator
    friend std::ostream &operator<<(std::ostream &os, const Fraction &frac)
    {
        if (frac.denominator == 1)
            os << frac.numerator;
        else
            os << frac.numerator << "/" << frac.denominator;

        return os;
    }

    friend std::istream &operator>>(std::istream &in, Fraction &frac)
    {
        in >> frac.numerator >> frac.denominator;
        return in;
    }

    ~Fraction() {}

    void print() const { cout << numerator << "/" << denominator << endl; }
};

// ==================== FractionVector Class ====================
class FractionVector
{
  private:
    Fraction *vec;
    int size;

  public:
    FractionVector(int size = 0) : size(size) { vec = new Fraction[size]; }

    // Copy constructor
    FractionVector(const FractionVector &other)
    {
        size = other.size;
        vec = new Fraction[size];
        for (int i = 0; i < size; ++i)
            vec[i] = other.vec[i];
    }
    // Destructor
    ~FractionVector() { delete[] vec; }

    // Assignment operator
    FractionVector &operator=(const FractionVector &other)
    {

        if (this == &other)
            return *this;
        delete[] vec;
        size = other.size;
        vec = new Fraction[size];
        for (int i = 0; i < size; i++)
            vec[i] = other.vec[i];

        return *this;
    }

    // Non-const version: allows modification
    Fraction &operator[](int index)
    {
        if (index < 0 || index >= size)
            throw std::out_of_range("Index out of bounds");
        return vec[index];
    }

    // Const version: for read-only access to const objects
    const Fraction &operator[](int index) const
    {
        if (index < 0 || index >= size)
            throw std::out_of_range("Index out of bounds");
        return vec[index];
    }

    // Vector operations
    FractionVector operator+(const FractionVector &other) const
    {
        if (size != other.size)
            throw std::length_error("Length of the two vectors must be the same");

        FractionVector temp(size); // Assuming you have a constructor that takes size
        for (int i = 0; i < size; i++)
            temp[i] = (*this)[i] + other[i];

        return temp;
    }

    FractionVector operator-(const FractionVector &other) const
    {
        if (size != other.size)
            throw std::length_error("Length of the two vectors must be the same");

        FractionVector temp(size); // Assuming you have a constructor that takes size
        for (int i = 0; i < size; i++)
            temp[i] = (*this)[i] - other[i];

        return temp;
    }

    // Scalar operations
    FractionVector operator*(const Fraction &scalar) const
    {
        FractionVector temp(size); // Assuming you have a constructor that takes size
        for (int i = 0; i < size; i++)
            temp[i] = (*this)[i] * scalar;

        return temp;
    }

    FractionVector operator/(const Fraction &scalar) const
    {
        FractionVector temp(size); // Assuming you have a constructor that takes size
        for (int i = 0; i < size; i++)
            temp[i] = (*this)[i] / scalar;

        return temp;
    }

    friend FractionVector operator*(const Fraction &scalar, const FractionVector &vec)
    {
        FractionVector temp(vec.size); // Assuming you have a constructor that takes size
        for (int i = 0; i < vec.size; i++)
            temp[i] = vec[i] * scalar;

        return temp;
    }

    // Dot product
    Fraction operator*(const FractionVector &other) const
    {
        if (size != other.size)
            throw std::length_error("Length of the two vectors must be the same");
        Fraction temp(0);
        for (int i = 0; i < size; i++)
            temp += (this->vec[i] * other.vec[i]);
        return temp;
    }

    // Magnitude (L2 norm)
    Fraction value() const
    {
        Fraction mag(0);
        for (int i = 0; i < size; i++)
            mag += vec[i] * vec[i];

        float res = mag.getnumerator() / mag.getdenominator();
        res = sqrtf(res);
        int num = res * precision;
        return Fraction(num, precision);
    }

    // Stream insertion
    friend std::ostream &operator<<(std::ostream &os, const FractionVector &vec)
    {
        os << "[";
        for (int i = 0; i < vec.size; i++)
        {
            os << vec[i];
            if (i != vec.size - 1)
                os << ", ";
        }
        os << "]";
        return os;
    }

    friend std::istream &operator>>(std::istream &in, FractionVector &vec)
    {
        for (int i = 0; i < vec.size; i++)
            in >> vec[i];
        return in;
    }
};

// ==================== FractionMatrix Class ====================
class FractionMatrix
{
  private:
    FractionVector *rows;
    FractionVector *columns;
    int rowCount;
    int colCount;

    void setupColumns()
    {
        if (colCount == 0 || rowCount == 0)
            return; // Handle empty matrix
        for (int col = 0; col < colCount; col++)
        {
            columns[col] = FractionVector(rowCount); // Ensure proper size
            for (int row = 0; row < rowCount; row++)
                columns[col][row] = rows[row][col];
        }
    }

  public:
    //FractionMatrix() : rows(nullptr), columns(nullptr), rowCount(0), colCount(0) {}

    FractionMatrix(int rows = 0, int cols = 0) : rowCount(rows), colCount(cols)
    {
        this->rows = new FractionVector[rowCount];
        for (int i = 0; i < rowCount; ++i)
            this->rows[i] = FractionVector(colCount); // Initialize each row
        this->columns = new FractionVector[colCount];
        for (int i = 0; i < colCount; ++i)
            this->columns[i] = FractionVector(rowCount); // Initialize each column
        setupColumns();                                  // Populate columns from rows
    }

    // Copy constructor
    FractionMatrix(const FractionMatrix &other) : rowCount(other.rowCount), colCount(other.colCount)
    {
        rows = new FractionVector[rowCount];
        columns = new FractionVector[colCount];
        for (int i = 0; i < rowCount; i++)
            rows[i] = other.rows[i]; // Calls FractionVector copy constructor
        for (int i = 0; i < colCount; i++)
            columns[i] = FractionVector(rowCount); // Initialize columns
        setupColumns();                            // Populate columns from rows
    }

    // Destructor
    ~FractionMatrix()
    {
        delete[] rows;
        delete[] columns;
    }

    // Assignment operator
    FractionMatrix &operator=(const FractionMatrix &other)
    {
        if (this == &other)
            return *this;

        delete[] rows;
        delete[] columns;

        rowCount = other.rowCount;
        colCount = other.colCount;

        rows = new FractionVector[rowCount];
        columns = new FractionVector[colCount];
        for (int i = 0; i < rowCount; i++)
            rows[i] = other.rows[i];
        for (int i = 0; i < colCount; i++)
            columns[i] = FractionVector(rowCount); // Initialize columns
        setupColumns();

        return *this;
    }

    // Subscript operator for row access
    FractionVector &operator[](int index)
    {
        if (index < 0 || index >= rowCount)
            throw std::out_of_range("Row index out of range");
        return rows[index];
    }

    const FractionVector &operator[](int index) const
    {
        if (index < 0 || index >= rowCount)
            throw std::out_of_range("Row index out of range");
        return rows[index];
    }

    // Column access
    FractionVector getColumnCopy(int index) const
    {
        if (index < 0 || index >= colCount)
            throw std::out_of_range("Column index out of range");
        return columns[index]; // returns a copy
    }

    FractionVector &getColumn(int index)
    {
        if (index < 0 || index >= colCount)
            throw std::out_of_range("Column index out of range");
        return columns[index];
    }

    const FractionVector &getColumn(int index) const
    {
        if (index < 0 || index >= colCount)
            throw std::out_of_range("Column index out of range");
        return columns[index];
    }

    // Matrix operations
    FractionMatrix operator+(const FractionMatrix &other) const
    {
        if (rowCount != other.rowCount || colCount != other.colCount)
            throw std::invalid_argument("Matrix dimensions must match for addition");

        FractionMatrix result(rowCount, colCount);
        for (int i = 0; i < rowCount; ++i)
            result.rows[i] = rows[i] + other.rows[i]; // assumes FractionVector + is implemented

        result.setupColumns();
        return result;
    }

    FractionMatrix operator-(const FractionMatrix &other) const
    {
        if (rowCount != other.rowCount || colCount != other.colCount)
            throw std::invalid_argument("Matrix dimensions must match for subtraction");

        FractionMatrix result(rowCount, colCount);
        for (int i = 0; i < rowCount; ++i)
            result.rows[i] = rows[i] - other.rows[i];

        result.setupColumns();
        return result;
    }

    // Scalar operations
    FractionMatrix operator*(const Fraction &scalar) const
    {
        FractionMatrix result(rowCount, colCount);
        for (int i = 0; i < rowCount; ++i)
            result.rows[i] = rows[i] * scalar;

        result.setupColumns();
        return result;
    }

    FractionMatrix operator/(const Fraction &scalar) const
    {
        FractionMatrix result(rowCount, colCount);
        for (int i = 0; i < rowCount; ++i)
            result.rows[i] = rows[i] / scalar;

        result.setupColumns();
        return result;
    }

    friend FractionMatrix operator*(const Fraction &scalar, const FractionMatrix &mat)
    {
        return mat * scalar; // reuse member implementation
    }

    // Matrix multiplication
    FractionMatrix operator*(const FractionMatrix &other) const
    {
        if (colCount != other.rowCount)
            throw std::invalid_argument("Invalid matrix dimensions for multiplication");

        FractionMatrix result(rowCount, other.colCount);
        for (int i = 0; i < rowCount; ++i)
        {
            for (int j = 0; j < other.colCount; ++j)
            {
                Fraction sum;
                for (int k = 0; k < colCount; ++k)
                    sum = sum + (rows[i][k] * other.rows[k][j]);
                result.rows[i][j] = sum;
            }
        }
        result.setupColumns();
        return result;
    }

    // Hadamard product
    FractionMatrix operator%(const FractionMatrix &other) const
    {
        if (rowCount != other.rowCount || colCount != other.colCount)
            throw std::invalid_argument("Matrix dimensions must match for Hadamard product");

        FractionMatrix result(rowCount, colCount);
        for (int i = 0; i < rowCount; ++i)
            for (int j = 0; j < colCount; ++j)
                result.rows[i][j] = rows[i][j] * other.rows[i][j];
        result.setupColumns();
        return result;
    }

    // Transpose
    FractionMatrix transpose() const
    {
        FractionMatrix result(colCount, rowCount); // swap dimensions
        for (int i = 0; i < rowCount; ++i)
            for (int j = 0; j < colCount; ++j)
                result.rows[j][i] = rows[i][j];
        result.setupColumns(); // optional, since already matched in `rows`
        return result;
    }

    // Stream insertion
    friend std::ostream &operator<<(std::ostream &os, const FractionMatrix &mat)
    {
        if (mat.rowCount == 0 || mat.colCount == 0)
        {
            os << "[Empty Matrix]";
            return os;
        }
        for (int i = 0; i < mat.rowCount; ++i)
        {
            os << "[ ";
            for (int j = 0; j < mat.colCount; ++j)
            {
                os << mat.rows[i][j];
                if (j < mat.colCount - 1)
                    os << ", ";
            }
            os << " ]\n";
        }
        return os;
    }

    friend std::istream &operator>>(std::istream &in, FractionMatrix &mat)
    {
        in >> mat.rowCount >> mat.colCount;
        for (int i = 0; i < mat.rowCount; i++)
            for (int j = 0; j < mat.colCount; j++)
                in >> mat.rows[i][j];
        return in;
    }
};
