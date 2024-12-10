/*Escreva uma função que inverta a ordem das células de uma lista
encadeada (a primeira passa a ser a última, a segunda passa a ser a penúltima etc.).
Faça isso sem criar novas células; apenas altere os ponteiros.*/

    void inverte(celula **p){
        celula *anterior=NULL;
        celula* atual=*p;
        celula *seguinte=NULL;
        while(atual!=null){
            seguinte=atual->prox;
            atual->prox=ant; //altera pra quem atual vai apontar
            anterior=atual; // avanca o ponteiro anterior
            atual=seguinte;//avanca o ponteiro atual
        }
        *p=anterior;// atualiza o ponteiro
    }
