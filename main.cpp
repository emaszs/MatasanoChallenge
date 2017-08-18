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
 * File:   main.cpp
 * Author: phoni
 *
 * Created on August 12, 2017, 12:32 AM
 */

#include <cstdlib>
#include <iostream>
#include <string>
#include "crypto.h"

/*
 *
 */
int main(int argc, char** argv) {

//    std::string testString = "ADDADD";
//    std::string testString = "49276d206b696c6c696e6720796f757220627261696e206c696b65206120706f69736f6e6f7573206d757368726f6f6d";
    std::string testString = "1234567764";


    try
    {

        std::cout << crypto::binString2Base64String(crypto::hexString2BinString(testString)) << std::endl;
    } catch (std::exception& e)
    {
        std::cout << "caught exception! " << e.what() << std::endl;
    }
//    std::cout << crypto::hexChar2BinCharArr('A') << std::endl;
    return 0;
}
