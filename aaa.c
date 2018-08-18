#include <stdio.h>

void preencher();
struct tel{
  int ddd, cel, trab, casa;
};
struct regagenda{
  char nome[100], endereco[300];
  struct tel fone;
};
struct regagenda agenda;

void preencher(){
  printf("Entre com o nome: ");
  gets(agenda.nome);
  printf("\nEntre com o endereço: ");
  gets(agenda.endereco);
  printf("\nEntre com o ddd: ");
  scanf("%d",&agenda.fone.ddd);
  printf("\nEntre com o telefone da casa: ");
  scanf("%d",&agenda.fone.casa);
  printf("\nEntre com o telefone celular: ");
  scanf("%d",&agenda.fone.cel);
  printf("\nEntre com o telefone do trabalho: ");
  scanf("%d",&agenda.fone.trab);
  printf("\nNome: %s\nEndereço: %s\nDDD: %d\nCasa: %d\nCelular: %d\nTrabalho: %d\n",agenda.nome,agenda.endereco,agenda.fone.ddd,agenda.fone.casa,agenda.fone.cel,agenda.fone.trab);

}

int main (void){
  int ;
  float ;
  FILE *arquivoUM;
  arquivoUM = fopen("arquivoBin.dat", "wb");


  if (arquivoUM == NULL){

    printf("Problema na abertura do arquivo.\n");
    return ;

  }
  preencher();
  fwrite(agenda.fone.casa,4 ,sizeof(agenda.fone.casa), arquivoUM);
  return 0;
  system("pause");

}
