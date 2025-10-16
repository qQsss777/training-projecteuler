#include <catch2/catch_test_macros.hpp>
#include <type_traits>
#include <iostream>

// https://projecteuler.fr/p/7

long Premier(unsigned int limit)
{
    long value = 3;
    long result = value;
    unsigned int count = 2;
    while (count <= limit)
    {
        bool estPremier = true;

        for (unsigned int i = 3; i < value; i = i + 2)
        {
            if (value % i == 0)
            {
                estPremier = false;
                break;
            }
        }
        if (estPremier)
        {
            count++;
            result = value;
        }
        value = value + 2;
    }
    return result;
}

TEST_CASE("Renvoie un long", "[Premier]")
{
    REQUIRE(std::is_same<decltype(Premier(10)), long>::value);
}

TEST_CASE("Pour une limite de 6, renvoie 13", "[Premier]")
{
    REQUIRE(Premier(6) == 13);
}

TEST_CASE("Pour une limite de 10001, renvoie 13", "[Premier]")
{
    REQUIRE(Premier(10001) == 104743);
}
