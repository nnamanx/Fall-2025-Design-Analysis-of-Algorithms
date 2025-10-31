#include <stdio.h>

int f(int x, int y) {
    
    if (x <= 0 || y <= 0) {           
        return 0;
    }
    
    else if (x <= y) {                
        return f(x - 1, y - 2) + f(x - 2, y - 1) + 2;
    }
    
    else return f(x - 2, y - 2) + 1;
}

int main(void) {
    
    int x, y;
    
    scanf("%d %d", &x, &y);
    printf("%d\n", f(x, y));
    
    return 0;
}
