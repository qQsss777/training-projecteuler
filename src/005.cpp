#include <catch2/catch_test_macros.hpp>
#include <type_traits>
#include <iostream>
#include <string>

// https://projecteuler.fr/p/5

long Divisible(unsigned int limit)
{
    long result = 0;
    long tmpValue = limit;
    bool continueLoop = true;
    while (continueLoop)
    {
        bool isFound = true;
        for (unsigned int i = 1; i <= limit; i++)
        {
            if (tmpValue % i > 0)
            {
                isFound = false;
                break;
            }
        }
        if (isFound)
        {

            continueLoop = false;
            result = tmpValue;
        }
        else
        {
            tmpValue += limit;
        }
    }
    return result;
}

TEST_CASE("Renvoie un long", "[Divisible]")
{
    REQUIRE(std::is_same<decltype(Divisible(10)), long>::value);
}

TEST_CASE("Renvoie 2520 pout 10", "[Divisible]")
{
    REQUIRE(Divisible(10) == 2520);
}

TEST_CASE("Renvoie 2520 pout 20", "[Divisible]")
{
    REQUIRE(Divisible(20) == 232792560);
}
