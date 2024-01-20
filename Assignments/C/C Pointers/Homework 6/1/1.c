#include<stdio.h>
int main(){
int m=29;
printf("Address of m: 0x%p",&m);
printf("\n\nvalue of m: %d",m);
int *ab=&m;
printf("\n\n\nNow ab is assigned with the address of m.");
printf("\n\nAddress of ab: 0x%p",ab);
printf("\n\nvalue of ab: %d",*ab);
printf("\n\n\nThe value of m assigned to 34 now.");
*ab=34;
printf("\n\nAddress of ab: 0x%p",ab);
printf("\n\nvalue of ab: %d",*ab);
printf("\n\n\nThe pointer variable ab is assigned with the value 7 now.");
*ab=7;
printf("\n\nAddress of m: 0x%p",&m);
printf("\n\nvalue of m: %d",m);
return 0;
}
