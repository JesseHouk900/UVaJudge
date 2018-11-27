/*



*/

#include <iostream>
#include <vector>
#include <queue>
#include <bitset>
#include <string>
#include <algorithm>
using namespace std;

class forest {
private:
	vector<vector<int> > forestNodes;
	int size;

public:
	forest() {
		forestNodes = vector<vector<int> >(0);
		size = 0;
	}

	forest(const int & size) {
		forestNodes = vector<vector<int> >(size, vector<int>(size, -1));
		this->size = size;
	}

	void AddNode(const int & node) {
		if (node > size) {
			for (int r = size; r < node; r++) {
				forestNodes.push_back(vector<int>());
			}
		}
		size = node;
	}

	void AddEdge(const int & a, const int & b, int mod = 0) {
		if (InForest(a - mod) && InForest(b - mod)) {
			/*AddNode(max(a, b) - 1);
		}*/
			if (!InForest(b - mod)/*InTree(b - mod, forestNodes[a - mod])*/) {
				for (int i = 0; i < size; i++) {
					if (i/*forestNodes[a - mod][i]*/ <= b - mod) {
						forestNodes[a - mod].insert(forestNodes[a - mod].begin() + i, b - mod);
						return;
					}
				}
				forestNodes[a - mod].push_back(b - mod);

			}
			else { // b is in tree a
				if (forestNodes[a - mod][b - mod] == -1) {
					forestNodes[a - mod][b - mod] = 1;
				}
				else {
					forestNodes[a - mod][b - mod] += 1;
				}
			}
		}
	}

	int CountEdges(const int & root, int mod = 0) {
		int count = 0;
		if (InForest(root - mod)) {
			for (int i = 0; i < size; i++) {
				if (forestNodes[root - mod][i] > 0) {
					count++;
				}
			}

		}
		return count;
	}
	// remember that indexing in the forest start at 0
	bool InForest(const int & n) {
		return n >= 0 && n < size;
	}

	bool InTree(const int & n, const vector<int> & v) {
		return InForest(n) && IsConnected(n, v);
	}

	string DisconnectedNodes(const int & n, int mod = 0, int depth = -1) {
		if (InForest(n - mod)) {
			string s = "";
			int count = 0;
			if (depth >= 0) {
				for (int i = 0; i < size; i++) {
					if (!Reachable(n - mod, i)) {
						s += " " + to_string(i + mod);
						count++;
					}
				}
				return to_string(count) + s + '\n';

			}
			else {
				queue<int> nodes;
				int i = 0, top;
				nodes.push(n - mod);
				vector<string> colors = vector<string>(size, "White");
				//nodes.push(FirstEdge(forestNodes[n - mod]));
				if (nodes.front() != -1) {
					while (!nodes.empty()) {
						top = nodes.front();
						for (int i = 0; i < size; i++) {
							if (InTree(i, forestNodes[top]) && colors[i] == "White") {
								nodes.push(i);
								colors[i] = "Grey";
							}
						}
						if (colors[top] == "Grey") {
							colors[top] = "Black";
						}
						nodes.pop();
					}

				}
				/*for (int i = 0; i < forestNodes[n - mod].size(); i++) {

				}*/

				for (int i = 0; i < colors.size(); i++) {
					if (colors[i] == "White") {
						count++;
						s += " " + to_string(i + mod);
					}
				}
				s += '\n';
				return to_string(count) + s;
			}
		}
		return "";
	}

	bool Reachable(const int & p, const int & q) {
		if (InForest(p) && InForest(q)/* && InTree(q, forestNodes[p])*/) {
			if (IsConnected(q, forestNodes[p])) {
				return true;
			}
			for (int i = 0; i < size; i++) {
				if (forestNodes[p][i] > 0) {
					if (InTree(q, forestNodes[i])) {
						return true;
					}
					/*for (int j = 0; j < forestNodes[i].size(); j++) {
						if (InTree)
					}*/
				}
			}

		}
	}

	bool IsConnected(const int & n, const vector<int> & v) {
		return v[n] > 0;
	}

	int FirstEdge(const vector<int> & v) {
		for (int i = 0; i < v.size(); i++) {
			if (v[i] > 0) {
				return i;
			}
		}
		return -1;
	}

	int Size() {
		return size;
	}
};

int main() {
	forest graph;
	int numNodes, vertex, edge;
	while (cin >> numNodes) {
		graph = forest(numNodes);
		while (cin >> vertex && vertex != 0) {
			while (cin >> edge && edge != 0) {
				graph.AddEdge(vertex, edge, 1);
			}
		}
		cin >> vertex;
		string disconnectedEdges;
		for (int i = 0; i < vertex; i++) {
			cin >> edge;
			cout << graph.DisconnectedNodes(edge, 1, -1);
		}

	}
}