/*/////////////////////////////////////////////////////////////////////////////
	Jesse Houk :	Compromise :	531 :	euclid5


/////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int main() {
	string term;
	bool isFirst = true;
	vector<string> list1, list2 = list1 = vector<string>();
	while (cin >> term) {

		if (term == "#") {
			if (isFirst) {
				isFirst = false;

			}
			else {
				// initialize a matrix to be pairs
				vector<vector<int> > RSQMatrix = vector<vector<
					int> >(list1.size() + 1, vector<int
					>(list2.size() + 1, 0));

				for (int r = 0; r < list1.size(); r++) {
					// add brekpoint
					for (int c = 0; c < list2.size(); c++) {
						if (list1[r] == list2[c]) {
							RSQMatrix[r + 1][c + 1] = RSQMatrix[r]
								[c] + 1;
							/*if (RSQMatrix[r + 1][c + 1] > 1) {
								RSQMatrix[r + 1][c + 1].second += " ";
							}*/
							//RSQMatrix[r + 1][c + 1].second += list1[r];

						}
						else {
							RSQMatrix[r + 1][c + 1] = max(RSQMatrix[r + 1][c], RSQMatrix[r][c + 1]);
						}
					}
				}
				int r = list1.size(), c = list2.size();
				// clear list 1 so it can be used to make our list of similar words
				list1.clear();
				while (r != 0 && c != 0) {
					if (RSQMatrix[r - 1][c - 1] == RSQMatrix[r][c]) {
						r -= 1;
						c -= 1;
					}
					else if (RSQMatrix[r][c - 1] == RSQMatrix[r][c]) {
						c -= 1;
					}
					else if (RSQMatrix[r - 1][c] == RSQMatrix[r][c]) {
						r -= 1;
					}
					else {
						r -= 1;
						c -= 1;
						list1.push_back(list2[c]);
					}
				}
				for (int i = list1.size() - 1; i > 0; i--) {
					
					cout << list1[i] << " ";
				}

				cout << list1[0] << '\n';
				list1 = list2 = vector<string>();
				isFirst = true;
			}
		}
		else {
			if (isFirst) {
				list1.push_back(term);
			}
			else {
				list2.push_back(term);
			}
		}

	}
}

