#include "Quaternion.h"

Quaternion::Quaternion(double real, double i, double j, double k)
    : a(real), b(i), c(j), d(k) {}

Quaternion::Quaternion(const Quaternion &other)
    : a(other.a), b(other.b), c(other.c), d(other.d) {}

Quaternion Quaternion::operator+(const Quaternion &q) const
{
    return Quaternion(a + q.a, b + q.b, c + q.c, d + q.d);
}

Quaternion Quaternion::operator-(const Quaternion &q) const
{
    return Quaternion(a - q.a, b - q.b, c - q.c, d - q.d);
}

Quaternion Quaternion::operator*(const Quaternion &q) const
{
    double newA = a * q.a - b * q.b - c * q.c - d * q.d;
    double newB = a * q.b + b * q.a + c * q.d - d * q.c;
    double newC = a * q.c - b * q.d + c * q.a + d * q.b;
    double newD = a * q.d + b * q.c - c * q.b + d * q.a;
    return Quaternion(newA, newB, newC, newD);
}

bool Quaternion::operator==(const Quaternion &q) const
{
    return (a == q.a && b == q.b && c == q.c && d == q.d);
}

bool Quaternion::operator!=(const Quaternion &q) const
{
    return !(*this == q);
}

Quaternion Quaternion::conjugate() const
{
    return Quaternion(a, -b, -c, -d);
}

double Quaternion::modulus() const
{
    return std::sqrt(a * a + b * b + c * c + d * d);
}

void Quaternion::display(std::ostream &os) const
{
    os << a;
    if (b >= 0)
        os << " + " << b << "i";
    else
        os << " - " << -b << "i";
    if (c >= 0)
        os << " + " << c << "j";
    else
        os << " - " << -c << "j";
    if (d >= 0)
        os << " + " << d << "k";
    else
        os << " - " << -d << "k";
}

std::ostream &operator<<(std::ostream &os, const Quaternion &q)
{
    q.display(os);
    return os;
}