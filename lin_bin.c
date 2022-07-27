#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void linear_search(int arr[], int index, int last, int key){
    if(index>last){ 
        printf("Element not found\n");
        return;
    }
    
    if(arr[index]==key){
        printf("Element found at position %d\n",index);
        return;
    }
    
    linear_search(arr,index+1,last,key);
}

void binary_search(int arr[], int low, int high, int key){
    if(low>high){
        printf("Element not found\n");
        return;
    }
    
    int mid = (low+high)/2;
    if(arr[mid]==key){
        printf("Element found at position %d\n",mid);
    }
    else if(arr[mid]>key){
        binary_search(arr,low,mid-1,key);
    }
    else{
        binary_search(arr,mid+1,high,key);
    }
}


int pivot_position(int arr[],int low, int high){
    
    int pivot = arr[low];
    int i=low;
    int j=high;
    
    while(i<j){
        // Move ahead till value is less than pivot
        while(arr[i]<=pivot && i<=high){
            i++;
        }
        
        // Move ahead till value is greater than pivot
        while(arr[j]>pivot && j>=low){
            j--;
        }
        
        // point of violation: swap the values that cause the violation
        if(i<j){
            int temp=arr[i];
            arr[i]=arr[j];
            arr[j]=temp;
        }
    }
    
    // While traversing if i>j, it means we have found pivot position(j), so swap pivot with a[j];
    arr[low] = arr[j];
    arr[j] = pivot;
    // returning j as the pivot position
    return j;
    
}

void quickSort(int arr[],int low,int high){
    if(low<high){
        int pivot = pivot_position(arr,low,high);
        quickSort(arr,low,pivot-1);
        quickSort(arr,pivot+1,high);
    }
}



void main(){
    clock_t start1,end1,start2,end2;
    int n,key,choice;
    printf("Enter number of elements\n");
    scanf("%d",&n);
    
    int arr[n];
    
    // printf("Enter the elements of the array\n");
    // for(int i=0;i<n;i++){
    //     scanf("%d",&arr[i]);
    // }
    
    // For random input
    for(int i=0;i<n;i++){
        arr[i]=(random()%1000);
    }
    printf("elements are:");
    for(int i=0;i<n;i++){
       printf("\t%d\t",arr[i]);
    }
    
    printf("Enter the  element you want to search\n");
    scanf("%d",&key);
    
    do{
        printf("Enter 1 to perform linear_search\n");
        printf("Enter 2 to perform binary_search\n");
        printf("Enter 3 to exit\n");
        scanf("%d",&choice);
    
    
        switch(choice){
            case 1: start1 = clock();
                    linear_search(arr,0,n-1,key);
                    end1 = clock();
                    printf("time taken %f \n",difftime(end1,start1)/CLOCKS_PER_SEC);
                    break;
            case 2: quickSort(arr,0,n-1);
                    start2 = clock();
                    binary_search(arr,0,n-1,key);
                    end2 = clock();
                    printf("time taken %f\n ",difftime(end2,start2)/CLOCKS_PER_SEC);
                    break;
            case 3: printf("Exiting..");
                    break;
        }
        
    }while(choice!=3);
}
