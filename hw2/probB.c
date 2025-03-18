#include <stdio.h>

int A, B, C;
int a, b, c;

int main() {
    
    scanf("%d %d %d", &A, &B, &C);
    // A = a+b; B = b+c; C = a+c;
    // A+B-C = 2b
    // A+C-B = 2a
    // B+C-A = 2c
    // b = (A+B-C)/2
    // a = (A+C-B)/2
    // c = (B+C-A)/2
    b = (A+B-C)/2;
    a = (A+C-B)/2;
    c = (B+C-A)/2;
    printf("%d %d %d\n", a, b, c);
    
}