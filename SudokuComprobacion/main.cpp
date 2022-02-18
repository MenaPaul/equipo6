#include <iostream>

using namespace std;

int main()
{
    int sudoku[9][9];
    int i, j, valor;

    cout << "\t\t ||--|| SUDOKU ||--||" << endl;
    //CREAR LA MATRIZ Y LLENARLA
    /*for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            cout << "Ingrese el numero: ";
            cin >> valor;
            while(valor<1 || valor >9){
                cout << "Valores del 1 al 9, ingrese nuevamente: ";
                cin >> valor;
            }
            sudoku[i][j]=valor;
        }
    }
    cout << "Impresion..." << endl;
    for(i=0;i<9;i++){
        for(j=0;j<9;j++){
            cout << sudoku[i][j] << " ";

        }
        cout << endl;
    }*/

    //MATRIZ DEFAULT
    int sudoku2[9][9]={
    {4,2,6,5,7,1,3,9,8},
    {8,5,7,2,9,3,1,4,6},
    {1,3,9,4,6,8,2,7,5},
    {9,7,1,3,8,5,6,2,4},
    {5,7,3,7,2,6,8,1,9},
    {6,8,2,1,4,9,7,5,3},
    {7,9,4,6,3,2,5,8,1},
    {2,6,5,8,1,4,9,3,7},
    {3,1,8,9,5,7,4,6,2},
    };

    //IMPRESION
    cout << "Impresion..." << endl;
    for(i=0;i<9;i++){
        cout << "==================================="<<endl;
        for(j=0;j<9;j++){
            cout << "|" << sudoku2[i][j] << "| ";
        }
        cout << endl;
    }
    cout << "==================================="<<endl;

    //VALIDACION FILAS
    int correcto=1;
    for(i=0;i<9;i++){
        int aux[10]={1,1,1,1,1,1,1,1,1,1};
        //int correcto=1;
        for(j=0;j<9;j++){
            aux[sudoku2[i][j]]=0;
        }
        for(int k=1;k<10;k++){
            if(aux[k]==1){
                cout<<"Error en la fila ["<<i+1<<"] y pos ["<<k<<"]"<<endl;
                correcto=0;
            }
        }
    }
    if(correcto==1){
        cout << "Filas correctas." <<endl;
    }

    //VALIDACION COLUMNAS
    //int correcto=1;
    for(i=0;i<9;i++){
        int aux[10]={1,1,1,1,1,1,1,1,1,1};
        for(j=0;j<9;j++){
            aux[sudoku2[j][i]]=0;
        }
        for(int k=1;k<10;k++){
            if(aux[k]==1){
                cout<<"Error en la fila ["<<k<<"] y pos ["<<i+1<<"]"<<endl;
                correcto=0;
            }
        }
    }
    if(correcto==1){
        cout << "Columnas correctas." <<endl;
    }




    return 0;
}
