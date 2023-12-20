  #include <stdio.h>
int main()
{
    int n,i,ins,loc;
    printf("Enter no of elements : ");
    scanf("%d",&n);
    int mat1[n],mat2[n+1];
    for(i=0; i<n; i++)
    {
        mat1[i]=i+1;
        i-1;
    }

    for(i=0;i<n;i++)
    {
        printf("%d ",mat1[i]);
    }
    printf("\nEnter the element to be inserted : ");
    scanf("%d",&ins);
    printf("\nEnter the location : ");
    scanf("%d",&loc);
    for(i=0; i<(loc-1); i++)
    {
        mat2[i]=mat1[i];
    }
    mat2[loc-1]=ins;
    for(i=(loc-1); i<(n+1); i++)
    {
        mat2[i+1]=mat1[i];
    }
     for(i=0; i<(n+1); i++)
    {
        printf("%d ",mat2[i]);
    }

    return 0;
}

