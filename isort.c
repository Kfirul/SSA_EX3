#include <stdio.h>
#define SIZE 50

void swap(int *a,int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void shift_element(int* arr, int i){
    for (int j = i; j>0; j--) {
        swap(arr+j, arr+j+1);
    }
}

void insertion_sort(int* arr , int len){

    for(int i=0;i< len-1;i++){
        int count =0;
        if(*(arr+i)> *(arr+i+1)){
            int j=i;
            int temp=*(arr+i+1);
        while(j>-1 && *(arr+j) > *(arr+i+1)){
            count++;
            j--;
        }
        shift_element(arr+j,count);
        *(arr+j)=temp;
        }
    }
}

int main(){
 int arr[SIZE];
    
    for (int i = 0; i < SIZE ;i++)
    {
       scanf("%d",&arr[i]);
    }
    insertion_sort(arr, SIZE);

    for (int i = 0 ; i < SIZE-1 ; i++){
            printf("%d,", *(arr+i));
        }
printf("%d", *(arr+i));
printf("\n");
return 0;
}