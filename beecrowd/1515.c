    #include <stdio.h>
    #include <string.h>

    typedef struct {
        char planeta[51]; 
        int ano_recebimento; 
        int tempo_viagem; 
    } Mensagem;

    int main() {
        int N;

        while (1) {
            scanf("%d", &N);
            if (N == 0) {
                break;
            }
            Mensagem mensagens[N];
            char primeiro_planeta[51]; 
            int menor_ano_envio = 9999; 

            for (int i = 0; i < N; i++) {
                scanf("%s %d %d", mensagens[i].planeta, &mensagens[i].ano_recebimento, &mensagens[i].tempo_viagem);

                int ano_envio = mensagens[i].ano_recebimento - mensagens[i].tempo_viagem;

                // Verifica se e o menor ano de envio
                if (ano_envio < menor_ano_envio) {
                    menor_ano_envio = ano_envio;
                    strcpy(primeiro_planeta, mensagens[i].planeta);
                }
            }

            printf("%s\n", primeiro_planeta);
        }

        return 0;
    }
