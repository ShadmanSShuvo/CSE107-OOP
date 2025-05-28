#include <iostream>
#include <cassert>
#include "2305025.cpp"

class FractionMatrix
{
  private:
    FractionVector *rows;
    int rowCount;
    int colCount;

    void setupColumns()
    {
        // This helper is not storing columns but could be used if needed.
        // Since each row is a FractionVector, column access can be derived from rows.
    }

  public:
    FractionMatrix(int rows = 0, int cols = 0) : rowCount(rows), colCount(cols)
    {
        this->rows = new FractionVector[rowCount];
        for (int i = 0; i < rowCount; ++i)
            this->rows[i] = FractionVector(colCount);
    }

    // Copy constructor
    FractionMatrix(const FractionMatrix &other) : rowCount(other.rowCount), colCount(other.colCount)
    {
        rows = new FractionVector[rowCount];
        for (int i = 0; i < rowCount; ++i)
            rows[i] = other.rows[i];
    }

    // Destructor
    ~FractionMatrix() { delete[] rows; }

    // Assignment operator
    FractionMatrix &operator=(const FractionMatrix &other)
    {
        if (this == &other)
            return *this;
        delete[] rows;

        rowCount = other.rowCount;
        colCount = other.colCount;
        rows = new FractionVector[rowCount];
        for (int i = 0; i < rowCount; ++i)
            rows[i] = other.rows[i];
        return *this;
    }

    // Subscript operator for row access
    FractionVector &operator[](int index)
    {
        assert(index >= 0 && index < rowCount);
        return rows[index];
    }

    const FractionVector &operator[](int index) const
    {
        assert(index >= 0 && index < rowCount);
        return rows[index];
    }

    // Column access
    FractionVector getColumn(int index) const
    {
        assert(index >= 0 && index < colCount);
        FractionVector col(rowCount);
        for (int i = 0; i < rowCount; ++i)
            col[i] = rows[i][index];
        return col;
    }

    // Matrix addition
    FractionMatrix operator+(const FractionMatrix &other) const
    {
        assert(rowCount == other.rowCount && colCount == other.colCount);
        FractionMatrix result(rowCount, colCount);
        for (int i = 0; i < rowCount; ++i)
            result[i] = rows[i] + other.rows[i];
        return result;
    }

    // Matrix subtraction
    FractionMatrix operator-(const FractionMatrix &other) const
    {
        assert(rowCount == other.rowCount && colCount == other.colCount);
        FractionMatrix result(rowCount, colCount);
        for (int i = 0; i < rowCount; ++i)
            result[i] = rows[i] - other.rows[i];
        return result;
    }

    // Scalar multiplication
    FractionMatrix operator*(const Fraction &scalar) const
    {
        FractionMatrix result(rowCount, colCount);
        for (int i = 0; i < rowCount; ++i)
            result[i] = rows[i] * scalar;
        return result;
    }

    // Scalar division
    FractionMatrix operator/(const Fraction &scalar) const
    {
        FractionMatrix result(rowCount, colCount);
        for (int i = 0; i < rowCount; ++i)
            result[i] = rows[i] / scalar;
        return result;
    }

    // Friend scalar * matrix
    friend FractionMatrix operator*(const Fraction &scalar, const FractionMatrix &mat) { return mat * scalar; }

    // Matrix multiplication
    FractionMatrix operator*(const FractionMatrix &other) const
    {
        assert(colCount == other.rowCount);
        FractionMatrix result(rowCount, other.colCount);
        for (int i = 0; i < rowCount; ++i)
        {
            for (int j = 0; j < other.colCount; ++j)
            {
                Fraction sum(0);
                for (int k = 0; k < colCount; ++k)
                    sum = sum + (rows[i][k] * other.rows[k][j]);
                result[i][j] = sum;
            }
        }
        return result;
    }

    // Hadamard product
    // FractionMatrix operator%(const FractionMatrix &other) const {
    //     assert(rowCount == other.rowCount && colCount == other.colCount);
    //     FractionMatrix result(rowCount, colCount);
    //     for (int i = 0; i < rowCount; ++i) {
    //         result[i] = rows[i] % other.rows[i]; // assuming FractionVector supports %
    //     }
    //     return result;
    // }
    FractionMatrix operator%(const FractionMatrix &other) const
    {
        assert(rowCount == other.rowCount && colCount == other.colCount);
        FractionMatrix result(rowCount, colCount);
        for (int i = 0; i < rowCount; ++i)
            for (int j = 0; j < colCount; ++j)
                result[i][j] = (*this)[i][j] * other[i][j]; // assumes Fraction has operator*
        return result;
    }

    // Transpose
    FractionMatrix transpose() const
    {
        FractionMatrix result(colCount, rowCount);
        for (int i = 0; i < rowCount; ++i)
            for (int j = 0; j < colCount; ++j)
                result[j][i] = rows[i][j];
        return result;
    }

    // Stream insertion
    friend std::ostream &operator<<(std::ostream &os, const FractionMatrix &mat)
    {
        for (int i = 0; i < mat.rowCount; ++i)
            os << mat.rows[i] << '\n';
        return os;
    }
};