#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int** Cria_Matriz(int linhas,int colunas){ //Retorna um matriz criada dinamicamente e com "lixo" da memória
    int **matriz=(int**)malloc(linhas * sizeof(int*));
    for(int i=0;i<colunas;i++){
        matriz[i]=(int*)malloc(colunas * sizeof(int));
    }
    return matriz;
}

void Imprime_Matriz(int **matriz,int linhas,int colunas){ //Imprime a matriz
    for(int i=0;i<linhas;i++){
        for(int j=0;j<colunas;j++){
            printf("%d ",matriz[i][j]);
        }
        printf("\n");
    }
}

void Desaloca_Matriz(int **matriz,int linhas){ //Libera a matriz criada dinamicamente
    for(int i=0;i<linhas;i++)
        free(matriz[i]);
    free(matriz);
}


void Flood_Fill(int **matriz,int linhas,int colunas,int x,int y,int cor_origem,int cor_nova){ //Algoritmo de  preenchimento de inundac˜ao
    if(x < 0 || x >= linhas || y < 0 || y >= colunas) return; //Verificando se a posição do nó durante a recursão é valida,ou seja, se existe na matriz,caso não exista retorna para a recursão anterior
    if(matriz[x][y] != cor_origem) return; //Caso a cor de um nó adjacente não for igual a cor de origem retorna para a recursão anterior
    matriz[x][y] = cor_nova; //Se o nó adjacente for igual a cor de origem a cor sera trocada para um nova,como propoe o método flood_fill
    printf("%d %d\n",x,y);
    //Verificando todos os 8 possíveis posições dos nós ao redor(quadrado em volta do nó a ser analisado)
    Flood_Fill(matriz,linhas,colunas,x+1,y,cor_origem,cor_nova);
    Flood_Fill(matriz,linhas,colunas,x+1,y+1,cor_origem,cor_nova);
    Flood_Fill(matriz,linhas,colunas,x+1,y-1,cor_origem,cor_nova);
    Flood_Fill(matriz,linhas,colunas,x,y+1,cor_origem,cor_nova);
    Flood_Fill(matriz,linhas,colunas,x,y-1,cor_origem,cor_nova);
    Flood_Fill(matriz,linhas,colunas,x-1,y,cor_origem,cor_nova);
    Flood_Fill(matriz,linhas,colunas,x-1,y+1,cor_origem,cor_nova);
    Flood_Fill(matriz,linhas,colunas,x-1,y-1,cor_origem,cor_nova);
}


