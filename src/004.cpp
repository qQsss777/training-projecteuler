#include <catch2/catch_test_macros.hpp>
#include <type_traits>
#include <iostream>
#include <string>

// https://projecteuler.fr/p/4

// je ne trouve pas propre car on termine forcément la boucle, j'aimerai avoir un break
long Palindrome(unsigned int digits)
{
    long result = 0;
    std::string strNumber(digits, '9');
    long a = std::stol(strNumber);
    long b = std::stol(strNumber);
    while (a > 0)
    {
        bool isFound = false;
        long tmpB = b;
        while (tmpB > 0)
        {
            long tmpResult = a * tmpB;
            // on vérifie si c'est un palindrome
            // on convertit en string et on regarde la taille
            std::string resToStr = std::to_string(tmpResult);
            int size = resToStr.size();
            // on cherche un la moitié de la taille et on prend l'entier inférieur
            int halfSize = std::floor(size / 2);

            // on compare les substring
            std::string endNumber = resToStr.substr(size - halfSize, size);
            reverse(endNumber.begin(), endNumber.end());
            if (resToStr.substr(0, halfSize) == endNumber)
            {
                result = tmpResult >= result ? tmpResult : result;
            }
            tmpB--;
        }
        a--;
        b--;
    }
    return result;
}

TEST_CASE("Renvoie un long", "[Palindrome]")
{
    REQUIRE(std::is_same<decltype(Palindrome(2)), long>::value);
}

TEST_CASE("Pour 2 chiffres, renvoie 91", "[Palindrome]")
{
    REQUIRE(Palindrome(2) == 9009);
}

TEST_CASE("Pour 3 chiffres, renvoie 906609", "[Palindrome]")
{
    REQUIRE(Palindrome(3) == 906609);
}