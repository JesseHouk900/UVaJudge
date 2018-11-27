/*/////////////////////////////////////////////////////////////////////////////
	Jesse Houk :	Compromise :	531 :	euclid5

	Data Structures : RSQMatrix
	
	Tricks of the Trade : Range Sum Query in 2D

	Problem : read in two statements from two people and determine the longest
		common subsequence

	Runtime : 0.050		Not great
/////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm> // for max

using namespace std;

int main() {
	// the current term or word that is being read in
	string term;
	// used to determine if the set of terms being read in is from the first
		// person or the second. Assume the first comes first
	bool isFirst = true;
	// make a list of words for person one and person 2
	vector<string> list1, list2 = list1 = vector<string>();
	// while there are words to read in...
	while (cin >> term) {
		// if it is a # symbol...
		if (term == "#") {
			// and it is the first person's words...
			if (isFirst) {
				// then the first person is done with their statement
				isFirst = false;
			}
			// it is the second person's words, so...
			else {
				// get the number of terms in the two statements
				int rows = list1.size(), cols = list2.size();
				// initialize a matrix with a number of rows to be one plus the
					// number of terms in the first person's statement and a
					// number of columns to be one plus the number of terms in
					// the second person's statement. This one extra row and
					// column is to make the programming of the RSQ more simple
				vector<vector<int> > RSQMatrix = vector<vector<int>
					>(rows + 1, vector<int>(cols + 1, 0));
				// loop through person one's statement
				for (int r = 0; r < rows; r++) {
					// loop through person two'2 statement
					for (int c = 0; c < cols; c++) {
						// if a word from person is the same word as from person
							// two...
						if (list1[r] == list2[c]) {
							// take the corresponding element in the RSQMatrix
								// and set it to the value of the element one to
								// the left and one up and increment it by one
							RSQMatrix[r + 1][c + 1] = RSQMatrix[r][c] + 1;
						}
						// the words do not match, so...
						else {
							// set the corresponding element in the RSQMatrix
								// to the max value between the element directly
								// above and directly to the left
							RSQMatrix[r + 1][c + 1] = max(RSQMatrix[r + 1][c],
								RSQMatrix[r][c + 1]);
						}
					}
				}
				// Now that the RSQMatrix has been processed, clear list 1 so it
					// can be used to make our list of words shared by both list 1
					// and list 2
				list1.clear();
				// while neither rows nor columns are 0, the dummy row/column,...
				while (rows != 0 && cols != 0) {
					// if the upper left adjacent element equals the current 
						// element...
					if (RSQMatrix[rows - 1][cols - 1] == RSQMatrix[rows][cols]) {
						// move to that element
						rows -= 1;
						cols -= 1;
					}
					// if the left adjacent element equals the current element...
					else if (RSQMatrix[rows][cols - 1] == RSQMatrix[rows][cols]) {
						// move to that element
						cols -= 1;
					}
					// if the upper adjacent element equals the current element...
					else if (RSQMatrix[rows - 1][cols] == RSQMatrix[rows][cols]) {
						// move to that element
						rows -= 1;
					}
					// the only option left is that m[r-1][c-1] = m[r][c] - 1,
						// meaning the words were equal when making the RSQMatrix,
						// so...
					else {
						// move to that element
						rows -= 1;
						cols -= 1;
						// and add to the list of similar words the corresponding
							// word from the unchanged list of words
						list1.push_back(list2[cols]);
					}
				}
				// print out the list of similar words with spaces following in
					// reverse order
				for (int i = list1.size() - 1; i > 0; i--) {
					
					cout << list1[i] << " ";
				}
				// print the last word with a new line
				cout << list1[0] << '\n';
				// reset the lists
				list1 = list2 = vector<string>();
				// make the first person's statement b read first
				isFirst = true;
			}
		}
		else { // the word read in is not a # and is an actual word
			// if it is the first person whose statement is being read...
			if (isFirst) {
				// add it to list 1
				list1.push_back(term);
			}
			// else if the first person is not the person whose statement is
				// being read...
			else {
				// assume it is the second person, so add it to list 2
				list2.push_back(term);
			}
		}
	}
}

