#include <stdio.h>
#include <stdlib.h>
#include <math.h>

int z,x,y,a,b,c;

int decisao,fatia;

void setar_parametros_matriz(){

printf("Digite por gentileza o numero de dimensoes (Z):\n");
scanf("%d",&z);
printf("\n\nDigite por gentileza o numero de dimensoes (X):\n");
scanf("%d",&x);
printf("\n\nDigite por gentileza o numero de dimensoes (Y):\n");
scanf("%d",&y);
printf("\n\n\n");

printf("Digite por gentileza o raio da dimensao z (a):\n");
scanf("%d",&a);
printf("\n\nDigite por gentileza o raio da dimensao x (b):\n");
scanf("%d",&b);
printf("\n\nDigite por gentileza o  raio da dimensao y  (c):\n");
scanf("%d",&c);


printf("\n\n Como voce deseja visualizar o resultado:\n\n");
printf("[0] Todas as fatias da matriz  [1] Apenas uma\n\n");
scanf("%d",&decisao);

if(decisao == 0){
    printf("\nVoce escolheu todas as fatias \n\n");
}else{

printf("\n\nQual a fatia (z), voce deseja visualizar:\n");

scanf("%d",&fatia);

printf("\n\nVoce escolheu a fatia: %d .\n\n",fatia);


}


}
void printMatrizfatia (char ***matriz){


 for (int i = 0; i < z; i++)

        if(i == fatia){

            {
        for (int j = 0; j < x; j++)
        {
            for (int k = 0; k < y; k++) {

                if(i == fatia)
                {
                    printf("%d ", matriz[i][j][k]);
                }else{

                }

            }
            printf("\n");
        }
        printf("\n");
    }

}else{

continue;
}






}
void printaMatrizInteira(char *** matriz){

     for (int i = 0; i < z; i++)
    {
        for (int j = 0; j < x; j++)
        {
            for (int k = 0; k < y; k++) {
                printf("%d ", matriz[i][j][k]);
            }
            printf("\n");
        }
        printf("\n");
    }


}

char*** monta_matriz(){

  char*** matriz = (char***)malloc(z * sizeof(char**));

    for (int i = 0; i < z; i++)
    {
        matriz[i] = (char**)malloc(x * sizeof(char*));

        for (int j = 0; j < y; j++)
        {
            matriz[i][j] = (char*)malloc(y * sizeof(char));
        }
    }


return matriz;
}

void testarMatriz(char *** matriz)
{
     for (int i = 0; i < z; i++)
    {
        for (int j = 0; j < x; j++)
        {
            for (int k = 0; k < y; k++) {
                matriz[i][j][k] = rand() % 2;
            }
        }
    }

}


int func_elipse(int z_,int x_, int y_)
{


  float meio_x = (float) x/2.0;

  float meio_y = (float) y/2.0;

  float meio_z = (float) z/2.0;


  float elipse =  (float) ( (x_ - meio_x)  * (x_ - meio_x) /(b * b))  + (float) ( (y_ - meio_y) * (y_ - meio_y) /(c * c)) + (float) ( (z_-meio_z) * (z_ - meio_z) /(a * a));


  if (elipse <= 1){
    return 1;
  }else{
  return 0;
  }




}



void desaloca_memoria(char *** matriz){
    for (int i = 0; i < x; i++)
        {
            for (int j = 0; j < y; j++) {
                free(matriz[i][j]);
            }
            free(matriz[i]);
        }
    free(matriz);




}

int main(void){



char*** matriz;

setar_parametros_matriz();

matriz = monta_matriz();



  for (int i = 0; i < z; i++)
    {
        for (int j = 0; j < x; j++)
        {
            for (int k = 0; k < y; k++) {

                if(func_elipse(i,j,k))
                {
                    matriz[i][j][k] = 1;
                }else{
                     matriz[i][j][k] = 0;
                }
            }

        }

    }






//

if(decisao == 0){
 printaMatrizInteira(matriz);
}else if(decisao == 1){

printMatrizfatia(matriz);
}



desaloca_memoria(matriz);

return 0;

}





