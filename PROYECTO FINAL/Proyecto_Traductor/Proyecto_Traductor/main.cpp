/*
	Universidad de las Fuerzas Armadas - ESPE
	Proyecto - Tercer Parcial Traductor
	Autores:
	Paúl Mena - Esteban Chablay
	
	Fecha de Creación: 21/02/2022
	Fecha de Modificación: 22/02/2022
*/

#pragma once
#pragma warning(disable : 4996)
#include "Nodo.h"
#include <thread>
#include "RadixTree.h"
#include "Menu.h"
#include "conio.h"
#include <fstream>
#include <iostream>
#include "Marquesina.h"
#include <stdio.h>
#include <clocale>
#include <windows.h>

using namespace std;


void marquee_limit(std::string text, size_t limit) {
	bool ciclo = true;
	while (ciclo)
	{
		std::string temp = text;
		text.erase(0, 1);
		text += temp[0];
		std::this_thread::sleep_for(std::chrono::milliseconds(800));
		//poner titulo en la consola

		SetConsoleTitleA(text.substr(0, limit).c_str());
		if (GetAsyncKeyState(VK_RETURN)) {
			ciclo = false;
			break;
		}

	}
}

bool contiene(const char* a,const char* b) {
	bool c = false;
	int j = 0;
	char* aux = (char*)calloc(200, sizeof(char));
	char* aux1 = (char*)calloc(strlen(b) + 3, sizeof(char));
	for (int i = 0; i <= strlen(a); i++) {
		if (*(a + i) != ' ' ){
			if (*(a + i) == ';' || *(a + i) == '\0' ) {
				j = 0;
				for (int x = 0; x < strlen(b); x++){
					if (*(b+x)=='ñ') {
						*(aux1 + j++) = 'n';
						*(aux1 + j++) = 'i';
					}
					else {
						*(aux1 + j++) = *(b + x);
					}
				}
				if (!strcmp(aux, aux1))
					c = true;
				for (int x = 0; x < strlen(b); x++) {
					if (*(b + x) == 'á') {
						*(aux1 + x) = 'a';
					}
					else {
						*(aux1 + x) = *(b + x);
					}
				}
				if (!strcmp(aux, aux1))
					c = true;
				for (int x = 0; x < strlen(b); x++) {
					if (*(b + x) == 'é') {
						*(aux1 + x) = 'e';
					}
					else {
						*(aux1 + x) = *(b + x);
					}
				}
				if (!strcmp(aux, aux1))
					c = true;
				for (int x = 0; x < strlen(b); x++) {
					if (*(b + x) == 'í') {
						*(aux1 + x) = 'i';
					}
					else {
						*(aux1 + x) = *(b + x);
					}
				}
				if (!strcmp(aux, aux1))
					c = true;
				for (int x = 0; x < strlen(b); x++) {
					if (*(b + x) == 'ó') {
						*(aux1 + x) = 'o';
					}
					else {
						*(aux1 + x) = *(b + x);
					}
				}
				if (!strcmp(aux, aux1))
					c = true;
				for (int x = 0; x < strlen(b); x++) {
					if (*(b + x) == 'ú') {
						*(aux1 + x) = 'u';
					}
					else {
						*(aux1 + x) = *(b + x);
					}
				}
				j = 0;
				if (!strcmp(aux, b)||!strcmp(aux,aux1))
					c = true;
				aux = (char*)calloc(200, sizeof(char));
			}
			else {
				*(aux + j++) = *(a + i);
			}
		}
		
	}
	return c;
}

void palabra(RadixTree r,Nodo*&raiz,char* cjPalabras) {	
	char* aux = (char*)calloc(100, sizeof(char));
	int j = 0;
	for (int i = 0; i < strlen(cjPalabras); i++){
		if (*(cjPalabras + i) == ' ') {
			i++;
		}
		else {
			if (*(cjPalabras + i) == ';') {
				string s = aux;
				r.insertar(s, raiz);
				aux = (char*)calloc(100, sizeof(char));
				j = 0;
			}
			else
				*(aux + j++) = *(cjPalabras + i);
		}
	}	
}

char* expSec(const char* a) {
	bool centinela = false;
	char* aux = (char*)calloc(200, sizeof(char));
	int j = 0;
	for (int i = 0; i < strlen(a); i++) {
		if (*(a + i) == '/') {
			centinela = true;
			i++;
		}
		if (centinela) {
			*(aux + j) = *(a + i);
			j++;
		}
	}
	return aux;
}

char* expPrim(const char* a) {
	char* aux = (char*)calloc(200, sizeof(char));
	int i = 0, j = 0;
	while (*(a + i) != '/') {
		*(aux + j) = *(a + i);
		j++;
		i++;
	}
	return aux;
}





int main()
{
	
	Marquee mark1(" Paul Mena --- Esteban Chablay ", 27);
	mark1.animation();
	cout << "" << endl;
	cout << "" << endl;
	cout << "" << endl;
	

	std::setlocale(LC_ALL, "¨Spanish");
	SetConsoleCP(1252); 
	SetConsoleOutputCP(1252); 
	char* word = NULL;
	char* aux = NULL;	
	char* test = (char*)calloc(100,sizeof(char));
	char* test_1 = (char*)calloc(100, sizeof(char));
	bool repite = true;
	int n = 0, x = 0;
	

	
	cout << "" << endl;
	cout << "" << endl;
	const char* titulo = "MENU PRINCIPAL";
	cout << "" << endl;
	const char* opciones[] = { "Inglés-Español","Español-Inglés","Salir" };
	cout << "" << endl;
	cout << "" << endl;
	string s;
	bool z = false;
	Nodo* raizIng = new Nodo();
	Nodo* raizEsp = new Nodo();
	RadixTree o;
	ifstream f;
	do {
		z = false;
		Menu m(titulo, opciones, 3);
		aux = (char*)calloc(200, sizeof(char));
		word = (char*)calloc(200, sizeof(char));
		system("CLS");
		int opcion = m.getOpcion();
		switch (opcion) {
		case 1: {
			std::setlocale(LC_ALL, ".UTF-8");
			cout << "" << endl;
			cout << "" << endl;
			cout << "" << endl;
			cout << "Ingrese una palabra en ingles:"<<endl;
			cin>> test;
			
			x = 0;
			n = 0;
			strcpy(word, test);
			f.open("dic1.txt");
			if (f.is_open()) {
				while (!f.eof()&&x!=1) {
					getline(f, s);
					if (contiene(expPrim(s.c_str()), word)) {
						strcpy(aux, expPrim(s.c_str()));
						palabra(o, raizIng, aux);
						x++;
						z = true;
					}
					n++;
				}
				f.close();
			}
			else cout << "Error de apertura del archivo." << endl;
			if (z) {
				x = 0;
				aux = (char*)calloc(200, sizeof(char));
				f.open("dic1.txt");
				if (f.is_open()) {
					while (!f.eof()) {
						if (x == n) {
							strcpy(aux, (expSec(s.c_str())));
							palabra(o, raizEsp, aux);
						}
						getline(f, s);
						x++;
					}
					f.close();
				}
				else cout << "Error de apertura del archivo." << endl;
				o.buscar(raizEsp, aux);
				cout << endl << "Traduccion: " << aux << endl;
			}
			else {
				cout<< "\nLa palabra no existe en el arbol Radix, ni en la base del diccionario o ingreso una palabra incorrecta intentelo de nuevo...";
			}
			setlocale(LC_ALL, "");// Cambiar locale - Suficiente para máquinas Linux
			
			cout << endl;
			system("pause");
			break;
		}
		case 2: {
			x = 0;
			n = 0;
			setlocale(LC_ALL, "sr_ME.UTF-8@latin");// Cambiar locale - Suficiente para máquinas Linux
			cout << "Ingrese una palabra en español:";
			cin>> test_1;
			strcpy(word, test_1);
			f.open("dic2.txt");
			if (f.is_open()) {
				while (!f.eof() && x != 1) {
					getline(f, s);
					if (contiene(expPrim(s.c_str()), word)) {
						strcpy(aux, expPrim(s.c_str()));
						palabra(o, raizEsp, aux);
						x++;
						z = true;
					}
					n++;
				}
				f.close();
			}
			else cout << "Error de apertura del archivo." << endl;
			if (z) {
				x = 0;
				aux = (char*)calloc(200, sizeof(char));
				f.open("dic2.txt");
				if (f.is_open()) {
					while (!f.eof()) {
						if (x == n) {
							strcpy(aux, (expSec(s.c_str())));
							palabra(o, raizIng, aux);
						}
						getline(f, s);
						x++;
					}
					f.close();
				}
				else cout << "Error de apertura del archivo." << endl;

				cout << endl << "Traduccion: " << aux << endl;
			}
			else {
				cout << "\nLa palabra no existe en el arbol Radix, ni en la base del diccionario o ingreso una palabra incorrecta intentelo de nuevo...";
			}
			setlocale(LC_ALL, "");// Cambiar locale - Suficiente para máquinas Linux
			cout << endl;
			system("pause");
			break;
		}
		case 3:
			exit(0);
			system("pause");
			break;
		}
	} while (repite);
	

}
