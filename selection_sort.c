#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[20],min,i,j,size,temp,loc;
    printf("Enter size of Array : ");
    scanf("%d",&size);
    printf("Enter Array Elements :\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=0;i<(size-1);i++)
    {
        min=arr[i];
        loc=i;
        for(j=i+1;j<size;j++)
        {
            if(arr[j]<min)
            {
                min=arr[j];
                loc=j;
            }
        }
        temp=arr[i];
        arr[i]=arr[loc];
        arr[loc]=temp;
    }
    printf("After Selection Sort :\n");
    for(i=0;i<size;i++)
    {
        printf("%d ",arr[i]);
    }
}
