#pragma once
#include<string>
#include "stdlib.h"
class Nodo
{
private:
public:
	std::string palabra;
	bool fin_palabra;
	Nodo**hijo=(Nodo**)calloc(26,sizeof(Nodo*));
	Nodo(std::string, bool);
	Nodo();
	~Nodo();
	friend class RadixTree;

};

