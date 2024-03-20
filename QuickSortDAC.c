#include <stdio.h>
#include <conio.h>
int a[10];
int n;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
int partition(int a[], int start, int end)
{
    int pivot = a[start];
    int i = start;
    int j = end;
    while (i < j)
    {
        while (a[i] <= pivot && i < end)
            i++;
        while (a[j] > pivot)
            j--;
        if (i < j)
            swap(&a[i], &a[j]);
    }
    swap(&a[start], &a[j]);
    return j;
}
void QuickSortDAC(int a[], int start, int end)
{
    // if start==end then array is sorted because there is one  element in array
    if (start < end)
    {
        int j = partition(a, start, end);
        QuickSortDAC(a, start, j - 1);
        QuickSortDAC(a, j + 1, end);
    }
}
void printArray()
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
}
int main()
{

    printf("enter the size of array less than 10 : ");
    scanf("%d", &n);
    if (n > 10)
    {
        printf("Size should be less than 10.\n");
        return 1;
    }
    printf("Enter the array elements : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &a[i]);
    }
    printf("print the Original array : ");
    printArray();
    QuickSortDAC(a, 0, n - 1);
    printf("print Sorted Array using Quicksort : ");
    printArray();
    return 0;
}