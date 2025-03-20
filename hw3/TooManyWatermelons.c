#include <stdio.h>
#define MAX_N 200000
int n; 
int arr[MAX_N+1];
int idx[MAX_N+1];
int order[MAX_N+1];
int ans[MAX_N+1];
// n = 10
// 5 2 9 3 6 8 1 7 10 4
// 1 2 5 3 10 9 7 4 6 8

// 7 0 0 0 2 0 0 1 0 0

// idx[5] = 1
// idx[2] = 2
// idx[9] = 3
// idx[3] = 4
// idx[6] = 5
// idx[8] = 6
// idx[1] = 7
// idx[7] = 8
// idx[10] = 9
// idx[4] = 10
                      
int main(void){           
               
    scanf("%d", &n);
    for(int i=1; i<=n; i++) {
        scanf("%d", &arr[i]);
        idx[arr[i]] = i;
    }

    for (int i=1; i<=n; i++) {
        scanf("%d", &order[i]);
    }

    int nowPos = 0;
    for (int i=1; i<=n; i++) {
        if (idx[order[i]] > nowPos){
        ans[i] = idx[order[i]] - nowPos;
        nowPos = idx[order[i]];
        }
        else ans[i] = 0;
    }

    for (int i=1; i<=n; i++) {
        printf("%d ", ans[i]);
    }
    printf("\n");

    return 0;
}