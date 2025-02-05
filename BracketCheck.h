#pragma once

#include <iostream>
#include <string>
#include <stack>
using namespace std;


class BracketCheck {
private:
    string expression;

public:
    BracketCheck(string exp) : expression(exp) {}

    int numBrackets() {
        int count = 0;
        for (char c : expression) {
            if (c == '[' || c == ']' || c == '{' || c == '}' || c == '(' || c == ')') {
                count++;
            }
        }
        return count / 2;  // Since each pair of brackets counts as one
    }

    bool isBalanced() const {
        stack<char> brackets;
        for (char c : expression) {
            if (c == '[' || c == '{' || c == '(') {
                brackets.push(c);
            } else if (c == ']' || c == '}' || c == ')') {
                if (brackets.empty()) {
                    return false;
                } else if ((c == ']' && brackets.top() == '[') ||
                           (c == '}' && brackets.top() == '{') ||
                           (c == ')' && brackets.top() == '(')) {
                    brackets.pop();
                } else {
                    return false;
                }
            }
        }
        return brackets.empty();
    }

    friend ostream& operator<<(ostream& os, const BracketCheck& bc) {
        if (bc.isBalanced()) {
            os << "Balanced";
        } else {
            os << "Not Balanced";
        }
        return os;
    }
};

