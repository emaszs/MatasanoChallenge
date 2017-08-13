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
 * File:   crypto.h
 * Author: phoni
 *
 * Created on August 12, 2017, 12:49 AM
 */

#include <string>
#include <vector>
#include <bitset>

#ifndef CRYPTO_H
#define CRYPTO_H


namespace crypto
{
    const char* hexChar2BinCharArr(char c);
    std::string hexString2BinString(std::string input);
    std::string binString2Base64String(std::string input);
    char int2Base64Char(int input);
}

#endif /* CRYPTO_H */


