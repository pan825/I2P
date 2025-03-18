#include <stdio.h>
#include <math.h>

int main() {
    double x, y;
    int z;
    
    // Read the two numbers x, y and the integer z
    scanf("%lf %lf %d", &x, &y, &z);
    
    // Calculate the product
    double result = x * y;
    
    // Create a format string for the specified number of decimal places
    char format[20];
    sprintf(format, "%%.%dlf\n", z);
    
    // Print the result with z decimal places
    printf(format, result);
    
    return 0;
}
