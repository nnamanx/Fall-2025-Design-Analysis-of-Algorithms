#include <stdio.h>
#include <string.h>
#define INF 0x3F3F3F3F
#define MAX 110

int main(void){
    
    int n, s, f;
    int m[MAX][MAX];
    int used[MAX];
    int d[MAX];
    
    if(scanf("%d %d %d", &n, &s, &f) != 3) return 0;
    
    for (int i = 1; i <= n; i++){
        for (int j = 1; j <= n; j++){
            int x;
            scanf("%d", &x);
            
            if(x == -1){
                m[i][j] = INF;
            } else m[i][j] = x;
            
        }
    }
    
    // end of inputing 
    
    memset(used, 0, sizeof(used));
    memset(d, 0x3F, sizeof(d));
    d[s] = 0;
    // end of initializing arrays
    
    
    for (int i = 1; i < n; i++){
        
        int min_d = INF;
        int w = -1;
        
        for(int j = 1; j <= n; j++){
            
            if(!used[j] && d[j] < min_d){
                min_d = d[j];
                w = j;
            }
        }
        
        if(w==-1 || min_d == INF) break; // no more reachable vertices
        
        
        // relaxation
        
        for(int j = 1; j <= n; j++){
            
            if(!used[j]){
                if (d[w] + m[w][j] < d[j]){
                    d[j] = d[w] + m[w][j];
                }
            }
        }
        
        used[w] = 1; // mark as processed
    }
    
    if(d[f] == INF) d[f] = -1;
    
    printf("%d\n", d[f]);
    return 0;
    
}