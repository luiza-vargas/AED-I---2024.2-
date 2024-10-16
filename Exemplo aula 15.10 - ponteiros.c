/******************************************************************************
	exemplo ponteiros aula : 15/10/2024
*******************************************************************************/

#include <stdio.h>

int main()
{
  int x=1,y=3;

	/*declara dois ponteiros que armazenam o endereco de uma variavel tipo int e inicializa
	eles com o endereco de y, assim px e py */
	int*px=&y,*py=&y;

	/*soma os valores apontados pelos ponteiros px e py e armazena o resultado no endereco apontado por px.
	O valor de y ser dobrado*/
	*px=*px+*py;

	/*imprime os valores de x e y*/
	printf("x=%d, y=%d\n", x, y);

	/*imprime os valores apontados pelos ponteiros px e py*/
	printf("*px=%d, *py=%d\n", *px, *py);

	/*imprime os enderecos armazenados em px e py*/
	printf("px=%p, py=%p\n", px, py);

	/*imprime o endereco das variaveis x e y */
	printf("&x=%p, &y=%p\n", &x, &y);

	return 0;
}
