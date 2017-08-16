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
 * File:   crypto.cpp
 * Author: phoni
 *
 * Created on August 12, 2017, 12:42 AM
 */

#include <iostream>
#include <string>
#include <bitset>
#include <sstream>
#include <cmath>
#include <stdexcept>
#include <cstring>

#include "crypto.h"


namespace crypto
{
    const char* hexChar2BinCharArr(char c)
    {
        c = toupper(c);
        if (!((48 <= c && c <= 57) || (65 <= c && c <= 70)))
        {
            std::string msg = "Not a hex char: ";
            const char invalidChar = c;
            throw std::invalid_argument(msg+invalidChar);
        }

        switch(toupper(c))
        {
            case '0': return "0000";
            case '1': return "0001";
            case '2': return "0010";
            case '3': return "0011";
            case '4': return "0100";
            case '5': return "0101";
            case '6': return "0110";
            case '7': return "0111";
            case '8': return "1000";
            case '9': return "1001";
            case 'A': return "1010";
            case 'B': return "1011";
            case 'C': return "1100";
            case 'D': return "1101";
            case 'E': return "1110";
            case 'F': return "1111";
        }
    }

    std::string hexString2BinString(std::string input)
    {
        std::string ret;
        ret.reserve(input.length() * 4);
        for (int i = 0; i < input.length(); i++)
        {
            ret += hexChar2BinCharArr(input[i]);
        }
        return ret;
    }

    std::string binString2Base64String(std::string input)
    {
        std::string ret;
        ret.reserve(input.length() / 6);

        int b64Val = 0;
        int blockIndex;
        int bit;

        for (int i = 0; i < input.length(); i++)
        {
            bit = input[i] - 48;
            blockIndex = 5 - i % 6;

            // Check if we've already calculated the b64 value for one block
            // before adding it to the return string and resetting
            if ((i != 0) && (i % 6 == 0))
            {
                ret += int2Base64Char(b64Val);
                b64Val = 0;
            }

            if (bit)
            {
                b64Val += std::pow(2, blockIndex);
            }
        }

        // Add the last character which wasn't done in the for loop
        ret += int2Base64Char(b64Val);
        return ret;
    }

    char int2Base64Char(int input)
    {
        if (input < 26)
        {
            return (char) (input + 65);
        } else if (input < 52)
        {
            return (char) (input + 97 - 26);
        } else if (input < 62)
        {
            return (char) (input + 48 - 52);
        } else if (input == 62)
        {
            return '+';
        } else if (input == 63)
        {
            return '/';
        }
    }

    std::string hexString2Base64(std::string input)
    {
        return binString2Base64String(hexString2BinString(input));
    }
}

