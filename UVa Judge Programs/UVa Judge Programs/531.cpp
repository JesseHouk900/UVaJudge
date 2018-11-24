/*/////////////////////////////////////////////////////////////////////////////
	Jesse Houk :	Compromise :	531 :	euclid5


/////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define p pair<int, string>

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
				vector<vector<p > > RSQMatrix = vector<vector<
					p > >(list1.size() + 1, vector<p
					>(list2.size() + 1, p(0, "")));

				for (int r = 0; r < list1.size(); r++) {
					// add brekpoint
					for (int c = 0; c < list2.size(); c++) {
						if (list1[r] == list2[c]) {
							RSQMatrix[r + 1][c + 1] = p(RSQMatrix[r]
								[c].first + 1, RSQMatrix[r][c].second);
							if (RSQMatrix[r + 1][c + 1].first > 1) {
								RSQMatrix[r + 1][c + 1].second += " ";
							}
							RSQMatrix[r + 1][c + 1].second += list1[r];

						}
						else {
							RSQMatrix[r + 1][c + 1] = max(RSQMatrix[r + 1][c], RSQMatrix[r][c + 1]);
						}
					}
				}
				p answer = RSQMatrix[list1.size()][list2.size()];
				cout << answer.second << '\n';
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