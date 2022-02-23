#pragma warning(disable : 4996)
#include "Menu.h"
#include <windows.h>
#include<iostream>
#include<conio.h>

/**
 * La función "Menú" crea las opciones de funcionamiento
 */
Menu::Menu(const char* _titulo, const char* _opciones[6], int _n){
	this->titulo = _titulo;
	for (int i = 0; i < 6; i++){
		this->opciones[i] = _opciones[i];
	}
	this->n = _n;
	int opcionSeleccionada = 1;
	bool repite = true;
	do {
		system("CLS");
		gotoxy(5, 3 + opcionSeleccionada);
		std::cout << "==>";
		gotoxy(15, 2);
		std::cout << titulo;
		for (int i = 0; i < n; i++) {
			gotoxy(10, 4 + i); std::cout << i + 1 << ")" << opciones[i];
		}
		int tecla = getch();
		switch (tecla) {
		case 72:
			opcionSeleccionada--;
			if (opcionSeleccionada < 1) {
				opcionSeleccionada = n;
			}
			break;
		case 80:
			opcionSeleccionada++;
			if (opcionSeleccionada > n) {
				opcionSeleccionada = 1;
			}
			break;
		case 13:
			repite = false;
			break;
		}
	} while (repite);
	this->opcion = opcionSeleccionada;
}
/**
 * La función "Gotoxy" ayuda a mover el curso para el desplazamiento del menú
 */
void Menu::gotoxy(short x, short y){
	COORD ord;
	ord.X = x;
	ord.Y = y;
	SetConsoleCursorPosition(GetStdHandle(STD_OUTPUT_HANDLE), ord);
}

int Menu::getOpcion()
{
	return opcion;
}
