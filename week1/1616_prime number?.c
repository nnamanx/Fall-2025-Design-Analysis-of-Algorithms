#include <stdio.h>
#include <math.h>

int main(void){
    
    int n, i, flag = 0;
    
    scanf("%d", &n);
    
    int m = sqrt(n);
    
    for(i = 2; i <=m; i++){
        
        if(n % i == 0){
            printf("No");
            flag = 1;
            break;
        }
    }
    
    if(flag == 0){
        printf("Yes");
    }
    
    return 0;
}