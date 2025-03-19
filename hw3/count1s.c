#include <stdio.h>

int calcOnes(int n){
    int count = 0;
    while(n > 0){
        if(n % 10 == 1) ++count;
        n /= 10;
    }
    return count;
}

#define MAX_N 1000000
// int ones[MAX_N+1];
long long prefix[MAX_N+1];


void solve(){
    int a, b;
    scanf("%d%d", &a, &b);
    int ans = 0;
    ans = prefix[b] - prefix[a-1];
    printf("%d\n", ans);
}

int main(){
    for(int i=1; i<=MAX_N; i++){
        // ones[i] = calcOnes(i);
        // prefix[i] = prefix[i-1] + ones[i]
        prefix[i] = prefix[i-1] + calcOnes(i);
    }
    int t;
    scanf("%d", &t);
    while(t--) solve();
    return 0;
}