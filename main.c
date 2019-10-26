#include <stdio.h>  // For IO operations
#include <stdlib.h> // for malloc/free

#include "my_graph.h" 

void unitTest1() {
	printf("unitTest1\n\n");
	graph_t * testGraph = create_graph();
	printf("Attempting to add node: 10\n");
	printf("Node_add return: %d\n", graph_add_node(testGraph, 10));
	my_graph_print(testGraph);
	printf("Attempting to add node: 20\n");
	printf("Node_add return: %d\n", graph_add_node(testGraph, 20));
	my_graph_print(testGraph);
	printf("Attempting to add node: 30\n");
	printf("Node_add return: %d\n", graph_add_node(testGraph, 30));
	my_graph_print(testGraph);
	printf("Attempting to add node: 40\n");
	printf("Node_add return: %d\n", graph_add_node(testGraph, 40));
	my_graph_print(testGraph);
	printf("Attempting to add node: 50\n");
	printf("Node_add return: %d\n", graph_add_node(testGraph, 50));
	my_graph_print(testGraph);
	
	printf("Attempting to add edge: 10 to 20\n");
	printf("Edge_add return: %d\n", graph_add_edge(testGraph, 10, 20));
	my_graph_print(testGraph);
	printf("Attempting to add edge: 10 to 30\n");
	printf("Edge_add return: %d\n", graph_add_edge(testGraph, 10, 30));
	my_graph_print(testGraph);
	printf("Attempting to add edge: 20 to 50\n");
	printf("Edge_add return: %d\n", graph_add_edge(testGraph, 20, 50));
	my_graph_print(testGraph);
	printf("Attempting to add edge: 20 to 40\n");
	printf("Edge_add return: %d\n", graph_add_edge(testGraph, 20, 40));
	my_graph_print(testGraph);

	printf("Contains node 10 return: %d\n", contains_node(testGraph, 10));
	printf("Contains node 20 return: %d\n", contains_node(testGraph, 20));
	printf("Contains node 30 return: %d\n", contains_node(testGraph, 30));
	printf("Contains node 40 return: %d\n", contains_node(testGraph, 40));
	printf("Contains node 50 return: %d\n", contains_node(testGraph, 50));
	printf("Contains node 60 return: %d\n", contains_node(testGraph, 60));
	printf("Contains node 70 return: %d\n", contains_node(testGraph, 70));
	printf("\n");

	printf("Contains edge 10 to 20 return: %d\n", contains_edge(testGraph, 10, 20));
	printf("Contains edge 10 to 30 return: %d\n", contains_edge(testGraph, 10, 30));
	printf("Contains edge 20 to 40 return: %d\n", contains_edge(testGraph, 20, 40));
	printf("Contains edge 20 to 50 return: %d\n", contains_edge(testGraph, 20, 50));
	printf("Contains edge 30 to 10 return: %d\n", contains_edge(testGraph, 30, 10));
	printf("Contains edge 50 to 30 return: %d\n", contains_edge(testGraph, 50, 30));
	printf("\n");

	printf("Number of neighbors for node 10: %d\n", numNeighbors(testGraph, 10));
	printf("Number of neighbors for node 20: %d\n", numNeighbors(testGraph, 20));
	printf("Number of neighbors for node 30: %d\n", numNeighbors(testGraph, 30));
	printf("Number of neighbors for node 40: %d\n", numNeighbors(testGraph, 40));
	printf("Number of neighbors for node 50: %d\n", numNeighbors(testGraph, 50));
	printf("Number of neighbors for node 60: %d\n", numNeighbors(testGraph, 60));
	printf("Number of neighbors for node 70: %d\n", numNeighbors(testGraph, 70));
	printf("\n");

	graph_print(testGraph);

	printf("\n");

	printf("Is reachable from 10 to 20 return: %d\n", is_reachable(testGraph, 10, 20));
	printf("Is reachable from 10 to 30 return: %d\n", is_reachable(testGraph, 10, 30));
	printf("Is reachable from 20 to 50 return: %d\n", is_reachable(testGraph, 20, 50));
	printf("Is reachable from 20 to 40 return: %d\n", is_reachable(testGraph, 20, 40));
	printf("Is reachable from 10 to 40 return: %d\n", is_reachable(testGraph, 10, 40));
	printf("Is reachable from 10 to 50 return: %d\n", is_reachable(testGraph, 10, 50));
	printf("Is reachable from 50 to 40 return: %d\n", is_reachable(testGraph, 50, 40));
	printf("Is reachable from 50 to 30 return: %d\n", is_reachable(testGraph, 50, 30));
	printf("Is reachable from 20 to 10 return: %d\n", is_reachable(testGraph, 20, 10));
	printf("\n");

	printf("Attempting to add edge: 10 to 30\n");
	printf("Edge_add return: %d\n", graph_add_edge(testGraph, 10, 30));
	my_graph_print(testGraph);
	printf("Attempting to add edge: 10 to 15\n");
	printf("Edge_add return: %d\n", graph_add_edge(testGraph, 10, 15));
	my_graph_print(testGraph);

	printf("Attempting to remove node: 40\n");
	printf("Node_remove return: %d\n", graph_remove_node(testGraph, 40));
	my_graph_print(testGraph);

	printf("Attempting to remove edge: 10 to 20\n");
	printf("Edge_remove return: %d\n", graph_remove_edge(testGraph, 10, 20));
	my_graph_print(testGraph);

	printf("Attempting to remove edge: 20 to 50\n");
	printf("Edge_remove return: %d\n", graph_remove_edge(testGraph, 20, 50));
	my_graph_print(testGraph);

	printf("Attempting to remove edge: 40 to 10\n");
	printf("Edge_remove return: %d\n", graph_remove_edge(testGraph, 10, 20));
	my_graph_print(testGraph);

	printf("Attempting to remove edge: 10 to 40\n");
	printf("Edge_remove return: %d\n", graph_remove_edge(testGraph, 10, 20));
	my_graph_print(testGraph);

	free_graph(testGraph);

	printf("\n\n");

}

void unitTest2() {
	printf("unitTest2\n\n");
	graph_t * testGraph = create_graph();

	printf("Attempting to add node: 10\n");
	printf("Node_add return: %d\n", graph_add_node(testGraph, 10));
	my_graph_print(testGraph);
	printf("Attempting to add node: 20\n");
	printf("Node_add return: %d\n", graph_add_node(testGraph, 20));
	my_graph_print(testGraph);
	printf("Attempting to add node: 30\n");
	printf("Node_add return: %d\n", graph_add_node(testGraph, 30));
	my_graph_print(testGraph);
	printf("Attempting to add node: 40\n");
	printf("Node_add return: %d\n", graph_add_node(testGraph, 40));
	my_graph_print(testGraph);
	printf("Attempting to add node: 50\n");
	printf("Node_add return: %d\n", graph_add_node(testGraph, 50));
	my_graph_print(testGraph);
	
	printf("Attempting to add edge: 10 to 20\n");
	printf("Edge_add return: %d\n", graph_add_edge(testGraph, 10, 20));
	my_graph_print(testGraph);
	printf("Has cycle return: %d\n\n\n\n", has_cycle(testGraph));
	printf("Attempting to add edge: 10 to 30\n");
	printf("Edge_add return: %d\n", graph_add_edge(testGraph, 10, 30));
	my_graph_print(testGraph);
	printf("Has cycle return: %d\n\n\n\n", has_cycle(testGraph));
	printf("Attempting to add edge: 20 to 40\n");
	printf("Edge_add return: %d\n", graph_add_edge(testGraph, 20, 40));
	my_graph_print(testGraph);
	printf("Has cycle return: %d\n\n\n\n", has_cycle(testGraph));
	printf("Attempting to add edge: 20 to 50\n");
	printf("Edge_add return: %d\n", graph_add_edge(testGraph, 20, 50));
	my_graph_print(testGraph);
	printf("Has cycle return: %d\n\n\n\n", has_cycle(testGraph));
	printf("Attempting to add edge: 50 to 40\n");
	printf("Edge_add return: %d\n", graph_add_edge(testGraph, 50, 40));
	my_graph_print(testGraph);
	printf("Has cycle return: %d\n\n\n\n", has_cycle(testGraph));
	printf("Attempting to add edge: 40 to 10\n");
	printf("Edge_add return: %d\n", graph_add_edge(testGraph, 40, 10));
	my_graph_print(testGraph);
	printf("Has cycle return: %d\n\n\n\n", has_cycle(testGraph));
	printf("Attempting to add edge: 30 to 50\n");
	printf("Edge_add return: %d\n", graph_add_edge(testGraph, 30, 50));
	my_graph_print(testGraph);
	printf("Has cycle return: %d\n\n\n\n", has_cycle(testGraph));
	printf("Attempting to add edge: 20 to 10\n");
	printf("Edge_add return: %d\n", graph_add_edge(testGraph, 20, 10));
	my_graph_print(testGraph);
	printf("Has cycle return: %d\n\n\n\n", has_cycle(testGraph));
	printf("Attempting to add edge: 30 to 40\n");
	printf("Edge_add return: %d\n", graph_add_edge(testGraph, 30, 40));
	my_graph_print(testGraph);
	printf("Has cycle return: %d\n", has_cycle(testGraph));
	printf("Attempting to add edge: 40 to 30\n");
	printf("Edge_add return: %d\n", graph_add_edge(testGraph, 40, 30));
	my_graph_print(testGraph);
	printf("Has cycle return: %d\n", has_cycle(testGraph));
	printf("\n");

	graph_print(testGraph);
	printf("\n");

	printf("Is reachable from 10 to 20 return: %d\n", is_reachable(testGraph, 10, 20));
	printf("Is reachable from 10 to 30 return: %d\n", is_reachable(testGraph, 10, 30));
	printf("Is reachable from 20 to 50 return: %d\n", is_reachable(testGraph, 20, 50));
	printf("Is reachable from 20 to 40 return: %d\n", is_reachable(testGraph, 20, 40));
	printf("Is reachable from 10 to 40 return: %d\n", is_reachable(testGraph, 10, 40));
	printf("Is reachable from 10 to 50 return: %d\n", is_reachable(testGraph, 10, 50));
	printf("Is reachable from 50 to 40 return: %d\n", is_reachable(testGraph, 50, 40));
	printf("Is reachable from 50 to 30 return: %d\n", is_reachable(testGraph, 50, 30));
	printf("Is reachable from 20 to 10 return: %d\n", is_reachable(testGraph, 20, 10));
	printf("Is reachable from 30 to 40 return: %d\n", is_reachable(testGraph, 30, 40));
	printf("Is reachable from 40 to 30 return: %d\n", is_reachable(testGraph, 40, 30));
	printf("Is reachable from 30 to 30 return: %d\n", is_reachable(testGraph, 30, 30));
	printf("Is reachable from 40 to 40 return: %d\n", is_reachable(testGraph, 40, 40));
	printf("\n");

	int i;
	int* n1 = getNeighbors(testGraph, 10);
	printf("getNeighbors of node 10: ");
	for (i = 0; i < 2; i++) {
		printf("%d ", n1[i]);
	}
	free(n1);
	printf("\n");
	int* n2 = getNeighbors(testGraph, 20);
	printf("getNeighbors of node 20: ");
	for (i = 0; i < 3; i++) {
		printf("%d ", n2[i]);
	}
	free(n2);
	printf("\n");
	int* n3 = getNeighbors(testGraph, 30);
	printf("getNeighbors of node 30: ");
	for (i = 0; i < 2; i++) {
		printf("%d ", n3[i]);
	}
	free(n3);
	printf("\n");
	int* n4 = getNeighbors(testGraph, 40);
	printf("getNeighbors of node 40: ");
	for (i = 0; i < 2; i++) {
		printf("%d ", n4[i]);
	}
	free(n4);
	printf("\n");
	int* n5 = getNeighbors(testGraph, 50);
	printf("getNeighbors of node 50: ");
	for (i = 0; i < 1; i++) {
		printf("%d ", n5[i]);
	}
	free(n5);
	printf("\n\n");

	printf("Path from 10 to 40:\n");
	print_path(testGraph, 10, 40);
	printf("\n");

	printf("Attempting to remove node: 40\n");
	printf("Node_remove return: %d\n", graph_remove_node(testGraph, 40));
	my_graph_print(testGraph);

	printf("Attempting to remove edge: 10 to 20\n");
	printf("Edge_remove return: %d\n", graph_remove_edge(testGraph, 10, 20));
	my_graph_print(testGraph);
	printf("Attempting to remove edge: 20 to 50\n");
	printf("Edge_remove return: %d\n", graph_remove_edge(testGraph, 20, 50));
	my_graph_print(testGraph);
	printf("Attempting to remove edge: 40 to 10\n");
	printf("Edge_remove return: %d\n", graph_remove_edge(testGraph, 10, 20));
	my_graph_print(testGraph);
	printf("Attempting to remove edge: 10 to 40\n");
	printf("Edge_remove return: %d\n", graph_remove_edge(testGraph, 10, 20));
	my_graph_print(testGraph);
	
	free_graph(testGraph);

	printf("\n\n");

}

int main() {

	unitTest1();
	unitTest2();

	return 0;

}
