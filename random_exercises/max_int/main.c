#include <stdio.h>
#include <stdlib.h>

void printLargest(int a, int b, int c);

int main()
{
    int a, b, c;
    printf("Input the first integer:\n");
    if(scanf("%d", &a) < 1)
    {
        printf("Error: non-integer entered!");
        return -1;
    }
    printf("Input the second integer:\n");
    if(scanf("%d", &b) < 1)
    {
        printf("Error: non-integer entered!");
        return -1;
    }
    printf("Input the third character:\n");
    if(scanf("%d", &c) < 1)
    {
        printf("Error: non-integer entered!");
        return -1;
    }
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