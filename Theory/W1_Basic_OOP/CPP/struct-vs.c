#include <iostream>
#include <string.h>
using namespace std;
typedef struct xx{
private:
char name[20];
int rollno;
double cgpa;
public: //setter - getter
void setName(char *N){ strcpy(name, N);}
char *getName(){return name;}
void setRollno(int R){ rollno = R; }
int getRollno(){ return rollno;};
void setCGPA(double CGPA){ cgpa = CGPA;}
double getCGPA(){ return cgpa;}
} Student;