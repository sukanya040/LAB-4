#include<stdio.h>
#define MAX 100
void swap(int* a,int* b){
    int temp;
    temp=*a;
    *a=*b;
    *b=temp;
}
int partition(int arr[],int low,int high){
    int p,i,j;
    p=arr[low];
    i=low;
    j=high;
    while(i<j){
        while(arr[i]<=p && i<=high-1){
            i++;
        }
        while(arr[j]>p&&j>=low+1){
            j--;
        }
        if(i<j){
            swap(&arr[i],&arr[j]);
        }
    }
    swap(&arr[low],&arr[j]);
    return j;
}
void quicksort(int arr[],int low,int high){
    if(low<high){
        int pivotindex = partition(arr,low,high);
        quicksort(arr,low,pivotindex-1);
        quicksort(arr,pivotindex+1,high);
    }
}
void main(){
    int arr[MAX];
    int n,i;
    printf("Enter n value:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d", &arr[i]);
    }
    quicksort(arr,0,n-1);
    printf("Array after sorting:\n");
    for(i=0;i<n;i++){
        printf("%d\n", arr[i]);
    }
    printf("\n");
}