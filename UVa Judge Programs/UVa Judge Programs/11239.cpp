#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;
bool isEntirelyUpper(string l) {
    for (int i = 0; i < l.length(); i++) {
        if (isalpha(l[i]) && islower(l[i]))
            return false; 
    }
    return true;
}

int main() {
    int bark = 0;
    string line;
    string project;
    map<string, set<string> > projectSignups;
    // when 0, terminate
    while (getline(cin, line) && line[0] != '0') {
        // when 1, print project
        if (line[0] == '1') {
            for (map<string, set<string> >::iterator i = projectSignups.begin(); i != projectSignups.end(); ++i) {
            // cout << bark << '\n';
            // bark++;
                cout << i->first << ' ' << i->second.size() << '\n';
                
            }
            projectSignups.~map();
            string project;
            map<string, set<string> > projectSignups;
        }
        else {
            if (isEntirelyUpper(line)) {
                projectSignups.insert(pair<string, set<string> >(line, set<string>()));
                project = line;
            }
            else {
                for (int i = 0; i < line.length(); i++) {
                    line[i] = tolower(line[i]);
                }
                projectSignups.at(project).insert(line);
            }

        }

    }
}