#include <stdio.h>
#include <conio.h>
int arr[10];
void BinarySearchDAC(int arr[], int lb, int ub, int x)
{
    if (lb == ub)
    {
        if (arr[lb] == x)
        {
            printf("Successful search found at location %d : ", lb);
        }
        else
        {
            printf("value not found unsuccessful search.");
        }
    }
    else
    {
        int mid = (lb + ub) / 2;
        if (arr[mid] == x)
        {
            printf("Successful search value x found at location %d: ", mid);
        }
        else if (x < arr[mid])
        {
            return BinarySearchDAC(arr, lb, mid - 1, x);
        }
        else
        {

            return BinarySearchDAC(arr, mid + 1, ub, x);
        }
    }
}
void printArray(int arr[], int n)
{
    for (int i = 0; i < n; i++)
    {
        printf("%d ", arr[i]);
    }
    printf("\n");
}
int main()
{
    printf("enter the size of array less than 10 : ");
    int n;
    scanf("%d", &n);
    if (n > 10)
    {
        printf("Size should be less than 10.\n");
        return 1;
    }
    int arr[n];
    printf("Enter the array elements : ");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", &arr[i]);
    }
    printf("print the Original array : ");
    printArray(arr, n);
    int x;
    printf("enter element to search : ");
    scanf("%d", &x);
    int lb = 0;
    int ub = n-1;
    BinarySearchDAC(arr, lb, ub, x);
    return 0;
}
