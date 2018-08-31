/*/////////////////////////////////////////////////////////////////////
Jesse Houk : Jolly Jumpers : 10038 : euclid5
Data structure required : 
Tricks of the trade : 
Problem definition: 
////////////////////////////////////////////////////////////////////*/
#include <iostream>

using namespace std;

int main() {
	// The number for how many numbers follow that will
	// have their differences analyzed
	int jumperNum = 0;
	// 
	int * jumpers;

	int * differences;
	// Whether or not the sequence of numbers is considered "Jolly"
	bool isJolly = false;
	while (cin >> jumperNum) {
		jumpers = new int[jumperNum];
		differences = new int[jumperNum - 1];
		for (int i = 0; i < jumperNum; i++) {
			cin >> jumpers[i];
			if (i >= 1) {
				differences[i - 1] = abs(jumpers[i] - jumpers[i - 1];
			}
		}
		delete [] jumpers;
	}

}