#include <stdio.h>
#include <stdlib.h>
void PrintArray(int *A, int n)
{
    for (int i = 0; i < n; i++)
    {
        printf(" %d ,", A[i]);
    }
}
void Insertion(int *A, int n)
{
    int key, i, j;
    for (i = 0; i < n; i++){
        key = A[i];
    j = i - 1;
    while (j >= 0 && key < A[j])
    {
        A[j + 1] = A[j];
        j--;
    }
    A[j + 1] = key;
    }
    printf("\n\nSorted array is : ");
    PrintArray(A, n);
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

    Insertion(A, n);
    
}