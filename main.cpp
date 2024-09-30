// Nome: Caio Moreira Cancela
// Objetivo : mostrar a notas dos alunos em forma decrescente.
// Entrada de dados: deve ser feita primeiro a entrada de dados da matricula(inteiro) e
// depois a entrada da nota(ponto flutuante de dupla preciss�o ou double).
// Resultado: tera como resultado uma pilha em ordem decrescente onde o topo e a maior nota. Se tiver mesma nota o desempate
// e por matricula que tambem estara em ordem decrescente;

#include <iostream>
#include <iomanip>
#include "Pilha.h"
#include "Fila.h"

using namespace std;

// tipo de dado complexo para adicionar a matricula e a nota em uma unica variavel.
struct ALUNO{
    int matricula;
    float nota;
};

//fun��o ultilizada para iniciar tanto a pilha quanto a fila
void construtores(){
    Fila_Construtor();
    Pilha_Construtor();
}


// fun��o para imprimir a pilha contendo a matricula e a nota, usando um la�o for e a fun��o Pilha_Desempilhar()
// retornando o valor para ser impresso. obs: foi ultilizado a biblioteca iomanip para setar que o numero da matricula
// tera 8 casas obrigatoriamente( se nao tiver sera adicionado 0 a sua esquerda).
bool Imprimirpilha(ALUNO Aluno) {
    cout << endl << "PILHA EM ORDEM DECRESENTE" << endl;
    while(!Pilha_Vazia()){
        if(Pilha_Desempilhar(Aluno.matricula,Aluno.nota)) {
            cout << endl << "Matricula: " << setfill('0') << setw(8) << Aluno.matricula << " Nota: " << Aluno.nota;
        }else {
            return false;
        }
    }
    cout<< endl << endl;
    Pilha_Destrutor();
    return true;
}

// Fun��o respons�vel por solicitar ao usu�rio a entrada da matr�cula e da nota de um aluno,que ser� ent�o
// enfileirada.A fun��o assegura que os dados inseridos sejam capturados corretamente e informa ao usu�rio
// sobre o sucesso da opera��o de enfileiramento.
bool enfileiramento(ALUNO Aluno){

    cout << "Digite a matricula do aluno em que deseja inserir a nota: ";
    cin >> Aluno.matricula;
    if(Aluno.matricula < 0){
        cout << "Matricula invalida" << endl;
        return false;
    }
    cout << "Digite a nota do aluno: ";
    cin >> Aluno.nota;
    if(Aluno.nota < 0){
        cout << "Nota invalida" << endl;
        return false;
    }

    if(Fila_Enfileirar(Aluno.matricula,Aluno.nota)) {
        cout<<endl << "Elementos enfileirado com sucesso" << endl << endl;
        return true;
    }else {
        return false;
    }
}


// A fun��o ordenarEImprimir executa as seguintes etapas:
// 1. Declara vari�veis para armazenar a matr�cula e a nota do aluno atual, bem como a matr�cula e a nota do topo da pilha.
// 2. Inicia um loop que continua enquanto a fila n�o estiver vazia, permitindo o processamento de todos os alunos.
// 3. Tenta desenfileirar (remover) um aluno da fila e armazenar sua matr�cula e nota; se essa opera��o falhar, a fun��o retorna false.
// 4. Dentro de um loop, verifica se a pilha n�o est� vazia e se a nota do aluno atual � menor que a nota do topo da pilha;
//    em caso de notas iguais, verifica tamb�m a matr�cula do aluno atual em rela��o � do topo para desempate.
//    4.1. Se a condi��o for verdadeira, desempilha (remove) o elemento do topo da pilha e enfileira (adiciona de volta) esse elemento na fila,
//         garantindo que os elementos com notas maiores permane�am na pilha.
//    4.2. Se a condi��o for falsa (ou seja, a pilha estiver vazia, a nota do aluno atual for maior que a nota do topo,
//         ou em caso de empate onde a matr�cula do aluno atual � maior que a do topo), a matr�cula e a nota do aluno atual s�o empilhadas na pilha.
// 5. Ap�s processar todos os alunos da fila, chama a fun��o imprimirPilha para exibir os alunos em ordem decrescente de notas.
// 6. Destr�i a fila para liberar mem�ria utilizada durante o processamento.
// 7. Retorna true para indicar que a opera��o foi bem-sucedida.
    bool OrdenarEImprimir(ALUNO pessoa,ALUNO topo) {

    while (!Fila_Vazia()) {
        if (Fila_Desenfileirar(pessoa.matricula, pessoa.nota)) {

            while (Pilha_Topo(topo.matricula, topo.nota) &&(pessoa.nota < topo.nota || (pessoa.nota == topo.nota && pessoa.matricula < topo.matricula))) {
                Pilha_Desempilhar(topo.matricula, topo.nota);
                Fila_Enfileirar(topo.matricula, topo.nota);
            }
            Pilha_Empilhar(pessoa.matricula, pessoa.nota);
        }else{
            return false;
        }
    }
    Imprimirpilha(pessoa);
    Fila_Destrutor(); // Destr�i a fila ap�s a impress�o
    return true;
}


// Fun��o principal do programa, onde a execu��o se inicia.
// Inicializa a pilha e a fila, solicita ao usu�rio a entrada de matr�cula e nota de alunos,
// e permite a repeti��o desse processo at� que o usu�rio decida parar.
// Ap�s a coleta de dados, a fun��o processa e exibe os alunos em ordem decrescente de notas,
// finalizando a execu��o do programa com um retorno de sucesso.
int main() {
    char continuar;
    ALUNO Aluno,AlunoTopo;

    construtores();

    do {
        system("cls");
        cout << "NOTAS E MATRICULAS" << endl << endl;
        enfileiramento(Aluno);
        cout << "Deseja continuar? (S/N): ";
        fflush(stdin);
        cin >> continuar;
    }while(toupper(continuar) != 'N');

    OrdenarEImprimir(Aluno,AlunoTopo);
    system("pause");
    return 0;
}