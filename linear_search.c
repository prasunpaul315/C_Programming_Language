#include <stdio.h>
#include <stdlib.h>

int main()
{
    int size,arr[20],flag=0,n,i;
    printf("Enter Size of Array : ");
    scanf("%d",&size);
    printf("Enter array Elements:\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    printf("Enter element for search : ");
    scanf("%d",&n);
    for(i=0;i<size;i++)
    {
        if(arr[i]==n)
        {
            flag=1;
            break;
        }
    }
    if(flag)
    {
        printf("%d has found at location %d",n,i+1);
    }
    else
    {
        printf("%d has not found",n);
    }
}
