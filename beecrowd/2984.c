    #include <stdio.h>
    #include <string.h>

    int main() {
        char S[100001]; // Para armazenar a string S com até 100000 caracteres
        scanf("%s", S); // Lê a string de entrada
        
        int pendentes = 0; // Contador de assuntos pendentes
        int i;
        for (i = 0; i < strlen(S); i++) {
            if (S[i] == '(') {
                pendentes++; // Aumenta o contador ao encontrar um parêntese de abertura
            } else if (S[i] == ')') {
                if (pendentes > 0) {
                    pendentes--; // Diminui o contador ao encontrar um parêntese de fechamento, se houver assuntos pendentes
                }
            }
        }
        
        if (pendentes > 0) {
            printf("Ainda temos %d assunto(s) pendente(s)!\n", pendentes);
        } else {
            printf("Partiu RU!\n");
        }
        
        return 0;
    }
