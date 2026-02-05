#include <stdio.h>

int main()
{
    int n, i, j;
    int capacity;
    int bins = 0;

    printf("Enter number of items: ");
    scanf("%d", &n);

    int weight[n];
    int remaining[n];

    printf("Enter capacity of each bin: ");
    scanf("%d", &capacity);

    printf("Enter weights of items:\n");
    for (i = 0; i < n; i++)
        scanf("%d", &weight[i]);

    for (i = 0; i < n; i++)
    {
        for (j = 0; j < bins; j++)
        {
            if (remaining[j] >= weight[i])
            {
                remaining[j] -= weight[i];
                break;
            }
        }

        if (j == bins)
        {
            remaining[bins] = capacity - weight[i];
            bins++;
        }
    }

    printf("Total bins required (First Fit): %d\n", bins);

    return 0;
}

