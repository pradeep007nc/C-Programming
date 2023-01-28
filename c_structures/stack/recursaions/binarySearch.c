#include<stdio.h>

int binarySearch(int arr[], int start, int end, int ele){ 
    int middle = ( start + end )/2;
    if(arr[middle] == ele) return middle;
    if(arr[middle] > ele){
       return binarySearch(arr, start, middle-1, ele);
    } 
    else{
       return binarySearch(arr, middle+1, end, ele);
     }  
    return -1;
}

int main(){
    int arr[]={10,20,30,40,50,80,90};
    int ele = 20;
    int length = sizeof(arr);
    int mid = sizeof(arr)/2;
    int x = binarySearch(arr, 0, sizeof(arr), ele);
    printf("\nthe index is %d\n",x);
    return 0;
}