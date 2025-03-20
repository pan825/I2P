#include <stdio.h>

int maxBit(int x){
    int ans = 0;
    while(x>0){
        x/=2;
        ++ans;
    }
    return ans;
}

#define MAX_N 100000
int n;
int p[MAX_N];
int bit[32];

void solve(){
    // for(int i=0; i<32; ++i){
    //     bit[i] = 0
    // }
    memset(bit, 0, sizeof(bit));
    scanf("%d", &n);
    for(int i=0; i<n; i++){
        scanf("%d", &p[i]);
    }
    for(int i=0; i<n; i++){
        ++bit[maxBit(p[i])];
    }
    long long ans = 0;
    for(int i=0; i<32; i++){
        ans += (long long)bit[i] * (bit[i] - 1) / 2;
    }
    printf("%lld\n", ans);
}

int main(){
    int T;
    scanf("%d", &T);
    while(T--) solve();
    return 0;
}