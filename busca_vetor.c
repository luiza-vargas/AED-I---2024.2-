   #include<stdio.h>

    // ineficiente, tem que percorrer o vetor inteiro
    int busca_linear(int*V,int N,int elem){
        int i;
        for(i=0;i<N;i++){
            if(elem==V[i]){
                return i;
            }
        }
        return -1;
    }

    // util em alguns casos, pois como e ordenado, para qnd o elemento e menor do que a posicao
    int busca_ordenada(int*V,int N,int elem){
        int i;
        for(i=0;i<N;i++){
            if(elem==V[i]){
                return i;
            }
            else{
                if(elem<V[i]){
                    return -1;
            }
        }
        }
        return -1;
    }

    //busca binaria
    int busca_binaria(int*V,int N,int elem){
        int ini,meio,fim;
        ini=0;
        fim=N-1;
        while(ini<=fim){
            meio=(ini+fim)/2;
          //para diminuir o intervalo de pesquisa, lembra o metodo de newton
            if(elem<V[meio]){ // ta na primeira metade
                fim=meio-1;
            } else if(elem>V[meio]{ // segunda metade
                ini=meio+1;
            } else {
                return meio;
            }
        }
        return -1;
    }

    int main(){
    
        return 0;
    }
