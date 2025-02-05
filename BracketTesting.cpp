#include <iostream>
#include <utility>
#include "BracketCheck.h"

using namespace std;

bool check(const string& , string , bool );

bool numCheck(const string&, const string &, int);

int main()
{
    check ("Easy", "()", true);
    check ("Not Matched", "(}", false);
    check ("Mixed but valid", "({}[])", true);
    check ("Too Many Closing", "({}[])]", false);
    check ("Not Matched", "({)(})", false);
    check ("Too Many Opening", "{()", false);
    check ("Code", "if (num == 7) { cout << num; }", true);
    check ("Bad Code", "if (num == 7)  cout << num; }", false);

    //Custom Test Cases
    numCheck("Empty", "", 0);
    numCheck("Single Pair", "()", 1);
    numCheck("3 Pairs", "{}[]()", 3);
    numCheck("Nested 3 Pair", "({}, {})", 3);
    numCheck("Mixed 3 Brackets", "([{]})", 3);
    return 0;
}

bool check(const string& name, string expression, const bool shouldBe){
    if(const BracketCheck b(move(expression)); shouldBe == b.isBalanced()){
        cout << "Passed: " << name << endl;
        return true;
    }
    else{
        cout << "Failed: " << name << " " << b << endl;
    }

    return false;
}

bool numCheck(const string& name, const string &expression, const int shouldBe) {
    if(BracketCheck b(expression); shouldBe == b.numBrackets()) {
        cout << "Passed: " << name << endl;
    }
    else {
        cout << "Failed: " << name << " " << b << endl;
    }

    return false;
}