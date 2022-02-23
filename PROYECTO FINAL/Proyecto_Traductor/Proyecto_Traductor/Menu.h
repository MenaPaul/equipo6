#pragma once
class Menu
{
private:
	const char* titulo;
	const char* opciones[6];
	int n;
	int opcion;
public:
	Menu(const char*, const char* opciones[6], int);
	void gotoxy(short, short);
	int getOpcion();
};

