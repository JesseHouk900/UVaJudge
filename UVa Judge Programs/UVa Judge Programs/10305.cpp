/*/////////////////////////////////////////////////////////////////////////////
	Jesse Houk :	Ordering Tasks :	10305 :	   euclid5

	Data Structures: Graph, queue

	Tricks of the Trade: Modify the DFS with a queue to get the nodes in the order
	they are discovered

	Problem: read in an N and M, the number of nodes in a graph and the number of 
	unweighted directed edges that will follow. Print a possible execution order
	of the graph

	Runtime: 0.000		Woo!
/////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <vector>		// necessary for graph
#include <queue>		// optional for graph with BFS or SSSP or DFS with return
// of nodes found
using namespace std;
// 
class Graph {
private:
	// support class for the verticies of the linked list
	struct Node {
		// the value of the node
		int value;
		// the list of nodes that has the distance to a node in the first spot 
		// and the index of the node in the second spot. Set the size to 0
		vector<pair<int, int> > adjacent = vector<pair<int, int> >(0);
		// default constructor
		Node() {
			// set the value of the node to a dummy value
			value = -1;
		}
		// Parameters: v - the value of the node
		// Purpose: A parameterized constructor that takes in a value for the
		// intended value of the node
		Node(const int & v) {
			// set the value of the node to the value passed in
			value = v;
		}
	};
	// Adjacency list for a graph of integers as nodes
	vector<Node> graph;
	// the number of verticies in the graph
	int size;
	// vector of chars used for DFS and BFS
	vector<char> colors;
	// true false value for if the graph is directed or undirected
	bool dir;
	// Parameters:	v - the node of the graph that you want to know if the node
	// n has a connection to
	//				n - the value of the node of the graph that you want to 
	// determine the adjacency index of
	// Return:		value >= 0 - the value n was found to be a value of a node 
	// adjacent to v
	//				value < 0 - if n does not connect to v (n -\> v)
	// Purpose: determine if v connects to n. NOTE: n connecting to v does not
	// imply that v connects to n. That is,      n -> v != n <-> v
	int ConnectedIndex(const Node & v, const int & n) {
		// loop through the connections of v
		for (int i = 0; i < v.adjacent.size(); i++) {
			// if any of those connections are n...
			if (v.adjacent[i].second == n) {
				// then v connects to n on index i
				return i;
			}
		}
		// if not returned an index by this point, then v does not connect to n
		return -1;
	}

	// Parameters: v - the value of the node that you want to find the index of
	// Return:	value >= 0 - the node was found in the graph and the index was
	// returned
	//			value < 0 - the node was not found and this is a dummy value to
	// tell you so
	// Purpose: since it is more likely that data given for a graph will be the
	// values of the nodes and not the indicies of those nodes in the graph,
	// this makes getting the index of a node easier to get
	int findIndex(int v) {
		// loop through the indicies of the nodes in the graph
		for (int i = 0; i < size; i++) {
			// if the value of the ith node in the graph equals the value passed
			// in... (the value was found in the graph)
			if (graph[i].value == v) {
				// return the index of the node found in the graph
				return i;
			}
		}
		// if the value of the node was not found as a value of a node in the 
		// list of nodes, then return a dummy value to indicate it was not found
		return -1;
	}

	// Parameters: & q - a reference to the queue that will hold the values of
	//				 i  - the index of the node being explored
	// the nodes in the graph. Effects the queue that was passed in from the call
	// Purpose: 
	void getNodesDfs(queue<int> & q, const int & i) {
		// security check
		//if (v.empty() || v[0] == NULL) {

		//}
		//else {
		// set the color of the node to grey for discovered
		colors[i] = 'G';
		// add that node to the list of nodes in order
		q.push(i);
		// loop through the nodes adjacent to the ith node
		for (int j = 0; j < graph[i].adjacent.size(); j++) {
			// if the jth node adjacent to the ith node is colored white...
			if (colors[graph[i].adjacent[j].second] == 'W') {
				// continue the DFS on that jth node
				getNodesDfs(q, graph[i].adjacent[j].second);
			}
		}

		//}
	}
public:
	// Parameters: none
	// Return: void
	// Purpose: Default constructor and parameterized constructor will initialize
	// the graph and size
	Graph() {
		// start with an emoty graph
		size = 0;
		// create the graph with no nodes
		graph = vector<Node>(size);
		// initialize an empty vector of colors
		colors = vector<char>(size);

	}

	// Parameters: node - the value of the node that will be added to the graph
	// Returns: void
	// Purpose: Add a node with the value of node to the grph
	void AddNode(const int & node) {
		// if the value was not found in the graph...
		// security check
		// if the node was not found i the graph,
		// if (findIndex(node) == -1) {
		// add the node to the list nodes 
		graph.push_back(Node(node));
		// add a new undiscovered node
		colors.push_back('W');
		// increase the size of the graph to reflect the addition of the node
		size++;
		//}
	}
	// Parameters:	a - the node of the graph that you want to establish a
	// connection to node b
	//				b - the node of the graph that you want to receive a
	// connection from node a
	//				weight - if the graph is weighted, this is the cost to go
	// from the node with the value a to the node with the value b
// Return:		void
// Purpose: establish a connection from a to b (a -> b). NOTE: a connecting
// to b does not imply that b connects to a. That is,   a -> b != a <-> b
//// ADDITIONALLY: This does not support psuedographs
	void AddEdge(const int & a, const int & b, const int weight = 0) {
		// security check
		// if a and b are in the graph...
		//if (InGraph(a) && InGraph(b)) {

		// use if values of nodes are not 0 - n or sequential
		// get the index of the node with the value of a
		// int aIndex = findIndex(a);
		// get the index of the node with tht value of b that is adjacent to
		// the node with the value of a
		// int aTobIndex = ConnectedIndex(graph[aIndex], b);
		// get the index of the node with the value of b
		// int bIndex = findIndex(b);

		// add the connection from a to b saving the distance to b in the
		// first position and the index of b in the second position
		graph[a].adjacent.push_back(pair<int, int>(weight, b));


	}

	// Parameters: root - the value of the node which you want to know the degree
	// of
	// Return:  value >= 0 - the number of elements the root is connected to
	//			-1 - the root was not a node in the graph
	// Purpose: Return the number of edges that connect to the root
	int CountEdges(const int & root) {
		// if the root is a node in the graph...
		if (InGraph(root)) {
			// index of the root node
			int i = findIndex(root);
			// if i is a valid index...
			if (i >= 0) {
				// return the number of nodes that the root connects to
				return graph[i].adjacent.size();
			}
		}
		// return a dummy value if the root passed in does not exist within the
		// graph
		return -1;
	}
	// Parameters: n - the value of the node you want to know is in the graph 
	// or not
	// Return:  true - n is a node in the graph
	//			false - n is not a node in the graph
	// Purpose: determine if the node n is in the graph 
	bool InGraph(const int & n) {
		// loop through the nodes of the graph
		for (auto a : graph) {
			// if a node in the graph has the same value as n...
			if (a.value == n) {
				// then n is in the graph
				return true;
			}
		}
		// if n was not found in the nodes of the graph, n is not in the graph
		return false;
	}

	// Parameters:	n - the node of the graph that you want to determine if it
	// connects to the node v
	//				v - the node of the graph that you want to know if the node
	// n has a connection to
	// Return:		true -  if there is a connection from n to v (n -> v) on 
	// the graph
	//				false - if n does not connect to v (n -\> v)
	// Purpose: determine if there exists a connection from n to v. NOTE: n
	// connecting to v does not imply that v connects to n. That is, 
	// n -> v != n <-> v
	bool IsConnected(const int & n, const int & v) {
		// get the index of the node with a value of n
		int i = findIndex(n);
		// if the index is valid...
		if (i >= 0) {
			// return true or false based on if n and v are in the graph and n
			// connects to v
			bool isConnected = (ConnectedIndex(graph[i], v) != -1);
			return InGraph(n) && InGraph(v) && isConnected;
		}
	}

	// Parameters: q - queue of integers that will store the node values that are
	// discovered during the DFS in the order that they are discovered
	//			   v - vector of values wished to searched. If null, the a regular
	// DFS is performed in terms of which nodes the recursive DFS called on
	// Purpose: Use a depth first search to put the values of nodes into a queue
	void GetNodesDFS(queue<int> & q, vector<int> v = { NULL }) {
		//if (v.empty() || v[0] == NULL) {
			//for (int i = 0; i < graph.size(); i++) {
				//if (colors[v[i]] == 'W') {
			//		getNodesDfs(q);
				//}
			//}
		//}
		//else {
		// loop through the values in the vector
		for (int i = 0; i < v.size(); i++) {
			// if the ith node in the vector is white, or undiscovered...
			if (colors[v[i]] == 'W') {
				// begin a DFS on that node
				getNodesDfs(q, v[i]);
			}
		}
		//}
	}

	// Return: int - the value saved as the size of the graph, refering to the
	// number of verticies in the graph
	// Purpose: Allow the user to access the number of verticies in the graph
	int Size() {
		// return the number of verticies
		return size;
	}
};

int main() {
	// get a graoh for the incoming data
	Graph g;
	// size is the number of nodes that will be in a graph
	// oneWayPaths is the number of directed edges that will be read in
	int size, oneWayPaths;
	// start is the node that has an edge to end
	// end is the node that start is connected to
	int start, end;
	// vector used for the purpose of finding the roots of the directed graph
	vector<int> parents;
	// while there is a size and oneWayPaths integer pair to be read...
	while (cin >> size >> oneWayPaths) {
		// reset the graph
		g = Graph();
		// make a vector to keep track of the parents of each node in the graph
		parents = vector<int>(size, -1);
		// add nodes from 0 to size
		for (int i = 0; i < size; i++) {
			g.AddNode(i);
		}
		// loop for the number of oneWayPaths
		for (int i = 0; i < oneWayPaths; i++) {
			// read in a new start and end point
			cin >> start >> end;
			// add an edge from start - 1 to end - 1 and keep those values for 
			// start and end
			g.AddEdge(--start, --end);
			// if the start node does not have a parent
			if (parents[start] == -1) {
				// make end have start as it's parent
				parents[end] = start;
			}
			else { // start has a parent
				// so save the parent of end as the parent of start
				parents[end] = parents[start];
			}
		}
		// vector for the roots of the graph, the nodes that have a value of 
		// -1 in parents
		vector<int> roots;
		// loop through the parents vector
		for (int j = 0; j < parents.size(); j++) {
			// if a parent has a -1 in the jth position...
			if (parents[j] == -1) {
				// add that index for the node to the roots vector
				roots.push_back(j);
			}
		}
		// make a queue for the nodes
		queue<int> executionOrder;
		// get a possible order of execution for the graph
		g.GetNodesDFS(executionOrder, roots);
		// if the number of nodes is grater than 0...
		if (size > 0) {
			// print the first element of the queue + 1 to go back to the 
			// original value
			cout << (executionOrder.front() + 1);
			// and remove it from the queue
			executionOrder.pop();
		}
		// print the values in the queue + 1 to go back to the original value
		for (int j = 1; j < size; j++) {
			cout << ' ' << (executionOrder.front() + 1);
			executionOrder.pop();
		}
		cout << '\n';

	}
}