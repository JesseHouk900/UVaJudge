/*/////////////////////////////////////////////////////////////////////////////

Jesse Houk:    Unique Snowflake:    11572:    euclid5

Data Structures : unordered map

Tricks of the trade : 

Problem : 

/////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <unordered_map>
#include <vector>

using namespace std;

int main() {
	// batches is the number of test cases and flakes is how many elements
		// there are in a batch
	int batches, flakes;
	// a hash table of integers mapping to integers

	// 
	cin >> batches;
	for (int b = 0, max; b < batches; b++) {
        unordered_map<int, int> snowflakePositions;
        vector<pair<int, int> > Starts, Ends;
		cin >> flakes;
		for (int f = max = 0, flake, last; f < flakes; f++) {
			cin >> flake;
			last = snowflakePositions[flake]
			for (int i = sbegin; i < send; i++) {
				if (snowflakes[i] == flake) {
					sbegin = i + 1;
				}
			}
			snowflakes[f] = flake;
			send++;
			if (max < send - sbegin) {
				max = send - sbegin;
			}
			
		}
		cout << max << '\n';
		snowflakes.clear();
	}

}