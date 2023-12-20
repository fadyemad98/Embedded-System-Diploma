#include <stdio.h>
int main()
{
    int r,c,i,j;
    printf("Enter row and column of matrix: ");
    scanf("%d %d",&r,&c);
    int mat[r][c];
    int trans[c][r];
    printf("Enter elements of matrix: \n");
    for(i=0; i<r; i++)
    {
        for (j=0; j<c; j++)
        {
            printf("Enter elements a[%d][%d]: ",++i,++j);
            --i;
            --j;
            scanf("%d",&mat[i][j]);

        }
    }
    printf("Entered Matrix: \n");
    for(i=0; i<r; i++)
    {
        if(i==r/2)
        {
            printf("\n\n");
        }
        for (j=0; j<c; j++)
        {
            printf("%d\t",mat[i][j]);

        }
    }
    for(i=0; i<r; i++)
    {
        for (j=0; j<c; j++)
        {
           trans[j][i]= mat[i][j];
        }
    }
    printf("\n\n Transpose of Matrix: \n");

    for(j=0; j<c; ++j)
    {
        if(j>0)
            printf("\n\n");

        for(i=0; i<r; ++i)
        {


            printf("%d\t",trans[j][i]);

        }
    }
    return 0;
}
