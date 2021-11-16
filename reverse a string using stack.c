#include <stdio.h>
#include <string.h>
#define max 100
int top,stack[max];

void push(char x){

      if(top == max-1)
      {
          printf("stack overflow\n");
      }
      else
      {
          stack[++top]=x;
      }
}

void pop()
{
      printf("%c",stack[top--]);
}


int main()
{
    char str[max];
    printf("Enter a string: ");
    scanf("%s", str);
    printf("Reverse of given string: ");
    int len = strlen(str);
    int i;
    for(i=0;i<len;i++)
        push(str[i]);
    for(i=0;i<len;i++)
        pop();
    printf("\n");
}
