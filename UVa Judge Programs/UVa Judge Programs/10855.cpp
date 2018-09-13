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

void Rotate(vector<string>&, int, vector<vector<vector<vector<int> > > > &, int);

void printMat(const vector<string> &, int);

int main() {
    int n, N;
    while (cin >> N >> n && (N != 0 || n != 0))  {
    vector<vector<vector<vector<int> > > > rotationPositions (n, vector<vector<vector<int> > >(n, vector<vector<int> >(4, vector<int>(2))));
        vector<int> occurences = {0, 0, 0, 0};
        vector<string> NxN(N);
        for (int i = 0; i < N; i++) {
            cin >> NxN[i];
        }
        vector<string> nxn(n);
        for (int i = 0; i < n; i++) {
            cin >> nxn[i];
        }
        Rotate(nxn, n, rotationPositions, 4);
        for (int r = 0; r < n; r++) {
            for (int c = 0; c < n; c++) {
                for (int rn = 0; rn < 4; rn++) {
                    cout << "("; 
                    for (int d = 0; d < 2; d++) {
                        cout << rotationPositions[r][c][rn][d];
                        if (!d) {
                            cout << ", ";
                        }
                    }
                    cout << ") ";
                }
                cout << '\n';
            }
        }    
        printMat(NxN, N);
        printMat(nxn, n);
        
        
    }
}
// rots is a vector of of vectors of vectors of indicies that keeps track the rotatated filter. For example, rots[1][2][3] is the vector of v[1][2] when rotated 270 degrees, the only elements are the row and column
void Rotate(const vector<string> & v, int n, vector<vector<vector<vector<int> > > > & rots, int numRots) {
    for (int r = 0; r < n; r++) {
        for (int c = 0; c < n; c++) {
            vector<int> vals = {r, c, n - r - 1, n - c - 1};
            int vi = 1;
            for (int rn = 0; rn < numRots; rn++) {
                for (int d = 0; d < 2; d++) {
                    rots[r][c][rn][d] = vals[(vi / 2) % numRots];
                    vi++;
                }
            }
        }
    }
}

void printMat(const vector<string> & v, int n) {
    for (int i = 0; i < n; i++) {
        for (int j = 0; j < n; j++) {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
}