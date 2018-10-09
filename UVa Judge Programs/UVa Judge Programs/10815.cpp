/*//////////////////////////////////////////////////////////////////////////////
*	Jesse Houk :   Andy's Dictionary :   10815 :   euclid5
*
*	Data Structures: set of strings for the dictionary
*
*	Tricks of the Trade: Iterating through a set from begin() to end() gets the
		elements in ascending order. Used substr to chop of parts of the string
*
*	Problem: Andy wants a dictionary and is using books from his room to fill it.
		Print out a word per line in ascending order alphabetically.
*
*	Runtime: 0.000
//////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	// Andy's dictionary. Really just a list of unique words
	set<string> dictionary;
	// variable for what word is was most recently read in
	string word;
	// while there is a word to possibly add to the dictionary
	while (cin >> word) {
		// loop through each element of the word
		for (int i = 0; i < word.length(); i++) {
			// if the char is not a letter...
			if (!isalpha(word[i])) {
				// don't add the empty string
				if (word.substr(0, i) != "") {
					// insert the letters read until non alphabet letter is
						// seen as a word
					dictionary.insert(word.substr(0, i));
				}
				// create a string that is the same as the origional without
					// the chars before and including the non alphabet letter
				word = word.substr(i + 1, word.size() - 1);
				// set the index to start at 0 when the next iteration starts
				i = -1;
			}
			// else, check if alpha char is upper
			else if (isupper(word[i])) {
				// if so, make lower
				word[i] = tolower(word[i]);
			}
		}
		// don't add the empty string as a word
		if (word != "") {
			dictionary.insert(word);
		}
	}
	// utilize the underlying red-black tree (special BST) of the set to print
		// the elements in order
	for (set<string>::iterator it = dictionary.begin(); it != dictionary.end(); ++it) {
		// access the value pointed to by the iterator
		cout << *it << '\n';
	}
}