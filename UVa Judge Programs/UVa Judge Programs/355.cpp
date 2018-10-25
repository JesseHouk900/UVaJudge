/*/////////////////////////////////////////////////////////////////////
Jesse Houk :    The Bases are Loaded :    355 :    euclid5

Data structure : Array of integers used to index with ascii values

Tricks of the trade : Indexing an array with ascii values, Horner's Rule for 
    converting to base 10, neat trick for converting from base 10 to any other 
    base. Also realizing that there is probably not a simple method for converting
    directly from one base to another, so I converted to base 10 the to the 
    desired base.

Problem : Given a starting base (integer), an ending base (integer), and some 
    number, determine if the number is in the starting base and what it looks 
    like in the ending base.

Runtime: .000

////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <string> 
#include <algorithm> // reverse

using namespace std;
// taking in a string that holds a number, the starting base, and an array 
// that can use ascii values to retrieve base 10 digit representation, return 
// the number as a base 10 long long
long long numToBase10(const string & num, const int & startBase, const int ascii[128]);
// tking in a possibly large number in base 10, the base to convert to, and a 
// string of possible digits, return the converted number as a string
string base10ToBaseN(long long num, const int & endBase, const string & digits);
int main() {
    int startBase, endBase;
    // a list of all possible digit representations up to base 36
    string num, digits = "0123456789ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    // an array used to be indexed with chars that holds the base 10 
    // representation of a single digit
    int ASCIITable [128];
    // for the length of digits...
    for (int i = 0; i < digits.length(); i++) {
        // assign the base 10 representation
        ASCIITable[digits[i]] = i;
    }
    
    while (cin >> startBase >> endBase >> num) {
        // convert the given number to base 10
        long long numBase10 = numToBase10(num, startBase, ASCIITable);
        // if the number is less than 0...
        if (numBase10 < 0) {
            // it was not an appropriate number in the starting base
            cout << num << " is an illegal base " << startBase << " number\n";
        }
        else {
            // convert base 10 number to the ending base
            string numBaseN = base10ToBaseN(numBase10, endBase, digits);
            // and print the appropriate message
            cout << num << " base " << startBase << " = " << numBaseN << " base " << endBase << '\n';

        }
    }
}
// taking a string representation of a number, the base in which it is starting
// from, and an array with the digit values in the places of ascii values, 
// convert the number to base 10
long long numToBase10(const string & num, const int & startBase, const int ascii[128]) {
    // if the number is not an empty string
    if (num != "") {
        long long base10;
        // check that the first value is less than the base
        if (ascii[num[0]] < startBase) {
            // get the base 10 value of the first digit
            base10 = ascii[num[0]];
        }
        else return -1;
        for (int i = 1; i < num.length(); i++) {
            // check the ith value of the base to be less than the base
            if (ascii[num[i]] < startBase) {
                // use Horner's Rule to convert to base 10
                base10 = (base10 * startBase) + ascii[num[i]];
                
            }
            else return -1;
        }
        return base10;
    }
    return -1;
}
// taking in a number, an ending base, and a string of the possible digits and
// return a string of the number in the ending base
string base10ToBaseN(long long num, const int & endBase, const string & digits) {
    string numBaseN = "";
    do {
        numBaseN += digits[num % endBase];
        num = num / endBase;
    } while (num != 0);
    reverse(numBaseN.begin(), numBaseN.end());
    return numBaseN;
}