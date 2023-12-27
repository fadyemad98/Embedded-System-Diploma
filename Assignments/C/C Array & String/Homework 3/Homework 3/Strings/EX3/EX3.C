#include<stdio.h>
#include<string.h>
int main()
{
    char s[1000],p[1000],length,i;
    printf("Enter the string : ");
    scanf("%s",&s);
    length=strlen(s);
    printf("Reverse string is : ");
    for(i=length-1;i>=0;i--)
    {
        printf("%c",s[i]);
    }
    return 0;
}
