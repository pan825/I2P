#include <stdio.h>
#include <math.h>

int main() {
    double x, y;
    int z;
    
    // Read the two numbers x, y and the integer z
    scanf("%lf %lf %d", &x, &y, &z);
    
    // Solution 1
    // double ans = round(x * y * pow(10, z)) / pow(10, z);
    // printf("%lf\n", ans);

    // Solution 2
    double ans = x * y;
    printf("%.*lf\n", z, ans);
    
    return 0;
}
