/*/////////////////////////////////////////////////////////////////////
Jesse Houk :    Rails :    514 :    euclid5

Data structure : stack

Tricks of the trade : do it right 

Problem : receiving train cars 1 through n determine if they can be
	rearranged using a stack to leave in the order specified by the
	following lines of numbers 1 through n in any order. A new set is
	indicated by a 0 and the program is terminated on 2 consecutive 0s
////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <stack>
#include <vector>
using namespace std;


int main () {
	// numCars is how many train cars are coming in. nextOut is what car
		// that needs to leave next for the order to be possible
	int numCars, nextOut;
	// while the file has not abrupty ended and the n number of cars
		// is not 0...
	while (cin >> numCars && numCars != 0) {
		// let c be the number of the train car that is incoming, will
			// always be 1, 2, ... , n
		int c = 1;
		// use a stack to take in trains
		stack<int> station;
		// used to alternate between checking the stack and checking c
		bool incomingTrain = true;
		// count how any trains have gone through
		int out = 0;
		// get the first order
		cin >> nextOut;
		// while the terminating signal is not found...
		while (nextOut != 0) {
			// check that a train should be coming in and that
				// not all the trains have not already gone
			if (incomingTrain && c <= numCars) {
				// check if the train coming in is the one needed
				if (c == nextOut) {
					// if it is, get the next train
					c++;
					// increase the amount that has gone out
					out++;
					// check that there is still a remaining train to be
						// ordered
					if (out < numCars) {
						// if so, get that required train
						cin >> nextOut;
					}
					// signal to check the stack
					incomingTrain = false;
				}
				// if the current train car is not te desired train car...
				else {
					// put it in the station
					station.push(c);
					// and get a new train
					c++;
				}
			}
			// if a train is not coming into the station, check the station
			else {
				// make sure the station is not empty
				if (!station.empty()) {
					// check if the last train in the station is the one
						// that is needed
					if (station.top() == nextOut) {
						// if it is, let it leave the station
						station.pop();
						// if the number of trains let through is not yet the
							// total number of cars...
						if (out < numCars - 1) {
							// get the next one
							cin >> nextOut;
						}
						// increment the number of trains that have left
						out++;
					}
					// if the next train car number is higher than the number
						// of train cars that should be grouped together...
					else if (c > numCars) {
						// skip until the last car
						for (; out < numCars - 1; out++) {
							cin >> nextOut;
						}
						out++;
					}
					// else try the incoming trains again
					else {
						incomingTrain = true;
					}
				}
				// if the station is empty, try the incoming trains again
				else {
					incomingTrain = true;
				}
			}
			// if all train cars have been sent out...
			if (out == numCars) {
				// reset the out counter
				out = 0;
				// make the next train a first train car
				c = 1;
				// if the station is empty, that implys the train order
					// was achievable
				if (station.empty()) cout << "Yes";
				else cout << "No";
				cout << '\n';
				// get the first desired train car number
				cin >> nextOut;
				// empty the station
				station = stack<int>();
				// accept incoming trains (can't use station because it is
					// empty)
				incomingTrain = true;
			}
		}
		// print a line to seperate where a new number of cars is used
		cout << '\n';
	}
}
