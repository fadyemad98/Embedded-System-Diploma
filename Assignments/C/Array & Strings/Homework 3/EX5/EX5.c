#include <stdio.h>
int main()
{
    int n,i,b=11,srch[1];
    printf("Enter no of elements : ");
    scanf("%d",&n);
    int mat[n];
    printf("\n");

    for(i=0; i<n; i++)
    {
        mat[i]=b*(i+1);
    }
    for(i=0; i<n; i++)
    {
        printf("%d ",mat[i]);
    }
    printf("\n\n");
    printf("Enter the elements to be searched : ");
    scanf("%d",&srch);
    for(i=0; i<n; i++)
    {
        if(mat[i]==srch[0])
        {
            printf("Number found at the location = %d",i+1);
            //break;
        }
    }

    return 0;
}
