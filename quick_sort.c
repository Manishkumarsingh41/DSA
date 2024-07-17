#include <stdio.h>
#include <sys/time.h>
#include <stdlib.h>
#include <time.h>
struct timeval t;
void swap(int *x, int *y);
int partition(int a[], int m, int n);
void quicksort(int a[], int x, int y);
int main()
{
    double start, end;
    int a[100000], i, n;
    printf("Enter the size of array\n");
    scanf("%d", &n);
    srand(time(NULL));
    printf("Array elements are randomly generated\n");
    for (i = 0; i < n; i++)
    {
        a[i] = rand() % 55;
    }
    gettimeofday(&t, NULL);
    start = t.tv_sec + (t.tv_usec / 1000000.0);
    quicksort(a, 0, n - 1);
    gettimeofday(&t, NULL);
    end = t.tv_sec + (t.tv_usec / 1000000.0);
    printf("The sorted array is - \n");
    for (i = 0; i < n; i++)
    {
        printf("%d\t", a[i]);
    }
    printf("\n");
    printf("Time taken to sort %d elements is = %lf\n", n, end - start);
    return 0;
}
void swap(int *x, int *y)
{
    int temp;
    temp = *x;
    *x = *y;
    *y = temp;
}
int partition(int a[], int m, int n)
{
    int pivot = a[m];
    int i = m;
    int j = n;
    do
    {
        do
        {
            i++;
        } while (a[i] < pivot);
        do
        {
            j--;
        } while (a[j] > pivot);
        if (i < j)
            swap(&a[i], &a[j]);
    } while (i < j);
    swap(&a[j], &a[m]);
    return j;
}
void quicksort(int a[], int x, int y)
{
    int p;
    if (x < y)
    {
        p = partition(a, x, y);
        quicksort(a, x, p - 1);
        quicksort(a, p + 1, y);
    }
}
