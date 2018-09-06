/*/////////////////////////////////////////////////////////////////////////////

 Jesse Houk:   WERTYU:   10082:   euclid5

Data structure required:

Tricks of the trade: Evaluate data as it comes in

Purpose: 

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