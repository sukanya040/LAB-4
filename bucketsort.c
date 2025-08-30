#include<stdio.h>
#include<stdlib.h>
#define MAX 100
void insertionsort(int arr[],int n){
    int i,key,j;
    for(i=1;i<n;i++){
        key=arr[i];
        j=i-1;
        while(j>=0&&arr[j]>key){
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=key;
    }
}
void bucketsort(int arr[],int n){
    int i,j,k;
    int max=arr[0];
    for(i=1;i<n;i++){
        if(arr[i]>max)
            max=arr[i];
    }
    int bucketcount=max/10+1;
    int* buckets[bucketcount];
    int bucketsizes[bucketcount];
    for(i=0;i<bucketcount;i++){
        buckets[i]=(int*)malloc(n*sizeof(int));
        bucketsizes[i]=0;
    }
    for(i=0;i<n;i++){
        int bi=arr[i]/10;
        buckets[bi][bucketsizes[bi]++]=arr[i];
    }
    for(i=0;i<bucketcount;i++){
        if(bucketsizes[i]>0){
            insertionsort(buckets[i],bucketsizes[i]);
        }
    }
     k=0;
    for(i=0;i<bucketcount;i++){
        for(j=0;j<bucketsizes[i];j++){
            arr[k++]=buckets[i][j];
        }
        free(buckets[i]);
    }   
}
int main(){
    int arr[MAX],n,i;
    printf("Enter n value:\n");
    scanf("%d",&n);
    printf("Enter array elements:\n");
    for(i=0;i<n;i++){
        scanf("%d",&arr[i]);
    }
    bucketsort(arr,n);
    printf("Sorted array elements:\n");
    for(i=0;i<n;i++){
        printf("%d\n",arr[i]);
    }
    printf("\n");
    return 0;
}