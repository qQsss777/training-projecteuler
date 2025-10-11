#include <catch2/catch_test_macros.hpp>
#include <type_traits>
#include <iostream>
#include <set>
#include <iterator>

// https://projecteuler.fr/p/3
// plus utilisé ancienne approche trop longue
std::set<long> NombrePremiers(long number)
{
    std::set<long> liste{};
    for (long i = 2; i < number; i++)
    {
        bool estPremier = true;
        for (long e : liste)
        {
            if (i % e == 0)
            {
                estPremier = false;
                break;
            }
        }
        if (estPremier)
        {
            liste.insert(i);
        }
    }
    return liste;
}

long FacteurPremier(long number)
{
    if (number <= 2)
    {
        return number;
    }
    long result = 2;
    long tmpNumber = number;
    while (tmpNumber % 2 == 0)
    {
        tmpNumber /= result;
    }

    // maintenant le résultat est impair. on va diviser par les nombre premiers impairs
    // on taille la boucle a la racine carré car on aura soit le premier soit le résultat le sera
    for (long i = 3; i <= std::sqrt(tmpNumber); i = i + 2)
    {
        if (tmpNumber % i == 0)
        {
            result = i;
            tmpNumber /= result;
        }
    }
    return tmpNumber > 2 ? tmpNumber : result;
}

TEST_CASE("Renvoie un int", "[NombrePremiers]")
{
    REQUIRE(std::is_same<decltype(NombrePremiers(10)), std::set<long>>::value);
}

TEST_CASE("La taille de la liste est 4", "[NombrePremiers]")
{
    REQUIRE(NombrePremiers(10).size() == 4);
}

TEST_CASE("L'element 3 est égal à 7", "[NombrePremiers]")
{
    std::set<long> result = NombrePremiers(10);
    auto it = result.begin();
    long value = *next(it, 3);
    REQUIRE(value == 7);
}

TEST_CASE("Renvoie un int", "[FacteurPremier]")
{
    REQUIRE(std::is_same<decltype(FacteurPremier(10)), long>::value);
}

TEST_CASE("Pour 10 le plus grand c'est 5", "[FacteurPremier]")
{
    REQUIRE(FacteurPremier(10) == 5);
}

TEST_CASE("Pour 11 le plus grand c'est 11", "[FacteurPremier]")
{
    REQUIRE(FacteurPremier(11) == 11);
}

TEST_CASE("Pour 13195 le plus grand c'est 29", "[FacteurPremier]")
{
    REQUIRE(FacteurPremier(13195) == 29);
}

TEST_CASE("Pour 91 le plus grand c'est 13", "[FacteurPremier]")
{
    REQUIRE(FacteurPremier(91) == 13);
}

TEST_CASE("Pour 600851475143 le plus grand c'est 6857", "[FacteurPremier]")
{
    REQUIRE(FacteurPremier(600851475143) == 6857);
}