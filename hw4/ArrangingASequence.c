#include <stdio.h>
int found[200005];
int arr[200005];
int main(){
    memset(found, 200005, 0);
    int n, t;
    scanf("%d%d", &n, &t);
    for(int i=t-1; i>=0; i--){
        scanf("%d",&arr[i]);
    }
    for(int i=0; i<t; i++){
        if(found[arr[i]]==0){
            printf("%d\n", arr[i]);
            found[arr[i]]=1;
        }
    }
    for(int i=1; i<=n; i++){
        if(found[i]==0) printf("%d\n", i);
    }
}
