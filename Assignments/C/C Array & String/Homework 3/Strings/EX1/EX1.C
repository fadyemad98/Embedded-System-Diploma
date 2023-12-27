#include<stdio.h>
int main()
{
    int i,count=0;
    char string[30],c[1];
    printf("Enter a string: ");
    gets(string);
    printf("Enter a character to find frequency: ");
    scanf("%c",&c[0]);
    for (i=0;i<sizeof(string);i++)
    {
        {
            if(string[i]==c[0])
            {
                count=count+1;
            }
        }
    }
    printf("Frequency of %c = %d",c[0],count);
    return 0;
}
