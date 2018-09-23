/*/////////////////////////////////////////////////////////////////////////////

Jesse Houk:    Rotated Square:    10855:     euclid5

Data Structures: 2 matricies that represent a vector of vectors of chars as a
	vector of strings.

Tricks of the Trade: Used parallel vectors to monitor when an occurence of the
	smaller array is found

Problem: Given a square matrix and a smaller square matrix, find the occurences
of the smaller matrix within the larger one rotated 0, 90, 180, and 270 degrees.

/////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
	int n, N;
	// used to track presence of the smaller matrix through a single iteration
	vector<bool> isPresent(4, true);
	// used to track how many times the smaller matrix has been seen at a given
		// angle. [0] refers to 0 degrees, [1] is 90 degrees, [2] is 180 degrees,
		// and [3] is 270 degrees. occurences is parallel with isPresent
    vector<int> occurences(4, 0);
    while (cin >> N >> n && (N != 0 || n != 0))  {
		// This is the larger matrix
        vector<string> NxN(N);
		// This is the smaller matrix
        vector<string> nxn(n);
        char temp;
        //for (int i = 0; i < 4; i++) {
           // isPresent.push_back(true);
          //  occurences.push_back(0);
        //}
        for (int i = 0; i < N; i++) {
            cin >> NxN[i];
        }
        for (int i = 0; i < n; i++) {
            cin >> nxn[i];
        }
        for (int R = 0; R <= N - n; R++) {
            for (int C = 0; C <= N - n; C++) {
                for (int r = 0; r < n; r++) {
                    for (int c = 0; c < n; c++) {
						// Check 0 degrees
                        if (isPresent[0] && (NxN[R + r][C + c] != nxn[r][c])) {
                            isPresent[0] = false;
                        }
						// Check 90 degrees clockwise
                        if (isPresent[1] && (NxN[R + r][C + c] != nxn[n - c - 1][r])) {
                            isPresent[1] = false;
                        }
						// Check 180 degrees clockwise (or counter-clockwise)
                        if (isPresent[2] && (NxN[R + r][C + c] != nxn[n - r - 1][n - c - 1])) {
                            isPresent[2] = false;
                        }
						// Check 270 degrees clockwise
                        if (isPresent[3] && (NxN[R + r][C + c] != nxn[c][n - r - 1])) {
                            isPresent[3] = false;
                        }
                    }
                } // end of filter
                for (int i = 0; i < 4; i++) {
                    if (isPresent[i]) {
                        occurences[i]++;
                    }
                    else isPresent[i] = true;
                }
            }
        } //end of NxN parsing
        for (int i = 1; i < 5; i++) {
            cout << occurences[i - 1];
            if (i % 4) {
                cout << " ";
            }
			occurences[i - 1] = 0;
        }    
        cout << '\n';       
    }
}