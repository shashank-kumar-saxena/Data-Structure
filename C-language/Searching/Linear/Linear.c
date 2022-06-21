#include <stdio.h>
#include <conio.h>
int search(int a[], int search);
void main()
{
    int num;
    int a[] = {1, 4, 6, 2, 8, 3, 9, 6, 2, 5, 4, 7, 8, 9, 10};
    printf("Enter the number you want to search\n");
    scanf("%d", &num);
    if (search(a, num))
        printf("Number Present");
    else
        printf("Number not present");
}
int search(int a[], int search)
{
    int i = 0;
    for (i = 0; i < 15; i++)
    {
        if (a[i] == search)
            return (1);
    }
    return (0);
}