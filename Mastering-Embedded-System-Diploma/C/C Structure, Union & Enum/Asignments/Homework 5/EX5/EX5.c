#include<stdio.h>
#include<conio.h>
#define pi 3.1416
int main()
{
  float area, radius;
  printf("Enter the radius: \n");
  scanf("%f",&radius);
  area=pi*radius*radius;
  printf("\nThe Area of the Circle is = %f",area);
  return 0;
}