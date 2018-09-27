/*/////////////////////////////////////////////////////////////////////
Jesse Houk :    Rails :    514 :    euclid5

Data structure : 

Tricks of the trade : 

Problem : 

////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <stack>

using namespace std;

int main () {
	// used to represent a train station where there is one entrance  and exit
    stack<int> station;
	// numCars is the number of cars that will be coming in and need to be
		// rolled out in the specified order
	// nextOut is used to track the next train that needs to be rolled out
	int numCars, nextOut;
	// isPossible tracks whether the car order is achievable with the single
		// "stack" architecture of the train depot in use
    bool isPossible;
	// while a car number can be read in and it is not zero
    while (cin >> numCars && numCars != 0) {
        isPossible = true;
        // check for valid order
        cin >> nextOut;
        for()
		//for (int c = 1; /*cin >> nextOut &&*/ nextOut != 0;) {
        //    if (c <= numCars ) {
        //        // if the car desired to go is not the car coming in
        //        if (nextOut != c) {
        //            // if the station is empty, put the incoming train in it
        //            // check if the car in the station is not the one desired
        //            if (station.size() == 0 || nextOut != station.top()) {
        //                station.push(c);
        //                c++;
        //            }
        //            else {
        //                station.pop();
        //                cin >> nextOut;
        //            }
        //        }
        //        else {
        //            cin >> nextOut;
        //        }
        //    }
        //    else {
        //        isPossible = false;
        //        c = 1;
        //    }


        //}
        if (isPossible) {
			cout << "Yes\n";
        }
		else {
			cout << "No\n";
		}
    }
}