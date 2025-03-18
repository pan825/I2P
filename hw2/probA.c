#include <stdio.h>

int main() {
    int n, q;
    
    // Read n and q first
    scanf("%d %d", &n, &q);
    
    // Declare arrays with proper size
    long long a[n+1];
    long long prefix_sum[n+1];
    
    // Initialize first element of prefix sum to 0
    prefix_sum[0] = 0;
    
    char trash_symbol[20]; // Buffer to store the symbol
    
    // Read array elements
    for (int i = 1; i <= n; i++) {
        scanf("%lld", &a[i]);
        scanf("%s", trash_symbol); // Read the "(/`A`)/ ~I__I" symbol
        
        // Calculate prefix sum
        prefix_sum[i] = prefix_sum[i-1] + a[i];
    }
    
    // Process queries
    for (int i = 0; i < q; i++) {
        int l, r;
        scanf("%d %d", &l, &r);
        
        // Ensure l and r are within bounds
        if (l < 1 || r > n || l > r) {
            printf("Invalid query range\n");
            printf("l: %d, r: %d, n: %d\n", l, r, n);
            continue;
        }
        
        // Calculate sum from l to r using prefix sums
        long long sum = prefix_sum[r] - prefix_sum[l-1];
        printf("%lld\n", sum);
    }
    
    return 0;
}

