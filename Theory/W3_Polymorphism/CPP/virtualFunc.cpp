#include <iostream>
using namespace std;

class Animal
{
public:
    virtual void makeSound()
    {
        cout << "Some generic animal sound" << endl;
    }
};

class Dog : public Animal
{
public:
    void makeSound() override
    {
        cout << "Woof!" << endl;
    }
};

class Cat : public Animal
{
public:
    void makeSound() override
    {
        cout << "Meow!" << endl;
    }
};

int main()
{
    Animal *a;
    Dog d;
    Cat c;

    a = &d;
    a->makeSound(); // Woof!

    a = &c;
    a->makeSound(); // Meow!

    return 0;
}