#include <iostream>
#include <set>
#include <map>
#include <string>

using namespace std;
inline
bool isEntirelyUpper(string l) {
    for (int i = 0; i < l.length(); i++) {
        if (isalpha(l[i]) && islower(l[i]))
            return false; 
    }
    return true;
}
struct orderPair{
	bool operator ()(const pair<int, string> & p1, const pair<int, string> & p2) {
		if (p1.first == p2.first) {
			return p1.second > p2.second;
		}
		else {
			return p1.first < p2.first;
		}
	}
};

//struct orderMap {
//	bool operator ()(const pair<string, set<string> > & m1, const pair<string, set<string> > & m2) {
//		if (m1.second.size() == m2.second.size()) {
//			return m1.first > m2.first;
//		}
//		else return m1.second.size() < m2.second.size();
//	}
//};

int main() {
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int bark = 0;
    string line;
	string project;
	set<string> students;
	set<pair<int, string>, orderPair> projectSummaries;
    map<string, set<string>/*, orderMap*/> projectSignups;
	bool isDeleting = false;
    // when 0, terminate
    while (getline(cin, line) && line[0] != '0') {
	     // when 1, print project
         if (line[0] == '1') {
			// remove names on multiple projects
			for (map<string, set<string> >::iterator project1 = projectSignups.begin(); project1 != projectSignups.end(); ++project1) {
				//
				for (set<string>::iterator student1 = (*project1).second.begin(); student1 != project1->second.end(); ++student1) {
					map<string, set<string> >::iterator project2 = project1;
					if (project2 != projectSignups.end()) {
						++project2;
					}

					for (; project2 != projectSignups.end(); ++project2) {
						if (project2->second.count(*student1) != 0) {
							isDeleting = true;
							project2->second.erase(*student1);
						}
						
					}
					if (isDeleting) {
						isDeleting = false;
						students.insert(*student1);
					}
				}
				for (auto s : students) {
					project1->second.erase(s);
				}
				projectSummaries.insert(pair<int, string>(project1->second.size(), project1->first));
			}
			/*for (auto max = projectSignups.rbegin(); max != projectSignups.rend(); ++max) {
				cout << max->first << ' ' << max->second.size() << '\n';
			}*/
			for (auto max = projectSummaries.rbegin(); max != projectSummaries.rend(); ++max) {
				cout << max->second << ' ' << max->first << '\n';
			}
			// clear the project sheets
			students.clear();
			projectSummaries.clear();
            projectSignups.clear();
            project = "";
        }
        else {
            if (isEntirelyUpper(line)) {
                projectSignups.insert(pair<string, set<string> >(line, set<string>()));
                project = line;
            }
            else {
                /*for (int i = 0; i < line.length(); i++) {
                    line[i] = tolower(line[i]);
                }*/
                projectSignups.at(project).insert(line);
            }

        }

    }
}