#include <iostream>
#include <string>
#include <stack>
#include <cctype>

using namespace std;

int precedence(char c) {
    if (c == '^') return 3;
    if (c == '*' || c == '/') return 2;
    if (c == '+' || c == '-') return 1;
    return -1;
}

string infixToPostfix(string inf) {
    stack<char> s;
    string post = "";
    for (char c : inf) {
        if (isspace(c)) continue;
        if (isalpha(c)) {
            post += c;
        } else if (c == '(') {
            s.push(c);
        } else if (c == ')') {
            while (!s.empty() && s.top() != '(') {
                post += s.top();
                s.pop();
            }
            if (!s.empty()) s.pop();
        } else {
            while (!s.empty() && precedence(s.top()) >= precedence(c)) {
                post += s.top();
                s.pop();
            }
            s.push(c);
        }
    }
    while (!s.empty()) {
        post += s.top();
        s.pop();
    }
    return post;
}

int main() {
    string infix;
    cout << "Enter Infix expression: ";
    getline(cin, infix);
    cout << "Postfix expression: " << infixToPostfix(infix) << endl;
    return 0;
}