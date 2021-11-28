// JSONRead.cpp : Ce fichier contient la fonction 'main'. L'exécution du programme commence et se termine à cet endroit.
//

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
