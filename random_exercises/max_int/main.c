#include <stdio.h>
#include <stdlib.h>

void printLargest(int a, int b, int c);

int main()
{
    int a, b, c;
    printf("Input the first integer:\n");
    scanf("%d", &a);
    printf("Input the second integer:\n");
    scanf("%d", &b);
    printf("Input the third character:\n");
    scanf("%d", &c);
    printLargest(a, b, c);
    return 0;
}

void printLargest(int a, int b, int c)
{
    if(a > b && a > c)
    {
        printf("The largest integer is: %d", a);
    }
    else if (b > a && b > c)
    {
        printf("The largest integer is: %d", b);
    }
    else
    {
        printf("The largest integer is: %d", c);
    }
}