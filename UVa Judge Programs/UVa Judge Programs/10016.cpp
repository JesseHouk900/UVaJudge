/*/////////////////////////////////////////////////////////////////////
Jesse Houk :    Flip - Flop the Squarelotron :    10016 :    euclid5

Data structure : 

Tricks of the trade : 

Problem : 

////////////////////////////////////////////////////////////////////*/
#include<iostream>
#include<vector>
using namespace std;

int main() {
    int cases, size, ringNumber, numRingOps;
    cin >> cases;
    for (int caseNum = 0; caseNum < cases; caseNum++) {
        cin >> size;
        vector<vector<int> > squarelotron(size, vector<int>(size));
        for (int r = 0; r < size; r++) {
            for (int c = 0; c < size; c++) {
                cin >> squarelotron[r][c];

            }
        }
        (size % 2) ? ringNumber = (size + 1) / 2 : ringNumber = size / 2;
        vector<vector<int> > ringOperations(ringNumber, vector<int>(ringNumber));
        for (int r = 0; r < ringNumber; r++) {
            cin >> numRingOps;
            for (int ro = 0; ro < numRingOps; ro++) {
                cin >> ringOperations[r][ro];
            }
            for (int ro = 0; ro < numRingOps; ro++) {
                cout << ringOperations[r][ro] << ' ';
                if (ro == numRingOps - 1) {
                    cout << '\n';
                }
            }
        }


        for (int r = 0; r < size; r++) {
            for (int c = 0; c < size; c++) {
                cout << squarelotron[r][c];
                if (c != size - 1) {
                    cout << ' ';
                }
                else cout << '\n';
            }
        }

        for (int j = 0; j < ringOperations.size(); j++) {
            cout << ringOperations[j].size() << '\n';
            for (int i = 0; i < ringOperations[j].size(); i++) {
                cout << ringOperations[j][i];
                if (i != ringOperations[j].size() - 1) {
                    cout << ' ';
                }
                else cout << '\n';
            }
        }
    }
}
