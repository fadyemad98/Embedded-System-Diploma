#include <stdio.h>
int main()
{
    int i,j;
    float mat1[2][2],mat2[2][2],sum[2][2];
    printf("Enter the elements of 1st matrix\n");
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("Enter a[%d][%d]: ",++i,++j);
            --i;
            --j;
            scanf("%f",&mat1[i][j]);
        }
    }

    printf("\nEnter the elements of 2nd matrix\n");
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            printf("Enter a[%d][%d]: ",++i,++j);
            --i;
            --j;
            scanf("%f",&mat2[i][j]);
        }
    }
    printf("\nSum Of Matrix: ");
    for(i=0; i<2; i++)
    {
        for(j=0; j<2; j++)
        {
            sum[i][j]=mat1[i][j]+mat2[i][j];
        }
    }
    printf("\n");
    for(i=0; i<2; i++)
    {
        if (i==1)
            printf("\n");
        for(j=0; j<2; j++)
        {
            printf("%.1f\t",sum[i][j]);

        }
    }
    return 0;
}
