#include <iostream>
using namespace std;

char llenar_pos(int fila, int indice) {
    if (fila == 1) {
        return  char(65);//en el pico del triángulo es A
    }
    else {
        if (indice == 0 || indice == fila - 1)//en los costados del triángulo siempre es A
            return char(65);
        else
            return 1 + llenar_pos(fila - 1, indice);
    }
}

void espacios_en_blanco(int n) {
    if (n > 0) {
        cout << " ";
        espacios_en_blanco(n - 1);
    }
    else cout << "";
}
void mostrar_pascal(int pos, int fila, int n, int esp, bool band) {

    if (fila <= n) {
        if (band == true) {
            espacios_en_blanco(esp);
            band = false;
        }
        cout << llenar_pos(fila, pos) << " ";
        if (pos < fila - 1)
            mostrar_pascal(pos + 1, fila, n, esp, band);
        else {
            cout << endl;
            band = true;
            mostrar_pascal(0, fila + 1, n, esp - 1, band);
        }
    }
    else {
        cout << endl;
        band = true;
    }
}
void triangulo_pascal(int filas) {
    mostrar_pascal(0, 1, filas, filas, true);
}
int main(int argc, char** argv) {
    /*int filas;
    cout << "\t\t ||-  TRIANGULO DE PASCAL  -||" << endl;
    cout << "ingrese filas:";
    cin >> filas;
    triangulo_pascal(filas);*/
    cout << char(65);
    return 0;
}

//DEBER
/*
Saber como funciona el sudoku
Investigar el problema del algoritmo de programacion de tareas
VIERNES - Grupos del 1 al 7 - Que es para que se usa como lo uso, tecnicas de analisis algoritmica
G1 eficiencia de algor
teoria, proceso matematico y programa

*/
