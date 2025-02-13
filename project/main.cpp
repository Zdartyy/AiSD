#include "Quaternion.h"
#include <cassert>

void test_addition() {
    Quaternion q1(1, 2, 3, 4);
    Quaternion q2(5, 6, 7, 8);
    Quaternion q3 = q1 + q2;
    assert(q3 == Quaternion(6, 8, 10, 12));
    std::cout << "test_addition passed" << std::endl;
}

void test_subtraction() {
    Quaternion q1(1, 2, 3, 4);
    Quaternion q2(5, 6, 7, 8);
    Quaternion q3 = q1 - q2;
    assert(q3 == Quaternion(-4, -4, -4, -4));
    std::cout << "test_subtraction passed" << std::endl;
}

void test_multiplication() {
    Quaternion q1(1, 2, 3, 4);
    Quaternion q2(5, 6, 7, 8);
    Quaternion q3 = q1 * q2;
    assert(q3 == Quaternion(-60, 12, 30, 24));
    std::cout << "test_multiplication passed" << std::endl;
}

void test_conjugate() {
    Quaternion q1(1, 2, 3, 4);
    Quaternion q2 = q1.conjugate();
    assert(q2 == Quaternion(1, -2, -3, -4));
    std::cout << "test_conjugate passed" << std::endl;
}

void test_modulus() {
    Quaternion q1(1, 2, 3, 4);
    double mod = q1.modulus();
    assert(mod == std::sqrt(30));
    std::cout << "test_modulus passed" << std::endl;
}

int main()
{

    Quaternion q1(2, 2, 3, 4);
    Quaternion q2(6, 5, 7, 8);

    std::cout << "q1 = " << q1 << std::endl;
    std::cout << "q2 = " << q2 << std::endl;

    Quaternion sum = q1 + q2;
    std::cout << "q1 + q2 = " << sum << std::endl;

    Quaternion diff = q1 - q2;
    std::cout << "q1 - q2 = " << diff << std::endl;

    Quaternion product = q1 * q2;
    std::cout << "q1 * q2 = " << product << std::endl;

    Quaternion conj = q1.conjugate();
    std::cout << "Conjugate of q1 = " << conj << std::endl;

    double mod = q1.modulus();
    std::cout << "Modulus of q1 = " << mod << std::endl;

    if (q1 == q2)
    {
        std::cout << "q1 is equal to q2" << std::endl;
    }
    else
    {
        std::cout << "q1 is not equal to q2" << std::endl;
    }

    test_addition();
    test_subtraction();
    test_multiplication();
    test_conjugate();
    test_modulus();

    std::cout << "All tests passed!" << std::endl;


    return 0;
}