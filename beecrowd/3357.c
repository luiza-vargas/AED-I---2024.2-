    #include <stdio.h>
    #include <math.h>
    #include <string.h>

    int main() {
        int N; 
        float L, Q; 
        char nomes[10][13]; 
        int rodadas, ricoIndex;
        float sobra;

        scanf("%d %f %f", &N, &L, &Q);
        for (int i = 0; i < N; i++) {
            scanf("%s", nomes[i]);
        }

        rodadas = (int)(L / Q); // Número total de cuias completas
        sobra = fmod(L, Q); // Quantidade de água na última cuia

        // Determina o índice do participante que recebe a última cuia
        if (sobra > 0) {
            ricoIndex = rodadas % N; // Última cuia vai para este índice
        } else {
            ricoIndex = (rodadas - 1) % N; // Última cuia é a anterior
            sobra = Q; // Última cuia é completa
        }

        printf("%s %.1f\n", nomes[ricoIndex], sobra);

        return 0;
    }
