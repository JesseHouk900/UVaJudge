/*/////////////////////////////////////////////////////////////////////
Jesse Houk :    Continued Fractions :    834 :    euclid5

Data structure : string

Tricks of the trade : 

Problem : Given two numbers, n and m, find the series of numbers that make a 
    continued fraction to represent n / m

Runtime: .000

////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <string>
#include <algorithm> //swap
using namespace std;

int main() {
    int num, den;
    // a string that will represent the continued fraction of num / den in the 
    // form of [b0;b1,b2,...,bn]
    string contFract;
    while (cin >> num >> den) {
        // add [b0 to the string
        contFract = "[" + to_string(num / den);
        // take away what was added onto the string
        num = num % den;
        // if the fraction given was not an integer...
        if (num != 0) {
            // add a ; so that you now have [b0;
            contFract += ";";

        } 
        // while there is still some remainder from modulus...
        while (num != 0) {
            swap(num, den);
            // add in the next b term
            contFract += to_string(num / den);
            num = num % den;
            // if there are still bs to be found...
            if (num != 0) {
                // add a commma to seperate
                contFract += ",";
            }
        }
        // finish the string with a closing brace
        contFract += "]";
        // and print the abbreviated continued fraction list
        cout << contFract << '\n';
    }
}