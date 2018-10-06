/*/////////////////////////////////////////////////////////////////////////////
*	Jesse Houk :   Splitting Numbers :   11933 :   euclid5
*
*	Data Structures: bitsets of 32 bits to represent an integer
*
*	Tricks of the Trade: bitsets with boolean flag to alternate action
*
*	Purpose: Reading in a positive integer n, break n into 2 numbers based on
	it's binary representation. For i = 0, a is made by including every odd ith
	1 in the binary n. Likewise, b is made by including every even ith 1 in the
	binary n. Terminate on n = 0
*
*/

#include <iostream>
#include <bitset>

using namespace std;

int main() {
	// n is used for holding the values read in from standard input
	int n;
	// while there is a number to be split and it is not 0...
	while (cin >> n && n != 0) {
		// start with 2 binary representations of n
		bitset<32> a(n), b(n);
		// signal for when a bit is turned off on one bitset or the other
		bool flipa = false;
		// loop through a and b
		for (int i = 0; i < 32; i++) {
			// only flip on the ones in either representation, a or b
			if (a[i]) {
				// if a is supposed to be flipped
				if (flipa) {
					// flip the ith position of b
					a.flip(i);
					// flip b next
					flipa = false;
				}
				// if b is supposed to be flipped
				else {
					// flip the ith position of b
					b.flip(i);
					// flip a next
					flipa = true;
				}
			}
		}
		// print the unsigned long type casting of a and b
		cout << a.to_ulong() << ' ' << b.to_ulong() << '\n';
		
	}

	return 0;
}