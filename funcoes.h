#ifndef FUNCOES_H_INCLUDED
#define FUNCOES_H_INCLUDED

//Definindo variáveis booleanas
#define FALSO      0
#define VERDADEIRO 1

#define OK         1
#define ERRO       0

//Definindo a struct coord como um novo tipo de dado
typedef struct coord  Tipo_Dado;

//Criando uma struct que representa um ponto(Coordenadas x e y)
struct coord{
    int x;
    int y;
};

//DefiniÃ§Ã£o do tipo lista
struct elemento{ //Criando uma struct que contem o conteudo da struct coord e o elemento anterior e posterior a ele
    struct elemento *ant;
    Tipo_Dado dado;
    struct elemento *prox;
};

typedef struct elemento Elem;

typedef struct elemento* Lista;

//Protótipos das funções referentes a LDED
Lista* cria_lista();
void libera_lista(Lista* li);
int insere_lista_ordenada(Lista* li, Tipo_Dado dt);
int tamanho_lista(Lista* li);
void imprime_lista(Lista* li);

//Protótipos das funções referente a matriz e ao flood fill
int** Cria_Matriz(int linhas,int colunas);
void Imprime_Matriz(int **matriz,int linhas,int colunas);
int** Desaloca_Matriz(int **matriz,int linhas);
void Flood_Fill(int **matriz,int linhas,int colunas,int x,int y,int cor_origem,int cor_nova,Lista *li);




#endif // FUNCOES_H_INCLUDED
