/**
 * @file mathLibTests.cpp
 * 
 * @brief Performs tests on math operations from math_operations.h.
 *  This file is used for testing all operations library. It tests basic cases as well as edgecases, which might 
 *  possibly give incorrect result. It also tests incorrect inputs and if they are handled properly.
 * 
 * @author xfignam00
 * @author xmalegt00
 * @author xnovakf00
 * @author xskovaj00
 */

#include "math_operations.h"
#define CATCH_CONFIG_MAIN
#include "catch.hpp"

MathOps m;


TEST_CASE("ADD", "zero or positive"){
    REQUIRE(m.add(0, 0) == 0);
    REQUIRE(m.add(0, 1) == 1);
    REQUIRE(m.add(0, 0.9) == 0.9);

    REQUIRE(m.add(12, 50) == 72);
    REQUIRE(m.add(7758, 22688) == 30446);
    
    REQUIRE(m.add(0.5, 0.5) == 1);
    REQUIRE(m.add(7.2565489, 2.564056465) == 9.820605365);
}

TEST_CASE("ADD", "negative"){
    REQUIRE(m.add(0, -5) == -5);
    REQUIRE(m.add(0, -1) == -1);
    REQUIRE(m.add(0, -0.9) == -0.9);

    REQUIRE(m.add(12, -50) == -38);
    REQUIRE(m.add(7758, -22688) == -14930);
    
    REQUIRE(m.add(0.5, -0.5) == 0);
    REQUIRE(m.add(-7.2565489, 2.564056465) == -4.692492435);

    REQUIRE(m.add(-5, -568.2) == -573.2);
}

TEST_CASE("SUBSTRACT", "zero or positive"){
    REQUIRE(m.subtract(0, 0) == 0);
    REQUIRE(m.subtract(0, 1) == -1);
    REQUIRE(m.subtract(0, 0.9) == -0.9);

    REQUIRE(m.subtract(20.5, 0.5) == 20);
    REQUIRE(m.subtract(565, 0.2) == 564.8);
    REQUIRE(m.subtract(100, 150.965489) == -50.965489);
}

TEST_CASE("SUBTRACT", "negative"){
    REQUIRE(m.subtract(0,-2) == 2);
    REQUIRE(m.subtract(18,-5) == 23);
    REQUIRE(m.subtract(-125.56, -125.56) == 0);
    REQUIRE(m.subtract(-896.12, -800.12) == 96);

    REQUIRE(m.subtract(158.356, -126.1894) == 284.5454);
}


/*  TODO - ADD ERROR CHECKING */
TEST_CASE("DIVIDE", "by zero"){
    m.divide(0, 0);
    //REQUIRE(ERR != 0);
    //ERR=0;
    m.divide(7, 0);
    //REQUIRE(ERR != 0);
    //ERR=0;
    m.divide(-58.265, 0);
    //REQUIRE(ERR != 0);
}

TEST_CASE("DIVIDE", "positives"){

    REQUIRE(m.divide(2,1) == 2);

    REQUIRE(m.divide(1,2) == 0.5);

    REQUIRE(m.divide(1,3) == 0.3333333333);

    REQUIRE(m.divide(1.2,10) == 0.12);

}

TEST_CASE("MULTIPLY", "zero"){
    REQUIRE(m.multiply(0,0) == 0);
    REQUIRE(m.multiply(0,189) == 0);
    REQUIRE(m.multiply(45498.4894,0) == 0);
}

TEST_CASE("MULTIPLY", "two positive"){
    REQUIRE(m.multiply(1,1) == 1);
    REQUIRE(m.multiply(156,1) == 156);
    REQUIRE(m.multiply(2, 45.25) == 90.5);
}

TEST_CASE("MULTIPLY", "positive and negative"){
    REQUIRE(m.multiply(-1, 159.8965) == -159.8965);
    REQUIRE(m.multiply(-89, 6) == -534);
    REQUIRE(m.multiply(15.9728, -45.87096) == -732.687669888);
    REQUIRE(m.multiply(-89.48, 0.4) == -223.7);
}

TEST_CASE("MULTIPLY", "two negative"){
    REQUIRE(m.multiply(-5,-1) == 5);
    REQUIRE(m.multiply(-868,-12.856) == 11159.008);
    REQUIRE(m.multiply(-159.55, -0.5) == 79.775);
    REQUIRE(m.multiply(-85.592, -99.56898) == 8436.71613616);
}

TEST_CASE("SQUARE ROOT", "zero"){
    REQUIRE(m.squareRoot(0) == 0);
}

TEST_CASE("SQUARE ROOT", "positive"){
    REQUIRE(m.squareRoot(4) == 2);
    REQUIRE(m.squareRoot(9) == 3);
    REQUIRE(m.squareRoot(9801) == 99);
    REQUIRE(m.squareRoot(17991.929956) == 134.134);
}

/* TODO - ERROR CHECKING */
TEST_CASE("SQUARE ROOT", "negative"){

}

/* TODO - ERROR CHECKING */
TEST_CASE("NTH ROOT", "not natural root"){

}

TEST_CASE("NTH ROOT", "zero"){
    REQUIRE(m.nthRoot(0, 2) == 0);
    REQUIRE(m.nthRoot(0, 5) == 0);
    REQUIRE(m.nthRoot(0, 99) == 0);
}

TEST_CASE("NTH ROOT", "even and positive"){
    REQUIRE(m.nthRoot(2401, 4) == 7);
    REQUIRE(m.nthRoot(244.140625, 6) == 2.5);
    REQUIRE(m.nthRoot(9756, 12) == 2.15);
}

/* TODO - ERROR CHECKING */
TEST_CASE("NTH ROOT", "even and negative"){

}

TEST_CASE("NTH ROOT", "odd"){
    REQUIRE(m.nthRoot(27,3) == 3);
    REQUIRE(m.nthRoot(97.65625, 5) == 2.5);
    REQUIRE(m.nthRoot(0.000000001, 9) == 0.1);
    
    REQUIRE(m.nthRoot(-27,3) == -3);
    REQUIRE(m.nthRoot(-97.65625, 5) == -2.5);
    REQUIRE(m.nthRoot(-0.000000001, 9) == -0.1);
}

TEST_CASE("NTH POWER", "zero and one"){
    REQUIRE(m.nthPower(0, 2) == 0);
    REQUIRE(m.nthPower(0, 3) == 0);
    REQUIRE(m.nthPower(0, 16) == 0);
    REQUIRE(m.nthPower(0, 27) == 0);
    REQUIRE(m.nthPower(0, 1276) == 0);

    REQUIRE(m.nthPower(1, 2) == 1);
    REQUIRE(m.nthPower(1, 3) == 1);
    REQUIRE(m.nthPower(1, 16) == 1);
    REQUIRE(m.nthPower(1, 27) == 1);
    REQUIRE(m.nthPower(1, 1276) == 1);
}

TEST_CASE("NTH POWER", "on zero"){
    REQUIRE(m.nthPower(56,0) == 1);
    REQUIRE(m.nthPower(4566.566,0) == 1);
    REQUIRE(m.nthPower(-659.4,0) == 1);
    REQUIRE(m.nthPower(-0.656,0) == 1);
}

TEST_CASE("NTH POWER", "even"){
    REQUIRE(m.nthPower(7, 4) == 2401);
    REQUIRE(m.nthPower(2.5, 6) == 244.140625);
    REQUIRE(m.nthPower(2.15, 12) == 9756);

    REQUIRE(m.nthPower(-7, 4) == 2401);
    REQUIRE(m.nthPower(-2.5, 6) == 244.140625);
    REQUIRE(m.nthPower(-2.15, 12) == 9756);
}

TEST_CASE("NTH POWER", "odd"){
    REQUIRE(m.nthPower(3,3) == 27);
    REQUIRE(m.nthPower(2.5, 5) == 97.65625);
    REQUIRE(m.nthPower(0.1, 9) == 0.000000001);
    
    REQUIRE(m.nthPower(-3,3) == -27);
    REQUIRE(m.nthPower(-2.5, 5) == -97.65625);
    REQUIRE(m.nthPower(-0.1, 9) == -0.000000001);
}

/* TODO */
TEST_CASE("NTH POWER", "invalid exponent"){

}

TEST_CASE("FACTORIAL", "zero"){
    REQUIRE(m.factorial(0) == 1);
}

TEST_CASE("FACTORIAL", "valid"){
    REQUIRE(m.factorial(1) == 1);
    REQUIRE(m.factorial(2) == 2);
    REQUIRE(m.factorial(3) == 6);
    REQUIRE(m.factorial(6) == 720);
    REQUIRE(m.factorial(10) == 3628800);
    REQUIRE(m.factorial(17) == 355687428096000);
}

/* TODO - ERROR CHECKING */
TEST_CASE("FACTORIAL", "invalid"){

}

TEST_CASE("MODULO", "valid"){
    REQUIRE(m.modulo(7,3) == 1);
    REQUIRE(m.modulo(10,5) == 0);
    REQUIRE(m.modulo(15,4) == 3);
    REQUIRE(m.modulo(20,7) == 6);
    REQUIRE(m.modulo(25,6) == 1);
    REQUIRE(m.modulo(30,8) == 6);
    REQUIRE(m.modulo(35,9) == 8);
    REQUIRE(m.modulo(40,11) == 7);
    REQUIRE(m.modulo(45,12) == 9);
    REQUIRE(m.modulo(50,13) == 11);
}
