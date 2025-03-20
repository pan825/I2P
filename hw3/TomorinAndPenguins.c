#include <stdio.h>
#define P_MAX 100005

// count valid pairs (i, j) where i < j and
// satisfies the following conditions:
// p_i AND p_j >= p_i XOR p_j

int t;
int n;
int p[P_MAX];

int main(void){
    scanf("%d", &t);
    while(t--){
        scanf("%d", &n);
        for(int i=0; i<n; i++){
            scanf("%d", &p[i]);
        }
        
        // The condition (a & b) >= (a ^ b) is equivalent to
        // (a & b) * 2 >= a + b
        // This happens when bits set in both numbers contribute more
        // than bits set in only one number
        
        long long count = 0;
        for(int i=0; i<n; i++){
            for(int j=i+1; j<n; j++){
                // Faster check: 2*(p[i] & p[j]) >= p[i] + p[j]
                if(2 * (p[i] & p[j]) >= p[i] + p[j]){
                    count++;
                }
            }
        }
        
        printf("%lld\n", count);
    }
    return 0;
}
