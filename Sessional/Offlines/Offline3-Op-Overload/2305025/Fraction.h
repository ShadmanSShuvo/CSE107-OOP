#ifndef FRACTION_H
#define FRACTION_H

#include <iostream>
using namespace std;

int gcd(int a, int b)
{
    if (b == 0)
        return a;
    return gcd(b, a % b);
}

class Fraction
{
private:
    int numerator;
    int denominator;

public:
    int getnumerator() const
    {
        return numerator;
    }
    int getdenominator() const
    {
        return denominator;
    }
    void setnumerator(int n)
    {
        numerator = n;
    }
    void setdenominator(int d)
    {
        denominator = d;
    }
    void reduce()
    {
        int g = gcd(abs(numerator), abs(denominator));
        numerator /= g;
        denominator /= g;
    }
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
    Fraction operator+(const Fraction& other) const
    {
        Fraction temp((numerator*other.denominator + denominator*other.numerator), (denominator*other.denominator));
        return temp;
        
    }
    Fraction operator-(const Fraction& other) const
    {
        Fraction temp((numerator*other.denominator - denominator*other.numerator), (denominator*other.denominator));
        return temp;
        
    }
    Fraction operator*(const Fraction& other) const
    {
        Fraction temp((numerator*other.numerator), denominator*other.denominator);
        return temp;
    }
    Fraction operator/(const Fraction& other) const
    {
        if (other.numerator == 0)
        {
            cout << "cannot divide by zero\n";
            return;
        }
        Fraction temp((numerator*other.denominator), (denominator*other.numerator));
        return temp;
    }

    // Arithmetic operators: Fraction with float
    Fraction operator+(float value) const
    {

    }
    Fraction operator-(float value) const;
    Fraction operator*(float value) const;
    Fraction operator/(float value) const;

    // Friend functions for float with Fraction
    friend Fraction operator+(float value, const Fraction& frac);
    friend Fraction operator-(float value, const Fraction& frac);
    friend Fraction operator*(float value, const Fraction& frac);
    friend Fraction operator/(float value, const Fraction& frac);

    // Compound assignment operators: Fraction
    Fraction& operator+=(const Fraction& other)
    {
        numerator = (numerator*other.denominator + denominator*other.numerator);
        denominator = (denominator*other.denominator);

        return *this;
    }
    Fraction& operator-=(const Fraction& other)
    {
        numerator = (numerator*other.denominator - denominator*other.numerator);
        denominator = (denominator*other.denominator);

        return *this;
    }
    Fraction& operator*=(const Fraction& other)
    {
        numerator = (numerator*other.numerator);
        denominator = denominator*other.denominator;
        return *this;
    }
    Fraction& operator/=(const Fraction& other)
    {
        if (other.numerator == 0)
        {
            cout << "cannot divide by zero\n";
            return;
        }
        numerator = (numerator*other.denominator);
        denominator = (denominator*other.numerator);
        return *this;
    }

    // Compound assignment operators: float
    Fraction& operator+=(float value)
    {
        
    }
    Fraction& operator-=(float value);
    Fraction& operator*=(float value);
    Fraction& operator/=(float value);

    // Stream insertion operator
    friend std::ostream& operator<<(std::ostream& os, const Fraction& frac);




    ~Fraction()
    {
    }
    void print() const
    {
        cout << numerator << "/" << denominator << endl;
    }
};

class FractionCollection
{
    Fraction *fractions;
    int maxlength;
    int length;

public:
    FractionCollection()
    {
        maxlength = 10;
        length = 0;
        fractions = new Fraction[maxlength];
    }

    FractionCollection(int n)
    {
        maxlength = n;
        length = 0;
        fractions = new Fraction[maxlength];
    }

    ~FractionCollection()
    {
        delete[] fractions;
    }

    void insert(Fraction &f)
    {
        if (length == maxlength)
        {
            cout << "Collection is full" << endl;
            return;
        }
        fractions[length] = f;
        length++;
    }
    void insert(int n, Fraction &f)
    {
        if (length == maxlength)
        {
            cout << "Collection is full" << endl;
            return;
        }
        if (n < 0 || n >= maxlength)
        {
            cout << "Invalid position" << endl;
            return;
        }

        for (int i = length; i > n; i--)
        {
            fractions[i] = fractions[i - 1];
        }
        length++;

        fractions[n] = f;
    }

    void remove()
    {
        if (length == 0)
        {
            cout << "Collection is empty" << endl;
            return;
        }

        length--;
    }
    void remove(const Fraction &f)
    {
        if (length == 0)
        {
            cout << "Collection is empty" << endl;
            return;
        }

        for (int i = 0; i < length; i++)
        {
            if (fractions[i].getnumerator() == f.getnumerator() &&
                fractions[i].getdenominator() == f.getdenominator())
            {

                for (int j = i; j < length - 1; j++)
                {
                    fractions[j] = fractions[j + 1];
                }
                length--;

                return;
            }
        }

        cout << "Element not found" << endl;
    }

    void remove(int pos)
    {
        if (length == 0)
        {
            cout << "Collection is empty" << endl;
            return;
        }
        if (pos < 0 || pos >= length)
        {
            cout << "Invalid position" << endl;
            return;
        }

        for (int i = pos; i < length - 1; i++)
        {
            fractions[i] = fractions[i + 1];
        }
        length--;
    }

    Fraction getmax()
    {
        if (length == 0)
        {
            cout << "Collection is empty" << endl;
            return Fraction();
        }
        Fraction max = fractions[0];
        for (int i = 1; i < length; i++)
        {
            if (fractions[i].getnumerator() * max.getdenominator() > max.getnumerator() * fractions[i].getdenominator())
            {
                max = fractions[i];
            }
        }
        return max;
    }

    Fraction getmin()
    {
        if (length == 0)
        {
            cout << "Collection is empty" << endl;
            return Fraction();
        }
        Fraction min = fractions[0];
        for (int i = 1; i < length; i++)
        {
            if (fractions[i].getnumerator() * min.getdenominator() < min.getnumerator() * fractions[i].getdenominator())
            {
                min = fractions[i];
            }
        }
        return min;
    }

    Fraction add(int start, int end)
    {
        if (length == 0)
        {
            cout << "Collection is empty" << endl;
            return Fraction();
        }
        if (start < 0 || end >= length)
        {
            cout << "Invalid range" << endl;
            return Fraction();
        }
        Fraction sum = fractions[start];
        for (int i = start + 1; i <= end; i++)
        {
            sum = sum.add(fractions[i]);
        }
        return sum;
    }

    Fraction mul(int start, int end)
    {
        if (length == 0)
        {
            cout << "Collection is empty" << endl;
            return Fraction();
        }
        if (start < 0 || end >= length)
        {
            cout << "Invalid range" << endl;
            return Fraction();
        }
        Fraction product = fractions[start];
        for (int i = start + 1; i <= end; i++)
        {
            product = product.mul(fractions[i]);
        }
        return product;
    }

    Fraction sub(int pos1, int pos2)
    {
        if (length == 0)
        {
            cout << "Collection is empty" << endl;
            return Fraction();
        }
        if (pos1 < 0 || pos2 >= length)
        {
            cout << "Invalid range" << endl;
            return Fraction();
        }
        return fractions[pos1].sub(fractions[pos2]);
    }

    Fraction div(int pos1, int pos2)
    {
        if (length == 0)
        {
            cout << "Collection is empty" << endl;
            return Fraction();
        }
        if (pos1 < 0 || pos2 >= length)
        {
            cout << "Invalid range" << endl;
            return Fraction();
        }
        return fractions[pos1].div(fractions[pos2]);
    }
    void print()
    {
        Fraction sum(0), prod(1);
        cout << "\nFractions" << endl;
        cout << "-------------------------------" << endl;
        for (int i = 0; i < length; i++)
        {
            cout << "Fraction " << i << ": ";
            fractions[i].print();
        }

        cout << "Max: ";
        getmax().print();
        cout << "Min: ";
        getmin().print();
        sum = add(0, length - 1);
        prod = mul(0, length - 1);
        cout << "Summation: ";
        sum.print();
        cout << "Multiplication: ";
        prod.print();
    }
};



#endif 