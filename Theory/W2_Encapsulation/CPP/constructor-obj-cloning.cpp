#include <iostream>
using namespace std;

class Box{
    double length;
    double width;
    double height;
    public:
    Box(double l, double w, double h){
    length = l;
    width = w;
    height = h;
    }
    Box(const Box& ob){
        length = ob.length;
        width = ob.width;
        height = ob.height;
    }
    double volume(){
        return length * width * height;
        }
    };

int main() {
    Box myBox(5, 3, 2);
    Box myClone(myBox);
    cout << "Box Volume: " << myBox.volume() << endl;
    cout << "Clone Volume: " << myClone.volume() << endl;
}