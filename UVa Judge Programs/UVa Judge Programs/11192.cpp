/*/////////////////////////////////////////////////////////////////////////////

Jesse Houk:    Group Reverse:    11192:    euclid5

Data Structures : vector

Tricks of the trade : Loop through segments of the string and work from both
    ends of the segment

Problem : Read in an integer that defines the number of groups that will be
    reversed, n. Then read in a string of characters that has a length
    divisable by n, L. The goal is to reverse these n groups in the text and to
    print it back out. The process is repeated and stops when n = 0;

/////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main() {
    // text is the string that will be processed
    string text = "";
    // numGroups is the number of groups that will be reversed within text
    int numGroups = 0;
    // groupSize is the number of elements in each group
    int groupSize = 0;
    // offset is used to move the swap process inward from the right
    int offset;
    // temp is used for swapping
    int temp;
    // right is the right index while swapping
    int right;
    while (cin >> numGroups  && numGroups != 0) {
        cin >> text;
        // groupSize is the number of characters per group
        groupSize = text.length() / numGroups;
        // groupIndicies is a vector that will be used to hold starting and
            // stopping indicies to aid in processing
        vector<int> groupIndicies(numGroups + 1);
        // each element of groupIndicies is a multiple of the groupSize
        for (int i = 0; i < groupIndicies.size(); i++) {
            groupIndicies[i] = groupSize * i;
        }
        // begin the reverse process
        for (int i = 0; i < groupIndicies.size() - 1; i++) {
            // reset the value of offset to it's base value
            offset = 1;
            // loop through the indicies from one starting point to the ending
                // point
            for (int j = groupIndicies[i]; j < groupIndicies[i + 1]; j++) {
                // right is the index starting at the end, effected by the
                // left-moving offset
                right = groupIndicies[i + 1] - offset;
                // as long as j refers to an index further left than right...
                if (j < right) {
                    // perform a swap
                    temp = text[j];
                    text[j] = text[right];
                    text[right] = temp;
                    // and increment the distance from the right right should be
                    offset++;
                }
            }
        }
        // print the group reversed string
        cout << text << endl;
    }
}