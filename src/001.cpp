#include <catch2/catch_test_macros.hpp>
#include <type_traits>
#include <iostream>

//https://projecteuler.fr/p/1

unsigned int P1( unsigned int number ) {
    unsigned int result = 0;
    for (int i = 1; i < number; i++) {
        if(i % 3 == 0 || i % 5 == 0){
            result += i;
        }
    }
    return result;
}

TEST_CASE( "Renvoie un int", "[P1]" ) {
    REQUIRE(std::is_same<decltype(P1(10)), unsigned int>::value);
}

TEST_CASE( "tous les nombres naturels en dessous de 10 qui sont des multiples de 3 ou 5 donne la somme de 23", "[P1]" ) {
        REQUIRE( P1(10) == 23 );
}

TEST_CASE( "tous les nombres naturels en dessous de 1000 qui sont des multiples de 3 ou 5 donne la somme de 1000", "[P1]" ) {
        REQUIRE( P1(1000) == 233168 );
}