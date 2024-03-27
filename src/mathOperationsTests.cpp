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