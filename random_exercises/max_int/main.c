#include <stdio.h>
#include <stdlib.h>

void printLargest(int a, int b, int c);
int getIntegers(int* a, int* b, int* c);
int checkInput(int *i);

int main()
{
    int a, b, c;
    if(getIntegers(&a, &b, &c) == -1) return -1;
    printLargest(a, b, c);
    return 0;
}

int getIntegers(int* a, int* b, int* c){
    printf("Input the first integer:\n");
    if(checkInput(a) == -1) return -1;
    printf("Input the second integer:\n");
    if(checkInput(b) == -1) return -1;
    printf("Input the third character:\n");
    if(checkInput(c) == -1) return -1;
    return 0;
}

int checkInput(int* i){
    if(scanf("%d", i) < 1)
    {
        printf("Error: non-integer entered!");
        return -1;
    }
    return 0;
}

void printLargest(int a, int b, int c)
{
    if(a > b && a > c)
        printf("The largest integer is: %d", a);
    else if (b > a && b > c)
        printf("The largest integer is: %d", b);
    else
        printf("The largest integer is: %d", c);
}