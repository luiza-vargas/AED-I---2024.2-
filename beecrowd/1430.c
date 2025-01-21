    #include <stdio.h>
    #include <string.h>

    double duracaoNota(char nota) {
        switch (nota) {
            case 'W': return 1.0;
            case 'H': return 0.5;
            case 'Q': return 0.25;
            case 'E': return 0.125;
            case 'S': return 0.0625;
            case 'T': return 0.03125;
            case 'X': return 0.015625;
            default: return 0.0;
        }
    }

    int main() {
        char composicao[205];

        while (1) {
            fgets(composicao, sizeof(composicao), stdin);

            composicao[strcspn(composicao, "\n")] = '\0';

            if (strcmp(composicao, "*") == 0) {
                break;
            }

            int compassosCorretos = 0;
            double somaDuracao = 0.0;

            for (int i = 1; composicao[i] != '\0'; i++) {
                if (composicao[i] == '/') {
              
                    if (somaDuracao == 1.0) {
                        compassosCorretos++;
                    }
                    somaDuracao = 0.0;
                } else {
                   
                    somaDuracao += duracaoNota(composicao[i]);
                }
            }

            printf("%d\n", compassosCorretos);
        }

        return 0;
        }
