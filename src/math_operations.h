#ifndef MATH_OPERATIONS_H
#define MATH_OPERATIONS_H

/**
 * @file math_operations.h
 * 
 * @brief Defines basic mathematical operations and some advanced functions.
 *
 * This header file provides function prototypes for performing various mathematical
 * operations. It includes functions for basic arithmetic operations, Nth root,
 * exponentiation, factorial calculation and modulo.
 * 
 * @author xfignam00
 * @author xmalegt00
 * @author xnovakf00
 * @author xskovaj00
 */

class MathOps {
public:
    
     /**
    * @brief Performs addition of two doubles.
    *
    * @param a The first double operand.
    * @param b The second double operand.
    * @return The sum of a and b as a double.
    */
    double add(double a, double b);
    
    /**
    * @brief Performs subtraction of two doubles.
    *
    * @param a The first double operand.
    * @param b The second double operand (subtrahend).
    * @return The difference of a and b as a double.
    */
    double subtract(double a, double b);

    /**
    * @brief Performs division of two doubles.   
    * 
    * @param a The first double operand (dividend).
    * @param b The second double operand (divisor).
    * @return The quotient of a divided with b as a double.
    */ 
    double divide(double a, double b);

    /**
    * @brief Performs multiplication of two doubles.   
    * 
    * @param a The first double operand (multiplicand).
    * @param b The second double operand (multiplier).
    * @return The product of multiplying a with b as a double.
    */ 
    double multiply(double a, double b);

    /**
    * @brief Performs the squareRoot of a double.   
    * 
    * @param a Double operand.
    * @return The result of square root of a as a double.
    */ 
    double squareRoot(double a); //possibly unnecessary

    /**
    * @brief Performs factorial of a double.   
    * 
    * @param a Double operand.
    * @return The factorial of a as an unsigned long long.
    */ 
    unsigned long long factorial(double a);
        
    /**
    * @brief Performs nth power of two doubles.  
    * 
    * @param a The first double operand (base).
    * @param n The second double operand (exponent).
    * @return The n-th power of a as a double.
    */ 
    double nthPower(double a, double n); // n maybe int?

    /**
    * @brief Performs nth root of two doubles.  
    * 
    * @param a The first double operand (radicand).
    * @param n The second double operand (root).
    * @return The n-th root of a as a double.
    */ 
    double nthRoot(double a, double n);

    /**
    * @brief Calculates the remainder by dividing two doubles.  
    * 
    * @param a The first double operand (dividend).
    * @param b The second double operand (divisor).
    * @return The remainder of a divided by b as an int.
    */ 
    int modulo(double a, double b);
    
private:

};

#define MATH_ERROR -1.0

#endif //MATH_OPERATIONS_H