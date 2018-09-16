/*/////////////////////////////////////////////////////////////////////////////

Jesse Houk:    Rotated Square:    10855:     euclid5

Data Structures:

Tricks of the Trade:

Problem: 

/////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    int n, N;
    while (cin >> N >> n && (N != 0 || n != 0))  {
        vector<bool> isPresent;
        vector<int> occurences;
        vector<string> NxN(N);
        vector<string> nxn(n);
        char temp;
        for (int i = 0; i < 4; i++) {
            isPresent.push_back(true);
            occurences.push_back(0);
        }
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
                        if (isPresent[0] && (NxN[R + r][C + c] != nxn[r][c])) {
                            isPresent[0] = false;
                        }
                        if (isPresent[1] && (NxN[R + r][C + c] != nxn[n - c - 1][r])) {
                            isPresent[1] = false;
                        }
                        if (isPresent[2] && (NxN[R + r][C + c] != nxn[n - r - 1][n - c - 1])) {
                            isPresent[2] = false;
                        }
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
        }    
        cout << '\n';       
    }
}