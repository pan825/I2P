#include <stdio.h>
#include <stdlib.h>

int main(void) {
    int n, m, element;
    scanf("%d %d", &n, &m);
    
    // Initialize the sequence and positions array
    int *sequence = (int *)malloc(n * sizeof(int));
    int *positions = (int *)malloc((n + 1) * sizeof(int));  // 1-based indexing
    
    for (int i = 0; i < n; i++) {
        sequence[i] = i + 1;
        positions[i + 1] = i;  // Store position of each number
    }
    
    // Process each request
    for (int i = 0; i < m; i++) {
        scanf("%d", &element);
        int pos = positions[element];
        
        // Move the element to the front
        for (int j = pos; j > 0; j--) {
            sequence[j] = sequence[j - 1];
            positions[sequence[j]] = j;  // Update positions
        }
        sequence[0] = element;
        positions[element] = 0;
    }
    
    // Output the final sequence
    for (int i = 0; i < n; i++) {
        printf("%d\n", sequence[i]);
    }
    
    free(sequence);
    free(positions);
    return 0;
}

