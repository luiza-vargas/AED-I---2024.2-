#include <stdio.h>
 
int main() {
    
 int n;
 
 scanf("%d",&n);
 
 int dist=0;
 
  for (int i = 0; i < n; i++) {
        int T, V;
        scanf("%d %d", &T, &V);
        dist += T * V; 
    }

    printf("%d\n", dist); 
 
    return 0;
}
