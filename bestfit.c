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
        int best = -1;

        for (j = 0; j < bins; j++)
        {
            if (remaining[j] >= weight[i])
            {
                if (best == -1 || remaining[j] < remaining[best])
                {
                    best = j;
                }
            }
        }

        if (best != -1)
        {
            remaining[best] -= weight[i];
        }
        else
        {
            remaining[bins] = capacity - weight[i];
            bins++;
        }
    }

    printf("Total bins required (Best Fit): %d\n", bins);

    return 0;
}

