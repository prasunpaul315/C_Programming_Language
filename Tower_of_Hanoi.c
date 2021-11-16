#include<stdio.h>
#include<stdlib.h>

void towers(int, char, char, char );

void main()
{
   int n;
   printf("Enter Number of disks: ");
   scanf("%d",&n);
   printf("\nSequence of move in Tower of Hanoi\n");
   towers(n,'S','D','A');
}

void towers(int num, char  s, char  d, char  a)
{
    if(num==1)
    {
        printf("Move disk 1 from %c to %c\n",s,d);
        return;
    }
    towers(num-1,s,a,d);
    printf("Move disk %d from %c to %c\n",num,s,d);
    towers(num-1,a,d,s);
}
