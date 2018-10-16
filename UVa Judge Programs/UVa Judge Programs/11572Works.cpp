/*/////////////////////////////////////////////////////////////////////////////

Jesse Houk:    Unique Snowflake:    11572:    euclid5

Data Structures : unordered map

Tricks of the trade : 

Problem : Too slow

/////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <unordered_map>

using namespace std;

int main() {
	// batches is the number of test cases and flakes is how many elements
		// there are in a batch
	int batches, flakes;
	// a hash table of integers mapping to integers
	unordered_map<int, int> snowflakes;
	// 
	cin >> batches;
	for (int b = 0, max; b < batches; b++) {
		int sbegin, send = sbegin = 0;
		cin >> flakes;
		for (int f = max = 0, flake; f < flakes; f++) {
			
			cin >> flake;
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