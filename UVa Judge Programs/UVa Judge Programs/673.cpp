/*/////////////////////////////////////////////////////////////////////
Jesse Houk :    Parentheses Balance :    673 :    euclid5

Data structure : Stack

Tricks of the trade : 

Problem : Read in a line containing N. Then read in N lines of (, ), [,
	] and determine if they have been paired appropriately.

Runtime: .05			Worse than before

////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <stack>
#include <string>

using namespace std;

int main() {
	// a stack for the incoming left parentheses, '(' or '['
	stack<char> tokens;
	string line;
	// the number of lines that will be processed
	int lines;
	// used to determine if the line of parentheses is valid or not
	bool isValid;
	cin >> lines;
	// move to the next line
	cin.ignore();
	for (int l = 0; l < lines; l++) {
		getline(cin, line);
		isValid = true;
		// iterate through the line
		for (int t = 0; t < line.size(); t++) {
			// check if it is possible that the stack can be emptied (and thus part of
				// being a valid balanced parentheses line) by checking the remaining
				// length of the line with the size of the stack. Also skip interior
				// logic if a space is seen
			if (line.size() - t + 1 >= tokens.size() && line[t] != ' ') {
				// check for left parentheses
				if (line[t] != ']' && line[t] != ')') {
					tokens.push(line[t]);
				}
				else {
					// make sure a left brace comes before a right brace
					if (tokens.size() > 0 && ((tokens.top() == '(' && line[t] == ')')
						|| (tokens.top() == '[' && line[t] == ']'))) {
							tokens.pop();
					}
					else isValid = false;
				}
			}
		} // end of iteration through line
		// empty stack
		if (!tokens.empty()) {
			isValid = false;
		}
		while (!tokens.empty()) {
			tokens.pop();
		}
		if (isValid) {
			cout << "Yes\n";
		}
		else {
			cout << "No\n";
		}
	} // end of looping through lines

}