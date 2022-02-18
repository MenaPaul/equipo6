#include <iostream>

using namespace std;

int main()
{
    int dim=0, i=0, j=0, k=0, p=0, m=0;
    cout << "\t\t ||- CUADRADO LATINO -||"<<endl;

    while(dim<2){
        cout << "Ingrese la dimension: ";
        cin >> dim;
    }
    k=dim;
    for(i=1; i<=dim; i++){
        if(i==1){
            for(j=1;j<=dim;j++){
                cout << j << " ";
            }
        }else{
            for(j=k+1;j<=dim;j++){
                cout << j << " ";
            }
            for(m=1; m<=dim-p; m++){
                cout << m << " ";
            }
        }
        k=k-1;
        p=p+1;
        cout << " " << endl;
    }

    return 0;
}
