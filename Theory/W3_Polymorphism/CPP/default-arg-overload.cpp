/*

➢Default argument can be
used instead of function
overload

*/

#include <iostream>
using namespace std;
double rect_area(double length, double width = 0)
{
    if (!width)
        width = length;
    return length * width;
}
int main()
{
    cout << rect_area(10.0, 5.8) << endl;
    cout << rect_area(10.0) << endl;
    return 0;
}