#ifndef PILHA_H_INCLUDED
#define PILHA_H_INCLUDED

// Define o tipo de dado que será armazenado na Pilha
typedef float TipoDado;
// Define um outro tipo de dado que será armazenado na Pilha
typedef int TipoDado2;

// Essa estrutura será utilizada como uma célula da Pilha item que armazena o valor informado pelo usuário
struct TipoCelula2{
   TipoDado Nota;
   TipoDado2 Matricula;
   TipoCelula2 *Prox;
};


// Um construtor é um método que deve ser executado  obrigatoriamente antes da pilha ser utilizada.
void Pilha_Construtor();

// Método para recuperar a memória dinâmica alocada para a pilha.Ao contrário de um construtor,
// o destrutor é um método que deve ser executado depois da pilha ser utilizada
void Pilha_Destrutor();

// Função para indicar se a Pilha está ou não vazia (se exite ou não algum elemento armazenado)
bool Pilha_Vazia();

// Função para retornar a quantidade de elementos armazenados na Pilha
int Pilha_Tamanho();

// Método para adicionar elementos do topo da Pilha.Se o elemento for Empilhado (armazenado na Pilha),
// o método retorna verdadeiro,caso contrário, retorna falso
bool Pilha_Empilhar(TipoDado2 matricula, TipoDado nota);

// Método para remover elementos da Pilha, retornando ele por referência pelo parâmetro da função . Se o elemento for
// Desempilhado (removido da Pilha),o método retorna verdadeiro,caso contrário, retorna falso
bool Pilha_Desempilhar(TipoDado2 &matricula, TipoDado &nota);

// Método para retornar o elemento no topo da Pilha sem removê-lo.O elemento é retornado por referência
// pelo parâmetro da função
bool Pilha_Topo(TipoDado2 &matricula, TipoDado &nota);

#endif // PILHA_H_INCLUDED

