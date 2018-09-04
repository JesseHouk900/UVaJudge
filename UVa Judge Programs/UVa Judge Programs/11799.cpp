/*/////////////////////////////////////////////////////////////////////////////
 
 Jesse Houk:   Horror Dash:   11799:   euclid5

Data structure required:

Tricks of the trade: Evaluate data as it comes in

Purpose: Read in an integer that tells how many lines follow. Then, at the
	beginning of each line is an integer that tells how many numbers follow in
	that line. For each line, find the max speed and print it out as speed in
	the message "Case i: speed" where i is the line number.

/////////////////////////////////////////////////////////////////////////////*/

#include <iostream>

using namespace std;

int main() {
	int currentSpeed, maxSpeed;
	int numRunners = 0, races = 0;
	cin >> races;
	for (int h = 0; h < races; h++) {
		maxSpeed = 0;
		cin >> numRunners;
		for (int i = 0; i < numRunners; i++) {
			cin >> currentSpeed;
			if (currentSpeed > maxSpeed) {
				maxSpeed = currentSpeed;
			}

		}
		cout << "Case " << (h + 1) << ": " << maxSpeed << endl;
	}
}