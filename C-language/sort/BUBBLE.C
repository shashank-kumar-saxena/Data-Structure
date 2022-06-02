#include <stdio.h>
void insert(int a[], int size);
int n, i;
void main()
{
    printf("Enter the size of array\n");
    scanf("%d", &n);
    int arr[n];
    insert(arr, n);
}
void insert(int a[], int size)
{
    printf("Enter the element in array one by one\n");
    for (i = 0; i < size; i++)
    {
        scanf("%d", a[i]);
    }
}