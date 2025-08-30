#include<stdio.h>
#define MAX 100
void merge(int arr[],int left,int mid,int right){
    int leftarr[MAX],rightarr[MAX];
    int i,j,k,n1,n2;
    n1=mid-left+1;
    n2=right-mid;
    for(i=0;i<n1;i++){
        leftarr[i]=arr[left+i];
    }
    for(j=0;j<n2;j++){
        rightarr[j]=arr[mid+1+j];
    }
    i=0;
    j=0;
    k=left;
    while(i<n1 && j<n2){
        if(leftarr[i]<= rightarr[j]){
            arr[k]=leftarr[i];
            k++; i++;
        }
        else{
            arr[k]=rightarr[j];
            k++;j++;
        }
    }
    while(i<n1){
        arr[k]=leftarr[i];
        k++; i++;
    }
    while(j<n2){
        arr[k]=rightarr[j];
        k++; j++;
    }
}
void mergesort(int arr[],int left,int right){
    if(left<right){
        int mid=(right-left)/2;
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);
        merge(arr,left,mid,right);
    }
}
void main(){
    int arr[MAX];
    int n,i;
    printf("Enter n value:\n");
    scanf("%d",&n);
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    mergesort(arr,0,n-1);
    printf("Sorted array:\n");
    for(i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
    printf("\n");
}