#include <stdio.h>
#include <stdlib.h>
int main()
{
	/*cria variavel ponteiro para o arquivo*/
	FILE*arq;
	char palavra[20];

	/*abre o arquivo com o tipo de abertura w,escrita/gravacao*/
	arq=fopen("arquivo_palavra.txt","w");

	/*confirmando se foi criado*/
	if(arq==NULL) {
		printf("Erro na abertura do arquivo!");
		return 1;
	}
	printf("Escreva uma palavra para gravar no arquivo: ");
	scanf("%s", palavra);

	/*usando printf para armazenar a string no arquivo*/
	fprintf(arq, "%s", palavra);

	/*fclose para fechar o arquivo*/
	fclose(arq);
	
	printf("Dados gravados com sucesso!");
	
	return 0;

}
