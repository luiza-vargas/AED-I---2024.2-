#include <stdio.h>

int main() {
    int horai, mini, horaf, minf;
    int duracao_horas, duracao_minutos;

    scanf("%d %d %d %d", &horai, &mini, &horaf, &minf);
    
    int inicio_total = horai * 60 + mini;
    int fim_total = horaf * 60 + minf;

    int duracao_total;
    if (fim_total > inicio_total) {
        duracao_total = fim_total - inicio_total;
    } else {
        duracao_total = (24 * 60 - inicio_total) + fim_total;
    }

    duracao_horas = duracao_total / 60;
    duracao_minutos = duracao_total % 60;

    if (duracao_horas == 24 && duracao_minutos > 0) {
        duracao_horas = 0;
    }

    printf("O JOGO DUROU %d HORA(S) E %d MINUTO(S)\n", duracao_horas, duracao_minutos);

    return 0;
}
