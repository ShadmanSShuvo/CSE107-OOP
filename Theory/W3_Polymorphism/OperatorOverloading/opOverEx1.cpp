#include <iostream>
using namespace std;

class array
{
    int nums[10];

public:
    array();
    void set(int n[10]);
    void show();
    array operator+(array ob2);
    array operator-(array ob2);
    bool operator==(array ob2); // Change return type to bool
};

// Constructor: initializes all elements to 0
array::array()
{
    for (int i = 0; i < 10; i++)
        nums[i] = 0;
}

// Set values from passed array
void array::set(int *n)
{
    for (int i = 0; i < 10; i++)
        nums[i] = n[i];
}

// Display elements
void array::show()
{
    for (int i = 0; i < 10; i++)
        cout << nums[i] << ' ';
    cout << "\n";
}

// Overload + operator: element-wise addition
array array::operator+(array ob2)
{
    array temp;
    for (int i = 0; i < 10; i++)
        temp.nums[i] = nums[i] + ob2.nums[i];
    return temp;
}

// Overload - operator: element-wise subtraction
array array::operator-(array ob2)
{
    array temp;
    for (int i = 0; i < 10; i++)
        temp.nums[i] = nums[i] - ob2.nums[i];
    return temp;
}

// Overload == operator: checks if all elements are equal
bool array::operator==(array ob2)
{
    for (int i = 0; i < 10; i++)
    {
        if (nums[i] != ob2.nums[i])
            return false;
    }
    return true;
}

// Main function
int main()
{
    array o1, o2, o3;
    int i[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10};

    o1.set(i);
    o2.set(i);

    o3 = o1 + o2;
    o3.show(); // 2 4 6 8 10 12 14 16 18 20

    o3 = o1 - o3;
    o3.show(); // -1 -2 -3 -4 -5 -6 -7 -8 -9 -10

    if (o1 == o2)
        cout << "o1 equals o2\n";
    else
        cout << "o1 does not equal o2\n";

    if (o1 == o3)
        cout << "o1 equals o3\n";
    else
        cout << "o1 does not equal o3\n";

    return 0;
}