#include<stdio.h>
void PrintArray(int *A, int n)
{
    
    for (int i = 0; i < n; i++)
    {
        printf(" %d ,", A[i]);
    }
    printf("\n");
}
int partition(int *A,int low,int high){
    int temp;
    int pivot =A[low];
    int i=low+1;
    int j=high;
    do
    {
        while(A[i]<= pivot){
            i++;
        }
        while(A[j]>pivot){
            j--;
        }
        if(i<j){
            temp=A[i];
            A[i] =A[j];
            A[j]=temp;
        }
    } while (i<j);
    temp=A[low];
    A[low]=A[j];
    A[j]=temp;
    return j;
    
}
int Quicksort(int *A, int low,int high){
    if(low<high){
        int Index=partition(A,low,high);
        Quicksort(A,low,Index-1);
        Quicksort(A,Index+1,high);
    }
}
int main(){
    int i, n;
    printf("Enter number of Elements:");
    scanf("%d", &n);
    int A[n];
    for (i = 0; i < n; i++)
    {
        printf("\n Enter %d element: ", i + 1);
        scanf("%d", &A[i]);
    }
    printf("the entered Array is :");
    
    PrintArray(A, n);
    Quicksort(A,0,n-1);
    PrintArray(A, n);
    return 0;
}