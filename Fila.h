#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

//Define o tipo de dado que ser� armazenado na Pilha
typedef float TipoDado;
//Define um outro tipo de dado que ser� armazenado na Pilha
typedef int TipoDado2;

//Essa estrutura ser� utilizada como uma c�lula da Pilha item que armazena o valor informado pelo usu�rio
struct TipoCelula{

   TipoDado Nota;
   TipoDado2 Matricula;
   TipoCelula *Prox;
};

// Um construtor � um m�todo que deve ser executado  obrigatoriamente antes da fila ser utilizada.
void Fila_Construtor();

// M�todo para recuperar a mem�ria din�mica alocada para a fila.Ao contr�rio de um construtor,
// o destrutor � um m�todo que deve ser executado depois da fila ser utilizada
void Fila_Destrutor();

// Fun��o para indicar se a fila est� ou n�o vazia (se exite ou n�o algum elemento armazenado)
bool Fila_Vazia();

// Fun��o para retornar a quantidade de elementos armazenados na fila
int Fila_Tamanho();

// M�todo para adicionar elementos na Fila (Enfileirar).Se o elemento for Enfileirado (armazenado na Fila),
// o m�todo retorna verdadeiro,caso contr�rio, retorna falso
bool Fila_Enfileirar(TipoDado2 matricula,TipoDado nota);

// M�todo para adicionar elementos na Fila (Enfileirar).Se o elemento for Enfileirado (armazenado na Fila),
// o m�todo retorna verdadeirocaso contr�rio, retorna falso
bool Fila_Desenfileirar(TipoDado2 &matricula,TipoDado &nota);

// M�todo para retornar o elemento na frente da Fila sem reemov�-lo.O elemento � retornado por refer�ncia
// pelo par�metro da fun��o
bool Fila_Frente(TipoDado2 &matricula,TipoDado &nota);







#endif // FILA_H_INCLUDED
