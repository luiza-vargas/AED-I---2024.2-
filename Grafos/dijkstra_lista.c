    //implementacao basica dijkstra
    void dijkstra(Grafo G, int origem, int *dist,int *pa){
        int i, *R;
        int v,w,custo, tam_R, min_dist;
        No *p;
        //inicializando distancias e predecessores 
        for(i=0;i<G->n;i++){
            dist[i]= INT_MAX;
            pred[i]=-1;
        }
        dist[origem]=0;
        //iniciando conjunto r
        R=malloc(G->n * sizeof(int));
        for(i=0;i<G->n;i++){
            R[i]=0; 
        }
        tam_R=0;
        //laco principal
        while(tam_R<G->n){
            //busca vertice v em V - R que minimiza dist[v]
            min_dist=INT_MAX;
            v=-1; 
            for(i=0;i<=G->n;i++){
                if(R[i]==0 && dist[i]<min_dist){
                    v=i;
                    min_dist=dist[i];
                }
            }
            //add v a R e atualizando R
            R[v]=1;
            tam_R++;
            //percorrendo lista com vizinhos de v;
            for(p=G->A[v];p!= NULL;p=p->prox){
                w = p->rotulo;
                custo= p->custo;

                //atualizando a dist e predecessores qnd necessario 
                if(R[w]==0 && dist[w]>dist[v]+custo){
                    dist[w]=dist[v]+custo;
                    pa[w]=v;
                }
            }
        
        }
        free(R)
    }


