#include <stdio.h>
int main()
{
    int a[10] = {1, 2, 3, 4, 5, 7, 8, 9, 10};
    void bubble(int[], int);
    bubble(a, 10);
}
void bubble(int a[], int size)
{
    int i, j, flag = 1;
    for (i = 1; i < size && flag; i++)
    {
        flag = 0;
        for (j = 0; j < (10 - i); j++)
        {
            if (a[j] > a[j + 1])
            {
                int temp = a[j];
                a[j] = a[j + 1];
                a[j + 1] = temp;
                flag = 1;
            }
        }
    }
    for (i = 0; i < 10; i++)
    {
        printf("%d,", a[i]);
    }
}