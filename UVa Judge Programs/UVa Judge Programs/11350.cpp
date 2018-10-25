/*/////////////////////////////////////////////////////////////////////
Jesse Houk :    Stern-Brocot Tree :    11350 :    euclid5

Data structure : Mimicing a BST

Tricks of the trade : recursion

Problem : Given a path of Ls and Rs (lefts and rights), find the Stern-Brocot Tree number

Runtime: .010       Could be better

////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <string>

using namespace std;
// shorten the typing of a pair of long longs to just Pair
typedef pair<long long, long long> Pair;
// taking in two Stern-Brocot Tree Values and a string that is the path, return the 
// resulting Stern-Brocot number found by traversing the path
Pair SBTree(Pair, Pair, string&);

int main() {
    int values;
    cin >> values;
    while (values > 0) {
        string path;
        cin >> path;
        // get the Stern-Brocot number given by the path, starting with a left 
        // number that represents 0 and another that represents infinity
        Pair SB = SBTree(Pair(0, 1), Pair(1, 0), path);
        // print the Stern-Brocot number
        cout << SB.first << '/' << SB.second << '\n';
        values--;
    }
}
// Taking in a Left Stern-Brocot number, a Right Stern-Brocot number, and a 
// path of Ls and Rs, recursively find the Stern-Brocot number at the end of 
// the path
Pair SBTree(Pair L, Pair R, string & path) {
    // if there is still a path to follow
    if (path.size() != 0) {
        // get the next direction
        char dir = path[0];
        // remove the next direction from the path
        path.erase(path.begin());
        // if the path says go left...
        if (dir == 'L') {
            // keep the left Stern-Brocot number and make the right number the 
            // mediant of the Left and Right (L = a / b, R = c / d, 
            // mediant = (a + c) / (b + d))
            return SBTree(L, Pair(L.first + R.first, L.second + R.second), path);
        }
        else {
            // make the left Stern-Brocot number the mediant of the Left and Right 
            // and keep the right  Stern-Brocot number (L = a / b, R = c / d,
            // mediant = (a + c) / (b + d))
            return SBTree(Pair(L.first + R.first, L.second + R.second), R, path);
        }

    }
    else { // you are at the end of the path
        // so return the final mediant
        //(L = a / b, R = c / d, mediant = (a + c) / (b + d))
        return Pair(L.first + R.first, L.second + R.second);
    }
}