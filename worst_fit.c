#include <stdio.h>
#include <stdlib.h>

void worstFit(int blockSize[], int m, int processSize[], int n, int allocation[]) {
    for (int i = 0; i < n; i++) {
        int worstIdx = -1;
        for (int j = 0; j < m; j++) {
            if (blockSize[j] >= processSize[i]) {
                if (worstIdx == -1 || blockSize[j] > blockSize[worstIdx]) {
                    worstIdx = j;
                }
            }
        }
        if (worstIdx != -1) {
            allocation[i] = worstIdx;
            blockSize[worstIdx] -= processSize[i];
        }
    } 	 	
}

int main() {
    int m, n, choice;
    printf("Enter the number of memory blocks: ");
    scanf("%d", &m);
    printf("Enter the number of processes: ");
    scanf("%d", &n);

    int blockSize[m], processSize[n], allocation[n];

    printf("Enter the sizes of %d memory blocks: ", m);
    for (int i = 0; i < m; i++)
        scanf("%d", &blockSize[i]);

    printf("Enter the sizes of %d processes: ", n);
    for (int i = 0; i < n; i++) {
        scanf("%d", &processSize[i]);
        allocation[i] = -1; 
    }

       worstFit(blockSize, m, processSize, n, allocation);

    printf("\nProcess No.\tProcess Size\tBlock No.\n");
    for (int i = 0; i < n; i++) {
        printf("%d\t\t%d\t\t", i + 1, processSize[i]);
        if (allocation[i] != -1)
            printf("%d\n", allocation[i] + 1); 
        else
            printf("Not Allocated\n"); 
    }

    return 0;
}

