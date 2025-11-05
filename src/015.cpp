#include <catch2/catch_test_macros.hpp>
#include <type_traits>
#include <charconv>
#include <iostream>
#include <numeric>
#include <vector>

// https://projecteuler.fr/p/15

long Paths(long height, long width)
{
    long result = 0;
    long mininumMouvments = height + width;
    long res = 1;
    for (int i = 1; i <= height; ++i)
    {
        res = res * (mininumMouvments - i + 1) / i;
    }

    return res;
}

TEST_CASE("Renvoie un long", "[Paths]")
{
    REQUIRE(std::is_same<decltype(Paths(2, 2)), long>::value);
}

TEST_CASE("Pour 2x2 renvoie 6", "[Paths]")
{
    REQUIRE(Paths(2, 2) == 6);
}

TEST_CASE("Pour 2x3 renvoie 6", "[Paths]")
{
    REQUIRE(Paths(2, 3) == 10);
}

TEST_CASE("Pour 3x2 renvoie 6", "[Paths]")
{
    REQUIRE(Paths(3, 2) == 10);
}

TEST_CASE("Pour 20x20 renvoie 6", "[Paths]")
{
    REQUIRE(Paths(20, 20) == 137846528820);
}