//test για αριθμητικούς τελεστές +,-,/,*
//Με την χρήση ενός αρχείου complex.h και custom συναρτήσεων μελών
#define CATCH_CONFIG_MAIN
#include "complex.h"
#include "catch.hpp"

TEST_CASE("complex test","operator_add")
{
    complex c1(4,5);
    complex c2(2,3);
    complex c3=c1+c2;//(6,8)
    //REQUIRE((c1+c2).getReal()==6)
    //REQUIRE((c1+c2).getImaginary()==8)
    double realpart=6,imaginarypart=8;
    REQUIRE(c3.getReal()==realpart);
    REQUIRE(c3.getImaginary()==imaginarypart);
}

//g++ testcasescomplex.cpp complex.cpp -o test -std=c++11
//test  || ./test