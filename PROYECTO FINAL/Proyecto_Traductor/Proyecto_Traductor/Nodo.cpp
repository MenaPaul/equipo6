#pragma once
#include "Nodo.h"
#include <iostream>
using namespace std;
/**
 * La función "Nodo" es el constructor de la clase nodo
 */
Nodo::Nodo(std::string word, bool EOS)
{
    this->palabra = word;
    this->fin_palabra = EOS;
    for (int t = 0; t < 26; t++)
        this->hijo[t] = nullptr;
}

Nodo::Nodo()
{
    for (int t = 0; t < 26; t++)
        this->hijo[t] = nullptr;

    this->fin_palabra = false;
}
/**
 * La función "Nodo" es el destructor de la clase nodo
 */
Nodo::~Nodo()
{
    for (int t = 0; t < 26; t++) {
        delete[] this->hijo[t];
        this->hijo[t] = nullptr;
    }
}


