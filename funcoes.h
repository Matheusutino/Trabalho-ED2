#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

int** Cria_Matriz(int linhas,int colunas);
void Imprime_Matriz(int **matriz,int linhas,int colunas);
void Desaloca_Matriz(int **matriz,int linhas);
void Flood_Fill(int **matriz,int linhas,int colunas,int x,int y,int cor_origem,int cor_nova);




#endif // FUNCOES_H_INCLUDED
