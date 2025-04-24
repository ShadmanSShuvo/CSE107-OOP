#include <iostream>
using namespace std;
int main() {
int a, b, sum;
char str[16];
cout << "Enter number 1: ";
cin >> a;
cout << "Enter number 2: ";
cin >> b;
cout << "Enter a String: ";
cin >> str;
sum = a + b;
cout << "The sum is "<< sum << " : " << str;
return 0;
}