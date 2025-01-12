#include <stdio.h>
#include <string.h>

typedef struct {
    char idioma[21];
    char mensagem[101];
} Traducao;

typedef struct {
    char nome[101];
    char idioma[21];
} Crianca;

int main() {
    int N, M;
    scanf("%d", &N);

    Traducao traducoes[N];
    for (int i = 0; i < N; i++) {
        scanf("%s", traducoes[i].idioma);
        getchar(); // Remove o '\n'
        fgets(traducoes[i].mensagem, 101, stdin);
        traducoes[i].mensagem[strcspn(traducoes[i].mensagem, "\n")] = '\0';
    }

    scanf("%d", &M);

    Crianca criancas[M];
    for (int i = 0; i < M; i++) {
        getchar(); // Remove o '\n'
        fgets(criancas[i].nome, 101, stdin);
        criancas[i].nome[strcspn(criancas[i].nome, "\n")] = '\0';
        scanf("%s", criancas[i].idioma);
    }

    for (int i = 0; i < M; i++) {
        printf("%s\n", criancas[i].nome);
        for (int j = 0; j < N; j++) {
            if (strcmp(criancas[i].idioma, traducoes[j].idioma) == 0) {
                printf("%s\n", traducoes[j].mensagem);
                break;
            }
        }
        printf("\n");
    }

    return 0;
}
