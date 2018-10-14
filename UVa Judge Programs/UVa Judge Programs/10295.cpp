#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
    map<string, int> taskWorth;
    int tasks, jobs;
    cin >> tasks >> jobs;
    string token;

    for (int i  = 0, worth; i < tasks; i++) {
        cin >> token >> worth;
        taskWorth[token] = worth;

    }

    for (int worth, i = 0; i < jobs; i++, worth = 0) {
        while (cin >> token && token != ".") {
            if (taskWorth.find(token) != taskWorth.end()) {
                worth += taskWorth[token];
            }
        }
        cout << worth << '\n';
    }
}