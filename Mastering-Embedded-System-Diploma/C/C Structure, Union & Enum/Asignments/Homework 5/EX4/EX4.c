/*********************Author:Eng. Fady Emad***********************/

#include <stdio.h>
#include <string.h>
#include <conio.h>

struct data
{
    char name[10];
    int roll;
    float marks;

};
int main()
{
    int i;
    struct data students[3];
    printf("Enter information of students:\n\n");
    for(i=0; i<3; i++)
    {
        students[i].roll=i+1;
        printf("For roll number %d",students[i].roll);
        printf("\nEnter name: ");
        scanf("%s",students[i].name);
        printf("Enter marks: ");
        scanf("%f",&students[i].marks);
        printf("\n\n");
    }
    printf("Displaying information of students: \n\n");
    for(i=0; i<3; ++i)
    {

        printf("Information for roll number %d:\n",i+1);
        printf("Name: %s\n",students[i].name);
        printf("Marks: %.1f\n",students[i].marks);

    }
    return 0;
}

