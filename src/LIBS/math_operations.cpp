/**
 * @file math_operations.cpp
 * 
 * @brief Implementation of the MathOps class for basic mathematical operations.
 * 
 * This file implements the MathOps class defined in math_operations.h.
 * It includes functions for basic arithmetic operations, Nth root,
 * exponentiation, factorial calculation and modulo.
 * 
 * @author xfignam00
 * @author xmalegt00
 * @author xnovakf00
 * @author xskovaj00
*/

#include "math_operations.h"
#include <cmath> 

double MathOps::add(double a, double b) {
    return a + b;
}

double MathOps::subtract(double a, double b) {
    return a - b;
}

double MathOps::divide(double a, double b, MathErrorCode &errCode) {
    if (b == 0) {
        errCode = DIVISION_BY_ZERO;
        return 0; 
    } 
    return a / b;
}

double MathOps::multiply(double a, double b) {
    return a * b;
}

double MathOps::squareRoot(double a, MathErrorCode &errCode) {
    if (a < 0) {
        errCode = NEGATIVE_ROOT_INPUT;
        return 0;
    }
    return sqrt(a);
}

unsigned long long MathOps::factorial(int a, MathErrorCode &errCode) {
    if (a < 0) {
        errCode = NEGATIVE_FACTORIAL_INPUT;
        return 0;
    }
    unsigned long long result = 1;
    for (int i = 1; i <= a; ++i) {
        result *= i;
    }
    return result;
}

double MathOps::nthPower(double a, int n) {
    return pow(a, n);
}

double MathOps::nthRoot(double a, int n, MathErrorCode &errCode) {
    if (a < 0 && n % 2 == 0) {
        errCode = NEGATIVE_ROOT_INPUT;
        return 0;
    }
    if (n <= 0) {
        errCode = INVALID_ROOT_INDEX;
        return 0;
    }
    if (a < 0) {
        return -pow(-a, 1.0 / n);
    }
    return pow(a, 1.0 / n);
}

double MathOps::modulo(double a, double b, MathErrorCode &errCode) {
    if (b == 0.0) {
        errCode = DIVISION_BY_ZERO;
        return 0;
    }
    return fmod(a, b);
}