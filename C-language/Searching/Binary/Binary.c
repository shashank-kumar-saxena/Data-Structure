#include <stdio.h>
#include <conio.h>
int search(int a[], int search);
void main()
{
    int num;
    int a[] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};
    printf("Enter the number you want to search\n");
    scanf("%d", &num);
    if (search(a, num))
        printf("Number Present");
    else
        printf("Number not present");
}
int search(int a[], int search)
{
    int l = 0, u = 10, m;
    while (l < u)
    {
        m = (l + u) / 2;
        if (a[m] == search)
            return (1);
        else if (search > a[m])
        {
            l = m;
        }
        else if (search < a[m])
        {
            u = m;
        }
    }
    return (0);
}