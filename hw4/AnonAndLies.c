// Given a sequence of non-negative integers a of length n (where n is an odd number), 
// every number in the sequence appears exactly twice except for one unique number. 
// Find this unique number.

// 2
// 7
// 5 6 6 1 3 3 5
// 7
// 12 1 13 14 12 14 1

#include <stdio.h>

int main(void){
    int t;
    scanf("%d", &t);
    
    while(t--){
        int n;
        scanf("%d", &n);
        
        long long unique = 0;
        long long num;
        
        for(int i=0; i<n; i++){
            scanf("%lld", &num);
            unique ^= num;  // 立即處理每個輸入的數字
        }
        
        printf("%lld\n", unique);  // 使用 %lld 而不是 %d
    }
    return 0;
}
