#include <stdio.h>
#include <stdlib.h>

int position(int[],int, int);
void quick_sort(int[],int,int);
int main()
{
   int a[20],n,i,j,k;
   printf("Enter Array Size:\n");
   scanf("%d",&n);
   printf("Enter %d elements:\n",n);
   for(i=0;i<n;i++)
   {
       scanf("%d",&a[i]);
   }
   printf("Array before sorting: ");
   for(j=0;j<n;j++)
   {
       printf("%d ",a[j]);
   }
   quick_sort(a,0,n-1);
   printf("After sorting :\n");
   for(k=0;k<n;k++)
   {
       printf("%d ",a[k]);
   }
}
void quick_sort(int a[],int start, int end)
{
    int loc;
    if(start<end)
    {
        loc=position(a,start,end);
        quick_sort(a,start,loc-1);
        quick_sort(a,loc+1,end);
    }
}

int position(int a[],int start, int end)
{
    int r,l,p,temp1,temp;
    r=end;
    l=start+1;
    p=start;
    while(l<r)
    {
        while(a[l]<=a[p] && l<end)
        {
            l++;
        }
        while(a[p]<a[r] && r>start)
        {
            r--;
        }
        if(l<r)
        {
            temp=a[r];
            a[r]=a[l];
            a[l]=temp;
        }
        if(r!=p)
        {
            temp1=a[r];
            a[r]=a[p];
            a[p]=temp1;
        }
    }
    return r;
}
