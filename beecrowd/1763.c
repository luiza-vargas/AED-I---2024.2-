#include <stdio.h>
#include <string.h>

typedef struct {
    char pais[31];
    char mensagem[101];
} Traducao;

int main() {
    Traducao traducoes[] = {
        {"brasil", "Feliz Natal!"},
        {"alemanha", "Frohliche Weihnachten!"},
        {"austria", "Frohe Weihnacht!"},
        {"coreia", "Chuk Sung Tan!"},
        {"espanha", "Feliz Navidad!"},
        {"grecia", "Kala Christougena!"},
        {"estados-unidos", "Merry Christmas!"},
        {"inglaterra", "Merry Christmas!"},
        {"australia", "Merry Christmas!"},
        {"portugal", "Feliz Natal!"},
        {"suecia", "God Jul!"},
        {"turquia", "Mutlu Noeller"},
        {"argentina", "Feliz Navidad!"},
        {"chile", "Feliz Navidad!"},
        {"mexico", "Feliz Navidad!"},
        {"antardida", "Merry Christmas!"},
        {"canada", "Merry Christmas!"},
        {"irlanda", "Nollaig Shona Dhuit!"},
        {"belgica", "Zalig Kerstfeest!"},
        {"italia", "Buon Natale!"},
        {"libia", "Buon Natale!"},
        {"siria", "Milad Mubarak!"},
        {"marrocos", "Milad Mubarak!"},
        {"japao", "Merii Kurisumasu!"}
    };

    int n = sizeof(traducoes) / sizeof(traducoes[0]);
    char pais[31];

    // Enquanto houver entrada
    while (scanf("%s", pais) != EOF) {
        int found = 0;

        // Verifica se o país está no banco de dados
        for (int i = 0; i < n; i++) {
            if (strcmp(pais, traducoes[i].pais) == 0) {
                printf("%s\n", traducoes[i].mensagem);
                found = 1;
                break;
            }
        }

        if (!found) {
            printf("--- NOT FOUND ---\n");
        }
    }

    return 0;
}
