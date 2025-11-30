#include <stdio.h>

int binary_search(int list[], int n, int x){
    
    int start = 0, end = n - 1;
    
    while(start <= end){
        
        int middle = (start + end) / 2;
        
        if(list[middle] == x){
            return 1;
        } else if(list[middle] < x){
            start = middle + 1;
        } else end = middle - 1;
    }
    
    return 0;

}

int main(){
    
    int n, q, i;
    
    if(scanf("%d %d", &n, &q) != 2){
        return 0;
    }
    
    int list[n];
    
    for(i = 0; i < n; i++){
        scanf("%d ", &list[i]);
    }
    
    while(q--){
        int x;
        scanf("%d", &x);
        
        if(binary_search(list, n, x)){
            printf("YES\n");
        } else printf("NO\n");
    }
    
    return 0;
}