#include <stdio.h>


int ternary_search(int list[], int n, int x){
    
    int l = 0, r = n-1;
    
    while(l <= r){
        int m1 = l + (r - l) / 3;
        int m2 = r - (r - l) / 3;
        
        if(list[m1] == x) return 1;
        if(list[m2] == x) return 1;
        
        if(x < list[m1]){
            r = m1 - 1;
        } else if(x > list[m2]){
            l = m2 + 1;
        } else {
            l = m1 + 1;
            r = m2 - 1;
        }
        
    }
    return 0;
    
}

int main(void){
    
    int n, q, i;
    
    if(scanf("%d %d", &n, &q) != 2){
        return 0;
    }
    
    int list[n];
    
    for(i = 0; i < n; i++){
        
        scanf("%d", &list[i]);
    }
    
    while(q--){
        
        int x;
        scanf("%d", &x);
        
        if(ternary_search(list, n, x)){
            printf("YES\n");
        } else printf("NO\n");
    }
    
    
    return 0;
}