/*
	Forest Class: By Jesse Houk
	Purpose: Create a modular class that can be used to quickly solve UVa Problems

*/
#include <vector>
#include <string>
#include <algorithm>
using namespace std;
class forest {
private:
	vector<vector<int> > forestNodes;
	int size;

public:
	forest();
	forest(const int &);
	
	void AddNode(const int &);
	void AddEdge(const int &, const int &, int);
	int CountEdges(const int &, int);
	bool InForest(const int &);
	bool InTree(const int &, const vector<int> &);
	string DisconnectedNodes(const int &, int, int);
	bool Reachable(const int &, const int &);
	bool IsConnected(const int &, const vector<int> &);
	int FirstEdge(const vector<int> &);
	int Size();
	//~forest();
};