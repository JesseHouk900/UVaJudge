/******************************************************************************
	Jesse Houk: There's Treasure Everywhere   : 587   : euclid5

	Data Structures: a map of directions to ordered pairs

	Tricks of the Trade: horner's rule, instant access ascii converstion (with a
		table), use math (trig), read into a string, load a string stream with
		that string, read characters from string stream

	Problem: given a set of instructions, "4N,7NW,14E." for example, determine
		the distance to the endpoint of the route you would travel.

	Runtime: 0.000
******************************************************************************/
#include <iostream>
#include <map>
#include <sstream>
#include <string>
#include <iomanip> // fixed << setprecision(3)
#include <math.h>
// an easier way to get the data structure of a pair of double variables
#define point pair<double, double>
// square root of 2, used for the distance on diagonals
const double SQRT_2 = sqrt(2);
using namespace std;

int main() {
	// a mapping of directions, N, E, W, S, NW, NE, SW, SE, to constant values
	// that are a unit of a step in that particular direction
	map<string, point> dirs;
	// the point that is the result of each step, when done, this will be the
	// location of the treasure
	point treasureLocation;
	// used to hold a line read in from cin
	string line;
	// a stream that can be read from that will consist of line
	stringstream map;
	// a quick access table for chars
	char ASCIITable[128];
	// used to read from map one character at a time
	char token;
	// values that will be used for reading from map
	string dir = "0123456789ENSW";
	// variable for how many steps the current instruction requires you to take
	double steps;
	// tells when it is the end of the line
	bool keepGoing = true;
	// set output of real numbers to have 3 decimal places
	cout << fixed << setprecision(3);
	// read in the values from dir to the ASCIITable
	for (int i = 0; i < 36; i++) {
		// read in the integer values for the character values that represent
		// integers
		if (i < 10) {
			ASCIITable[dir[i]] = i;
		}
		// read in the letters that will be used for directions
		else {
			ASCIITable[dir[i]] = dir[i];
		}
	}
	// initialize the values of each direction to act as units in a given direction
	dirs["N"] = point(0, 1);
	dirs["E"] = point(1, 0);
	dirs["S"] = point(0, -1);
	dirs["W"] = point(-1, 0);
	// one step in a diagonal is not a step that has a unit point of (1, 1)
	//               /|			pow(a, 2) + pow(b, 2) = pow(c, 2)
	//              / |			pow(1, 2) + pow(1, 2) = pow(c, 2)
	//             /  |			    1     +     1     = pow(c, 2)
	//            /   |					  2           = pow(c, 2)
	//           /    |				   sqrt(2)        = sqrt(pow(c, 2))
	// sqrt(2)  /     |				   sqrt(2)        = c
	//         /      |1
	//        /       | 
	//       /        |
	//      /         | 
	//	   /          |
	//    /___________|
	//           1 
	dirs["NE"] = point(1 / SQRT_2, 1 / SQRT_2);
	dirs["NW"] = point(-1 / SQRT_2, 1 / SQRT_2);
	dirs["SE"] = point(1 / SQRT_2, -1 / SQRT_2);
	dirs["SW"] = point(-1 / SQRT_2, -1 / SQRT_2);
	// initialize i before the for loop so that the first part of the for loop
	// can initialize all the necessary values
	int i;
	// reset values of steps and dir to 0 and the empty string, respectively
	// then loop while a line can be read from the input and that line is not END
	for (i = 0, steps = 0, dir = ""; cin >> line && line != "END"; steps = 0, i++) {
		// load map to have line as it's "output"
		map.str(line);
		// while there is a character that can be read from map and you are not
		// at the end of the map yet
		while (map >> token && keepGoing) {
			// if the character is a digit...
			if (isdigit(token)) {
				// use horner's rule to make a valid integer from the input
				steps = (steps * 10) + ASCIITable[token];
			}
			// else, check if the character is an alphabetic letter...
			else if (isalpha(token)) {
				// if so, add it to the direction
				dir += token;
			}
			// else it is comma and end of direction letters
			else {
				// take the step in it's x direction
				treasureLocation.first += (dirs[dir].first * steps);
				// take the step in it's y direction
				treasureLocation.second += (dirs[dir].second * steps);
				// reset the direction...
				dir = "";
				// and the steps necessary to progress
				steps = 0;
				// if the character read in is a . ...
				if (token == '.') {
					// signal to read a new line and exit the while loop
					keepGoing = false;
					// put the map read position back to the beginning
					map.seekg(0, map.beg);
				}
			}
		}
		// set keepGoing back to allow you to continue to read from the file
		keepGoing = true;
		// print out the map location and the distance from point (0, 0) to
		// that location
		cout << "Map #" << i + 1 << "\nThe treasure is located at (" <<
			treasureLocation.first << ',' << treasureLocation.second <<
			").\nThe distance to the treasure is " << sqrt((treasureLocation.first
			* treasureLocation.first) + (treasureLocation.second
			* treasureLocation.second)) << ".\n\n";
		treasureLocation = point();
	}

}