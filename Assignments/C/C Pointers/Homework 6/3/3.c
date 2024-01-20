#include<stdio.h>
#include<string.h>
int main()
{
    int i;
    char input_string[20];
    printf("Input  a string: ");
    gets(input_string);
    char strln=strlen(input_string);
    char *ptr_string=&input_string[strln-1];
    printf("Reverse of the string is :");
    for(i=0; i<=strln-1; i++)
    {
        printf("%c",*ptr_string);
        ptr_string--;
    }
    return 0;
}
