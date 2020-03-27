#include <stdio.h>
#include <stdlib.h>
#include "funcoes.h"

int** Cria_Matriz(int linhas,int colunas){ //Retorna um matriz criada dinamicamente e com "lixo" da mem�ria
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

int** Desaloca_Matriz(int **matriz,int linhas){ //Libera a matriz criada dinamicamente
    for(int i=0;i<linhas;i++)
        free(matriz[i]);
    free(matriz);
    return matriz; //retorna o ponteiro NULL da matriz
}


void Flood_Fill(int **matriz,int linhas,int colunas,int x,int y,int cor_origem,int cor_nova,Lista *li){ //Algoritmo de  preenchimento de inundac�ao
    Tipo_Dado Dado;
    if(x < 0 || x >= linhas || y < 0 || y >= colunas) return; //Verificando se a posi��o do n� durante a recurs�o � valida,ou seja, se existe na matriz,caso n�o exista retorna para a recurs�o anterior
    if(matriz[x][y] != cor_origem) return; //Caso a cor de um n� adjacente n�o for igual a cor de origem retorna para a recurs�o anterior
    matriz[x][y] = cor_nova; //Se o n� adjacente for igual a cor de origem a cor sera trocada para um nova,como propoe o m�todo flood_fill
    Dado.x=x;
    Dado.y=y;
    insere_lista_ordenada(li,Dado); //Inserindo as coordernadas na lista dinamica
    //Verificando todos os 8 poss�veis posi��es dos n�s ao redor(quadrado em volta do n� a ser analisado)
    Flood_Fill(matriz,linhas,colunas,x+1,y,cor_origem,cor_nova,li);
    Flood_Fill(matriz,linhas,colunas,x+1,y+1,cor_origem,cor_nova,li);
    Flood_Fill(matriz,linhas,colunas,x+1,y-1,cor_origem,cor_nova,li);
    Flood_Fill(matriz,linhas,colunas,x,y+1,cor_origem,cor_nova,li);
    Flood_Fill(matriz,linhas,colunas,x,y-1,cor_origem,cor_nova,li);
    Flood_Fill(matriz,linhas,colunas,x-1,y,cor_origem,cor_nova,li);
    Flood_Fill(matriz,linhas,colunas,x-1,y+1,cor_origem,cor_nova,li);
    Flood_Fill(matriz,linhas,colunas,x-1,y-1,cor_origem,cor_nova,li);
}


