#include<stdio.h>
//factorial of number using recursion.
unsigned int Get_factorial(unsigned int number)
{
    unsigned int result=0;
    if(number==0)
    {
        result=1;
    }
    else
    {
        result=number*Get_factorial(number-1);
    }
    return result;
}
int main()
{
    int number;
    printf("enter a number to get its factorial: ");
    scanf("%d",&number);
    printf("\nfactorial of %d is: %d\n",number,Get_factorial(number));

    return 0;
}
