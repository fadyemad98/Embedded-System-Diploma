#include<stdio.h>
int main(){
char a[1000];
int i;
printf("Enter a string: ");
scanf("%s",&a);
for (i=0;a[i]!='\0';i++);
printf("Length of string: %d ",i);
return 0;
}
