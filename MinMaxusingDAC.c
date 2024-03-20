#include <stdio.h>
#include <conio.h>
int a[10];
int min, max;
void MinMaxDAC(int i, int l)
{
    int min1, max1, mid;
    if (i == l)
    {
        max = min = a[i];
    }
    else
    {
        if (i == l - 1)
        {
            if (a[i] < a[l])
            {
                min = a[i];
                max = a[l];
            }
            else
            {
                min = a[l];
                max = a[i];
            }
        }
        else
        {
            mid = (i + l) / 2;
            MinMaxDAC(i, mid);
            max1 = max;
            min1 = min;
            MinMaxDAC(mid + 1, l);
            if (max < max1)
            {
                max = max1;
            }
            if (min > min1)
            {
                min = min1;
            }
        }
    }
}
int main()
{
    int n;
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
    printf("print array : ");
    for (int i = 0; i < n; i++)
    {
        printf("%d ", a[i]);
    }
    printf("\n");
    min = max = a[0];

    MinMaxDAC(0, n - 1);
    printf("max element in  array : %d\n ", max);
    printf("min element in array : %d\n", min);
    return 0;
}