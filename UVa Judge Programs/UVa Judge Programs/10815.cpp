#include <iostream>
#include <set>
#include <string>

using namespace std;

int main() {
	set<string> dictionary;
	string word;
	while (cin >> word) {
		for (int i = 0; i < word.length; i++) {
			if (isupper(word[i])) {
				word[i] = tolower(word[i]);
			}
		}
		dictionary.insert(word);
	}
	for (int i = 0; i < dictionary.size; i++) {
		cout << dictionary;
	}
}