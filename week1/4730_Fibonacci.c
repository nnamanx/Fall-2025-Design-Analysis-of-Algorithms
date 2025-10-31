#include <stdio.h>
#define MAX 46

int i, n;
int fib[MAX];

int main(void){
    
    fib[0] = 1;
    fib[1] = 1;
    
    for(i = 2; i < MAX; i++){
        fib[i] = fib[i-1] + fib[i-2];
    }
    
    scanf("%d", &n);
    printf("%d", fib[n]);
    return 0;
}