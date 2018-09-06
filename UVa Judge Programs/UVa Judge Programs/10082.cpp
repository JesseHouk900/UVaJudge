/*/////////////////////////////////////////////////////////////////////////////

 Jesse Houk:   WERTYU:   10082:   euclid5

Data structure required: Array of chars

Tricks of the trade: Make a table of ascii values and use it as an encoding
	tool where we read in the correct value into the encoded character's
	position.

Purpose: Given an undetermined number of encrypted lines, print out the correct
	message. The encryption is done such that a given character is the
	character to the left of the intended character on the keyboard, excluding
	Q, A, Z (and q, a, z).

/////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <string>

using namespace std;

int main() {
	string uncoded = "QWERTYUIOP[]ASDFGHJKLM;ZXCVBNM,.`1234567890-";
	string encoded = "WERTYUIOP[]\\SDFGHJKL;,'XCVBNM,./1234567890-=";
	string coded = "", decoded = "";
	char Table[128];
	Table[32] = ' ';
	for (int i = 0; i < encoded.length(); i++) {
		Table[encoded[i]] = uncoded[i];
	}
	while (getline(cin, coded)) {
		decoded = "";
		for (int i = 0; i < coded.length(); i++) {
			decoded += Table[coded[i]];
			cout << decoded[i];
		}
		cout << endl;
	}
}