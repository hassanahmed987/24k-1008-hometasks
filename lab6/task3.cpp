#include <iostream>
#include <string>
using namespace std;

struct Node {
    string url;
    Node* next;
    Node(string u) {
        url = u;
        next = nullptr;
    }
};


class Stack {
private:
    static const int MAX = 100;
    string arr[MAX];
    int topIndex;

public:
    Stack() { topIndex = -1; }

    bool empty() { return topIndex == -1; }

    void push(string url) {
        if (topIndex >= MAX - 1) {
            cout << " Stack overflow\n";
            return;
        }
        arr[++topIndex] = url;
    }

    string pop() {
        if (empty()) {
            cout << " Stack underflow\n";
            return "";
        }
        return arr[topIndex--];
    }

    string top() {
        if (empty()) return "";
        return arr[topIndex];
    }
};


class BrowserHistory {
private:
    Node* head;   
    Stack backStack;

public:
    BrowserHistory() {
        head = nullptr;
    }


    void visit(string url) {
        Node* newNode = new Node(url);
        newNode->next = head;
        head = newNode;
        backStack.push(url);
        cout << "Visited: " << url << endl;
    }


    void goBack(int n) {
        cout << "\n Going back " << n << " time(s)...\n";
        for (int i = 0; i < n; i++) {
            if (head != nullptr) {
                string popped = backStack.pop();

                Node* temp = head;
                head = head->next;
                delete temp;

                cout << "Removed: " << popped << " from history.\n";
            } else {
                cout << " No more history to go back.\n";
                return;
            }
        }
        cout << "\nNow on page: " << currentPage() << endl;
    }


    string currentPage() {
        if (head == nullptr)
            return "No current page (history empty)";
        return head->url;
    }

    void showHistory() {
        cout << "\n Browsing History (most recent first):\n";
        Node* temp = head;
        int i = 1;
        while (temp != nullptr) {
            cout << i++ << ". " << temp->url << endl;
            temp = temp->next;
        }
        if (head == nullptr)
            cout << "History is empty.\n";
    }
};


int main() {
    BrowserHistory browser;

    browser.visit("Google");
    browser.visit("Facebook");
    browser.visit("Twitter");
    browser.visit("LinkedIn");
    browser.visit("Instagram");

    browser.showHistory();
    browser.goBack(2);
    browser.showHistory();
    return 0;
}
