#include <stdio.h>

int main (void){
  int ;
  float ;
  FILE *arquivoUM;
  arquivoUM = fopen("arquivoBin.dat", "rb");
  if (arquivoUM == NULL){

    printf("Problema na abertura do arquivo.\n");
    return ;

  }
  return 0;

}
