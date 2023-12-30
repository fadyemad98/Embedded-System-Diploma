/*********************Author:Eng. Fady Emad***********************/

#include <stdio.h>
#include <string.h>
#include <conio.h>

struct data
{
    int feet_dist;
    float inch_dist;

} dist1,dist2,sum;


int main()
{
    float isum=0,rsum=0,fsum=0;

    printf("Enter information for 1st distance\n");
    printf("Enter feet: ");
    scanf("%d",&dist1.feet_dist);
    printf("Enter inch: ");
    scanf("%f",&dist1.inch_dist);
    printf("Enter information for 2nd distance\n");
    printf("Enter feet: ");
    scanf("%d",&dist2.feet_dist);
    printf("Enter inch: ");
    scanf("%f",&dist2.inch_dist);
    sum.feet_dist=dist1.feet_dist+dist2.feet_dist;
    sum.inch_dist=dist1.inch_dist+dist2.inch_dist;
    if(sum.inch_dist>12)
    {
        sum.inch_dist=sum.inch_dist-12;
        ++sum.feet_dist;
    }
    printf("\nSum of distances=%d\'-%.1f\"",sum.feet_dist,sum.inch_dist);
    return 0;
}
