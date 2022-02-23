#include "RadixTree.h"
#include <iostream>
using namespace std;
/**
 * La función "Mover_Nodos_hijos" realiza el cambio de nodos cuando una palabra se segmenta en otras
 */
void RadixTree::mover_nodos_hijos(Nodo*& raiz, Nodo*& aux)
{
    raiz->fin_palabra = false;
    for (int i = 0; i < 26; i++) {
        if (*(raiz->hijo+i)) {
            *(aux->hijo + i) = *(raiz->hijo+i);

            *(raiz->hijo+i) = nullptr;
        }
    }
    return;
}
/**
 * La función "get_posicion_corte" obtiene el punto en el que el la palabra se tiene que cortar para formar otro nodo
 */
int RadixTree::get_posicion_corte(Nodo* aux, std::string key)
{
    int aux_1 = 0;
    while ((aux_1 < aux->palabra.length()) && (aux_1 < key.length()) && (*(aux->palabra.c_str()+aux_1) == *(key.c_str()+aux_1))) {
        ++aux_1;
    }
    return aux_1;
}
/**
 * La función "hoja_izquierda" obtiene el dato si existe o no una hoja a la izquierda
 */
bool RadixTree::hoja_izquierda(Nodo* raiz)
{
    for (int i = 0; i < 26; i++) {
        if (*(raiz->hijo+i))
            return false;
    }
    return true;
}
/**
 * La función "dividir_nodos" realiza la division de nodos cuando existe una repeticion de caracteres
 */
Nodo* RadixTree::dividir_nodos(Nodo*& raiz, std::string izq, int pos)
{
    bool tieneHijo = false;
    if (!hoja_izquierda(raiz))
        tieneHijo = true;

    std::string der;
    int rI, lI;
    der = raiz->palabra.substr(pos);
    raiz->palabra = raiz->palabra.substr(0, pos);

    rI = *(der.c_str()+0) - 'a';
    lI = *(izq.c_str()+0) - 'a';
    Nodo* hijoIzq, * hijoDer;

    if (tieneHijo && !raiz->fin_palabra) {
        hijoIzq = new Nodo(izq, true);
        hijoDer = new Nodo(der, false);
    }
    else {
        hijoIzq = new Nodo(izq, true);
        hijoDer = new Nodo(der, true);
    }

    mover_nodos_hijos(raiz, hijoDer);

    *(raiz->hijo+lI) = hijoIzq;
    *(raiz->hijo+rI) = hijoDer;
    return raiz;
}
/**
 * La función "insertar" realiza la insercion de una palabra al arbol
 */
Nodo* RadixTree::insertar(std::string key, Nodo*& raiz)
{
    if (key.length() == 0)
        return raiz;
    Nodo* aux = raiz;
    int ind = *(key.c_str()+0) - 'a';
    int pos;
    if (*(aux->hijo+ind)) {
        aux = *(aux->hijo+ind);
        pos = get_posicion_corte(aux, key);
        key = key.substr(pos);

        if (pos < aux->palabra.length()) {
            aux = dividir_nodos(aux, key, pos);
        }
        else {
            insertar(key, aux);
        }
        if (key.length() == 0)
            aux->fin_palabra = true;
    }
    else {
        *(aux->hijo + ind) = new Nodo(key, true);
    }
    return aux;
}

/**
 * La función "buscar" realiza la busqueda de una palabra en el arbol
 */
bool RadixTree::buscar(Nodo* raiz, std::string palabra)
{
    if (raiz->fin_palabra && (sufijo == palabra))
        return true;
    if (hoja_izquierda(raiz))
        return false;
    for (int i = 0; i < 26; i++) {
        if (*(raiz->hijo+i)) {
            Nodo* tmp = *(raiz->hijo + i);
            pos = sufijo.length();
            sufijo += tmp->palabra;
            if (buscar(*(raiz->hijo+i), palabra))
                return true;
            sufijo = sufijo.substr(0, sufijo.length() - tmp->palabra.length());
        }
    }
    return (raiz->fin_palabra && sufijo == palabra);
}
/**
 * La función "eliminar" realiza la eliminacion de una palabra al arbol
 */
bool RadixTree::eliminar(Nodo* raiz, std::string palabra)
{
    if (raiz->fin_palabra && (sufijo == palabra)) {
        return true;
    }
    if (hoja_izquierda(raiz)) {
        return false;
    }
    for (int i = 0; i < 26; i++) {
        if (*(raiz->hijo + i)) {
            Nodo* tmp = *(raiz->hijo + i);
            pos = sufijo.length();
            sufijo += tmp->palabra;
            if (buscar(*(raiz->hijo + i), palabra)) {
                for (int i = 0; i < 26; i++)
                    *(raiz->hijo + i) = NULL;
                return true;
            }
            sufijo = sufijo.substr(0, sufijo.length() - tmp->palabra.length());
        }
    }

    return (raiz->fin_palabra && sufijo == palabra);
    
}

/**
 * La función "imprimir" realiza la impresion de las palabras que constan en el arbol
 */
void RadixTree::imprimir(Nodo* raiz)
{
    if (raiz->fin_palabra) {
        cout << suf << " ";
        cout << endl;
    }
    if (hoja_izquierda(raiz))
        return;
    for (int i = 0; i < 26; i++) {
        if (*(raiz->hijo + i)) {
            Nodo* tmp = *(raiz->hijo + i);
            pos = suf.length();
            suf += tmp->palabra;
            imprimir(*(raiz->hijo + i));
            suf = suf.substr(0, suf.length() - tmp->palabra.length());
        }
    }
    return;
}
/**
 * La función "setSufijo" obtiene el dato Sufijo
 */
void RadixTree::setSufijo(std::string a){
    this->sufijo = a;
}
