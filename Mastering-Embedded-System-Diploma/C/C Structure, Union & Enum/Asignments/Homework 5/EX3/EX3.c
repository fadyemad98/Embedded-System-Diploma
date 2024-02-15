/*********************Author:Eng. Fady Emad***********************/

#include <stdio.h>
#include <string.h>
#include <conio.h>
float sumreal,sumimg;
struct complex
{
    float real;
    float img;
};
struct complex EnterComplexNumber();
float SumReal(float x1,float x2);
float SumImg(float y1,float y2);
int main()
{
    struct complex n1;
    struct complex n2;
    printf("For 1st complex number\n");
    n1=EnterComplexNumber();
    printf("For 2nd complex number\n");
    n2=EnterComplexNumber();
    sumreal=SumReal(n1.real,n2.real);
    sumimg=SumImg(n1.img,n2.img);
    printf("Sum=%.1f+%.1fi",sumreal,sumimg);
    return 0;

}
struct complex EnterComplexNumber()
{
    struct complex ComplexNumber;
    printf("Enter real and imaginary respectively: ");
    scanf("%f",&ComplexNumber.real);
    scanf("%f",&ComplexNumber.img);
    printf("\n");
    return ComplexNumber;
};
float SumReal(float x1,float x2)
{
    float X=0;
    X=x1+x2;
    return X;
};
float SumImg(float y1,float y2)
{
    float Y=0;
    Y=y1+y2;
    return Y;
};
