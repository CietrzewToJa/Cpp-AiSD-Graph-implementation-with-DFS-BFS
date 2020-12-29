#include "main.h"

int main() {
	
	Graph<int> graf(5);
	graf.addEdge(0, 5);
	graf.addEdge(0, 1);
	graf.addEdge(1, 2);
	graf.addEdge(2, 3);
	graf.addEdge(3, 4);
	graf.addEdge(4, 5);
	graf.addEdge(1, 5);
	graf.display();
	std::cout << graf.edgeCount();
	std::cout << graf.hasEdge(0, 5);
	std::cout << graf.hasEdge(0, 2);
}