#include <iostream>
using namespace std;

class Exam {
private:
    int* marks;  
public:
    Exam(int m) {
        marks = new int(m);
    }


    ~Exam() {
        delete marks;
    }

    int getMarks() const {
        return *marks;
    }

    void setMarks(int m) {
        *marks = m;
    }

    void display() const {
        cout << "Marks = " << *marks << endl;
    }
};

int main() {
    Exam e1(80);
    cout << "Original e1: ";
    e1.display();

    Exam e2 = e1;   
    cout << "Copied e2 from e1: ";
    e2.display();

    e2.setMarks(100);

    cout << "\nAfter modifying e2:" << endl;
    cout << "e2: ";
    e2.display();
    cout << "e1 (affected due to shallow copy): ";
    e1.display();

    return 0;
}

