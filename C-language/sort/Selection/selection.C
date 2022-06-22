#include <stdio.h>
void swap(int *a, int *b);
void selectionSort(int a[], int s);
void printArray(int a[], int s);
int i, j;
int main()
{
  int a[] = {1, 3, 4, 2, 5};
  int size = 5;

  printf("Array before sort\n");
  printArray(a, size);
  selectionSort(a, size);
  printf("Sorted array in Acsending Order:\n");
  printArray(a, size);
  return (0);
}

void swap(int *a, int *b)
{
  int temp = *a;
  *a = *b;
  *b = temp;
}

void selectionSort(int a[], int s)
{
  for (j = 0; j < s; j++)
  {
    int min = j;
    for (i = j + 1; i < s; i++)
    {
      if (a[i] < a[min])
        min = i;
    }
    swap(&a[min], &a[j]);
  }
}
void printArray(int a[], int s)
{
  for (i = 0; i < s; ++i)
  {
    printf("%d  ", a[i]);
  }
  printf("\n");
}
