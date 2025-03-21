#include <stdio.h>

int n, q;
int l, r, m;
int a[1000005];
long long prefix[1000005];

int main(){
    scanf("%d%d", &n, &q);
    for(int i=1; i<=n; i++){
        scanf("%d", &a[i]);

        if (a[i]< 0){
            a[i] = 0;
        }
        prefix[i] = prefix[i-1] + a[i];
    }

    while(q--){
        scanf("%d%d%d", &l, &r, &m);
        printf("%lld\n", prefix[l+m-1]-prefix[l-1]);
    }
}