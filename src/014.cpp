#include <catch2/catch_test_macros.hpp>
#include <type_traits>
#include <charconv>
#include <iostream>

// https://projecteuler.fr/p/14

long Suite(long start)
{
    long currentCount = 0;
    long result = 0;
    int stop = 1;
    std::unordered_map<long, long> memory{};
    for (int idx = start; idx > 0; --idx)
    {
        long current = idx;
        int count = 0;
        while (current > stop)
        {
            if (memory.find(current) != memory.end())
            {
                count += memory[current];
                break;
            }
            count++;
            if (current % 2 == 0)
            {
                current = current / 2;
            }
            else
            {
                current = current * 3 + 1;
            }
        }
        memory[idx] = count;
        if (count > currentCount)
        {
            currentCount = count;
            result = idx;
        }
    }
    return result;
}

TEST_CASE("Renvoie un long", "[Suite]")
{
    REQUIRE(std::is_same<decltype(Suite(999999)), long>::value);
}

TEST_CASE("Pour 999999 renvoie 837799", "[Suite]")
{
    REQUIRE(Suite(999999) == 837799);
}
