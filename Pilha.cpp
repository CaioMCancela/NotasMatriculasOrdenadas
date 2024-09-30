//Bibliotecas necess�rias
#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

TipoCelula2 *Topo;

int Contador1;

void Pilha_Construtor(){
  Topo = NULL;
  Contador1 = 0;
}


void Pilha_Destrutor(){

   TipoCelula2 *Temp;

   while(Topo != NULL)
   {
     Temp = Topo;
     Topo = Topo -> Prox;
     Temp->Prox = NULL;
     free(Temp);
   }

   Contador1 = 0;
}

bool Pilha_Vazia(){
   return Topo == NULL;
}

int Pilha_Tamanho(){
    return Contador1;
}

bool Pilha_Empilhar(TipoDado2 matricula,TipoDado nota){

   TipoCelula2 *Nova;
   Nova = (TipoCelula2 *) malloc(sizeof(TipoCelula2));

   if(Nova==NULL){
       return false;
   }else{
       Nova->Nota = nota;
       Nova->Matricula = matricula;
       Nova->Prox = Topo;

       Topo = Nova;

       Contador1++;
       return true;
   }
}



bool Pilha_Desempilhar(TipoDado2 &matricula,TipoDado &nota){

   if(!Pilha_Vazia()) {
      TipoCelula2 *Temp = Topo;

      Topo = Topo->Prox;

      matricula = Temp->Matricula;
      nota = Temp->Nota;

      Temp->Prox = NULL;

      free(Temp);

      Contador1--;
      return true;
   }else {
      return false;
   }
}



bool Pilha_Topo(TipoDado2 &matricula,TipoDado &nota){
      if(!Pilha_Vazia()) {
         matricula = Topo->Matricula;
         nota = Topo->Nota;

         return true;
      }else{
         return false;
      }
}
