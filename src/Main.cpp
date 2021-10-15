/*
 * Main.cpp
 *
 *  Created on: 13 de out de 2021
 *      Author: njaneto
 */
#include <iostream>
#include "CowAsciiString.h"

using namespace Navmii::ProgrammingTest;

int main(int argc, char* argv[])
{
    CowAsciiString str("CowAsciiString -> Hello, world!!!");
    std::cout << "str: " << str << std::endl;

    CowAsciiString str_2(str);
    std::cout << "str_2: " << str_2 << std::endl;

    CowAsciiString str_3 = str_2 + " - " + str_2;

    std::cout << "str_3: " << str_3 << std::endl;

    std::cout << "str == str_2: " << (str == str_2) << std::endl;
    int pos;
    str.Find(" ", pos);
    str.Insert(str, pos);
    std::cout << "str: " << str << std::endl;

    char buffer[30];
    str_2.ToPlainString(buffer, 30);

    std::cout << buffer << std::endl;

	return 0;
}
