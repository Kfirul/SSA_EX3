#include <stdio.h>
#define SIZE 50

void shift_element(int* arr, int i){

}

void insertion_sort(int* arr , int len){

}

int main(){
int arr[SIZE];
int i=0;
while(i<SIZE){
    scanf("%d",(arr+i));
    i++;
}
// insertion_sort(0,50);

for(int j=0;j<SIZE-1;j++){
    printf("%d,",*(arr+j));
}
printf("%d",*(arr+SIZE-1));
return 0;
}
