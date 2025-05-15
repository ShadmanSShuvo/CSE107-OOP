#include <stdio.h>
typedef struct xx
{
    char name[20];
    int rollno;
    double cgpa;
} Student;
int main()
{
    Student karim;
    printf("Enter the name: ");
    gets(karim.name);
    printf("Enter Rollno: ");
    scanf("%d", &karim.rollno);
    printf("Enter CGPA: ");
    scanf("%lf", &karim.cgpa);
    printf(“\nName: %s\n", karim.name);
    printf("Rollno: %d\n", karim.rollno);
    printf("CGPA: %.2lf\n", karim.cgpa);
}