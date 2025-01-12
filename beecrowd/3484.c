#include <stdio.h>
#include <stdlib.h>

typedef struct No {
    int altura;
    int nivel;
    struct No *esquerda, *direita;
} No;

No* criarNo(int altura, int nivel) {
    No* novoNo = (No*)malloc(sizeof(No));
    novoNo->altura = altura;
    novoNo->nivel = nivel;
    novoNo->esquerda = novoNo->direita = NULL;
    return novoNo;
}

void inserir(No** raiz, int altura, int nivel) {
    if (*raiz == NULL) {
        *raiz = criarNo(altura, nivel);
    } else if (altura < (*raiz)->altura) {
        inserir(&((*raiz)->esquerda), altura, nivel + 1);
    } else {
        inserir(&((*raiz)->direita), altura, nivel + 1);
    }
}

void encontrarMenoresPorNivel(No* raiz, int* menoresAlturas, int nivelMaximo) {
    if (raiz == NULL) return;
    
    if (menoresAlturas[raiz->nivel] == 0 || raiz->altura < menoresAlturas[raiz->nivel]) {
        menoresAlturas[raiz->nivel] = raiz->altura;
    }
    
    encontrarMenoresPorNivel(raiz->esquerda, menoresAlturas, nivelMaximo);
    encontrarMenoresPorNivel(raiz->direita, menoresAlturas, nivelMaximo);
}

int main() {
    int quantidadeAlunos;
    scanf("%d", &quantidadeAlunos);

    int alturas[quantidadeAlunos];
    for (int i = 0; i < quantidadeAlunos; i++) {
        scanf("%d", &alturas[i]);
    }

    No* raiz = NULL;

    for (int i = 0; i < quantidadeAlunos; i++) {
        inserir(&raiz, alturas[i], 0);
    }

    int nivelMaximo = quantidadeAlunos;
    int menoresAlturas[nivelMaximo];
    for (int i = 0; i < nivelMaximo; i++) {
        menoresAlturas[i] = 0;
    }

    encontrarMenoresPorNivel(raiz, menoresAlturas, nivelMaximo);

    for (int i = 0; i < nivelMaximo; i++) {
        if (menoresAlturas[i] != 0) {
            printf("%d %d\n", i, menoresAlturas[i]);
        }
    }

    return 0;
}
