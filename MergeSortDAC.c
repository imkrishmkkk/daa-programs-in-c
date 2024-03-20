#include <stdio.h>
#include <conio.h>
int a[10];
int n;
void Merge(int start, int mid, int end)
{
    int h = start;
    int i = start;
    int j = mid + 1;
    int b[n];
    while ((h <= mid) && (j <= end))
    {
        if (a[h] <= a[j])
        {
            b[i] = a[h];
            h = h + 1;
        }
        else
        {
            b[i] = a[j];
            j = j + 1;
        }
        i = i + 1;
    }
    if (h > mid)
    {
        for (int k = j; k <= end; k++)
        {
            b[i] = a[k];
            i++;
        }
    }
    else
    {
        for (int k = h; k <= mid; k++)
        {
            b[i] = a[k];
            i++;
        }
    }
    for (int k = start; k <= end; k++)
    {
        a[k] = b[k];
    }
}
void MergeSortDAC(int start, int end)
{
    // if (start == end) then the array is already sorted
    if (start < end)
    {
        int mid = (start + end) / 2;
        MergeSortDAC(start, mid);
        MergeSortDAC(mid + 1, end);
        Merge(start, mid, end);
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
    MergeSortDAC(0, n - 1);
    printf("print Sorted Array using mergesort : ");
    printArray();
    return 0;
}