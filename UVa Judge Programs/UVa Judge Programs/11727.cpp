/*


*/


#include <iostream>

using namespace std;

int main() {
	int layoffs, min, max, median;
	int emps[3];

	cin >> layoffs;
	for (int i = 0; i < layoffs; i++) {
		for (int j = 0; j < 3; j++) {
			cin >> emps[j];
			if (j == 0) {
				min = max = median = emps[j];
			}
			else {
				if (emps[j] < min) {
					min = emps[j];
				}if (emps[j] > max) {
					max = emps[j];
				}
			}

		}
		for (int j = 1; j < 3; j++) {
			if (emps[j] >= min && emps[j] <= max) {
				median = emps[j];
			}
		}
		cout << "Case " << (i + 1) << ": " << median << endl;
	}

}