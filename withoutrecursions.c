#include <stdio.h>

void moveDisk(int disk, char from, char to)
{
    printf("Move disk %d from %c to %c\n", disk, from, to);
}

void moveBetween(int *a, int *b, char x, char y)
{
    int temp;

    if (*a == 0)
    {
        *a = *b;
        *b = 0;
        printf("Move disk %d from %c to %c\n", *a, y, x);
    }
    else if (*b == 0)
    {
        *b = *a;
        *a = 0;
        printf("Move disk %d from %c to %c\n", *b, x, y);
    }
    else if (*a < *b)
    {
        temp = *a;
        *a = 0;
        *b = temp;
        printf("Move disk %d from %c to %c\n", *b, x, y);
    }
    else
    {
        temp = *b;
        *b = 0;
        *a = temp;
        printf("Move disk %d from %c to %c\n", *a, y, x);
    }
}

int main()
{
    int n, i;
    int source[100], auxiliary[100], destination[100];
    int topS = -1, topA = -1, topD = -1;
    int totalMoves;

    printf("Enter number of disks: ");
    scanf("%d", &n);

    totalMoves = (1 << n) - 1;

    for (i = n; i >= 1; i--)
        source[++topS] = i;

    for (i = 1; i <= totalMoves; i++)
    {
        if (i % 3 == 1)
        {
            if (topS == -1)
            {
                source[++topS] = destination[topD--];
                printf("Move disk %d from C to A\n", source[topS]);
            }
            else if (topD == -1)
            {
                destination[++topD] = source[topS--];
                printf("Move disk %d from A to C\n", destination[topD]);
            }
            else if (source[topS] < destination[topD])
            {
                destination[++topD] = source[topS--];
                printf("Move disk %d from A to C\n", destination[topD]);
            }
            else
            {
                source[++topS] = destination[topD--];
                printf("Move disk %d from C to A\n", source[topS]);
            }
        }
        else if (i % 3 == 2)
        {
            if (topS == -1)
            {
                source[++topS] = auxiliary[topA--];
                printf("Move disk %d from B to A\n", source[topS]);
            }
            else if (topA == -1)
            {
                auxiliary[++topA] = source[topS--];
                printf("Move disk %d from A to B\n", auxiliary[topA]);
            }
            else if (source[topS] < auxiliary[topA])
            {
                auxiliary[++topA] = source[topS--];
                printf("Move disk %d from A to B\n", auxiliary[topA]);
            }
            else
            {
                source[++topS] = auxiliary[topA--];
                printf("Move disk %d from B to A\n", source[topS]);
            }
        }
        else
        {
            if (topA == -1)
            {
                auxiliary[++topA] = destination[topD--];
                printf("Move disk %d from C to B\n", auxiliary[topA]);
            }
            else if (topD == -1)
            {
                destination[++topD] = auxiliary[topA--];
                printf("Move disk %d from B to C\n", destination[topD]);
            }
            else if (auxiliary[topA] < destination[topD])
            {
                destination[++topD] = auxiliary[topA--];
                printf("Move disk %d from B to C\n", destination[topD]);
            }
            else
            {
                auxiliary[++topA] = destination[topD--];
                printf("Move disk %d from C to B\n", auxiliary[topA]);
            }
        }
    }

    return 0;
}