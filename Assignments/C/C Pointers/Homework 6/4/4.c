#include<stdio.h>
int main(){
int N;
printf("Input the number of elements to store in the array (max 15) : ");
scanf("%d",&N);
int Arr[5],i;
printf("\n\nInput %d number of elements in the array : ",N);
for(i=0;i<N;i++){
    printf("\n\nelement -%d : ",i+1);
    scanf("%d",&Arr[i]);
}
printf("\n\nThe elements of array in reverse order are : \n\n");
int *Ptr_Arr=&Arr[N-1];
for(i=N;i>0;i--){
    printf("\n\nelement -%d : %d",i,*Ptr_Arr);
    Ptr_Arr--;

}

return 0;
}
