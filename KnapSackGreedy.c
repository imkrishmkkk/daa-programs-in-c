#include <stdio.h>

int max(int a, int b) {
    return (a > b) ? a : b;
}

int knapsack(int W, int wt[], int val[], int n) {
    if (n == 0 || W == 0)
        return 0;

    if (wt[n - 1] > W)
        return knapsack(W, wt, val, n - 1);

    else
        return max(val[n - 1] + knapsack(W - wt[n - 1], wt, val, n - 1),
                   knapsack(W, wt, val, n - 1));
}

int main() {
    int val[100], wt[100], W, n;
    
    printf("Enter the number of items: ");
    scanf("%d", &n);
    
    printf("Enter the values of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &val[i]);
    }
    
    printf("Enter the weights of the items:\n");
    for (int i = 0; i < n; i++) {
        scanf("%d", &wt[i]);
    }
    
    printf("Enter the maximum weight capacity of the knapsack: ");
    scanf("%d", &W);
    
    printf("Maximum value that can be obtained is %d\n", knapsack(W, wt, val, n));
    return 0;
}
