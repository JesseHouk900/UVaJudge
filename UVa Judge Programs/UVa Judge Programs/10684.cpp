/******************************************************************************
	Jesse Houk : The jackpot : 10684 : euclid5

	Data Structures :

	Tricks of the Trade :   do an on-the-fly load and evaluate using Jay Kadane's
		range sum query (RSQ) algorithm.

	Problem: reading in a positive integer, N, followed by N integers, find the
		highest sum of any range within the N integers in the order they are
		given.

	Runtime:  0.030		Hmm, still not the best
******************************************************************************/
#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	// read from stdi0 faster
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// a value to hold the number of incoming bets that are made
	int numBets;
	// bet - holds the current bet to be added to the currentRangeTotal
	// currentRangeTotal - the sum of any plausible of range
	// highestRangeTotal - the highest sum of any range in bets
	int bet, currentRangeTotal, highestRangeTotal;
	// while there is a number to read...
	while (cin >> numBets) {
		// if that number is 0 (integers evaluate to true, not true is false
			// but 0 evaluates to 1 when notted)...
		if (!numBets) {
			// terminate the program
			return 0;
		}
		highestRangeTotal = currentRangeTotal = 0;
		while (numBets--) {
			cin >> bet;
			highestRangeTotal = max(highestRangeTotal, currentRangeTotal+= bet);
			if (currentRangeTotal < 0) {
				currentRangeTotal = 0;
			}
		}
		// if the highestRangeTotal is 0...
		(highestRangeTotal == 0) ?
			cout << "Losing streak.\n" : 
			// else
			cout << "The maximum winning streak is " << highestRangeTotal << ".\n";
		
		
	}
}