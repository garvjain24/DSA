#include <stdio.h>
#include <stdlib.h>
void PrintArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ,", A[i]);
    }
}
void Selection(int *A, int n)
{
    int temp, i, j, min;
    for (i = 0; i < n; i++)
    {
        min = i;
        for (j = i + 1; j < n; j++)
        {
            if (A[min] > A[j])
                min = j;
        }
        if (min!=i)
        {
            temp=A[min];
            A[min]=A[i];
            A[i]=temp;
        }
        PrintArray(A,n);
        printf("\n");
        
    }
}
int main()
{
    int i, n;
    printf("Enter number of Elements:");
    scanf("%d", &n);
    int A[n];
    for (i = 0; i < n; i++)
    {
        printf("\n Enter %d element: ", i + 1);
        scanf("%d", &A[i]);
    }
    PrintArray(A, n);
    
    Selection(A, n);
    printf("\n\nSorted array is : ");
    PrintArray(A, n);
}