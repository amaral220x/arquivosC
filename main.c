#include <stdio.h>
#include <stdlib.h>
#include <string.h>
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
  void preencher();
  int contador =0 ;
  float ;
  char opcao;
  FILE *arquivoUM;
  arquivoUM = fopen("arquivoBin.txt", "wb");
  if (arquivoUM == NULL) {
    printf("Erro ao abrir o arquivo\n" );
    system("pause");
  }

    //preencher();
    contador++;
    strcpy (agenda.nome, "JATO");
    strcpy (agenda.endereco, "RUA PINTO");
    agenda.fone.ddd=11;
    printf("%d\n",agenda.fone.ddd);
    printf("%s\n", agenda.nome);

    //fwrite( agenda.nome ,sizeof(agenda.nome),1, arquivoUM);
    fwrite( &agenda, sizeof(struct regagenda), 1, arquivoUM);


    fclose (arquivoUM);

  return 0;

}
