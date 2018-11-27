/*/////////////////////////////////////////////////////////////////////////////

	Jesse Houk :	Largest Submatrix :	   836 :	euclid5

	Data Structures : RSQMatrix

	Tricks of the Trade : Range Sum Query

	Problem : given some number of matricies to read in, read in those matricies
		and determine the maximum size of a submatrix within each matrix. The
		size of a submatrix is the number of continuious 1s to form a rectangle.
		For instance:
			111
			111
			111 
		has a maximum size of a submatrix at 9, whereas
			011
			111
			111
		has a maximum size of a submatrix at 6, limited by the 0.

	Runtime : 0.000		Woot
/////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <vector>
#include <string>

using namespace std;

// load the matrix passed in
void getMatrix(vector<vector<int> > & m);
// take the matrix m and process it into the matrix pm, of the same dimensions
void processMatrix(const vector<vector<int> > & m, vector<vector<int> > & pm);
// return the max size of a submatrix in matrix m
int getMax(const vector<vector<int> > & m);
// return the number of active elements in b from b[0][0] to b[k][l]
int PreprocessSum(vector<vector<int> > & b, const int & k, const int & l);
// return the number of active elements in b from b[i][j] to b[k][l] from the
	// PreprocessSum-ed matrix m
int NumSubMatrixElements(const vector<vector<int> > & m, const int & i, 
	const int & j, const int & k, const int & l);

int main() {
	// make two matricies, one for the data to be read in, the other to be
		// used after the data is processed
	vector<vector<int> > matrix, preprocessedMatrix;
	// cases is used for the number of matricies to be processed currently
	// max is used for what the maximum size of a submatrix in the given matrix is
	int cases, max;
	// while there are cases to process...
	while (cin >> cases) {
		// ignore the end of the line cases is read from and the line after
		cin.ignore(), cin.ignore();
		// loop through those cases
		for (int i = 0; i < cases; i++) {
			// read in the matrix
			getMatrix(matrix);
			// process matrix and save into preprocessedMatrix
			processMatrix(matrix, preprocessedMatrix);
			// get the max size of a submatrix from this preprocessed matricies
			max = getMax(preprocessedMatrix);
			// print out the max
			cout << max << '\n';
			// if the case is not the last case...
			if (i != cases - 1) {
				// print another line
				cout << '\n';
			}
			// reset the two matricies
			matrix = preprocessedMatrix = vector<vector<int> >();
		}
	}
}
// read in the values for a matrix m
void getMatrix(vector<vector<int> > & m) {
	// string used to read in one line of elements at a time
	string line;
	// loop while there is a line to get from standard in and the line is not 
		// empty 
	for (int i = 0; getline(cin, line) && line != ""; i++) {
		// make a new row in m
		m.push_back(vector<int>());
		// loop through the line
		for (int j = 0; j < line.size(); j++) {
			// adding the values in the line to the matrix (assumption that the
				// input is going to be integers mushed together)
			m[i].push_back(line[j] - '0');
		}
	}
}
// fill out the matrix pm to have the RSQMatrix of m based on whether m[i][j] = 1
	// for m, an MxN matrix, i in {0, 1, ..., M - 1}, and j in {0, 1, ..., N - 1}
void processMatrix(const vector<vector<int> > & m, vector<vector<int> > & pm) {
	// get the size of the rows of the matrix m and add one to make the code
		// easier. Do the same for the columns, similar to an RSQMatrix 
	int rows = m.size() + 1, cols = m[0].size() + 1;
	// set pm to be of the dimensions described above and set all the elements
		// to 0
	pm = vector<vector<int > >(rows, vector<int>(cols, 0));
	// loop through the rows starting at 1
	for (int r1 = 1; r1 < rows; r1++) {
		// loop through the columns starting at 1
		for (int c1 = 1; c1 < cols; c1++) {
			// set the pm[r1][c1] element to the sum of active elements from
				// m[0][0] to m[r1 - 1][c1 - 1]
			pm[r1][c1] = PreprocessSum(pm, r1, c1) + m[r1 - 1][c1 - 1];
		}
	}
}
// return the maximum continuious size of a submatrix consisting of only 1s
	// to form a rectangle
int getMax(const vector<vector<int> > & m) {
	// get the dimensions of m and a variable that will hold the max size of
		// a submatrix in m
	int rows = m.size(), cols = m[0].size(), max = 0;
	// bool to know if continuing to check columns will be productive, assume
		// true
	bool checkCols = true;
	// the following 4 for loops are used to find all points (r1, c1), (r2, c2)
		// within m to determine a max submatrix size
	for (int r1 = 1; r1 < rows; r1++) {
		for (int c1 = 1; c1 < cols; c1++) {
			// loop for (r2, c2) starting r2 and c2 at r1 and c1, respectively,
				// so as to be more effiecient
			for (int r2 = r1, numElements; r2 < rows; r2++) {
				// ensure that the columns should be checked to continue in the
					// loop
				for (int c2 = c1; c2 < cols && checkCols; c2++) {
					// get the number of elements of the submatrix from m[r1][c1]
						// to m[r2][c2]
					numElements = NumSubMatrixElements(m, r1, c1, r2, c2);
					// if the size of the submatrix is equal to the number of
						// elements...
					if ((1 + r2 - r1) * (1 + c2 - c1) == numElements) {
						// and that number of elements is greater than the 
							// current max...
						if (max < numElements) {
							// set the max equal to the number of elements
							max = numElements;
						}
					}
					else { // there are less elements than there can be, so
							// there can not be any more to gain by continuing
						// so stop checking the columns
						checkCols = false;

					}
				}
				// new iteration, so start by checking the columns
				checkCols = true;
				
			}
		}
	}
	// return the max size of a submatrix in m
	return max;
}
// take in a matrix and some position within that matrix as k, for the row, and
	// l, for the column
int PreprocessSum(vector<vector<int> > & b, const int & k, const int & l) {
	// return the sum of the number of active elements (positions in original
		// matrix that were 1's) in the submatrix to the left of position b[k][l]
		// plus the number of active elements in the submatrix above position
		// b[k][l] minus the elements shared by both submatricies
	return b[k - 1][l] + b[k][l - 1] - b[k - 1][l - 1];
}
// take in a matrix, an i and j corresponding to the upper left corner of a submatrix,
	// and a k and l corresponding to the lower right corner of a submatrix and
	// return the number of elements in the submatrix. NOTE: the number of
	// elements in the submatrix != size of the submatrix
int NumSubMatrixElements(const vector<vector<int> > & m, const int & i, const int & j, const int & k, const int & l) {
	// take the elements in the submatrix from m[0][0] to m[k][l] minus the 
		// elements in the submatrix of the same width, but without the elements
		// in the i through k rows minus the elements in the submatrix of the
		// original height, but without the elements in the columns j through l
		// plus the elements in the submatrix that were subtracted twice
	return m[k][l] - m[i - 1][l] - m[k][j - 1] + m[i - 1][j - 1];
}