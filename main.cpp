// Nome: Caio Moreira Cancela
// Objetivo : mostrar a notas dos alunos em forma decrescente.
// Entrada de dados: deve ser feita primeiro a entrada de dados da matricula(inteiro) e
// depois a entrada da nota(ponto flutuante de dupla precissão ou double).
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

//função ultilizada para iniciar tanto a pilha quanto a fila
void construtores(){
    Fila_Construtor();
    Pilha_Construtor();
}


// função para imprimir a pilha contendo a matricula e a nota, usando um laço for e a função Pilha_Desempilhar()
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

// Função responsável por solicitar ao usuário a entrada da matrícula e da nota de um aluno,que será então
// enfileirada.A função assegura que os dados inseridos sejam capturados corretamente e informa ao usuário
// sobre o sucesso da operação de enfileiramento.
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


// A função ordenarEImprimir executa as seguintes etapas:
// 1. Declara variáveis para armazenar a matrícula e a nota do aluno atual, bem como a matrícula e a nota do topo da pilha.
// 2. Inicia um loop que continua enquanto a fila não estiver vazia, permitindo o processamento de todos os alunos.
// 3. Tenta desenfileirar (remover) um aluno da fila e armazenar sua matrícula e nota; se essa operação falhar, a função retorna false.
// 4. Dentro de um loop, verifica se a pilha não está vazia e se a nota do aluno atual é menor que a nota do topo da pilha;
//    em caso de notas iguais, verifica também a matrícula do aluno atual em relação à do topo para desempate.
//    4.1. Se a condição for verdadeira, desempilha (remove) o elemento do topo da pilha e enfileira (adiciona de volta) esse elemento na fila,
//         garantindo que os elementos com notas maiores permaneçam na pilha.
//    4.2. Se a condição for falsa (ou seja, a pilha estiver vazia, a nota do aluno atual for maior que a nota do topo,
//         ou em caso de empate onde a matrícula do aluno atual é maior que a do topo), a matrícula e a nota do aluno atual são empilhadas na pilha.
// 5. Após processar todos os alunos da fila, chama a função imprimirPilha para exibir os alunos em ordem decrescente de notas.
// 6. Destrói a fila para liberar memória utilizada durante o processamento.
// 7. Retorna true para indicar que a operação foi bem-sucedida.
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
    Fila_Destrutor(); // Destrói a fila após a impressão
    return true;
}


// Função principal do programa, onde a execução se inicia.
// Inicializa a pilha e a fila, solicita ao usuário a entrada de matrícula e nota de alunos,
// e permite a repetição desse processo até que o usuário decida parar.
// Após a coleta de dados, a função processa e exibe os alunos em ordem decrescente de notas,
// finalizando a execução do programa com um retorno de sucesso.
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