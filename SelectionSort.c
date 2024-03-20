#include <stdio.h>
int a[10];
int n;
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}
void SelectionSort(int a[], int start, int end)
{
    int i, j, min;
    for (i = start; i < end - 1; i++)
    {
        min = i;
        for (j = i + 1; j < end; j++)
        {
            if (a[j] < a[min])
            {
                min = j;
            }
        }
        swap(&a[i], &a[min]);
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
    SelectionSort(a, 0, n);
    printf("print Sorted Array  using Selectionsort : ");
    printArray();
    return 0;
}