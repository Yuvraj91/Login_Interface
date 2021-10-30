#include <stdio.h>
#include <stdlib.h>

int f(int a, int *b){
    a = 5;
    *b = *b + 3*a;
    printf("%i %i\n", a, b);
    return 0;
}

int main(){
    int x, y;
    x = 4;
    y = 6;
    f(x, &y);
    printf("%i %i\n", x, y);
    // What are x and y now?
}