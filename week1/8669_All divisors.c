#include <stdio.h>
#include <math.h>

// All divisors
int main(void){
    
    long long n;
    scanf("%lld", &n);
    
    for(long long i = 1; i*i <= n; i++){
        if(n % i == 0){
            printf("%lld ", i);
        }
    }
    
    for(long long i = sqrt(n); i >= 1; i--){
        if(n % i == 0 && n/i != i){
            printf("%lld ", n/i);
        }
    }
    
    return 0;
}