#ifndef GRAPH_H
#define GRAPH_H

#include <iostream>
#include <vector>

template <typename T>
struct graphEdge {
	graphEdge * next;
	T value;
};

template<typename T>
class Graph {
	graphEdge<T> ** A;
public:
	int size;
	Graph(int n) { 
		size = n;
		A = new graphEdge<T> * [size]; 
	}
	~Graph() { ; }
	void addEdge(int v1, int v2) {
		graphEdge<T> *p;
		p = new graphEdge<T>;
		p->value = v2;
		p->next = A[v1];
		A[v1] = p; 
	}
	void removeEdge(int v1, int v2) {
		if(hasEdge(v1, v2)) {
			graphEdge<T> *p;
			p = A[v1];
			
		}
	}
	bool hasEdge(int v1, int v2) {
		graphEdge<T> *p;
		p = A[v1];
		while(p) {
			if(p->value == v2)
				return true;
			p = p->next;
		}
		return false;
	}
	void display() {
		graphEdge<T> *p;
		for(int i = 0; i < size; i++) {
			std::cout << "A [ " << i << " ] = ";
			p = A[i];
			while(p) {
				std::cout << " " << p->value;
				p = p->next;
			}
			std::cout << std::endl;
		}
	}
	int edgeCount() {
		graphEdge<T> *p;
		int counter = 0;
		for(int i = 0; i < size; i++) {
			p = A[i];
			while(p) {
				counter++;
				p = p->next;
			}
		}
		return counter;
	}


};

#endif


    // cin >> 0 >> 1;    // Wierzchołek startowy i końcowy krawędzi
    // p = new slistEl;    // Tworzymy nowy element
    // p->v = 1;          // Numerujemy go jako v2
    // p->next = A [ 0 ]; // Dodajemy go na początek listy A [ v1 ] 
    // A [ 0 ] = p;
  