#include <stdio.h>
static long int c = 0;
void main()
{
    void toh(int, char, char, char);
    int n;
    printf("enter the no of disc\n");
    scanf("%d", &n);
    toh(n, 'A', 'B', 'C');
    printf("%d", c);
}
void toh(int n, char A, char B, char C)
{
    c++;
    if (n == 1)
    {
        printf("Move %c to %c\n", A, B);
    }
    else
    {
        toh(n - 1, A, C, B);
        printf("move %c to %c\n", A, B);
        toh(n - 1, C, B, A);
    }
}
