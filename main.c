#include <stdio.h>
#include <stdlib.h>

int main()
{
   int x,y,z,arr[20],loc,temp,min,high,key,n,low,i,mid,flag=0;
   printf("Enter Array Size : ");
   scanf("%d",&n);
   printf("Enter %d elements :\n",n);
   for(i=0;i<n;i++)
   {
       scanf("%d",&arr[i]);
   }
   for(x=0;x<n-1;x++)
   {
       min=arr[x];
       loc=x;
       for(y=x+1;y<n;y++)
       {
           if(arr[y]<min)
           {
               min=arr[y];
               loc=y;
           }
       }
       temp=arr[x];
       arr[x]=arr[loc];
       arr[loc]=temp;

   }
   printf("In Sorted Form :\n");
   for(i=0;i<n;i++)
   {
       printf("%d\t",arr[i]);
   }
   printf("\n");



   printf("Enter value to be Search : ");
   scanf("%d",&key);
   high=n-1;
   low=0;
   while(low<=high)
   {
       mid=(high+low)/2;
       if(key==arr[mid])
       {
           flag=1;
           break;
       }
       else if(key>arr[mid])
       {
           low=mid+1;
       }
       else
       {
           high=mid-1;
       }
   }
   if(flag==1)
   {
       printf("%d has found at Location %d",key,mid+1);
   }
   else
   {
       printf("%d has not found",key);
   }
}







