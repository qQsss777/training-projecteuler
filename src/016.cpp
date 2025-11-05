#include <catch2/catch_test_macros.hpp>
#include <type_traits>
#include <charconv>
#include <iostream>
#include <string>

// https://projecteuler.fr/p/16

long SumDeux(int factor)
{
    long result = 0;
    std::string sum = "1";
    int count = 0;
    while (count < factor)
    {
        int carry = 0;
        std::string tmpResult = "";
        for (auto c : sum)
        {
            int value = (c - '0') * 2 + carry;
            if (value >= 10)
            {
                carry = 1;
                value = value - 10;
            }
            else
            {
                carry = 0;
            }
            tmpResult.push_back(value + '0');
        }
        if (carry == 1)
        {
            tmpResult.push_back('1');
            carry = 0;
        }
        count++;
        sum = tmpResult;
    }
    std::reverse(sum.begin(), sum.end());
    for (auto c : sum)
    {
        result = result + (c - '0');
    }
    return result;
}

TEST_CASE("Renvoie un long", "[SumDeux]")
{
    REQUIRE(std::is_same<decltype(SumDeux(2)), long>::value);
}

TEST_CASE("Pour 3 renvoie 8", "[SumDeux]")
{
    REQUIRE(SumDeux(3) == 8);
}

TEST_CASE("Pour 6 renvoie 10", "[SumDeux]")
{
    REQUIRE(SumDeux(6) == 10);
}

TEST_CASE("Pour 7 renvoie 11", "[SumDeux]")
{
    REQUIRE(SumDeux(7) == 11);
}

TEST_CASE("Pour 15 renvoie 26", "[SumDeux]")
{
    REQUIRE(SumDeux(15) == 26);
}

TEST_CASE("Pour 1000 renvoie 1366", "[SumDeux]")
{
    REQUIRE(SumDeux(1000) == 1366);
}
