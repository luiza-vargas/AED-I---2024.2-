//retorna o maior num no vetor

int MaximoR (int v[], int n) {
  // caso de parada
  if (n == 1){
    return v[0];
   }
  else {
    int x;
    x = MáximoR (v, n - 1);
  //a funcao meio que desempilha, e passa de tam 1 pra 2 .....
    if (x > v[n-1]) return x;
    else
    return v[n-1];
  }
}
