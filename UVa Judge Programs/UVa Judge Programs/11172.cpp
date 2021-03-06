/*///////////////////////////////////////////////////////////////////// 
Jesse Houk : Relational Operators : 11172 : euclid5
Data structure required : N/A
Tricks of the trade : For loop
Problem definition: while reading in numbers from cin the first number
	is how many pairs of numbers that follow. For each following pair
	compare the values of the numbers and cout their relationship: <,
	>, =.
////////////////////////////////////////////////////////////////////*/ 
#include <iostream>

using namespace std;

int main() {
	// The number for how many comparisons that will be made
	int relationNum = 0;
	// The left and right number of a pair of numbers that
	// will be read in
	int lNum, rNum;
	// The resulting relationship between the lNum and rNum
	char operatorChar;
	cin >> relationNum;
	for (int i = 0; i < relationNum; i++) {
		cin >> lNum >> rNum;
		if (lNum > rNum) {
			operatorChar = '>';
		}
		else if (lNum < rNum) {
			operatorChar = '<';
		}
		else {
			operatorChar = '=';
		}
		cout << operatorChar << endl;
	}

}