// Arboles_AVL.cpp
//Este programa permite crear un arbol AVL, agregar nodos, buscarlos y eliminarlos

#include <iostream>
#include <conio.h>
#include <stdlib.h>

using namespace std;

struct Nodo {
	int dato;
	Nodo* der;
	Nodo* izq;
	Nodo* padre;
};

// Prototipos de las funciones
void menu();
Nodo* n_crear(int, Nodo*);
void n_insertar(Nodo*&, int, Nodo*);
void mostrarArbol(Nodo*, int);
bool buscar(Nodo*, int);
void eliminar(Nodo*, int);
void eliminarNodo(Nodo*);
Nodo* minimo(Nodo*);
void reemplazar(Nodo*, Nodo*);
void destruir(Nodo*);

Nodo* arbol = NULL;

int main()
{
	menu();

	return 0;
}

// Funcion para un menu :D
void menu() {
	int dato, opcion, contador = 0;

	do {
		cout << "\t\tMENU" << endl;
		cout << "1: Insertar un nuevo nodo" << endl;
		cout << "2: Mostrar el arbol" << endl;
		cout << "3: Buscar un elemento en el arbol" << endl;
		cout << "4: Eliminar un nodo" << endl;
		cout << "5: Salir" << endl;
		cin >> opcion;

		switch (opcion) {
		case 1: 
			cout << "Digite un numero:" << endl;
			cin >> dato;
			n_insertar(arbol, dato, NULL);
			cout << endl;
			system("pause");
			break;
		case 2:
			cout << "\nMostrando el arbol" << endl;
			mostrarArbol(arbol, contador);
			cout << endl;
			system("pause");
			break;
		case 3:
			cout << "\nDigite el elemento a buscar: " << endl;
			cin >> dato;
			if (buscar(arbol, dato) == true) {
				cout << "\nElemento " << dato << " ha sido encontrado en el arbol" << endl;
			}
			else {
				cout << "Elemento no encontrado" << endl;
			}
			cout << endl;
			system("pause");
			break;
		case 4:
			cout << "\nDigite el nodo a eliminar" << endl;
			cin >> dato;
			eliminar(arbol, dato);
			cout << endl;
			system("pause");
			break;
		}
		system("cls");
	} while (opcion != 5);
}

// Funcion para crear un nuevo nodo
Nodo* n_crear(int n, Nodo* padre) {
	Nodo* n_nuevo = new Nodo();

	n_nuevo->dato = n;
	n_nuevo->der = NULL;
	n_nuevo->izq = NULL;
	n_nuevo->padre = padre;

	return n_nuevo;
}

// Funcion para insertar elementos en el arbol
void n_insertar(Nodo*& arbol, int n, Nodo* padre) {
	// Si el arbol esta vacio
	if (arbol == NULL) {
		Nodo* n_nuevo = n_crear(n, padre);
		arbol = n_nuevo;
	}
	//Si el arbol tiene uno o mas nodos
	else {
		// Obtenemos el valor de la raiz
		int valorRaiz = arbol->dato;
		//Si el elemento es menor a la raiz se insierta a la izquierda
		if (n < valorRaiz) {
			n_insertar(arbol->izq, n, arbol);
		}
		// Si el elemento es mayor a la raiz se insierta a la derecha
		else {
			n_insertar(arbol->der, n, arbol);
		}

	}
}

// Funcion para mostrar el arbol completo
void mostrarArbol(Nodo *arbol, int cont) {
	// Si el arbol esta vacio
	if (arbol == NULL) {
		return;
	}
	else {
		mostrarArbol(arbol->der, cont + 1);
		for (int i = 0; i < cont; i++){
			cout << "   ";
		}
		cout << arbol->dato << endl;
		mostrarArbol(arbol->izq, cont + 1);
	}
}

//Funcion para buscar un elemento en el arbol
bool buscar(Nodo* arbol, int n) {
	if (arbol == NULL) {
		return false;
	}
	else if (arbol->dato == n) {
		return true;
	}
	else if (n < arbol->dato) {
		return buscar(arbol->izq, n);
	}
	else {
		return buscar(arbol->der, n);
	}
}

// Funcion para eliminar nodos
void eliminar(Nodo* arbol, int n) {
	if (arbol == NULL) {
		return;
	}
	// Si el valor es menor
	else if (n < arbol->dato) {
		// Busca por la izquierda
		eliminar(arbol->izq, n);
	}
	// Si el valor es mayor
	else if (n > arbol->dato) {
		// Busca por la derecha
		eliminar(arbol->der, n);
	}
	// Si ya encontraste el valor
	else {
		eliminarNodo(arbol);
	}
}

// Funcion para determinar el nodo mas a la izquierda
Nodo* minimo(Nodo* arbol) {
	if (arbol == NULL) {
		return NULL;
	}
	// Si tiene hijo izquierdo
	if (arbol->izq) {
		// Buscamos lo mas a la izquierda posible
		return minimo(arbol->izq);
	}
	// Si no tiene hijo izquierdo
	else {
		// Retornamos el mismo nodo
		return arbol;
	}
}

// Funcion para reemplazar dos nodos
void reemplazar(Nodo* arbol, Nodo* nuevoNodo) {
	// A padre le asignamos su nuevo hijo
	if (arbol->padre) {
		if (arbol->dato == arbol->padre->izq->dato) {
			arbol->padre->izq = nuevoNodo;
		}
		else if (arbol->dato == arbol->padre->der->dato) {
			arbol->padre->der = nuevoNodo;
		}
	}
	// Asignamos un nuevo padre
	if (nuevoNodo) {
		nuevoNodo->padre = arbol->padre;
	}
}

// Funcion para destruir un nodo
void destruir(Nodo* nodo) {
	nodo->izq = NULL;
	nodo->der = NULL;

	delete nodo;
}

// Funcion para eliminar un nodo encontrado
void eliminarNodo(Nodo* nodoEliminar) {
	// Si el nodo tiene hijo izquierdo y derecho
	if (nodoEliminar->izq && nodoEliminar->der) {
		Nodo* menor = minimo(nodoEliminar->der);
		nodoEliminar->dato = menor->dato;
		eliminarNodo(menor);
	}
	// Si tiene hijo izquierdo
	else if (nodoEliminar->izq) {
		reemplazar(nodoEliminar, nodoEliminar->izq);
		destruir(nodoEliminar);
	}
	// Si tiene un hijo derecho
	else if (nodoEliminar->der) {
		reemplazar(nodoEliminar, nodoEliminar->der);
		destruir(nodoEliminar);
	}
	// Si no tiene hijos
	else {
		reemplazar(nodoEliminar, NULL);
		destruir(nodoEliminar);
	}
}
