#include <stdio.h>
#include <conio.h>

void towers(int num, char source, char dest, char spare);

int main()
{
    int num;


    printf("Enter the number of disks: ");
    scanf("%d", &num);

    printf("\nThe sequence of moves involved in Towers of Hanoi:\n");

    towers(num, 'A', 'C', 'B');

    return 0;
}

void towers(int num, char source, char dest, char spare)
{
    if (num == 1)
    {
        printf("\nMove disk 1 from %c to %c", source, dest);
        return;
    }

    towers(num - 1, source, spare, dest);

    printf("\nMove disk %d from %c to %c", num, source, dest);

    towers(num - 1, spare, dest, source);
    getch();
}

