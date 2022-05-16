#include<stdio.h>
#include<conio.h>
void main()
{
    int a[10] = {1, 41, 6, 3, 7, 7, 75, 3, 63, 12};
    void bubble(int[], int);
    void print(int[]);
    clrscr();
    printf("\nArray Before sort\n");
    print(a);
    bubble(a, 10);
    printf("\nArray After sort\n");
    print(a);
    getch();
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
}
void print(int a[])
{
 int i;
 for (i = 0; i < 10; i++)
    {
	printf("%d ", a[i]);
    }
}