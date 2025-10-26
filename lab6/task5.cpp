#include <iostream>
#include <stack>
#include <cmath>
#include <string>
using namespace std;

bool isOperator(char ch) {
    return (ch == '+' || ch == '-' || ch == '*' || ch == '/' || ch == '^');
}

double evaluatePrefix(const string& prefix) {
    stack<double> st;

    for (int i = prefix.length() - 1; i >= 0; i--) {
        char ch = prefix[i];

        if (ch == ' ') continue;

        if (isdigit(ch)) {
            st.push(ch - '0'); 
        }

        else if (isOperator(ch)) {
            if (st.size() < 2) {
                cout << "Invalid Expression!" << endl;
                return 0;
            }

            double op1 = st.top(); st.pop();
            double op2 = st.top(); st.pop();
            double result = 0;

            switch (ch) {
                case '+': result = op1 + op2; break;
                case '-': result = op1 - op2; break;
                case '*': result = op1 * op2; break;
                case '/': result = op1 / op2; break;
                case '^': result = pow(op1, op2); break;
            }

            st.push(result);
        }
    }

    return st.top();
}

int main() {
    string prefix;
    cout << "Enter Prefix Expression: ";
    cin >> prefix;

    double result = evaluatePrefix(prefix);
    cout << "Final Evaluated Result: " << result << endl;

    return 0;
}
