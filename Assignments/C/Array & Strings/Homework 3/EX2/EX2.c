#include<stdio.h>
int main()
{
    int n,i,j;
    printf("Enter the numbers of data: ");
    scanf("%d",&n);
    float arr[n],sum=0,avrg;
    for(i=0,j=1;i<n,j<=n;i++,j++)
    {
        printf("\n%d. Enter number: ",j);
        scanf("%f",&arr[i]);
        sum=sum+arr[i];

    }
    avrg=sum/n;
    printf("\nAverage = %.2f",avrg);
    return 0;
}
