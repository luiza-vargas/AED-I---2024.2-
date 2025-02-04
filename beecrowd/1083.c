    #include <stdio.h>
    #include <stdlib.h>
    #include <string.h>
    #include <ctype.h>

    #define TAMANHO_MAX 1000

    typedef struct {
    char dados[TAMANHO_MAX];
    int topo;
    } Pilha;

    void inicializar_pilha(Pilha *p) {
    p->topo = -1;
    }

    int pilha_vazia(Pilha *p) {
    return p->topo == -1;
    }

    int pilha_cheia(Pilha *p) {
    return p->topo == TAMANHO_MAX - 1;
    }

    void empilhar(Pilha *p, char c) {
    if (pilha_cheia(p)) {
        printf("Estouro de pilha!\n");
        exit(1);
    }
    p->dados[++(p->topo)] = c;
    }

    char desempilhar(Pilha *p) {
    if (pilha_vazia(p)) {
        printf("Pilha vazia!\n");
        exit(1);
    }
    return p->dados[(p->topo)--];
    }

    char topo(Pilha *p) {
    if (pilha_vazia(p)) {
        return '\0';
    }
    return p->dados[p->topo];
    }

    int eh_operador(char c) {
    return (c == '^' || c == '*' || c == '/' || c == '+' || c == '-' ||
            c == '>' || c == '<' || c == '=' || c == '#' || c == '.' || c == '|');
    }

    int prioridade(char c) {
    switch (c) {
        case '^': return 6;
        case '*': case '/': return 5;
        case '+': case '-': return 4;
        case '>': case '<': case '=': case '#': return 3;
        case '.': return 2;
        case '|': return 1;
        default: return 0;
    }
    }

    int erro_lexico(char *expressao) {
    for (int i = 0; expressao[i] != '\0'; i++) {
        if (!isalnum(expressao[i]) && expressao[i] != '(' && expressao[i] != ')' && !eh_operador(expressao[i])) {
            return 1;
        }
    }
    return 0;
    }

    int erro_sintatico(char *expressao) {
    Pilha p;
    inicializar_pilha(&p);
    int tamanho = strlen(expressao);

    for (int i = 0; i < tamanho; i++) {
        char c = expressao[i];

        if (c == '(') {
            empilhar(&p, c);
        } else if (c == ')') {
            if (pilha_vazia(&p) || topo(&p) != '(') {
                return 1;
            }
            desempilhar(&p);
        } else if (eh_operador(c)) {
            if (i == 0 || i == tamanho - 1 || eh_operador(expressao[i - 1]) || expressao[i - 1] == '(') {
                return 1;
            }
        } else if (isalnum(c)) {
            if (i > 0 && isalnum(expressao[i - 1])) {
                return 1;
            }
        }
    }

    if (!pilha_vazia(&p)) {
        return 1;
    }

    return 0;
    }

    void infixo_para_posfixo(char *expressao, char *saida) {
    Pilha p;
    inicializar_pilha(&p);
    int j = 0;

    for (int i = 0; expressao[i] != '\0'; i++) {
        char c = expressao[i];

        if (isalnum(c)) {
            saida[j++] = c;
        } else if (c == '(') {
            empilhar(&p, c);
        } else if (c == ')') {
            while (!pilha_vazia(&p) && topo(&p) != '(') {
                saida[j++] = desempilhar(&p);
            }
            desempilhar(&p);
        } else if (eh_operador(c)) {
            while (!pilha_vazia(&p) && prioridade(topo(&p)) >= prioridade(c)) {
                saida[j++] = desempilhar(&p);
            }
            empilhar(&p, c);
        }
    }

    while (!pilha_vazia(&p)) {
        saida[j++] = desempilhar(&p);
    }

    saida[j] = '\0';
    }

    int main() {
    char expressao[TAMANHO_MAX];
    char saida[TAMANHO_MAX];

    while (scanf("%s", expressao) != EOF) {
        if (erro_lexico(expressao)) {
            printf("Lexical Error!\n");
        } else if (erro_sintatico(expressao)) {
            printf("Syntax Error!\n");
        } else {
            infixo_para_posfixo(expressao, saida);
            printf("%s\n", saida);
        }
    }

    return 0;
    }
