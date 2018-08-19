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
  fflush(stdin);
  printf("\nEntre com o nome: ");
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
}
void mostrar (){
  printf("\nNome: %s\nEndereço: %s\nDDD: %d\nCasa: %d\nCelular: %d\nTrabalho: %d\n",agenda.nome,agenda.endereco,agenda.fone.ddd,agenda.fone.casa,agenda.fone.cel,agenda.fone.trab);
}
void limpar(){
  strcpy(agenda.nome, " ");
  strcpy(agenda.endereco," ");
  agenda.fone.ddd = 0;
  agenda.fone.casa = 0;
  agenda.fone.cel = 0;
  agenda.fone.trab = 0;
}
int main (void){
  void preencher();
  void limpar();
  void mostrar();
  int contReg = 0, registro;
  char opcao;
  FILE *arquivoUM;
  do {
    contReg++;
    if (contReg == 1){
      arquivoUM = fopen("arquivoBin.dat", "wb");
      if (arquivoUM == NULL) {
        printf("Erro ao abrir o arquivo\n" );
        system("pause");
      }
    }else{
      system("pause");
      printf("--------LIMPANDO O LIXO DA STRUCT---------\n");
      limpar();
      arquivoUM = fopen("arquivoBin.dat", "ab");
      printf("\nabrindo para editar arquivo existente");
      if (arquivoUM == NULL) {
        printf("Erro ao abrir o arquivo\n" );
        system("pause");
      }
    }

    preencher();
    system("cls");
    printf("--------ESCREVENDO NO ARQUIVO---------\n");
    mostrar();
    fwrite( &agenda, sizeof(struct regagenda), 1, arquivoUM);
    system("pause");
    printf("--------REGISTRO SALVO---------\n");
    system("pause");
    fclose (arquivoUM);
    system ("cls");
    printf("----DESEJA CRIAR MAIS UM REGISTRO---------\n");
    printf("\n's' ou 'n'\n");
    opcao = getch();
    printf("----------------\n");
  }while(opcao != 'n');
  //Arquivo fechado

  printf("--------Arquivo Fechado!---------\n");
  system("pause");
  limpar();
  printf("--------STRUCT LIMPA---------\n");
  mostrar();
  system ("pause");
  system ("cls");
  printf("QUANTIDADE DE REGISTROS: %d\n",contReg);
  printf("\n ---Digite o registro a ser consultado---\n");
  scanf("%d",&registro);
  registro = registro-1;
  printf("--------LENDO DO ARQUIVO ---------\n");
  FILE *arquivoDOIS;
  arquivoDOIS = fopen("arquivoBin.dat", "rb");
  if (arquivoDOIS == NULL) {
    printf("Erro ao abrir o arquivo\n");
    system("pause");
    }
  fseek(arquivoDOIS, registro*sizeof(struct regagenda), SEEK_SET);
  fread(&agenda, sizeof(struct regagenda), 1, arquivoDOIS);
  //ARQUIVOLIDO
  mostrar();
  system("pause");//Começando a procurar pelo final do arquivo. Indo de registro em registro.
  while(!feof(arquivoDOIS)){
    fseek(arquivoDOIS, registro*sizeof(struct regagenda), SEEK_SET);
    fread(&agenda, sizeof(struct regagenda), 1, arquivoDOIS);
    registro++;
    printf(".");
  }
  printf("Fim do arquivo!");
  fclose(arquivoDOIS);

  system("pause");
  printf("--------.PRESSIONE para REMOVER o CONTEÚDO do arquivo---------\n");
  FILE *arquivoTRES;
  arquivoTRES=fopen("arquivoBin.dat", "wb");
  fclose(arquivoTRES);
  system("pause");
  printf("--------CONTEÚDO APAGADO---------\n");
  system("pause");
  printf("--------PRESSIONE para REMOVER o arquivo---------\n");
  remove("arquivoBin.dat");
  system("pause");
  printf("--------ARQUIVO REMOVIDO ---------\n");
  system("pause");
  return 0;
}
