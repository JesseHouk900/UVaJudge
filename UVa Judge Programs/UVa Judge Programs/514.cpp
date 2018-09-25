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
    stack<int> station;
    int numCars, nextOut;
    bool isPossible;

    while (cin >> numCars && numCars != 0) {
        isPossible = true;
        // check for valid order
        cin >> nextOut;
        for (int c = 1; /*cin >> nextOut &&*/ nextOut != 0;) {
            if (c <= numCars ) {
                // if the car desired to go is not the car coming in
                if (nextOut != c) {
                    // if the station is empty, put the incoming train in it
                    // check if the car in the station is not the one desired
                    if (station.size() == 0 || nextOut != station.top()) {
                        station.push(c);
                        c++;
                    }
                    else {
                        station.pop();
                        cin >> nextOut;
                    }
                }
                else {
                    cin >> nextOut;
                }
            }
            else {
                isPossible = false;
                c = 1;
            }


        }
        if (isPossible) {
            cout << "Yes"
        }
    }
}