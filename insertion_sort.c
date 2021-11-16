#include <stdio.h>
#include <stdlib.h>

int main()
{
    int arr[20],i,j,size,temp;
    printf("Enter Array size : ");
    scanf("%d",&size);
    printf("Enter Array elements :\n");
    for(i=0;i<size;i++)
    {
        scanf("%d",&arr[i]);
    }
    for(i=1;i<size;i++)
    {
        temp=arr[i];
        j=i-1;
        while(j>=0 && arr[j]>temp)
        {
            arr[j+1]=arr[j];
            j--;
        }
        arr[j+1]=temp;
    }
    printf("After InsertionSort :\n");
    for(i=0;i<size;i++)
    {
        printf("%d\t",arr[i]);
    }
}
