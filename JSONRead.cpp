/**
* @file JSON_Read.cpp
* @author Francisco Dos Reis
* @version 0.0
* @date 28.11.2021
* @brief test de la librairie JSONRead
*/

#include <iostream>
#include <stdio.h>
#include "./json-c/json.h"
#include "JSON_Parser.hpp"
#include "string.h"
#include "malloc.h"
#include "JSON_Parser.hpp"

int main()
{
    std::cout << "Hello World!\n";
    JSONRead j("dataLambda.json");
    double lambda=j.ReadDouble("lambda");
    std::cout << lambda;
}
