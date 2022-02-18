#include <iostream>

using namespace std;

int factorial(int n){
    int resultado=1;
    for(int i=1;i<=n;i++){
        resultado*=i;
    }
    return resultado;
}

int combinacion(int n, int k){
    return(factorial(n))/(factorial(k)*factorial(n-k));
}

char combinacionC(int n, int k){

    return char((factorial(n))/(factorial(k)*factorial(n-k)));
}

int main()
{
    int n;
    int numero;
    char c = 'A';
    cout << "\t\t ||-  TRIANGULO DE PASCAL  -||" << endl;
    cout << "Ingrese el numero de Filas: ";
    cin >> n;
    for(int i=0; i<n; i++){
        cout << "Fila " << i+1 << ": ";
        for(int j=n-i; j>=0; j--){
            cout << " ";
        }
        for(int j=0; j<=i; j++){
            cout << combinacion(i,j) << " ";
        }
        cout << endl;
    }

    cout << "\nPascal al reves" << endl;
    for(int i=n-1; i>=0; i--){
        cout << "Fila " << i+1 << ": ";
        for(int j=n-i; j>=0; j--){
            cout << " ";
        }
        for(int j=i; j>=0; j--){
            cout << combinacion(i,j) << " ";
        }
        cout << endl;
    }

    cout << "\n\t\t ||-  TRIANGULO DE PASCAL (LETRAS)  -||" << endl;
    for(int i=0; i<n; i++){
        cout << "Fila " << i+1 << ": ";
        for(int j=n-i; j>=0; j--){
            cout << " ";
        }
        for(int j=0; j<=i; j++){
            cout << char(combinacion(i,j)+64) << " ";
        }
        cout << endl;
    }


    return 0;
}
