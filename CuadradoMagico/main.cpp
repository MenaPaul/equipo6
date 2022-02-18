#include <iostream>
#define CM(x, N) ( (x)<0 ? N+(x)%N : ( (x)>=N ? (x)%N : (x) ) )

using namespace std;

int main()
{
    int cuadrado[15][15], x, y, n, N;

    do{
        cout<<"Ingrese el orden (impar entre 3 y 15): \n";
        cin>>N;
    }while(!(N%2));

    cout<<"\nCuadrado Magico de orden "<<N<<"x"<<N<<" :\n\n";

    for(x=0;x<N;x++)
        for(y=0;y<N;y++)
        cuadrado[x][y]=0;

    for(x=N/2, y=0, n=1; n<=N*N; )
        if(!cuadrado[x][y])
        cuadrado[x][y]=n++,
        x=CM(x+1,N),
        y=CM(y-1,N);
        else x=CM(x-1,N),
            y=CM(y+2,N);

    for(y=0;y<N;y++){
        cout<<"\n\n||\t";
        for(x=0;x<N;x++)
            cout<<cuadrado[x][y]<<"\t";
        cout<<"||";
    }

    cout<<"\n\n Suma = "<<((N*(N*N+1))/2)<<"\n\n";

    return 0;
}
