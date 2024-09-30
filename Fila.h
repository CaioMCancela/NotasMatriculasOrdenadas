#ifndef FILA_H_INCLUDED
#define FILA_H_INCLUDED

//Define o tipo de dado que será armazenado na Pilha
typedef float TipoDado;
//Define um outro tipo de dado que será armazenado na Pilha
typedef int TipoDado2;

//Essa estrutura será utilizada como uma célula da Pilha item que armazena o valor informado pelo usuário
struct TipoCelula{

   TipoDado Nota;
   TipoDado2 Matricula;
   TipoCelula *Prox;
};

// Um construtor é um método que deve ser executado  obrigatoriamente antes da fila ser utilizada.
void Fila_Construtor();

// Método para recuperar a memória dinâmica alocada para a fila.Ao contrário de um construtor,
// o destrutor é um método que deve ser executado depois da fila ser utilizada
void Fila_Destrutor();

// Função para indicar se a fila está ou não vazia (se exite ou não algum elemento armazenado)
bool Fila_Vazia();

// Função para retornar a quantidade de elementos armazenados na fila
int Fila_Tamanho();

// Método para adicionar elementos na Fila (Enfileirar).Se o elemento for Enfileirado (armazenado na Fila),
// o método retorna verdadeiro,caso contrário, retorna falso
bool Fila_Enfileirar(TipoDado2 matricula,TipoDado nota);

// Método para adicionar elementos na Fila (Enfileirar).Se o elemento for Enfileirado (armazenado na Fila),
// o método retorna verdadeirocaso contrário, retorna falso
bool Fila_Desenfileirar(TipoDado2 &matricula,TipoDado &nota);

// Método para retornar o elemento na frente da Fila sem reemovê-lo.O elemento é retornado por referência
// pelo parâmetro da função
bool Fila_Frente(TipoDado2 &matricula,TipoDado &nota);







#endif // FILA_H_INCLUDED
