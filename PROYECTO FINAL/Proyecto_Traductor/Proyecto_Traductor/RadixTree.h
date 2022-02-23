#pragma once
#include "Nodo.h"
class RadixTree
{
public:
	std::string sufijo;
	std::string suf;
	int pos;
	RadixTree() = default;
	void mover_nodos_hijos(Nodo*&, Nodo*&);
	int get_posicion_corte(Nodo*, std::string);
	bool hoja_izquierda(Nodo*);
	Nodo* dividir_nodos(Nodo*&, std::string, int);
	Nodo* insertar(std::string, Nodo*&);
	bool buscar(Nodo*, std::string);
	bool eliminar(Nodo*, std::string);
	void imprimir(Nodo*);
	void setSufijo(std::string);
};

