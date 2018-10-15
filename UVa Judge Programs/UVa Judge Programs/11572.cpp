#include <iostream>
#include <map>

using namespace std;

int main() {
	int batches, flakes;
	map<int, int> snowflakes;
	cin >> batches;
	for (int b = 0, max; b < batches; b++) {
		int sbegin, send = sbegin = 0;
		cin >> flakes;
		for (int f = max = 0, flake; f < flakes; f++) {
			
			cin >> flake;
			map<int, int>::iterator sf;
			int x = 0;
			for (sf = snowflakes.begin(); sf != snowflakes.end() && sf->first < sbegin; ++x, ++sf) { continue; }
			for (; sf != snowflakes.end() ; ++x, ++sf) { 
				if (sf->second == flake) 
					sbegin = x + 1; 
			}
			if (sf == snowflakes.end()) {
				snowflakes[f] = flake;
				send++;
			}
			else {
				if (max < send - sbegin) {
					max = send - sbegin;
				}
				//sbegin = sf->first;
				if (sbegin >= send) {
					send = sbegin + 1;
				}
				//snowflakes.erase(snowflakes.begin(), ++sf);
				snowflakes[f] = flake;
			}
		}
		if (max < send - sbegin) {
			max = send - sbegin;
		}
		cout << max << '\n';
		snowflakes.clear();
	}

}