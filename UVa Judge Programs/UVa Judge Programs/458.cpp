/*-----------------------------------------------------------------------------
Jesse Houk:    The Decoder:    458:    euclid5

Data structure required : N/A

Tricks of the trade : Cast characters after modifying them by their ascii code

Problem definition : Read in an unknown number of lines that are encoded and
	print their decoded message

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