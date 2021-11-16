#include <stdio.h>
#include <stdlib.h>

int main()
{
    int i,j,arr[20],size,temp,swap;
    printf("Enter Array size : ");
    scanf("%d",&size);
    printf("Enter Array elements :\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<size-1;i++)
    {
        swap=0;
        for(j=0;j<(size-1)-1;j++)
        {
            if(arr[j]>arr[j+1])
            {
                temp=arr[j];
                arr[j]=arr[j+1];
                arr[j+1]=temp;
                swap=1;
            }
        }
        if(swap==0)
        {
            break;
        }
    }
    printf("After BubbleSort :\n");
    for(i=0;i<size;i++)
    {
        printf("%d\t",arr[i]);
    }
}

