/******************************************************************************
	Jesse Houk: Is This Integration?   : 10209   : euclid5

	Data Structures: 

	Tricks of the Trade: trig, Dr. Cobb, math, math, math. Specifically, 
		given a circle of radius a, a sector of the circle with angle B,
		the area of the segment is ((B / 360) * (PI * pow(a, 2))) - area of the
		triangle.						area of segment
		The area of the triangle is sqrt(s * (s - a) * (s - b) * (s - c)) where
		a, b, c are the side lengths of a triangle and s = (a + b + c) / 2.
		For the third side of any triangle, given 2 sides and an angle, side 3
		is sqrt(2) * ((1 + sqrt(3)) / 2). 

	Problem: given the length of the side of a square, find the area of 3 distinct
		regions that are formed when drawing 4 circles on the verticies of the square

	Runtime: 0.000
******************************************************************************/
#include <iostream>
#include <math.h> // sqrt
#include <iomanip> // fixed << setprecision(3)
using namespace std;
// get a constant variable that is the value of pi, sqrt(2), sqrt(3), to save
// on processing time
double const PI = acos(-1.0);
double const SQRT_2 = sqrt(2);
double const SQRT_3 = sqrt(3);
// calculate the area of a triangle
double Area(const double&, const double&, const double&);

int main() {
	// variable for the length of a side of a square that is read in from the input
	double sideLength;
	// an array for the areas of each area desired
	double areas[3];
	// speed up the processing of IO
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	// make it so that numbers that are printed out have 3 decimal places
	cout << fixed << setprecision(3);
	// while there is a value to read in...
	while (cin >> sideLength) {

		// get X with isosceles triangels
		// find the unknown side of the triange that is drawn from one vertex
		// to the further intersection of circle drwan from that vertex with
		// other circles
		double XshortSide = sideLength / (SQRT_2 * ((1 + SQRT_3) / 2));
		// get the area of the triange formed by the sides previously mentioned
		double area = Area(sideLength, sideLength, XshortSide);
		// save the area of the middle inflated square as the first index of
		// areas. This area is calculated by 4 * the area of the segment of the
		// sector + the area of the square found by the missing side of the
		// triangle squared
		areas[0] = (4 * (((1 / 12.0) * (PI * sideLength * sideLength))
			- area)) + (XshortSide * XshortSide);
		// get Y with right, isosceles triangle
		// now observe the triangle formed by 2 sides of the square, the missing
		// side is then simply sqrt(2) * the length of the side
		double shortside = SQRT_2 * sideLength;
		// the area is then calculated
		area = Area(sideLength, sideLength, shortside);
		// L is then the segment of that sector
		double L = ((PI * sideLength * sideLength) / 4) - area;
		// one of the shapes protruding from the inflated square is then L minus
		// one half of the shape first calculated. 4 of these will give you the
		// full area of these protruding shapes
		areas[1] = 4 * (L - (areas[0] / 2));
		// get Z with subtraction
		// then the remaining area can be calculated by taking the area of the
		// square minus the first and second calculated areas added together
		areas[2] = (sideLength * sideLength) - (areas[1] + areas[0]);
		// print the areas in the order they were found
		cout << areas[0] << " " << areas[1] << " " << areas[2] << "\n";
	}
}

// calculate the area of any triangle given 3 sides using heron's formula
double Area(const double & a, const double & b, const double & c) {
	// first calculate the semi-perimeter
	double semiPerimeter = (a + b + c) / 2;
	// use heron's formula to calculate the area
	return sqrt(semiPerimeter * (semiPerimeter - a)
		* (semiPerimeter - b) * (semiPerimeter - c));
}