#include <iostream>
using namespace std;

class Box {
private:
    int* volume;  

public:
    Box() {
        volume = new int(0);
    }

    Box(int v) {
        volume = new int(v);
    }

    Box(const Box& other) {
        volume = new int(*other.volume);  
    }

    ~Box() {
        delete volume;
    }

    int getVolume() const {
        return *volume;
    }

    void setVolume(int v) {
        *volume = v;
    }

    void display() const {
        cout << "Box Volume = " << *volume << endl;
    }
};

int main() {
    Box b1;
    cout << "Default constructed b1: ";
    b1.display();

    Box b2(50);
    cout << "Parameterized constructed b2: ";
    b2.display();

    Box b3 = b2;  
    cout << "\nAfter copy constructor, b3 copied from b2:" << endl;
    b3.display();

    b3.setVolume(100);
    cout << "\nAfter modifying b3 volume:" << endl;
    b3.display();

    cout << "Original b2 remains unchanged:" << endl;
    b2.display();

    return 0;
}

