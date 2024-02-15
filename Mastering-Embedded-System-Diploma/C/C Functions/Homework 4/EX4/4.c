#include<stdio.h>
void powerf(unsigned base,unsigned power,unsigned result,unsigned counter)
{
    result*=base;
    counter++;
    if(counter<power)
        powerf(base,power,result,counter);

    if (counter==(power))
        printf("%d^%d= %d",base,power,result);
}
int main()
{
    unsigned int base,power,result=1,counter=0 ;
    printf("Enter base number: ");
    scanf("%d",&base);
    printf("Enter power number(positive only): ");
    scanf("%d",&power);
    powerf(base,power,result,counter);

    return 0;
}
