    #include <stdio.h>
    #include <string.h>

    int main()
    {
        int largura, altura, i, j, max_passos, x = 0, y = 0, direcao_atual, passos;
        char simbolo;

        // Lê a largura e altura do mapa
        scanf("%d%d", &largura, &altura);
        char mapa[altura][largura + 1];

        // Lê as linhas do mapa
        for (i = 0; i < altura; i++)
            scanf("%s", mapa[i]);

        max_passos = largura * altura;

        for (passos = 1; passos <= max_passos; )
        {
            if (mapa[y][x] == '>')
            {
                x++; passos++; direcao_atual = 1; // Movendo para a direita
                if (x >= largura) break;
            }
            else if (mapa[y][x] == 'v')
            {
                y++; passos++; direcao_atual = 2; // Movendo para baixo
                if (y >= altura) break;
            }
            else if (mapa[y][x] == '<')
            {
                x--; passos++; direcao_atual = 3; // Movendo para a esquerda
                if (x < 0) break;
            }
            else if (mapa[y][x] == '^')
            {
                y--; passos++; direcao_atual = 4; // Movendo para cima
                if (y < 0) break;
            }
            else if (mapa[y][x] == '*')
            {
                passos = max_passos + 1; // Baú encontrado
                break;
            }
            else if (mapa[y][x] == '.')
            {
                // Continua na direção atual
                if (direcao_atual == 1)
                {
                    x++; passos++;
                    if (x >= largura) break;
                }
                else if (direcao_atual == 2)
                {
                    y++; passos++;
                    if (y >= altura) break;
                }
                else if (direcao_atual == 3)
                {
                    x--; passos++;
                    if (x < 0) break;
                }
                else if (direcao_atual == 4)
                {
                    y--; passos++;
                    if (y < 0) break;
                }
            }
        }

        // Verifica o resultado
        if (passos > max_passos) 
            printf("*\n"); // Baú encontrado
        else 
            printf("!\n"); // Mapa inválido ou caminho fora dos limites

        return 0;
    }
