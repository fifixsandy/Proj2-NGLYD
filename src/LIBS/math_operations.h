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


/**
 * @brief Enumerates error codes for mathematical operations in the MathOps class.
 *
 * This enumeration provides a way of reporting errors encountered while
 * executing mathematical operations. Each enumerator corresponds
 * to a specific error condition that can be encountered.
 */
enum MathErrorCode {
    SUCCESS = 0, ///< No error occured during mathematical operation.
    DIVISION_BY_ZERO, ///< Division by zero occured while calculating.
    NEGATIVE_ROOT_INPUT, ///< Negative number was provided as an input for calculating root.
    NEGATIVE_FACTORIAL_INPUT, ///< Negative number was provided as an input for calculating factorial.
    INVALID_ROOT_INDEX
};

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
    * @param errCode Adress where error code should be stored.
    * @return The quotient of a divided with b as a double.
    */ 
    double divide(double a, double b, MathErrorCode &errCode);

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
    * @param errCode Adress where error code should be stored.
    * @return The result of square root of a as a double.
    */ 
    double squareRoot(double a, MathErrorCode &errCode);

    /**
    * @brief Performs factorial of an int.   
    * 
    * @param a Int operand.
    * @param errCode Adress where error code should be stored.
    * @return The factorial of a as an unsigned long long.
    */ 
    unsigned long long factorial(int a, MathErrorCode &errCode);
        
    /**
    * @brief Performs nth power of a double and int.  
    * 
    * @param a The first double operand (base).
    * @param n The second int operand (exponent).
    * @return The n-th power of a as a double.
    */ 
    double nthPower(double a, int n);

    /**
    * @brief Performs nth root of double and int.  
    * 
    * @param a The first double operand (radicand).
    * @param n The second int operand (root).
    * @param errCode Adress where error code should be stored.
    * @return The n-th root of a as a double.
    */ 
    double nthRoot(double a, int n, MathErrorCode &errCode);

    /**
    * @brief Calculates the remainder by dividing two doubles.  
    * 
    * @param a The first double operand (dividend).
    * @param b The second double operand (divisor).
    * @param errCode Adress where error code should be stored.
    * @return The remainder of a divided by b as a double.
    */ 
    double modulo(double a, double b, MathErrorCode &errCode);
    
private:

};

#endif //MATH_OPERATIONS_H