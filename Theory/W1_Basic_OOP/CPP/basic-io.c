#include <stdio.h>
int main() {
int a, b, sum;
char str[16];
printf("Enter number 1: ");
scanf("%d", &a);
printf("Enter number 2: ");
scanf("%d", &b);
printf("Enter a string: ");
scanf("%s", str);
sum = a + b;
printf("The sum is %d : %s", sum, str);
return 0;

}