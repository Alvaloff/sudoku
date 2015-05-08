#include <stdio.h>
#include <stdlib.h>

void ingreso (int tablero [9][9]){

    int i, ii;
    for(i=0;i<9;i++){
        for(ii=0;ii<9;ii++){
            scanf("%i",&tablero[i][ii]);
        }

        printf("\n");

    }

}
void llenarposibilidades(int posibilidades [9]){

    int i=1;
    for(i=1;i<9;i++){
        posibilidades[i]=i;
        //printf("%i",posibilidades[i]);
    }

}

void eliminar_posibilidad(int posibilidades[9],int p,int cantidad_de_posibilidades){
    int i=p+1;

    for(i;i<cantidad_de_posibilidades;i++){
        posibilidades[i-1]=posibilidades[i];
    }

    cantidad_de_posibilidades= cantidad_de_posibilidades - 1;

}

int busca_el_unico_numero (int tablero[9][9],int x,int y){

    int posibilidades[9],cantidad_de_posibilidades = 9;

    llenarposibilidades(posibilidades);



//||||||||||||||||||||ELIMINA LAS POSIBILIDADES EN LAS LINEAS LARGAS||||||||||||||

    int i=0,p=0;
    for(i=0;i<9;i++){
            if(cantidad_de_posibilidades==0){
                return posibilidades[0];
            }
            else{
                for(p=0;p<cantidad_de_posibilidades;p++){
                    if (tablero[x][i]==posibilidades[p]){

                        eliminar_posibilidad(posibilidades,p,cantidad_de_posibilidades);
                    }
                }
            }
    }

//||||||||||||||||||||ELIMINA LAS POSIBILIDADES EN LAS COLUMNAS LARGAS||||||||||||||

    for(i=0;i<9;i++){
        if(cantidad_de_posibilidades==0){
            return posibilidades[0];
        }
        else{
            for(p=0;p<cantidad_de_posibilidades;p++){
                if (tablero[i][y]==posibilidades[p]){

                    eliminar_posibilidad(posibilidades,p,cantidad_de_posibilidades);
                }
            }
        }
    }























    return 0;

}
int main()
{
    int tableroreal[9][9];
    ingreso(tableroreal);
    busca_el_unico_numero(tableroreal,1,1);
    return 0;
}
