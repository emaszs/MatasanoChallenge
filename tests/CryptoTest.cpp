/*
 * Copyright (C) 2017 phoni
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * as published by the Free Software Foundation; either version 2
 * of the License, or (at your option) any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program; if not, write to the Free Software
 * Foundation, Inc., 59 Temple Place - Suite 330, Boston, MA  02111-1307, USA.
 */

/*
 * File:   CryptoTest.cpp
 * Author: phoni
 *
 * Created on August 16, 2017, 10:58 PM
 */

#define CATCH_CONFIG_MAIN
#include "catch.hpp"


#include <stdlib.h>
#include <iostream>

#include "crypto.h"
/*
 * Simple C++ Test Suite
 */



TEST_CASE("Convert hex string to Base64", "B64")
{
    std::string testString = "49276d206b696c6c696e6720796f75722062726"
            "1696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";

    std::string resString = crypto::hexString2Base64(testString);

    REQUIRE(resString == "SSdtIGtpbGxpbmcgeW91ciBicmFpbiB"
            "saWtlIGEgcG9pc29ub3VzIG11c2hyb29t");
}

TEST_CASE("Exception when trying to convert non-hex char to binary", "Bin")
{
    REQUIRE_THROWS_WITH(crypto::hexChar2BinCharArr('Z'), "Not a hex char: Z");
}

TEST_CASE("Convert hex character to 4bit representation", "Bin")
{
    REQUIRE(strcmp(crypto::hexChar2BinCharArr('0'), "0000") == 0);
    REQUIRE(strcmp(crypto::hexChar2BinCharArr('1'), "0001") == 0);
    REQUIRE(strcmp(crypto::hexChar2BinCharArr('2'), "0010") == 0);
    REQUIRE(strcmp(crypto::hexChar2BinCharArr('3'), "0011") == 0);
    REQUIRE(strcmp(crypto::hexChar2BinCharArr('4'), "0100") == 0);
    REQUIRE(strcmp(crypto::hexChar2BinCharArr('5'), "0101") == 0);
    REQUIRE(strcmp(crypto::hexChar2BinCharArr('6'), "0110") == 0);
    REQUIRE(strcmp(crypto::hexChar2BinCharArr('7'), "0111") == 0);
    REQUIRE(strcmp(crypto::hexChar2BinCharArr('8'), "1000") == 0);
    REQUIRE(strcmp(crypto::hexChar2BinCharArr('9'), "1001") == 0);
    REQUIRE(strcmp(crypto::hexChar2BinCharArr('A'), "1010") == 0);
    REQUIRE(strcmp(crypto::hexChar2BinCharArr('B'), "1011") == 0);
    REQUIRE(strcmp(crypto::hexChar2BinCharArr('C'), "1100") == 0);
    REQUIRE(strcmp(crypto::hexChar2BinCharArr('D'), "1101") == 0);
    REQUIRE(strcmp(crypto::hexChar2BinCharArr('E'), "1110") == 0);
    REQUIRE(strcmp(crypto::hexChar2BinCharArr('F'), "1111") == 0);
}

