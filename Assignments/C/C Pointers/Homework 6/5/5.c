#include<stdio.h>
struct SData
{
    char employee_name[10];
    unsigned employee_ID;
};
int main()
{
    struct SData one={"Alex",1002};
    struct SData two={"Peter",1003};
    struct SData three={"Ahmed",1004};
    struct SData *ptr1;
    struct SData *ptr2;
    struct SData *ptr3;
    struct SData Arr[3]={*ptr1,*ptr2,*ptr3};
    struct SData *ptr=Arr;
    ptr1=&one;
    ptr2=&two;
    ptr3=&three;
    printf("Employee name:%s",ptr1->employee_name);
    printf("Employee ID:%d",ptr1->employee_name);
    return 0;
}
