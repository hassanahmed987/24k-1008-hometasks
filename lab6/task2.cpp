#include <iostream>
#include <string>
#include <cmath>
using namespace std;


class Stack {
private:
    static const int MAX = 100;
    double arr[MAX];   
    int topIndex;

public:
    Stack() {
        topIndex = -1;
    }

    bool empty() {
        return topIndex == -1;
    }

    bool full() {
        return topIndex == MAX - 1;
    }

    void push(double value) {
        if (full()) {
            cout << " Stack overflow! Cannot push more values.\n";
            return;
        }
        arr[++topIndex] = value;
    }

    double pop() {
        if (empty()) {
            cout << " Stack underflow! Invalid expression.\n";
            exit(1); 
        }
        return arr[topIndex--];
    }

    double top() {
        if (empty()) {
            cout << " Stack is empty.\n";
            exit(1);
        }
        return arr[topIndex];
    }
};


double evaluatePostfix(const string &expr) {
    Stack stack;

    for (int i = 0; i < expr.length(); i++) {
        char ch = expr[i];

        if (ch == ' ')
            continue;

        if (isdigit(ch)) {
            double num = ch - '0'; 
            stack.push(num);
        }
        else {
            double val2 = stack.pop(); 
            double val1 = stack.pop(); 
            double result;

            switch (ch) {
                case '+': result = val1 + val2; break;
                case '-': result = val1 - val2; break;
                case '*': result = val1 * val2; break;
                case '/': 
                    if (val2 == 0) {
                        cout << " Division by zero error!\n";
                        exit(1);
                    }
                    result = val1 / val2; break;
                case '^': result = pow(val1, val2); break;
                default:
                    cout << " Invalid operator: " << ch << endl;
                    exit(1);
            }

            stack.push(result);
        }
    }

    if (!stack.empty())
        return stack.top();
    else {
        cout << " Invalid postfix expression.\n";
        exit(1);
    }
}


int main() {
    string expression;

    cout << "Enter a postfix expression : ";
    cin >> expression;

    double result = evaluatePostfix(expression);
    cout << "\n Final Evaluated Result: " << result << endl;

    return 0;
}
