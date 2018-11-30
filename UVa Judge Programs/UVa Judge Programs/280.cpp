/*/////////////////////////////////////////////////////////////////////////////
	Jesse Houk :	Vertex :	280 :	euclid5

	Data Structure :    Graph

	Tricks of the Trade :    BFS

	Problem :read in the 

	Bonus :    Started working on a graph that will be reusable

	Runtime : 2.920			Much worse than original implementation, need to find
								problem
/////////////////////////////////////////////////////////////////////////////*/

#include <iostream>
#include <vector>
#include <queue>	// used for BFS
#include <string>
using namespace std;

// 
class Graph {
private:
	// support class for the verticies of the linked list
	struct Node {
		// the value of the node
		int value;
		// the list values associated with the nodes that this node connects to
		vector<int> adjacent;
		// default constructor
		Node() {
			// set the value of the node to a dummy value
			value = -1;
			// set the adjacency list to have a size of 0
			adjacent = vector<int>(0);
		}
		// Parameters: v - the value of the node
		// Purpose: A parameterized constructor that takes in a value for the
		// intended value of the node
		Node(const int & v) {
			// set the value of the node to the value passed in
			value = v;
			// set the adjacency list to have a size of 0
			adjacent = vector<int>(0);
		}
	};
	// Adjacency list for a graph of integers as nodes
	vector<Node> graph;
	// the number of verticies in the graph
	int size;
	// Parameters:	v - the node of the graph that you want to know if the node
	// n has a connection to
	//				n - the value of the node of the graph that you want to 
	// determine if it connects to the node v
	// Return:		true -  if there is a connection from n to v (n -> v) on 
	// the graph
	//				false - if n does not connect to v (n -\> v)
	// Purpose: determine if v connects to n. NOTE: n connecting to v does not
	// imply that v connects to n. That is,      n -> v != n <-> v
	bool isConnected(const Node & v, const int & n) {
		// loop through the connections of v
		for (int i = 0; i < v.adjacent.size(); i++) {
			// if any of those connections are n...
			if (v.adjacent[i] == n) {
				// then v connects to n
				return true;
			}
		}
		// if not returned true by this point, then v does not connect to n
		return false;
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
	Graph() {
		// start with an emoty graph
		size = 0;
		// create the graph with no nodes
		graph = vector<Node>(size);
	}

	// Parameters: node - the value of the node that will be added to the graph
	// Returns: void
	// Purpose: Add a node with the value of node to the graph
	void AddNode(const int & node) {
		// if the value was not found in the graph...
		if (findIndex(node) == -1) {
			// if the node was not found i the graph, then add the node to the list
				// nodes 
			graph.push_back(Node(node));
			// increase the size of the graph to reflect the addition of the node
			size++;
		}
	}

	// Parameters:	a - the node of the graph that you want to establish a
	// connection to node b
	//				b - the node of the graph that you want to receive a
	// connection from node a
	// Return:		void
	// Purpose: establish a connection from a to b (a -> b). NOTE: a connecting
	// to b does not imply that b connects to a. That is,   a -> b != a <-> b
	// ADDITIONALLY: This does not support psuedographs
	void AddEdge(const int & a, const int & b) {
		// if a and b are in the graph...
		if (InGraph(a) && InGraph(b)) {
			int i = findIndex(a);

			/*for (; j < size; j++) {
				if (graph[i].value == b) {
					break;
				}
			}*/
			// if a does not connect to b... (a -\> b)
			if (!isConnected(graph[i], b)) {
				// add the connection from a to b
				graph[i].adjacent.push_back(b);
			}
		}
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
			return InGraph(n) && InGraph(v) && isConnected(graph[i], v);
		}
	}

	// Parameters: n - the value of the node that you want to find nodes not
	// connected to
	// Return:	string - a string of node values that n does not connect to,
	// will return an empty string if n connects to all nodes in the graph
	// Purpose: use a BFS search to find the nodes that n connects to, then
	// take the remaining white values from the colors list and return the
	// a string that is the number of disconnected nodes to n, the values of
	// those disconnected nodes, and then a newline.
	string DisconnectedNodes(const int & n) {
		// if n is a node in the graph...
		if (InGraph(n)) {
			// make a string that will be used to hold the values of disconnected
			// nodes
			string s = "";
			// start a counter for how many disconned nodes there are
			int count = 0;
			// quese used for the BFS of the graph
			queue<int> nodes;
			// value used to easily access the front value of queue (or the previous
			// front)
			int front;
			// enqueue the root of this "tree"
			nodes.push(n);
			// make a support vector, colors, that will be used for the BFS,
			// tracking what nodes in the graph have been discovered, Grey,
			// processed, Black, and yet to be found, White. Assume all nodes have
			// yet to be found
			vector<string> colors = vector<string>(size, "White");
			//nodes.push(FirstEdge(graph[n]));
			// while the queue of nodes still has nodes to process...
			while (!nodes.empty()) {
				// take the front value of the queue
				front = nodes.front();
				// get the index of the front
				int frontIndex = findIndex(front);
				// loop through the graph nodes
				for (int i = 0; i < size; i++) {
					// if the ith node connects to this front node and is not
					// yet discovered...
					if (isConnected(graph[frontIndex], graph[i].value) && colors[i] == "White") {
						// mark it as discovered
						colors[i] = "Grey";
						// and add the value of that node to the back of the queue
						nodes.push(graph[i].value);
					}
				}
				// remove the front node from the queue
				nodes.pop();
			}
			// loop through the colors
			for (int i = 0; i < colors.size(); i++) {
				// if any of the colors are still white, the node was not connected
				// to n, so...
				if (colors[i] == "White") {
					// increment the number of nodes that n is disconnected to
					count++;
					// and add the value of the disconnected node to the string of 
					// disconnected values
					s += " " + to_string(graph[i].value);
				}
			}
			// return the number of disconnected nodes followed by the value of
			// those disconnected nodes (in order?) and a newline character
			return to_string(count) + s + '\n';
		}
		// if the n is not in the graph, return an empty string
		return "";
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
	// make a graph to model the incoming adjacency list
	Graph graph;
	// numNodes will be the number of nodes in a particular graph
	// vertex will be the value of a current node
	// edge is the value a node will connect to vertex
	int numNodes, vertex, edge;
	// while there is some new size for a graph that can be read in...
	while (cin >> numNodes) {
		// initialize the graph (or clear it out)
		graph = Graph();
		// loop through the numbers 1 to numNodes
		for (int i = 1; i <= numNodes; i++) {
			// and add that value to the graph as a node
			graph.AddNode(i);
		}
		// while there is some value read in for a particular node and that
		// value is not 0...
		while (cin >> vertex && vertex != 0) {
			// and while there is some value read in for vertex to connect to
			// and that value is not 0...
			while (cin >> edge && edge != 0) {
				// and an edge from the node of vertex to the node of edge
				graph.AddEdge(vertex, edge);
			}
		}
		// reuse the variable that was used for vertex to now be the value for
		// the number of querries to be made on verticies
		cin >> vertex;
		// loop for that number of time
		for (int i = 0; i < vertex; i++) {
			// and reuse the variable that was used for edge and get the vertex
			// to querry
			cin >> edge;
			// call the method for finding nodes that do not connect to the
			// querring vertex and print it
			cout << graph.DisconnectedNodes(edge);
		}

	}
}