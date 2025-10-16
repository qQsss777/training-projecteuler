#include <catch2/catch_test_macros.hpp>
#include <type_traits>
#include <iostream>
#include <string>
#include <array>

// https://projecteuler.fr/p/6

std::array<long, 2> Difference(unsigned int limit)
{
    std::array<long, 2> result = {0, 0};
    long squareSum = 0;
    long sum = 0;
    for (unsigned int i = 1; i <= limit; i++)
    {
        squareSum += (i * i);
        sum += i;
    }
    sum = sum * sum;
    result[0] = sum;
    result[1] = sum - squareSum;
    return result;
}

TEST_CASE("Renvoie un array", "[Difference]")
{
    REQUIRE(std::is_same<decltype(Difference(10)), std::array<long, 2>>::value);
}

TEST_CASE("Renvoie un array de taille 2", "[Difference]")
{
    REQUIRE(Difference(10).size() == 2);
}

TEST_CASE("La somme des carrés allant jusque 10 est de 3025", "[Difference]")
{
    REQUIRE(Difference(10)[0] == 3025);
}

TEST_CASE("La différence pour une limite de 10 est 2640", "[Difference]")
{
    REQUIRE(Difference(10)[1] == 2640);
}

TEST_CASE("La somme des carrés allant jusque 100 est de 25502500", "[Difference]")
{
    REQUIRE(Difference(100)[0] == 25502500);
}

TEST_CASE("La différence pour une limite de 100 est ", "[Difference]")
{
    REQUIRE(Difference(100)[1] == 25164150);
}