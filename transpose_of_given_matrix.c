#include <stdio.h>
#include <stdlib.h>

main()
{
   int a[3][3],b[3][3],i,j;
   printf("Enter value for Matrix\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            scanf("%d",&a[i][j]);
        }
    }
    printf("\nGiven Matrix :\n");
     for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("\t%d",a[i][j]);
        }
        printf("\n");
    }
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            b[i][j]=a[j][i];
        }
    }
    printf("\nTranspose of the Matrix is :\n");
    for(i=0;i<3;i++)
    {
        for(j=0;j<3;j++)
        {
            printf("\t%d",b[i][j]);
        }
        printf("\n");
    }

}
