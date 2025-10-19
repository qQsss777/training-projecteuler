#include <catch2/catch_test_macros.hpp>
#include <type_traits>
#include <iostream>
#include <string>
#include <charconv>

// https://projecteuler.fr/p/9

long Triplet(unsigned int value)
{
    long result = 0;
    long a = 1;
    long b = 2;
    long c = value - a - b;

    while (b < c)
    {
        int tmpB = b;
        int tmpC = c;
        bool hasResult = false;

        while (tmpB < tmpC)
        {
            if ((a * a + tmpB * tmpB) == tmpC * tmpC)
            {
                result = a * tmpB * tmpC;
                hasResult = true;
                break;
            }
            tmpB++;
            tmpC--;
        }
        if (hasResult)
        {
            break;
        }
        a++;
        b++;
        c = c - 2;
    }

    return result;
}

TEST_CASE("Renvoie un long", "[Triplet]")
{
    REQUIRE(std::is_same<decltype(Triplet(4)), long>::value);
}

TEST_CASE("Pour une somme à 12, renvoie 60", "[Triplet]")
{
    REQUIRE(Triplet(12) == 60);
}

TEST_CASE("Pour une somme à 1000, renvoie 31875000", "[Triplet]")
{
    REQUIRE(Triplet(1000) == 31875000);
}