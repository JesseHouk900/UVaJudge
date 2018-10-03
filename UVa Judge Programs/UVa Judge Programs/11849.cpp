/*/////////////////////////////////////////////////////////////////////////////
*   Jesse Houk :   CD :   11849 :   euclid5
*
*   Data Structures: set
*
*   Tricks of the trade: good ol' math. used the inclusion exclusion principal
*		|A U B| = |A| + |B| - |A n B|
*
*	Purpose: read in an N and M for how many CDs Jack and Jill have, respectively.
*		The following N + M lines are Jack and Jills CDs, marked by a positive
*		integer, e, and, individually, they use e at most once.
*
*NEEDS TO BE SUBMIT
/////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <set>

using namespace std;

int main() {
	int N, M, e;
	while (cin >> N >> M && N != 0 && M != 0) {
		// 
		set<int> c;
		// take all of Jack and Jills cds
		for (int i = 0; i < N + M && cin >> e; i++) {
			// keep unique cds
			c.insert(e);
		}
		// print the number of CDs Jack and Jill can sell which is found by
			// using the inclusion exclusion principal, taking the size of
			// Jack's cd collection, adding it to Jill's cd collection, and
			// removing their keep pile
		cout << N + M - c.size() << '\n';
	}
}