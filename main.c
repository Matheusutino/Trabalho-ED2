#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int main(){
    int **matriz,*linhas,colunas,coord_x,coord_y;
    FILE *Arquivo;
    Lista *li=cria_lista();
    char nome_arquivo[30];

    //Realizando a leitura dos dados de entrado do arquivo
    printf("Digite o nome do arquivo a ser aberto : ");
    scanf("%s",nome_arquivo);
    Arquivo = fopen(nome_arquivo,"r");
    fscanf(Arquivo,"%d %d",&linhas,&colunas);
    matriz=Cria_Matriz(linhas,colunas);
    for(int i=0;i<linhas;i++){
        for(int j=0;j<colunas;j++){
            fscanf(Arquivo,"%d",&matriz[i][j]);
        }
    }
    fscanf(Arquivo,"%d %d",&coord_x,&coord_y);
    fclose(Arquivo);

    Flood_Fill(matriz,linhas,colunas,coord_x,coord_y,matriz[coord_x][coord_y],2,li); //A nova cor sera o valor inteiro 2

    printf("Total : %d\n",tamanho_lista(li));
    imprime_lista(li);
    Imprime_Matriz(matriz,linhas,colunas);

    Desaloca_Matriz(matriz,linhas);
    libera_lista(li);

}
