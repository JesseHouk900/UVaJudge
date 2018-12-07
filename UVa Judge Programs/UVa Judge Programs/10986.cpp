/*/////////////////////////////////////////////////////////////////////////////
	Jesse Houk :	Vertex :	10986 :	   euclid5

	Data Structure :    Graph , queue

	Tricks of the Trade : Hamlin SSSP with lazy deletion

	Problem : read in an N for the number of graphs to process. For each case
	read in n, m, S, T where n is th number of nodes in a graph, m is how many
	weighted undirected edges are that follow, S is the starting point for a
	path, T is the ending point for a path. For each m line that follows, read
	in a, b, w where a is the index of the start node that connects to the node
	indexed by b, b is the index of the end node that is connected to by the node
	indexed by a, and w is the weight on that edge.
	N
	n m S T
	S1 T1 w1
	S2 T2 w2
	.
	.
	.
	Sm Tm wm
	where S[1, 2, ..., m], T[1, 2, ..., m] are in the range [0, n - 1]

	Runtime : 0.210
/////////////////////////////////////////////////////////////////////////////*/
#include <iostream>
#include <string>		// optional for graph
#include <vector>		// necessary for graph
#include <queue>		// optional for graph with BFS or SSSP
#include <functional>	// optional for graph with SSSP
#include <climits>		// optional for graph with SSSP (INT_MAX)
using namespace std;
// 
class Graph {
private:
	// support class for the verticies of the linked list
	struct Node {
		// the value of the node
		int value;
		// the list of nodes that has the index of the node in the first spot 
		// and the distance to that node in the second spot.
		vector<pair<int, int> > adjacent;
		// default constructor
		Node() {
			// set the value of the node to a dummy value
			value = -1;
			// set the adjacency list to have a size of 0
			adjacent = vector<pair<int, int> >(0);
		}
		// Parameters: v - the value of the node
		// Purpose: A parameterized constructor that takes in a value for the
		// intended value of the node
		Node(const int & v) {
			// set the value of the node to the value passed in
			value = v;
			// set the adjacency list to have a size of 0
			adjacent = vector<pair<int, int> >(0);
		}
	};
	// Adjacency list for a graph of integers as nodes
	vector<Node> graph;
	// the number of verticies in the graph
	int size;

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

public:
	// Parameters: none
	// Return: void
	// Purpose: Default constructor and parameterized constructor will initialize
	// the graph and size
	Graph(bool d = false) {
		// start with an emoty graph
		size = 0;
		// create the graph with no nodes
		graph = vector<Node>(size);
		// set the type of graph, directed (true) or undirected (false)
		dir = d;
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
		// check for a directed or undirected graph
		if (!dir) {
			// add the connection from a to b saving the distance to b 
			// in the first position and the index of b in the second 
			// position
			graph[b].adjacent.push_back(pair<int, int>(weight,
				a));
		}
		//}
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

	// Parameters: a - the value of the node from which to begin at
	//			   b - the value of the node you want to know the shortest path to
	// Return: int >= 0 - the distance from a to b
	//		   int < 0 - the node with a value of b is unreachable from the node
	//		   with a value of a
	// Purpose: Find the shortest distance from the node with the value of a to
	// the node with the value of b.
	int SSSP(int a, int b) {
		// make a vector of distances for each node in th graph with infinity 
		// as their value
		vector<int> distances = vector<int>(size, INT_MAX);
		// make a max priority queue that sorts based on pairs 
		priority_queue< pair<int, int>, vector<pair<int, int> >, greater<pair
			<int, int> > > nodePriorityQueue;
		// get the index of a
		int sourceIndex = findIndex(a);
		// if a is in the graph...
		if (sourceIndex != -1) {
			// set the distance to the source to 0
			distances[sourceIndex] = 0;
			// add the pair of the distance to the source and the source index 
			// to the heap
			nodePriorityQueue.push(pair<int, int>(0, sourceIndex));
			// while the queue is not empty...
			while (!nodePriorityQueue.empty()) {
				// get the front value from the queue
				pair<int, int> front = nodePriorityQueue.top();
				// and remove it from the queue
				nodePriorityQueue.pop();
				// save the values of the distance to the node that came from 
				// the queue and its index in the graph
				int distance = front.first, index = front.second;
				// if the distance to the node is less than the distance saved 
				// at that index...
				if (distance <= distances[index]) {
					// make a pair for the adjacent node to the node indexed by index
					pair<int, int> adjacentNode;
					// loop through the nodes adjacent to the node indexed by index
					for (int i = 0; i < graph[index].adjacent.size(); i++) {
						// get the ith adjacent node
						adjacentNode = graph[index].adjacent[i];
						// if the distance from the current node to the adjacent 
						// node is less than the distance to the adjacent node 
						// in distances...
						if (distances[index] + adjacentNode.first < distances[
							adjacentNode.second]) {
							// save that lesser distance
							distances[adjacentNode.second] = distances[index]
								+ adjacentNode.first;
							// and enqueue that adjacent node with the distance
							// to it and the index to it
							nodePriorityQueue.push(pair<int, int>(distances[
								adjacentNode.second], adjacentNode.second));
						}
					}
				}
			}
		}
		// get the index of the diestination node
		int destinaitonIndex = findIndex(b);
		//if the destination was not reachable from source...
		if (distances[destinaitonIndex] == INT_MAX) {
			// return an invalid distance
			return -1;
		}
		// return the distance to the destination
		return distances[destinaitonIndex];
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
	// the number of graphs to be processed
	int cases;
	// range is the size of the graph
	// edges is the number of edges to be read in
	// source is the source for the SSSP to the destination
	// destination is the node that you want to find the shortest path to from
	// source
	int range, edges, source, destination;
	// from is the start node for an edge
	// to is the end node for an edge
	// weight is the weight on the edge from from to to
	int from, to, weight;
	// graph for the incoming data
	Graph g;
	// read in the number of graphs to process
	cin >> cases;
	// loop through the cases
	for (int i = 0; i < cases; i++) {
		// reset the graph
		g = Graph();
		// read in the m, n, S, T for the graph
		cin >> range >> edges >> source >> destination;
		// loop throguh the range...
		for (int j = 0; j < range; j++) {
			// and add the values from 0 to range - 1
			g.AddNode(j);
		}
		// loop through the number of edges
		for (int j = 0; j < edges; j++) {
			// read in data for a new edge
			cin >> from >> to >> weight;
			// and add it to the graph
			g.AddEdge(from, to, weight);
		}
		// get the shortest distance from source to distance
		int distance = g.SSSP(source, destination);
		// print which graph was processed
		cout << "Case #" << i + 1 << ": ";
		// if the distance from source to destination is nonnegative...
		if (distance >= 0) {
			// print that as the distance from source to destination
			cout << distance;
		}
		else { // there was no valid distance found
			// so destination is unreachable from source
			cout << "unreachable";
		}
		cout << '\n';
	}

}
