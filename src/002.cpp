#include <catch2/catch_test_macros.hpp>
#include <type_traits>
#include <iostream>

// https://projecteuler.fr/p/2

unsigned int Fibonacci(unsigned int limit)
{
    unsigned int result = 0;
    unsigned int a = 0;
    unsigned int b = 1;

    while (b < limit)
    {
        if (b % 2 == 0)
        {
            result += b;
        }
        unsigned int value = a + b;
        a = b;
        b = value;
    }
    return result;
}

TEST_CASE("Renvoie un int", "[Fibonacci]")
{
    REQUIRE(std::is_same<decltype(Fibonacci(10)), unsigned int>::value);
}

TEST_CASE("Fibonnacci avec limite à 3 renvoie 2", "[Fibonacci]")
{
    REQUIRE(Fibonacci(3) == 2);
}

TEST_CASE("Fibonnacci avec limite à 5 renvoie 2", "[Fibonacci]")
{
    REQUIRE(Fibonacci(5) == 2);
}

TEST_CASE("Fibonnacci avec limite à 10 iterations, renvoie 10", "[Fibonacci]")
{
    REQUIRE(Fibonacci(10) == 10);
}

TEST_CASE("Fibonnacci avec limite à 4000000 renvoie 4613732", "[Fibonacci]")
{
    REQUIRE(Fibonacci(4000000) == 4613732);
}
