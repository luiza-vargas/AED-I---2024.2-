
int verifica_linha_99(int matriz[9][9]) {
	int i,j,k;

	for(i=0; i<9; i++) {
		for(j=0; j<9; j++) {
			if (matriz[i][j] > 9) {  // verifica se algum numero maior que 9
				return 0;
			}

			for(k=j+1; k<9; k++) {
				if((j!=k) && matriz[i][j]==matriz[i][k] ) {
					return 0;
				}

			}
		}
	}

	return 1;
}

int verifica_coluna_99(int matriz[9][9]) {
	int i,j,k;

	for(j=0; j<9; j++) {
		for(i=0; i<9; i++) {
			if (matriz[i][j] > 9) {  // verifica se algum nC:mero C) maior que 9
				return 0;
			}
			for(k=0; k<9; k++) {
				if((j!=k) && matriz[i][j]==matriz[k][j] ) {
					return 0;
				}

				if( matriz[i][j]>9 || matriz[k][j]>9) {
					return 0;
				}

				else {
					return 1;
				}
			}
		}
	}
	return 1;
}

int monta_matriz_33 (int matriz[9][9]) {
	int i,j,k,l,num,qntd;
	int nova[3][3];

	//criando a matriz 3x3
	for(i=0; i<9; i+=3) {
		for(j=0; j<9; j+=3) {
			for(k=0; k<3; k++) {
				for(l=0; l<3; l++) {
					nova[3][3]=matriz[k+i][l+j];
					{
						if(verifica_matriz_33(nova) != 1) {
							return 0;
						}
					}
				}
			}
		}
	}
	return 1;
}

int verifica_matriz_33(int nova[3][3]) {
	int num,i,j,qnt,mini[3][3];

	for(num = 1; num <= 9; num++) {
		for(i = 0; i < 3; i++)
			for(j = 0; j < 3; j++)
				if(mini[i][j] == num) {
					qnt++;
				}
		if(qnt > 1) {
			return 0;
		}
		qnt = 0;
	}
	return 1;
}

#include <stdio.h>

int main()
{
	int n,i,j,matriz[9][9],aux;
	scanf("%d",&n);
	
	for (aux=1;aux<=n;aux++){
		for (i=0; i<8; i++) {
			for (j=0; j<8; j++) {
				scanf("%d",&matriz[i][j]);
			}
		}
      printf("Instancia %d \n",n);
      
        if (verifica_linha_99(matriz) == verifica_coluna_99(matriz) == monta_matriz_33(matriz) ==1) {
            printf("Sim\n");
        } else {
            printf("Nao\n");
        }
	    printf ("\n");
	}
	return 0;
}
