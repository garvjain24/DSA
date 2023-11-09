#include <stdio.h>

void Linear(int *A,int n,int val){
    int i;
    for(i=0;i<n;i++){
        if(A[i]==val){
            printf("them element is at position %d",i+1);
            break;
        }
    }
}
int Binary(int *A,int left,int right,int val){
    while(left<=right){
        int mid = left+(right-left)/2;
        if (A[mid]==val){
            printf("the element is at position %d",mid+1);
            break;
        }
        else if(val>A[mid]){
            left = mid +1;
        }
        else{
            right = mid -1;
        }
    }
    return -1;
}
void main(){
    int i,n, value;
    printf("Enter number of Elements: ");
    scanf("%d", &n);
    int A[n];
    for (i = 0; i < n; i++) {
        printf("\nEnter %d element: ", i + 1);
        scanf("%d", &A[i]);
    }
    printf("enter value to search:");
    scanf("%d",&value);
    //Linear(A,n,value);
    Binary(A,0,n-1,value);
}