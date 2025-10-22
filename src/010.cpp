#include <catch2/catch_test_macros.hpp>
#include <type_traits>
#include <iostream>
#include <string>
#include <charconv>

// https://projecteuler.fr/p/10

long SommePremiers(long limit)
{
    if (limit < 0)
    {
        return 0;
    }

    if (limit > 0 && limit < 3)
    {
        return limit - 1;
    }

    long result = 2;
    long value = 3;

    while (value < limit)
    {
        bool isNotPremier = false;
        long squareValue = static_cast<long>(std::sqrt(value));

        for (long i = 3; i <= squareValue; i += 2)
        {
            if (value % i == 0)
            {
                isNotPremier = true;
                break;
            }
        }
        if (!isNotPremier)
        {
            result += value;
        }
        value += 2;
    }
    return result;
}

TEST_CASE("Renvoie un long", "[SommePremiers]")
{
    REQUIRE(std::is_same<decltype(SommePremiers(4)), long>::value);
}

TEST_CASE("Pour une limite à 10 renvoie 17", "[SommePremiers]")
{
    REQUIRE(SommePremiers(10) == 17);
}

TEST_CASE("Pour une limite à 2000000 renvoie 17", "[SommePremiers]")
{
    REQUIRE(SommePremiers(2000000) == 142913828922);
}
