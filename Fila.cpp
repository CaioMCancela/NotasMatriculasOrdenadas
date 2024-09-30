//Bibliotecas necessárias
#include <cstdio>
#include <cstdlib>
#include "Fila.h"

TipoCelula *Frente, *Tras;

int Contador;


void Fila_Construtor() {
    Frente = Tras = NULL;
    Contador = 0;
}


void Fila_Destrutor(){
   TipoCelula *Temp;

   while(Frente != NULL)  {
     Temp = Frente;
     Frente = Frente -> Prox;

     Temp->Prox = NULL;
     free(Temp);
   }

   Tras = NULL;
   Contador = 0;
}


bool Fila_Vazia(){
   return Frente == NULL;
}


int Fila_Tamanho(){
    return Contador;
}




bool Fila_Enfileirar(TipoDado2 matricula, TipoDado nota){

   TipoCelula *Nova;
   Nova = (TipoCelula *) malloc(sizeof(TipoCelula));

   if(Nova==NULL){
       return false;
   }else{
          Nova->Nota = nota;
          Nova->Matricula = matricula;
          Nova->Prox = NULL;

          if(Fila_Vazia())
            Frente = Nova;
          else Tras->Prox = Nova;

          Tras = Nova;
          Contador++;

          return true;
   }
}



bool Fila_Desenfileirar(TipoDado2 &matricula, TipoDado &nota){

     if(!Fila_Vazia()){

        TipoCelula *Temp = Frente;

        matricula = Frente->Matricula;
        nota = Frente->Nota;

        Frente = Frente->Prox;

        Temp->Prox = NULL;

        free(Temp);

        if(Frente == NULL)
          Tras = NULL;

        Contador--;

        return true;
     }else {
         return false;
     }

}


bool Fila_Frente(TipoDado2 &matricula, TipoDado &nota) {
    if(!Fila_Vazia())  {
        matricula = Frente->Matricula;
        nota = Frente->Nota;
        return true;
    }
    else {
        return false;
    }
}
