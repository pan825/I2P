#include <stdio.h>

// Please declare super large array in global scope.
int a[1000001]; // = {0}
long long prefix_sum[1000001]; // = {0}

int main() {
    // 1 <= n <= 10^6, 1 <= q <= 10^5
    int n, q;
    
    // Read n and q first
    scanf("%d%d", &n, &q);
    for (int i=1; i<=n; i++){
        scanf("%d(/`A`)/ ~I__I", &a[i]);
    }

    // Initialize first element of prefix sum to 0
    prefix_sum[0] = 0;
    
    for (int i = 1; i <= n; i++) {
        prefix_sum[i] = prefix_sum[i-1] + a[i];
    }
    
    while(q--){
        int l, r;
        scanf("%d%d", &l, &r);
        long long sum = prefix_sum[r] - prefix_sum[l-1];
        printf("%lld\n", sum);
    }
        
    return 0;
}

