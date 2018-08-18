#include <stdio.h>
struct tel{
  int ddd, cel, trab, casa;
};
struct regagenda{
  char nome[100], endereco[300];
  struct tel fone;
};
struct regagenda agenda;

int main (void){
  int ;
  float ;
  FILE *arquivoUM;
  arquivoUM = fopen("arquivoBin.dat", "wb");


  if (arquivoUM == NULL){

    printf("Problema na abertura do arquivo.\n");
    return ;

  }
  return 0;

}
