#include <stdio.h>
void heapSort(int a[], int n);
void heapify(int a[], int i, int s);
void swap(int *a, int *b);
void print(int a[], int s);
int i = 0;
void main()
{
    int a[] = {3, 2, 5, 2, 5, 7, 2, 1, 4, 1};
    printf("Array Before Sort\n");
    print(a, 10);
    heapSort(a, 10);
    printf("\nArray After Sort\n");
    print(a, 10);
}
void heapSort(int a[], int s)
{
    for (i = s / 2 - 1; i >= 0; i--)
    {
        heapify(a, i, 10);
    }
    for (int i = s - 1; i >= 0; i--)
    {
        swap(&a[0], &a[i]);
        heapify(a, 0, i);
    }
}
void heapify(int a[], int i, int s)
{
    int max = i;
    int left = i * 2;
    int right = i * 2 + 1;
    if (left < s && a[max] < a[left])
    {
        max = left;
    }
    if (right < s && a[max] < a[right])
    {
        max = right;
    }
    if (max != i)
    {
        swap(&a[max], &a[i]);
        heapify(a, max, s);
    }
}
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void print(int a[], int s)
{
    for (i = 0; i < s; i++)
    {
        printf("%d  ", a[i]);
    }
}