#include <iostream>
#include <cstring>
using namespace std;

class ResearchPaper {
private:
    string* authors;   
    int authorCount;

public:
  
    ResearchPaper(int count, const string* names) {
        authorCount = count;
        authors = new string[authorCount];
        for (int i = 0; i < authorCount; i++) {
            authors[i] = names[i];
        }
    }
};
int main(){
    cout<<"yeah"<<endl;
}
