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
		int i = 0;

		if (term == "#") {
			if (isFirst) {
				isFirst = false;

			}
			else {
				// initialize a matrix to be pairs
				vector<vector<pair<int, string> > > RSQMatrix = vector<vector<
					pair<int, string> > >(list1.size(), vector<pair<int, string>
					>(list2.size(), pair<int, string>(0, "")));
				
				for (int r = 1; r < list1.size(); r++) {
					for (int c = 1; c < list2.size(); c++) {
						if (list1[r] == list2[c]) {
							RSQMatrix[r][c] = pair<int, string>(RSQMatrix[r - 1]
								[c - 1].first + 1, RSQMatrix[r - 1][c - 1].second
								+ " " + list1[r]);
						}
						else {
							RSQMatrix[r][c] = max(RSQMatrix[r][c - 1], RSQMatrix[r - 1][c]);
						}
					}
				}
				pair<int, string> answer = RSQMatrix[list1.size() - 1][list2.size() - 1];
				cout << answer.first << ' ' << answer.second << '\n';
				list1 = list2 = vector<string>();
				isFirst = true;
			}
			i = 0;
		}
		else {
			if (isFirst) {
				list1.push_back(term);
			}
			else {
				list2.push_back(term);
			}
			i++;
		}

	}
}