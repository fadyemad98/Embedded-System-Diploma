/*********************Author:Eng. Fady Emad***********************/
#include <stdio.h>
#include <string.h>
#include <conio.h>
struct Sstudent
{
    char name[10];
    int roll;
    float marks;

};
int main()
{
    struct Sstudent variable;

        printf("Enter information of students: \n\n");
        printf("Enter name: ");
        scanf("%s",&variable.name);
        printf("Enter roll number: ");
        scanf("%d",&variable.roll);
        printf("Enter marks: ");
        scanf("%f",&variable.marks);
        printf("\n");
        printf("Displaying information:\n");

            printf("name: %s\n",variable.name);
            printf("Roll: %d\n",variable.roll);
            printf("Marks: %.2f\n",variable.marks);

    return 0;
}
