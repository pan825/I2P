#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, q;
    if (scanf("%d %d", &n, &q) != 2) return 1;
    
    // Allocate arrays (using 1-indexing)
    int *A = (int *)malloc((n + 1) * sizeof(int));
    long long *prefix = (long long *)malloc((n + 1) * sizeof(long long));
    
    // Read the treasure values
    for (int i = 1; i <= n; i++) {
        if (scanf("%d", &A[i]) != 1) return 1;
    }

    // Precompute prefix sums (1-indexed, prefix[0] = 0)
    prefix[0] = 0;
    for (int i = 1; i <= n; i++) {
        prefix[i] = prefix[i - 1] + A[i];
    }

    // Determine the last index with a positive value.
    // Since the array is sorted in descending order, once a non-positive value is encountered, no further values will be positive.
    int lastPositive = 0;
    for (int i = 1; i <= n; i++) {
        if (A[i] > 0) {
            lastPositive = i;
        } else {
            break;
        }
    }

    // Process each query
    while (q--) {
        int l, r, m;
        if (scanf("%d %d %d", &l, &r, &m) != 3) break;

        // If the starting index is beyond the positive region, answer is 0 as picking any crate would lower the sum.
        if (l > lastPositive || A[l] <= 0) {
            printf("0\n");
            continue;
        }

        // In the interval [l, r], the positive crates are from l to min(r, lastPositive) (they are contiguous due to sorting).
        int effectiveEnd = (r < lastPositive) ? r : lastPositive;
        int positiveCount = effectiveEnd - l + 1;

        // We can select at most m crates, but not more than the available positive ones.
        int k = (m < positiveCount) ? m : positiveCount;

        // The answer is the sum of the first k positive crates in the interval [l, effectiveEnd]
        long long ans = prefix[l + k - 1] - prefix[l - 1];
        printf("%lld\n", ans);
    }

    free(A);
    free(prefix);
    return 0;
}

