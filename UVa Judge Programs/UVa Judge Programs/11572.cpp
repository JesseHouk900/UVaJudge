#include <iostream>
#include <map>

using namespace std;

int main() {
    map<int, int> snowflakes;
    int batches, flakes;
    cin >> batches;
    for (int b = 0; b < batches; b++) {
        cin >> flakes;
        for (int f = 0, flake; f < flakes; f++) {
            cin >> flake;
            map<int, int>::iterator sf;
            for (auto it = sf = snowflakes.begin(); it != snowflakes.end(); ++it) {
                if (it->second == flake) {
                    sf = it;
                }
            }
            cout << sf->first << "_" << sf->second << '\n';
            if (sf == snowflakes.end()) {
                snowflakes[f] = flake;
            }
            else {
                snowflakes.erase(snowflakes.begin(), sf);
                snowflakes[f] = flake;
            }
        }
        for (auto it = snowflakes.begin(); it != snowflakes.end(); ++it) {
            cout << it->first << " " << it->second << '\n';
        }
        cout << snowflakes.size() << '\n';
        snowflakes.clear();
    }

}