#include<stdio.h>
struct SData
{
    char employee_name[10];
    unsigned employee_ID;
};
int main()
{
    struct SData one={"Peter",1001};
    struct SData two={"Alex",1002};
    struct SData three={"Ahmed",1003};
    struct SData *Arr[3]={&one,&two,&three};
    struct SData (*(*ptr)[3])=&Arr;
    printf("\nEmployee name: %s",(**(*ptr+1)).employee_name);
    /*
                    ***************OR*************
        printf("\nEmployee name: %s",(*(*ptr+1))->employee_name);
    */
    printf("\nEmployee ID: %d",(**(*ptr)).employee_ID);
    return 0;
}
