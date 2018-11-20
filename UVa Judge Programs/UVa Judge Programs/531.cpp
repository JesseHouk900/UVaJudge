/*/////////////////////////////////////////////////////////////////////////////
	Jesse Houk :	Compromise :	531 :	euclid5


/////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#define p pair<int, string>

using namespace std;

p orderedMax(const p & p1, const p & p2);

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
					p > >(list2.size(), vector<p
					>(list1.size(), p(0, "")));

				for (int r = 1; r < list2.size(); r++) {
					// add brekpoint
					for (int c = 1; c < list1.size(); c++) {
						if (list2[r - 1] == list1[c - 1]) {
							RSQMatrix[r][c] = p(RSQMatrix[r - 1]
								[c - 1].first + 1, RSQMatrix[r - 1][c - 1].second);
							if (RSQMatrix[r][c].first > 1) {
								RSQMatrix[r][c].second += " ";
							}
							RSQMatrix[r][c].second += list2[r - 1];

						}
						else {
							RSQMatrix[r][c] = orderedMax(RSQMatrix[r][c - 1], RSQMatrix[r - 1][c]);
						}
					}
				}
				p answer = RSQMatrix[list2.size() - 1][list1.size() - 1];
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

p orderedMax(const p & p1, const p & p2) {
	// get the max of the two integers of the pairs
	int m = max(p1.first, p2.first);
	// if the max euquals both values...
	if (m == p1.first && m == p2.first) {
		//
		string s = min(p1.second, p2.second);
		if (s == p1.second) {
			return p1;
		}
		return p2;

	}
	else if (m == p1.first) {
		return p1;
	}
	return p2;
}
	//p mymax(const p & p1, const p & p2) {
	//	int m = max(p1.first, p2.first);
	//	if (m == p1.first) {
	//		if (m == p1.first) {
	//			if (p1.second != "" && p2.second != "") {
	//				string s = min(p1.second, p2.second);
	//				if (s != p1.second) {
	//					return p2;
	//				}
	//
	//			}
	//			else {
	//				return 
	//			}
	//		return p1;
	//		}
	//	}
	//	else if (m == p2.first) {
	//		return p2;
	//
	//	}