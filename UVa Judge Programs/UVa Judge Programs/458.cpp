/*-----------------------------------------------------------------------------
Jesse Houk:    The Decoder:    458:    euclid5

Data structure required : 

Tricks of the trade : 

Problem definition : 

Runtime: 0.040
-----------------------------------------------------------------------------*/
#include <iostream>
#include <string>

using namespace std;

int main() {
    string line;
    while(getline(cin, line)) {
        for (int i = 0; i < line.length(); i++) {
            cout << static_cast<char>(line[i] - 7);
        }
        cout << endl;
    }
}