#include <iostream>
#include <Graphics.h>

using namespace std;

void switchMenu(char r)
{
    cleardevice();
    switch(r)
    {
        case 'D' :case 'd': setfillstyle(1,YELLOW);
        setcolor(BLACK);
        pieslice(650,350,15,345,30);
        outtextxy(300,300,"INGRESE LA PALABRA EN INGLES");
        outtextxy(300,350,"INGRESE LA PALABRA EN ESPAÑOL");
        break;

        case 'S' :case 's':
        setcolor(BLACK);
        pieslice(650,350,15,345,30);
        outtextxy(300,300,"LABERINTO");
        break;

        case 'A' :case 'a':
        setcolor(BLACK);
        pieslice(650,350,15,345,30);
        outtextxy(300,300,"REINAS");
        break;

        case 'X' :case 'x':

        break;
    }
    outtextxy(300,600,"Presione una tecla para continuar...");
    getch();
}

int main()
{
    char r;
    int xm,ym;
    //Tamaño de la pantalla
    initwindow(800, 600, "PROYECTO FINAL --MENA PAUL - CHABLAY ESTEBAN--");
    //color de fondo
    setbkcolor(RGB(130,190,150));
    //para limpiar pantalla y que aparezca el color
    cleardevice();

    do{
        setbkcolor(RGB(130,190,150));
        cleardevice();
        setfillstyle(1,WHITE);
        setbkcolor(WHITE);
        setcolor(RED);
        bar(110,20,550,50);
        outtextxy(120,30,"      UNIVERSIDAD DE LAS FUERZAS ARMADAS - ESPE      ");
        bar(110,60,550,90);
        outtextxy(120,70,"    PROYECTO FINAL --MENA PAUL - CHABLAY ESTEBAN--   ");
        //genera una barra
        bar(200,100,470,150);
        //genera un rectangulo alrededor
        rectangle(200,100,470,150);
        outtextxy(210,120,"1. TRADUCTOR -> ");
        // 2da opcion del menu
        bar(200,160,470,210);
        //genera un rectangulo alrededor
        rectangle(200,160,470,210);
        outtextxy(210,180,"2. LABERINTO -> ");
        // 3ra opcion del menu
        bar(200,220,470,270);
        //genera un rectangulo alrededor
        rectangle(200,220,470,270);
        outtextxy(210,240,"3. REINAS -> ");
        // 4ra opcion del menu
        bar(200,280,470,330);
        //genera un rectangulo alrededor
        rectangle(200,280,470,330);
        outtextxy(210,300,"4. SALIR DEL PROGRAMA-> ");

        delay(200);
        //control con mouse
        if(ismouseclick(WM_LBUTTONDOWN))
        {
            //posicion de donde lo presione
            getmouseclick(WM_LBUTTONDOWN,xm,ym);
            if((xm>200&&xm<470)&&(ym>100&&ym<150))
                switchMenu('d');
            if((xm>200&&xm<470)&&(ym>160&&ym<210))
                switchMenu('s');
            if((xm>200&&xm<470)&&(ym>220&&ym<270))
                switchMenu('a');
            if((xm>200&&xm<470)&&(ym>280&&ym<330))
                exit(0);
        }
        //si presionas una tecla se activa
        if(kbhit())
        {
            r=getch();
            //funcion switch menu para el contenido del menu
            switchMenu(r);
        }


    }while(r!='x');

    closegraph;
    return (0);
}
