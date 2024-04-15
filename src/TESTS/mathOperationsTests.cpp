/**
 * @file mathLibTests.cpp
 * 
 * @brief Performs tests on math operations from math_operations.h.
 * 
 *  This file is used for testing all operations from math_operations.h library. It tests basic cases as well as 
 *  edgecases, which might possibly give incorrect result. It also tests incorrect inputs and if they are handled properly.
 * 
 *  These tests are implemented with Google Tests.
 * 
 * @author xfignam00
 * @author xmalegt00
 * @author xnovakf00
 * @author xskovaj00
 */

#include "../LIBS/math_operations.h"
#include "gtest/gtest.h"

MathOps m;


TEST(ADD, zeroOrPositive){
    EXPECT_EQ(m.add(0, 0) , 0);
    EXPECT_EQ(m.add(0, 1) , 1);
    EXPECT_EQ(m.add(0, 0.9) , 0.9);

    EXPECT_EQ(m.add(12, 50) , 62);
    EXPECT_EQ(m.add(7758, 22688) , 30446);
    
    EXPECT_EQ(m.add(0.5, 0.5) , 1);
    EXPECT_EQ(m.add(7.2565489, 2.564056465) , 9.820605365);
}

TEST(ADD, negative){
    EXPECT_EQ(m.add(0, -5) , -5);
    EXPECT_EQ(m.add(0, -1) , -1);
    EXPECT_EQ(m.add(0, -0.9) , -0.9);

    EXPECT_EQ(m.add(12, -50) , -38);
    EXPECT_EQ(m.add(7758, -22688) , -14930);
    
    EXPECT_EQ(m.add(0.5, -0.5) , 0);
    EXPECT_EQ(m.add(-7.2565489, 2.564056465) , -4.692492435);

    EXPECT_EQ(m.add(-5, -568.2) , -573.2);
}

TEST(SUBTRACT, zeroOrPositive){
    EXPECT_EQ(m.subtract(0, 0) , 0);
    EXPECT_EQ(m.subtract(0, 1) , -1);
    EXPECT_EQ(m.subtract(0, 0.9) , -0.9);

    EXPECT_EQ(m.subtract(20.5, 0.5) , 20);
    EXPECT_EQ(m.subtract(565, 0.2) , 564.8);
    EXPECT_NEAR(m.subtract(100, 150.965489) , -50.96489, 1e-3);
}

TEST(SUBTRACT, negative){
    EXPECT_EQ(m.subtract(0,-2) , 2);
    EXPECT_EQ(m.subtract(18,-5) , 23);
    EXPECT_EQ(m.subtract(-125.56, -125.56) , 0);
    EXPECT_EQ(m.subtract(-896.12, -800.12) , -96);

    EXPECT_EQ(m.subtract(158.356, -126.1894) , 284.5454);
}

TEST(DIVIDE, byZero){
    MathErrorCode ERR = SUCCESS;
    m.divide(0, 0, ERR);
    EXPECT_EQ(ERR , DIVISION_BY_ZERO);
    ERR=SUCCESS;
    m.divide(7, 0, ERR);
    EXPECT_EQ(ERR , DIVISION_BY_ZERO);
    ERR=SUCCESS;
    m.divide(-58.265, 0, ERR);
    EXPECT_EQ(ERR , DIVISION_BY_ZERO);
}

TEST(DIVIDE, positives){
    MathErrorCode ERR = SUCCESS;
    EXPECT_EQ(m.divide(2,1,ERR) , 2);
    ASSERT_EQ(ERR , SUCCESS);

    EXPECT_EQ(m.divide(1,2,ERR) , 0.5);
    ASSERT_EQ(ERR , SUCCESS);

    EXPECT_NEAR(m.divide(1,3,ERR) , 0.333333, 1e-6);
    ASSERT_EQ(ERR , SUCCESS);

    EXPECT_EQ(m.divide(1.2,10,ERR) , 0.12);
    ASSERT_EQ(ERR , SUCCESS);
}

TEST(MULTIPLY, zero){
    EXPECT_EQ(m.multiply(0,0) , 0);
    EXPECT_EQ(m.multiply(0,189) , 0);
    EXPECT_EQ(m.multiply(45498.4894,0) , 0);
}

TEST(MULTIPLY, twoPositive){
    EXPECT_EQ(m.multiply(1,1) , 1);
    EXPECT_EQ(m.multiply(156,1) , 156);
    EXPECT_EQ(m.multiply(2, 45.25) , 90.5);
}

TEST(MULTIPLY, positiveAndNegative){
    EXPECT_EQ(m.multiply(-1, 159.8965) , -159.8965);
    EXPECT_EQ(m.multiply(-89, 6) , -534);
    EXPECT_EQ(m.multiply(15.9728, -45.87096) , -732.687669888);
    EXPECT_EQ(m.multiply(-89.48, 0.4) , -35.792);
}

TEST(MULTIPLY, twoNegative){
    EXPECT_EQ(m.multiply(-5,-1) , 5);
    EXPECT_EQ(m.multiply(-868,-12.856) , 11159.008);
    EXPECT_EQ(m.multiply(-159.55, -0.5) , 79.775);
    EXPECT_NEAR(m.multiply(-85.592, -99.56898) , 8522.308136, 1e-3);
}

TEST(SQUARE_ROOT, zero){
    MathErrorCode ERR = SUCCESS;
    EXPECT_EQ(m.squareRoot(0, ERR) , 0);
    EXPECT_EQ(ERR, SUCCESS);
}

TEST(SQUARE_ROOT, positive){
    MathErrorCode ERR = SUCCESS;
    EXPECT_EQ(m.squareRoot(4, ERR) , 2);
    EXPECT_EQ(ERR, SUCCESS);

    EXPECT_EQ(m.squareRoot(9, ERR) , 3);
    EXPECT_EQ(ERR, SUCCESS);

    EXPECT_EQ(m.squareRoot(9801, ERR) , 99);
    EXPECT_EQ(ERR, SUCCESS);

    EXPECT_EQ(m.squareRoot(17991.929956, ERR) , 134.134);
    EXPECT_EQ(ERR, SUCCESS);
}

TEST(SQUARE_ROOT, negative){
    MathErrorCode ERR = SUCCESS;
    EXPECT_EQ(m.squareRoot(-2, ERR) , 0);
    EXPECT_EQ(ERR, NEGATIVE_ROOT_INPUT);
    ERR = SUCCESS;
    EXPECT_EQ(m.squareRoot(-254454, ERR) , 0);
    EXPECT_EQ(ERR, NEGATIVE_ROOT_INPUT); 
    ERR = SUCCESS;
    EXPECT_EQ(m.squareRoot(-0.485454, ERR) , 0);
    EXPECT_EQ(ERR, NEGATIVE_ROOT_INPUT);
    ERR = SUCCESS;
    EXPECT_EQ(m.squareRoot(-58.54545444, ERR) , 0);
    EXPECT_EQ(ERR, NEGATIVE_ROOT_INPUT);
}


TEST(NTH_ROOT, zero){
    MathErrorCode ERR = SUCCESS;
    EXPECT_EQ(m.nthRoot(0, 2, ERR) , 0);
    EXPECT_EQ(ERR, SUCCESS);

    EXPECT_EQ(m.nthRoot(0, 5, ERR) , 0);
    EXPECT_EQ(ERR, SUCCESS);

    EXPECT_EQ(m.nthRoot(0, 99, ERR) , 0);
    EXPECT_EQ(ERR, SUCCESS);
}

TEST(NTH_ROOT, evenAndPositive){
    MathErrorCode ERR = SUCCESS;
    EXPECT_EQ(m.nthRoot(2401, 4, ERR) , 7);
    EXPECT_EQ(ERR, SUCCESS);

    EXPECT_EQ(m.nthRoot(244.140625, 6, ERR) , 2.5);
    EXPECT_EQ(ERR, SUCCESS);
}

TEST(NTH_ROOT, evenAndNegative){
    MathErrorCode ERR = SUCCESS;
    EXPECT_EQ(m.nthRoot(-45, 4, ERR), 0);
    EXPECT_EQ(ERR, NEGATIVE_ROOT_INPUT);
    ERR = SUCCESS;

    EXPECT_EQ(m.nthRoot(-0.5646, 28, ERR), 0);
    EXPECT_EQ(ERR, NEGATIVE_ROOT_INPUT);
    ERR = SUCCESS;

    EXPECT_EQ(m.nthRoot(-9.24566, 156, ERR), 0);
    EXPECT_EQ(ERR, NEGATIVE_ROOT_INPUT);   
}

TEST(NTH_ROOT, odd){
    MathErrorCode ERR = SUCCESS;
    EXPECT_EQ(m.nthRoot(27,3,ERR) , 3);
    EXPECT_EQ(ERR, SUCCESS);
    EXPECT_EQ(m.nthRoot(97.65625, 5,ERR) , 2.5);
    EXPECT_EQ(ERR, SUCCESS);
    EXPECT_NEAR(m.nthRoot(0.000000001, 9,ERR) , 0.1, 1e-3);
    EXPECT_EQ(ERR, SUCCESS);
    
    EXPECT_NEAR(m.nthRoot(-27,3,ERR) , -3, 1e-3);
    EXPECT_EQ(ERR, SUCCESS);
    EXPECT_NEAR(m.nthRoot(-97.65625, 5,ERR) , -2.5, 1e-3);
    EXPECT_EQ(ERR, SUCCESS);
    EXPECT_NEAR(m.nthRoot(-0.000000001, 9,ERR) , -0.1, 1e-3);
    EXPECT_EQ(ERR, SUCCESS);
}

TEST(NTH_ROOT, invalidIndex){
    MathErrorCode ERR = SUCCESS;
    EXPECT_EQ(m.nthRoot(56,-5,ERR), 0);
    EXPECT_EQ(ERR, INVALID_ROOT_INDEX);
    ERR = SUCCESS;

    EXPECT_EQ(m.nthRoot(556.23,0,ERR), 0);
    EXPECT_EQ(ERR, INVALID_ROOT_INDEX);
    ERR = SUCCESS;

    EXPECT_EQ(m.nthRoot(-56.1111,-6569,ERR), 0);
    EXPECT_EQ(ERR, INVALID_ROOT_INDEX);
    ERR = SUCCESS;

    EXPECT_EQ(m.nthRoot(0.26656,0,ERR), 0);
    EXPECT_EQ(ERR, INVALID_ROOT_INDEX);
}

TEST(NTH_POWER, zeroAndOne){
    EXPECT_EQ(m.nthPower(0, 2) , 0);
    EXPECT_EQ(m.nthPower(0, 3) , 0);
    EXPECT_EQ(m.nthPower(0, 16) , 0);
    EXPECT_EQ(m.nthPower(0, 27) , 0);
    EXPECT_EQ(m.nthPower(0, 1276) , 0);

    EXPECT_EQ(m.nthPower(1, 2) , 1);
    EXPECT_EQ(m.nthPower(1, 3) , 1);
    EXPECT_EQ(m.nthPower(1, 16) , 1);
    EXPECT_EQ(m.nthPower(1, 27) , 1);
    EXPECT_EQ(m.nthPower(1, 1276) , 1);
}

TEST(NTH_POWER, onZero){
    EXPECT_EQ(m.nthPower(56,0) , 1);
    EXPECT_EQ(m.nthPower(4566.566,0) , 1);
    EXPECT_EQ(m.nthPower(-659.4,0) , 1);
    EXPECT_EQ(m.nthPower(-0.656,0) , 1);
}

TEST(NTH_POWER, even){
    EXPECT_EQ(m.nthPower(7, 4) , 2401);
    EXPECT_EQ(m.nthPower(2.5, 6) , 244.140625);
    EXPECT_NEAR(m.nthPower(2.15, 12) , 9755.769238, 1e-3);

    EXPECT_EQ(m.nthPower(-7, 4) , 2401);
    EXPECT_EQ(m.nthPower(-2.5, 6) , 244.140625);
    EXPECT_NEAR(m.nthPower(-2.15, 12) , 9755.769238,1e-3);
}

TEST(NTH_POWER, odd){
    EXPECT_EQ(m.nthPower(3,3) , 27);
    EXPECT_EQ(m.nthPower(2.5, 5) , 97.65625);
    EXPECT_NEAR(m.nthPower(0.1, 9) , 1e-09, 1e-12);
    
    EXPECT_EQ(m.nthPower(-3,3) , -27);
    EXPECT_EQ(m.nthPower(-2.5, 5) , -97.65625);
    EXPECT_NEAR(m.nthPower(-0.1, 9) , -1e-09, 1e-12);
}


TEST(FACTORIAL, zero){
    MathErrorCode ERR = SUCCESS;
    EXPECT_EQ(m.factorial(0,ERR) , 1);
    EXPECT_EQ(ERR, SUCCESS);
}

TEST(FACTORIAL, valid){
    MathErrorCode ERR = SUCCESS;
    EXPECT_EQ(m.factorial(1,ERR) , 1);
    EXPECT_EQ(ERR, SUCCESS);
    EXPECT_EQ(m.factorial(2,ERR) , 2);
    EXPECT_EQ(ERR, SUCCESS);
    EXPECT_EQ(m.factorial(3,ERR) , 6);
    EXPECT_EQ(ERR, SUCCESS);
    EXPECT_EQ(m.factorial(6,ERR) , 720);
    EXPECT_EQ(ERR, SUCCESS);
    EXPECT_EQ(m.factorial(10,ERR) , 3628800);
    EXPECT_EQ(ERR, SUCCESS);
    EXPECT_EQ(m.factorial(17,ERR) , 355687428096000);
    EXPECT_EQ(ERR, SUCCESS);
}

TEST(FACTORIAL, invalid){
    MathErrorCode ERR = SUCCESS;
    EXPECT_EQ(m.factorial(-1,ERR), 0);
    EXPECT_EQ(ERR, NEGATIVE_FACTORIAL_INPUT);
    ERR = SUCCESS;

    EXPECT_EQ(m.factorial(-5,ERR), 0);
    EXPECT_EQ(ERR, NEGATIVE_FACTORIAL_INPUT);
    ERR = SUCCESS;

    EXPECT_EQ(m.factorial(-10,ERR), 0);
    EXPECT_EQ(ERR, NEGATIVE_FACTORIAL_INPUT);
    ERR = SUCCESS;

    EXPECT_EQ(m.factorial(-55,ERR), 0);
    EXPECT_EQ(ERR, NEGATIVE_FACTORIAL_INPUT);
    ERR = SUCCESS;
}

TEST(MODULO, naturalNumbers){
    MathErrorCode ERR = SUCCESS;
    EXPECT_EQ(m.modulo(7,3,ERR) , 1);
    EXPECT_EQ(ERR, SUCCESS);
    EXPECT_EQ(m.modulo(10,5,ERR) , 0);
    EXPECT_EQ(ERR, SUCCESS);
    EXPECT_EQ(m.modulo(15,4,ERR) , 3);
    EXPECT_EQ(ERR, SUCCESS);
    EXPECT_EQ(m.modulo(20,7,ERR) , 6);
    EXPECT_EQ(ERR, SUCCESS);
    EXPECT_EQ(m.modulo(25,6,ERR) , 1);
    EXPECT_EQ(ERR, SUCCESS);
    EXPECT_EQ(m.modulo(30,8,ERR) , 6);
    EXPECT_EQ(ERR, SUCCESS);
    EXPECT_EQ(m.modulo(35,9,ERR) , 8);
    EXPECT_EQ(ERR, SUCCESS);
    EXPECT_EQ(m.modulo(40,11,ERR) , 7);
    EXPECT_EQ(ERR, SUCCESS);
    EXPECT_EQ(m.modulo(45,12,ERR) , 9);
    EXPECT_EQ(ERR, SUCCESS);
    EXPECT_EQ(m.modulo(50,13,ERR) , 11);
    EXPECT_EQ(ERR, SUCCESS);
}

TEST(MODULO, negativeNumbers){
    MathErrorCode ERR = SUCCESS;
    EXPECT_EQ(m.modulo(-30, 7, ERR), -2);
    EXPECT_EQ(ERR, SUCCESS);
    ERR = SUCCESS;

    EXPECT_EQ(m.modulo(25, -8, ERR), 1);
    EXPECT_EQ(ERR, SUCCESS);
    ERR = SUCCESS;
    
    EXPECT_EQ(m.modulo(-48, -5, ERR), -3);
    EXPECT_EQ(ERR, SUCCESS);
    ERR = SUCCESS;
    
    EXPECT_EQ(m.modulo(37, 9, ERR), 1);
    EXPECT_EQ(ERR, SUCCESS);
    ERR = SUCCESS;
    
    EXPECT_EQ(m.modulo(-20, 6, ERR), -2);
    EXPECT_EQ(ERR, SUCCESS);
    ERR = SUCCESS;
    
    EXPECT_EQ(m.modulo(18, -4, ERR), 2);
    EXPECT_EQ(ERR, SUCCESS);
    ERR = SUCCESS;
    
    EXPECT_EQ(m.modulo(-15, -3, ERR), 0);
    EXPECT_EQ(ERR, SUCCESS);
}

TEST(MODULO, nonInt){
    MathErrorCode ERR = SUCCESS;
    EXPECT_NEAR(m.modulo(5.5, 2.5, ERR), 0.5, 1e-3);
    EXPECT_EQ(ERR, SUCCESS);
    ERR = SUCCESS;
    
    EXPECT_NEAR(m.modulo(7.8, 3.2, ERR), 1.4, 1e-3);
    EXPECT_EQ(ERR, SUCCESS);
    ERR = SUCCESS;
    
    EXPECT_NEAR(m.modulo(6.2, -4.3, ERR), 1.9, 1e-3);
    EXPECT_EQ(ERR, SUCCESS);
    ERR = SUCCESS;
    
    EXPECT_NEAR(m.modulo(-9.7, 5.1, ERR), -4.6, 1e-3);
    EXPECT_EQ(ERR, SUCCESS);
    ERR = SUCCESS;
    
    EXPECT_NEAR(m.modulo(-8.4, -6.5, ERR), -1.9, 1e-3);
    EXPECT_EQ(ERR, SUCCESS);
    ERR = SUCCESS;
    
    EXPECT_NEAR(m.modulo(3.3, 1.1, ERR), 1.1, 1e-3);
    EXPECT_EQ(ERR, SUCCESS);
    ERR = SUCCESS;
    
    EXPECT_NEAR(m.modulo(-2.5, 1.5, ERR), -1.0, 1e-3);
    EXPECT_EQ(ERR, SUCCESS);
    ERR = SUCCESS;
    
    EXPECT_NEAR(m.modulo(9.2, -2.3, ERR), 0, 1e-3);
    EXPECT_EQ(ERR, SUCCESS);
}

TEST(MODULO, zeroDivident){
    MathErrorCode ERR = SUCCESS;
    EXPECT_EQ(m.modulo(0,13,ERR) , 0);
    EXPECT_EQ(ERR, SUCCESS);
    EXPECT_EQ(m.modulo(0,6,ERR) , 0);
    EXPECT_EQ(ERR, SUCCESS);
    EXPECT_EQ(m.modulo(0,8,ERR) , 0);
    EXPECT_EQ(ERR, SUCCESS);
    EXPECT_EQ(m.modulo(0,9,ERR) , 0);
    EXPECT_EQ(ERR, SUCCESS);
    EXPECT_EQ(m.modulo(0,11,ERR) , 0);
    EXPECT_EQ(ERR, SUCCESS);  
}

TEST(MODULO, zeroDivisor){
    MathErrorCode ERR = SUCCESS;
    EXPECT_EQ(m.modulo(0,0,ERR) , 0);
    EXPECT_EQ(ERR, DIVISION_BY_ZERO);
    ERR = SUCCESS;

    EXPECT_EQ(m.modulo(5,0,ERR) , 0);
    EXPECT_EQ(ERR, DIVISION_BY_ZERO);
    ERR = SUCCESS;

    EXPECT_EQ(m.modulo(12,0,ERR) , 0);
    EXPECT_EQ(ERR, DIVISION_BY_ZERO);
    ERR = SUCCESS;

    EXPECT_EQ(m.modulo(89,0,ERR) , 0);
    EXPECT_EQ(ERR, DIVISION_BY_ZERO);
    ERR = SUCCESS;

    EXPECT_EQ(m.modulo(413,0,ERR) , 0);
    EXPECT_EQ(ERR, DIVISION_BY_ZERO);
}




