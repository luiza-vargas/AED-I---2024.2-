/*A seguinte função calcula o maior divisor comum dos inteiros positivos
m e n. Escreva uma função recursiva equivalente.
int Euclides (int m, int n) {
int r;
do {
r = m % n;
m = n; n = r;
} while (r != 0);
return m; }*/
int EuclidesRecursivo(int m, int n) {
    if (n == 0) {
        return m; // Caso base: mdc(m, 0) é m
    }
    return EuclidesRecursivo(n, m % n); // Passo recursivo
}
