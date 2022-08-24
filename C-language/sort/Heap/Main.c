#include <stdio.h>
#include <conio.h>
void heapSort(int a[], int size)
{
    int i = 0;
    for (i = (size - 1) / 2; i >= 0; i--)
    {
        heapify(a, i, size);
    }
    for (int i = size - 1; i >= 0; i--)
    {
        swap(&a[0], &a[i]);
        heapify(a, 0, i);
    }
}
void heapify(int a[], int i, int size)
{
    int max = i;
    int left = 2 * i;
    int right = 2 * i + 1;
    if (left < size && a[left] > a[max])
    {
        max = left;
    }
    if (right < size && a[right] > a[max])
    {
        max = right;
    }
    if (max != i)
    {
        swap(&a[i], &a[max]);
        heapify(a, max, size);
    }
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void main()
{
    int a[] = {4, 6, 5, 2, 8, 3, 2, 9, 1, 7};
    printf("Array Before Swap\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
    heapSort(a, 10);
    printf("\nArray Before Swap\n");
    for (int i = 0; i < 10; i++)
    {
        printf("%d ", a[i]);
    }
}