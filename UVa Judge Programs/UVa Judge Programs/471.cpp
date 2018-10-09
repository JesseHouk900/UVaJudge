/*//////////////////////////////////////////////////////////////////////////////
*	Jesse Houk :   Magic Numbers :   471 :   euclid5
*
*	Data Structures :
*
*	Tricks of the Trade :
*
*	Problem : Given a positive integer, N, find an s1 and s2 such that no digit
		in s1 is repeated and no digit in s2 is repeated. Also, s1 / s2 = N.
		Print out s1 / s2 = N
*
*	Runtime : 0.020			Boo
//////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <bitset>

using namespace std;

// taking in a number of a very large size, in particular, including digits
	// with more than 10 digits and those with up to 10 digits. Return true if
	// each base 10 digit is used at most once (1234567890 will return true) and
	// return false when any digit is repeated (11 is invalid, as well as 1987615
bool isUnique(long long n) {
	// use a bitset to "count" how many times a digit is seen
	bitset<10> digi;
	// convert the number into a string so that getting the length is easier as
		// well as indexing individual elements
	string number = to_string(n);
	if (number.length() <= 10) {
		for (int i = 0; i < number.length(); i++) {
			// if a digit within the number (fixed from being a char) has already
				// been seen...
			if (digi[number[i] - '0']) {
				// declare the number has repeated digits
				return false;
			}
			// else if the next digit has not been seen yet, turn on the bit representing
				// that number
			else {
				digi[number[i] - '0'] = true;
			}
		}
		// if the loop terminates, that means no digit was seen more than once,
			// so declare that the number has all unique digits
		return true;
	}
	// if the number is larger than 10 elements or digits, automatically assume
		// some digit is being repeated
	return false;
}
int main() {
	// the first number with 11 digits, to many to be represented by base 10
		// digits
	const unsigned long long MUST_BE_REPEATING = 10000000000;
	// number read in from the input file. Will be used for finding s1 and s2
	long long number;
	// the number that will be the maximum value of s2, the number on the
		// denominator
	int max_s2;
	// the number of test cases that will be used to find "Magic Numbers"
	int test_cases;
	// get the number of test cases
	cin >> test_cases;
	// loop through each test case
	for (int c = 0; c < test_cases; c++) {
		// get test case
		cin >> number;
		// calculate the largest multiple number can have before getting to the
			// length where repeating digits must occur
		max_s2 = (MUST_BE_REPEATING / number) + 1;
		// check integer multiples of number until a safe spot where repeat
			// digits are guaranteed
		for (int i = 1; i <= max_s2; i++) {
			// check if i has all unique digits and if the integer multiple of
				// number has all unique digits
			if (isUnique(i) && isUnique(i * number)) {
				
				//	if so, print in the form of s1 / s2 = N
				cout << i * number << " / " << i << " = " << number << '\n';
			}
		}
		// if it is not the last test case...
		if (c != test_cases - 1) {
			// print a new line
			cout << '\n';
		}
	}
}