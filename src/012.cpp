#include <catch2/catch_test_macros.hpp>
#include <type_traits>
#include <iostream>
#include <string>
#include <charconv>

// https://projecteuler.fr/p/12

long NombreTriangulaire(unsigned int limit)
{
    long result = 1;
    if (limit == result)
    {
        return result;
    }

    int value = 1;
    int counter = 2;
    while (result == 1)
    {
        if (value > limit)
        {
            int count = 2;
            int sqrtValue = sqrt(value);
            for (int i = 2; i <= sqrtValue; i++)
            {
                if (value % i == 0)
                {
                    count = value == sqrtValue ? count + 1 : count + 2;
                }
            }

            if (count >= limit)
            {
                result = value;
                break;
            }
        }
        value += counter;
        counter++;
    }
    return result;
}

TEST_CASE("Renvoie un long", "[NombreTriangulaire]")
{
    REQUIRE(std::is_same<decltype(NombreTriangulaire(5)), long>::value);
}

TEST_CASE("Renvoie 28", "[NombreTriangulaire]")
{
    REQUIRE(NombreTriangulaire(5) == 28);
}

TEST_CASE("Renvoie 76576500", "[NombreTriangulaire]")
{
    REQUIRE(NombreTriangulaire(501) == 76576500);
}