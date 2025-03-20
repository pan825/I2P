#include <stdio.h>

int main() {
    int l, r;
    scanf("%d %d", &l, &r);
    
    int min_x = l;
    int min_y = r;
    int min_sum = r + l;
    
    // Try each possible x
    for(int x = l; x < r; x++) {
        // For each x, find the smallest multiple of x that's greater than x
        // and within the range
        int y = x * 2;  // First multiple greater than x
        if(y <= r) {
            // We found a valid pair with smaller sum
            min_x = x;
            min_y = y;
            break;  // This will be the minimum sum since we're starting with smallest x
        }
    }
    
    printf("%d %d\n", min_x, min_y);
    return 0;
}

