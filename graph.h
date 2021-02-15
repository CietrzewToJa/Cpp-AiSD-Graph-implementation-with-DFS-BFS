#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>
#include <assert.h>
#include <queue>
#include <assert.h>


template <typename T>
struct graphEdge {
	graphEdge * next;
	T value;
};

template<typename T>
class Graph {
	graphEdge<T> ** A;
	bool directed;

	int vertexNumber;
	int edgeNumber = 0;
	bool hasNext(int v1, int v2);
public:
	Graph(int n, bool dir) { 
		vertexNumber = n;
		directed = dir;
		A = new graphEdge<T> * [vertexNumber]; 
	}
	~Graph() { };

	bool is_directed() const { return directed; }
	int getV() { return vertexNumber; }
	int getE();
	bool addEdge(int v1, int v2);
	void removeEdge(int v1, int v2);
	bool hasEdge(int v1, int v2);
	void display();
	void clear();
	void DFS(int v);
	void DFS(int v, bool visited[]);
	void BFS(int v);
};

template<typename T>
int Graph<T>::getE()  {

	if(directed) {
		return edgeNumber;
	} else {
		return edgeNumber/2;
	}
}


template<typename T>
bool Graph<T>::addEdge(int v1, int v2)  {

	if(v1 < vertexNumber && v2 < vertexNumber && !hasEdge(v1,v2)
		&& v1 >= 0 && v2 >= 0) {
		graphEdge<T> *p;

		p = new graphEdge<T>;
		p->value = v2;
		p->next = A[v1];
		A[v1] = p; 

		if(!directed) {
			addEdge(v2,v1);
		}

		edgeNumber++;
		return true;
	} else return false;
}

template<typename T>
void Graph<T>::removeEdge(int v1, int v2) {
	if(hasEdge(v1, v2)) {
		graphEdge<T> *p, *q;
		p = A[v1];

		if(A[v1]->value == v2) {
			A[v1] = p->next;
			delete p;
		} else {
			while(p->next->value != v2) {
				p = p->next;
			} 
			q = p->next;
			p->next = q->next;
			delete q;
		}

		if(!directed) {
			removeEdge(v2, v1);
		}

		edgeNumber--;
	}
}

template<typename T>
bool Graph<T>::hasEdge(int v1, int v2) {
	graphEdge<T> *p;
	p = A[v1];
	while(p) {
		if(p->value == v2)
			return true;
		p = p->next;
	}
	return false;
}

template<typename T>
void Graph<T>::display() {
	graphEdge<T> *p;
	for(int i = 0; i < vertexNumber; i++) {
			std::cout << i << ":";
			p = A[i];
			while(p) {
				std::cout << " " << p->value;
				p = p->next;
			}
			std::cout << std::endl;
	}
}

template<typename T>
void Graph<T>::clear() {
	graphEdge<T> *p;
	for(int i = 0; i < vertexNumber; i++) {
		p = A[i];
		while(p) {
			removeEdge(i, p->value);
			p = A[i];
		}
	}
}

template<typename T>
void Graph<T>::DFS(int v) {
	bool *visited = new bool[vertexNumber];
	for(int i = 0; i < vertexNumber; i++) {
		visited[i] = false;
	}

	DFS(v, visited);
}

template<typename T>
void Graph<T>::DFS(int v, bool visited[]) {
	graphEdge<T> *p;
  	visited[v] = true;
 	std::cout << v << " ";

  	for(p = A[v]; p; p = p->next)
    	if(!visited[p->value]) 
    		DFS(p->value, visited);
}

template<typename T>
void Graph<T>::BFS(int v) {
	graphEdge<T> *p;
	bool *visited = new bool[vertexNumber];
	for(int i = 0; i < vertexNumber; i++) {
		visited[i] = false;
	}

	std::queue<T> queue; 

	visited[v] = true;
	queue.push(v);

	while(!queue.empty()) {
		v = queue.front();
		std::cout << v << " ";
		queue.pop();

		for(p = A[v]; p; p = p->next) {
			if(!visited[p->value]) {
				visited[p->value] = true;
				queue.push(p->value);
			}
		}
	}
}

#endif
