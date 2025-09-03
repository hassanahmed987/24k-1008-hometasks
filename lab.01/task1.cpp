#include <iostream>
#include <cstring>
using namespace std;

class ResearchPaper {
private:
    string* authors;   
    int authorCount;

public:
  
    ResearchPaper(int count,string* names) {
        authorCount = count;
        authors = new string[authorCount];
        for (int i = 0; i < authorCount; i++) {
            authors[i] = names[i];
        }
    }
    ResearchPaper(ResearchPaper& other) {
        authorCount = other.authorCount;
        authors = new string[authorCount];
        for (int i = 0; i < authorCount; i++) {
            authors[i] = other.authors[i];
        }
    }

    ResearchPaper& operator=(ResearchPaper& other) {
        if (this != &other) {  
            delete[] authors;  
            authorCount = other.authorCount;
            authors = new string[authorCount];
            for (int i = 0; i < authorCount; i++) {
                authors[i] = other.authors[i];
            }
        }
        return *this;
    }

    ~ResearchPaper() {
        delete[] authors;
    }

    void display() {
        cout << "Authors (" << authorCount << "): ";
        for (int i = 0; i < authorCount; i++) {
            cout << authors[i];
            if (i != authorCount - 1) cout << ", ";
        }
        cout << endl;
    }

    void setAuthor(int index, const string& name) {
        if (index >= 0 && index < authorCount) {
            authors[index] = name;
        }
    }
};

int main() {
    string authors1[] = {"charles dickens", "Hassan", "Jk rowling"};
    ResearchPaper paper1(3, authors1);

    cout << "Original Paper1:" << endl;
    paper1.display();

    ResearchPaper paper2 = paper1;
    cout << "\nCopied Paper2 :" << endl;
    paper2.display();

    string authors2[] = {"David", "Eve"};
    ResearchPaper paper3(2, authors2);
    paper3 = paper1;
    cout << "\nPaper3 after Assignment from Paper1:" << endl;
    paper3.display();

    paper2.setAuthor(0, "bilal");
    cout << "\nAfter modifying Paper2:" << endl;
    paper2.display();
    cout << "Paper1 remains unchanged:" << endl;
    paper1.display();

    return 0;
}
