/*/////////////////////////////////////////////////////////////////////
Jesse Houk : Cost Cutting : 11727 : euclid5
Data structure required : Array of boolean values and an array of
	integers
Tricks of the trade : Used bit representation of relationships in data
	and did comparisons of similar evaluations for a minimal solution.
	WARNING: Solution may not expand to arrays larger than 3 elements.
Problem definition: Read in a value that is the number of lines that
	follow. Each following line contains 3 numbers, representing the
	salary of employees. The goal is to print out the median salary of
	each line in the form "Case i: median" where i is the line of
	salaries that is being evaluated and median is the median salary.
////////////////////////////////////////////////////////////////////*/

#include <iostream>

using namespace std;

int main() {
	// layoffGroups is the number of lines that will follow once it
		// has been read in. max is the value of the max salary in
		// a group at a time. median is the value of the median
		// salary in a group at a time.
	int layoffGroups, max, median;
	// emps is an array of values representing employee salaries.
		// There will only ever be 3 salaries in a group
	int emps[3];
	// isOrdered is a boolean array that will keep the values of if
		// emps[0] < emps[1], emps[1] < emps[2], emps[0] < emps[2]
		//for each index respectively
	bool isOrdered[3];

	cin >> layoffGroups;
	for (int i = 0; i < layoffGroups; i++) {
		for (int j = 0; j < 3; j++) {
			isOrdered[j] = false;
			cin >> emps[j];
			if (j > 0) {
				if (j == 1) {
					if (emps[0] < emps[1]) {
						isOrdered[0] = true;
						max = emps[1];
					}
				}
				else if (j == 2) {
					if (max < emps[2]) {
						max = emps[2];
					}
					if (emps[1] < emps[2]) {
						isOrdered[1] = true;
					}
					if (emps[0] < emps[2]) {
						isOrdered[2] = true;
					}
				}
			}
			else {
				max = emps[1];
			}
		}
		/* The following conclusions are made on the basis of the
			table below which results from isOrdered being calculated
			as mentioned in its definition:

isOrdered[0]:	isOrdered[1]:	isOrdered[2]:	Median Position:
	0				0				0					1
	0				0				1				  empty
	0				1				0			   (2), (0, 2) = 2
	0				1				1			   (0), (0, 1) = 0
	1				0				0			   (0), (0, 2) = 0
	1				0				1			   (2), (1, 2) = 2
	1				1				0				  empty
	1				1				1					1

		  Where the notation (x, y) indicated the median value is in
			position x and position y							  */
		// From the above, when the first two elements are in order
			// the same results can be obtained with the inversion
			// of the values of isOrdered[1] and isOrdered[2]
		if (isOrdered[0]) {
			isOrdered[1] = !isOrdered[1];
			isOrdered[2] = !isOrdered[2];
		}
		if (isOrdered[1]) {
			if (isOrdered[2]) {
				median = emps[0];
			}
			else {
				median = emps[2];
			}
		}
		else {
			median = emps[1];
		}
		cout << "Case " << (i + 1) << ": " << median << endl;
	}
}