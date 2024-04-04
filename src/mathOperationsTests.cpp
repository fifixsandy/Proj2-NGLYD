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

#include "math_operations.h"
#include "gtest/gtest.h"

MathOps m;


TEST(ADD, zeroOrPositive){
    EXPECT_EQ(m.add(0, 0) , 0);
    EXPECT_EQ(m.add(0, 1) , 1);
    EXPECT_EQ(m.add(0, 0.9) , 0.9);

    EXPECT_EQ(m.add(12, 50) , 72);
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
    EXPECT_EQ(m.subtract(100, 150.965489) , -50.965489);
}

TEST(SUBTRACT, negative){
    EXPECT_EQ(m.subtract(0,-2) , 2);
    EXPECT_EQ(m.subtract(18,-5) , 23);
    EXPECT_EQ(m.subtract(-125.56, -125.56) , 0);
    EXPECT_EQ(m.subtract(-896.12, -800.12) , 96);

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

    EXPECT_EQ(m.divide(1,3,ERR) , 0.3333333333);
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
    EXPECT_EQ(m.multiply(-89.48, 0.4) , -223.7);
}

TEST(MULTIPLY, twoNegative){
    EXPECT_EQ(m.multiply(-5,-1) , 5);
    EXPECT_EQ(m.multiply(-868,-12.856) , 11159.008);
    EXPECT_EQ(m.multiply(-159.55, -0.5) , 79.775);
    EXPECT_EQ(m.multiply(-85.592, -99.56898) , 8436.71613616);
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

    EXPECT_EQ(m.squareRoot(-254454, ERR) , 0);
    EXPECT_EQ(ERR, NEGATIVE_ROOT_INPUT); 

    EXPECT_EQ(m.squareRoot(-0.485454, ERR) , 0);
    EXPECT_EQ(ERR, NEGATIVE_ROOT_INPUT);

    EXPECT_EQ(m.squareRoot(-58.54545444, ERR) , 0);
    EXPECT_EQ(ERR, NEGATIVE_ROOT_INPUT);
}

/* TODO - ERROR CHECKING */
TEST(NTH_ROOT, notNaturalRoot){

}

TEST(NTH_ROOT, zero){
    EXPECT_EQ(m.nthRoot(0, 2) , 0);
    EXPECT_EQ(m.nthRoot(0, 5) , 0);
    EXPECT_EQ(m.nthRoot(0, 99) , 0);
}

TEST(NTH_ROOT, evenAndPositive){
    EXPECT_EQ(m.nthRoot(2401, 4) , 7);
    EXPECT_EQ(m.nthRoot(244.140625, 6) , 2.5);
    EXPECT_EQ(m.nthRoot(9756, 12) , 2.15);
}

/* TODO - ERROR CHECKING */
TEST(NTH_ROOT, evenAndNegative){

}

TEST(NTH_ROOT, odd){
    EXPECT_EQ(m.nthRoot(27,3) , 3);
    EXPECT_EQ(m.nthRoot(97.65625, 5) , 2.5);
    EXPECT_EQ(m.nthRoot(0.000000001, 9) , 0.1);
    
    EXPECT_EQ(m.nthRoot(-27,3) , -3);
    EXPECT_EQ(m.nthRoot(-97.65625, 5) , -2.5);
    EXPECT_EQ(m.nthRoot(-0.000000001, 9) , -0.1);
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
    EXPECT_EQ(m.nthPower(2.15, 12) , 9756);

    EXPECT_EQ(m.nthPower(-7, 4) , 2401);
    EXPECT_EQ(m.nthPower(-2.5, 6) , 244.140625);
    EXPECT_EQ(m.nthPower(-2.15, 12) , 9756);
}

TEST(NTH_POWER, odd){
    EXPECT_EQ(m.nthPower(3,3) , 27);
    EXPECT_EQ(m.nthPower(2.5, 5) , 97.65625);
    EXPECT_EQ(m.nthPower(0.1, 9) , 0.000000001);
    
    EXPECT_EQ(m.nthPower(-3,3) , -27);
    EXPECT_EQ(m.nthPower(-2.5, 5) , -97.65625);
    EXPECT_EQ(m.nthPower(-0.1, 9) , -0.000000001);
}

/* TODO */
TEST(NTH_POWER, invalidExponent){

}

TEST(FACTORIAL, zero){
    EXPECT_EQ(m.factorial(0) , 1);
}

TEST(FACTORIAL, valid){
    EXPECT_EQ(m.factorial(1) , 1);
    EXPECT_EQ(m.factorial(2) , 2);
    EXPECT_EQ(m.factorial(3) , 6);
    EXPECT_EQ(m.factorial(6) , 720);
    EXPECT_EQ(m.factorial(10) , 3628800);
    EXPECT_EQ(m.factorial(17) , 355687428096000);
}

/* TODO - ERROR CHECKING */
TEST(FACTORIAL, invalid){

}

TEST(MODULO, validNumbers){
    EXPECT_EQ(m.modulo(7,3) , 1);
    EXPECT_EQ(m.modulo(10,5) , 0);
    EXPECT_EQ(m.modulo(15,4) , 3);
    EXPECT_EQ(m.modulo(20,7) , 6);
    EXPECT_EQ(m.modulo(25,6) , 1);
    EXPECT_EQ(m.modulo(30,8) , 6);
    EXPECT_EQ(m.modulo(35,9) , 8);
    EXPECT_EQ(m.modulo(40,11) , 7);
    EXPECT_EQ(m.modulo(45,12) , 9);
    EXPECT_EQ(m.modulo(50,13) , 11);
}

TEST(MODULO, zeroDivident){
    EXPECT_EQ(m.modulo(0,13) , 0);
    EXPECT_EQ(m.modulo(0,6) , 0);
    EXPECT_EQ(m.modulo(0,8) , 0);
    EXPECT_EQ(m.modulo(0,9) , 0);
    EXPECT_EQ(m.modulo(0,11) , 0);  
}

/* TODO - ERROR CHECKING*/
TEST(MODULO, zeroDivisor){

}

/* TODO - ERROR CHECKING*/
TEST(MODULO, invalidNumbers){

}

