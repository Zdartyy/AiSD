#ifndef QUATERNION_H
#define QUATERNION_H

#include <iostream>
#include <cmath>

class Quaternion
{
private:
    double a, b, c, d; // Współczynniki: a + bi + cj + dk

public:
    Quaternion(double real = 0.0, double i = 0.0, double j = 0.0, double k = 0.0);
    Quaternion(const Quaternion &other);

    Quaternion operator+(const Quaternion &q) const;
    Quaternion operator-(const Quaternion &q) const;
    Quaternion operator*(const Quaternion &q) const;

    bool operator==(const Quaternion &q) const;
    bool operator!=(const Quaternion &q) const;

    Quaternion conjugate() const;
    double modulus() const;
    void display(std::ostream &os) const;

    double getReal() const { return a; }
    double getI() const { return b; }
    double getJ() const { return c; }
    double getK() const { return d; }

    void setReal(double value) { a = value; }
    void setI(double value) { b = value; }
    void setJ(double value) { c = value; }
    void setK(double value) { d = value; }
};

// Operator << dla wygodnego wyświetlania
std::ostream &operator<<(std::ostream &os, const Quaternion &q);

#endif // QUATERNION_H