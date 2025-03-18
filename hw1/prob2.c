#include <stdio.h>

int main() {
    int a_int, a_dec, b_int, b_dec;
    
    // Read the two numbers as integer parts and decimal parts
    scanf("%d.%d %d.%d", &a_int, &a_dec, &b_int, &b_dec);
    
    // Convert to integers (multiplied by 100)
    long long a = a_int * 100 + a_dec;
    long long b = b_int * 100 + b_dec;
    
    // Calculate the product
    long long result = a * b;
    
    // The result is now multiplied by 10000, so we need to separate it
    // into integer part and 4 decimal digits
    long long result_int = result / 10000;
    long long result_dec = result % 10000;
    
    // Print the result with 4 decimal places
    printf("%lld.%04lld\n", result_int, result_dec);
    
    return 0;
}
