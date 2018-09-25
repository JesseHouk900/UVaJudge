/*/////////////////////////////////////////////////////////////////////
Jesse Houk :    Parentheses Balance :    673 :    euclid5

Data structure : 

Tricks of the trade : 

Problem : 

////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
    stack<char> tokens;
    string line;
    int lines;
    bool isValid;
    cin >> lines;
    for (int l = 0; l < lines; l++) {
        cin >> line;
        isValid = true;
        //cout << line.size() << '\n';
        if (line.size() > 0) {
            if ((line.size() % 2) == 0) {
                for (int t = 0; t < line.size() && isValid; t++) {
                    //cout << t << ' ';
                    //cout << line[t] << ' ';
                    if (line.size() - t + 1 >= tokens.size()) {
                        if (line[t] != ']' && line[t] != ')') {
                                tokens.push(line[t]);
                        }
                        else {
                            //cout << l << ": l\n" << tokens.size() << '\n';
                            if (tokens.size() > 0) {
                                if ((tokens.top() == '(' && line[t] == ')') || (tokens.top() == '[' && line[t] == ']')) {
                                    tokens.pop();
                                }
                                else isValid = false;

                            }
                            else isValid = false;
                        }
                    }
                    else isValid = false;
                } // end of iteration through line
                //cout << '\n';
            }
            else {
                isValid = false;
            }
        }
        if (isValid) {
            cout << "Yes\n";
        }
        else {
            cout << "No\n";
        }
        // empty stack
        while (!tokens.empty()) {
            tokens.pop();
        }
    } // end of looping through lines

}