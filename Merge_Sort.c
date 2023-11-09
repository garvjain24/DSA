#include <stdio.h>

void PrintArray(int *A, int n) {
    for (int i = 0; i < n; i++) {
        printf(" %d ,", A[i]);
    }
    printf("\n");
}

void Merge(int *A, int low, int high, int mid) {
    int i, j, k;
    int n1 = mid - low + 1;
    int n2 = high - mid;
    int L[n1], R[n2];

    for (i = 0; i < n1; i++) {
        L[i] = A[low + i];
    }

    for (j = 0; j < n2; j++) {
        R[j] = A[mid + 1 + j];
    }

    i = 0;
    j = 0;
    k = low;

    while (i < n1 && j < n2) {
        if (L[i] <= R[j]) {
            A[k] = L[i];
            i++;
        } else {
            A[k] = R[j];
            j++;
        }
        k++;
    }

    while (i < n1) {
        A[k] = L[i];
        i++;
        k++;
    }

    while (j < n2) {
        A[k] = R[j];
        j++;
        k++;
    }
}

void MergeSort(int *A, int low, int high) {
    if (low < high) {
        int mid = low + (high - low) / 2;
        MergeSort(A, low, mid);
        MergeSort(A, mid + 1, high);
        Merge(A, low, high, mid);
    }
}

int main() {
    int i, n;
    printf("Enter number of Elements: ");
    scanf("%d", &n);
    int A[n];

    for (i = 0; i < n; i++) {
        printf("\nEnter %d element: ", i + 1);
        scanf("%d", &A[i]);
    }

    printf("The entered Array is: ");
    PrintArray(A, n);

    printf("The Sorted Array is: ");
    MergeSort(A, 0, n - 1);
    PrintArray(A, n);

    return 0;
}
