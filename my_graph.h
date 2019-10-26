#ifndef MYGRAPH_H
#define MYGRAPH_H

struct queue {
	unsigned int back;	    // The next free position in the queue
								  // (i.e. the end or tail of the line)
	unsigned int front;	    // Current 'head' of the queue
								  // (i.e. the front or head of the line)
	unsigned int size;	    // How many total elements we currently have enqueued.
	unsigned int capacity;  // Maximum number of items the queue can hold
	int* data; 		          // The 'integer' data our queue holds	
};

typedef struct queue queue_t;

// Create a queue
// Returns a pointer to a newly created queue.
// The queue should be initialized with data on
// the heap.
queue_t* create_queue(unsigned int _capacity) {
	if ((int)_capacity <= 0) {
		exit(1);
	}
	else {
		queue_t* myQueue = NULL;
		myQueue = (queue_t*)malloc(sizeof(queue_t));
		myQueue->back = 0;
		myQueue->front = 0;
		myQueue->size = 0;
		myQueue->capacity = _capacity;
		myQueue->data = (int*)malloc(sizeof(int) * myQueue->capacity);
		return myQueue;
	}
}

// Free queue
// Removes a queue and all of its elements from memory.
// This should be called before the proram terminates.
void free_queue(queue_t* q) {
	if (q == NULL) {
		exit(1);
	}
	else {
		free(q->data);
		free(q);
	}
}

// Queue Empty
// Check if the queue is empty
// Returns 1 if true (The queue is completely empty)
// Returns 0 if false (the queue has at least one element enqueued)
int queue_empty(queue_t* q) {
	if (q == NULL) {
		exit(1);
	}
	else if ((int)q->capacity <= 0) {
		free_queue(q);
		exit(1);
	}
	else if (q->size == 0) {
		return 1;
	}
	else {
		return 0;
	}
}

// Queue Full
// Check if the queue is Full
// Returns 1 if true (The queue is completely full)
// Returns 0 if false (the queue has more space available to enqueue items)
int queue_full(queue_t* q) {
	if (q == NULL) {
		exit(1);
	}
	else if ((int)q->capacity <= 0) {
		free_queue(q);
		exit(1);
	}
	else if (q->size == q->capacity) {
		return 1;
	}
	else {
		return 0;
	}
}

// Enqueue a new item
// i.e. push a new item into our data structure
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. if the queue is full that is an error).
int queue_enqueue(queue_t *q, int item) {
	if (q == NULL) {
		exit(1);
	}
	else if ((int)q->capacity <= 0) {
		free_queue(q);
		exit(1);
	}
	if (queue_full(q) == 1) {
		return -1;
	}
	else {
		q->data[q->back] = item;
		q->back = (q->back + 1) % q->capacity;
		q->size++;
		return 0;
	}
}

// Dequeue an item
// Returns the item at the front of the queue and
// removes an item from the queue.
// Removing from an empty queue should crash the program, call exit(1)
int queue_dequeue(queue_t *q) {
	if (q == NULL) {
		exit(1);
	}
	else if ((int)q->capacity <= 0) {
		free_queue(q);
		exit(1);
	}
	else if (queue_empty(q) == 1) {
		free_queue(q);
		exit(1);
	}
	else {
		int temp = q->data[q->front];
		int i = q->front;
		q->front = (q->front + 1) % q->capacity;
		q->size--;
		return temp;
	}
}


// Create a neighbor data structure to server as the neighbor's list.
// In our case, we will stores 'integers' as our neighbors that 
// corresponding to the data that the actual nodes store.
typedef struct neighbor {
	int data;
	struct neighbor * next;
}neighbor_t;

// Create a node data structure to store data within
// our graph. In our case, we will stores 'integers'
// as our data in the nodes
typedef struct node {
	int data;
	struct node *next;
	struct neighbor * neighbor;
}node_t;

// Create a graph data structure
// Our graph keeps track of the number of nodes, the number of edges and an array
// of all the nodes in the graph, and the maximum number of nodes we store in our graph.
typedef struct graph {
	int numNodes;
	int numEdges;
	node_t* nodes;	 //an array of nodes storing all of our nodes.
					 //points to head node of linked list
}graph_t;

// Creates a graph
// Returns a pointer to a newly created graph.
// The graph should be initialized with data on the heap.
// The graph fields should also be initialized to default values.
graph_t* create_graph() {
	// Modify the body of this function as needed.
	graph_t* myGraph = NULL;
	myGraph = malloc(sizeof(graph_t));
	myGraph->nodes = NULL;
	myGraph->numNodes = 0;
	myGraph->numEdges = 0;
	return myGraph;
}

// Graph Empty
// Check if the graph is empty
// Returns 0 if true (The graph is completely empty, i.e. numNodes == 0 )
// Returns -1 if false (the graph has at least one node)
int graph_empty(graph_t* g) {
	if (g == NULL) {
		exit(1);
	}
	if (g->numNodes == 0) {
		return 0;
	}
	else {
		return -1;
	}
}

// Adds a new node withe the correspoding item in the graph.
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (i.e. the memory allocation for a new node failed).
// Duplicates nodes should not be added. For a duplicate node returns 0.
int graph_add_node(graph_t* g, int item) {
	if (g == NULL) {
		exit(1);
	}
	node_t* temp = malloc(sizeof(node_t));
	if (temp == NULL) {
		return -1;
	}
	temp->data = item;
	temp->next = NULL;
	temp->neighbor = NULL;
	if (g->nodes == NULL) {
		g->nodes = temp;
		g->numNodes++;
		return 0;
	}
	node_t* iterator = g->nodes;
	while (iterator->next != NULL) {
		if (iterator->data == item) {
			return 0;
		}
		iterator = iterator->next;
	}
	if (iterator->data == item) {
		return 0;
	}
	iterator->next = temp;
	g->numNodes++;
	return 0;
}

// Removes the node from the graph and the corresponding edges connected 
// to the node.
// Returns a -1 if the operation fails (otherwise returns 0 on success).
// (the node to be removed doesn't exist in the graph).
int graph_remove_node(graph_t* g, int item) {
	if (g == NULL) {
		exit(1);
	}
	if (graph_empty(g) == 0) {
		return -1;
	}
	if (g->nodes->data == item) {
		if (g->nodes->next == NULL) {
			g->nodes = NULL;
			free(g->nodes);
			g->numNodes--;
			return 0;
		}
		else {
			int edge_counter = 0;
			neighbor_t* n_iterator = g->nodes->neighbor;
			while (n_iterator != NULL) {
				edge_counter++;
				n_iterator = n_iterator->next;
			}
			node_t* temp = g->nodes;
			g->nodes = g->nodes->next;
			free(temp);
			g->numEdges -= edge_counter;
			g->numNodes--;
		}
	}
	else {
		node_t* previous = g->nodes;
		while (previous->next != NULL && previous->next->data != item) {
			previous = previous->next;
		}
		if (previous->next == NULL) {
			return -1;
		}
		node_t* temp = previous->next;
		neighbor_t* temp_n = temp->neighbor;
		while (temp->neighbor != NULL) {
			temp_n = temp->neighbor;
			temp->neighbor = temp->neighbor->next;
			free(temp_n);
			g->numEdges--;
		}
		previous->next = previous->next->next;
		free(temp);
		g->numNodes--;
	}
	node_t* iterator = g->nodes;
	while (iterator != NULL) {
		graph_remove_edge(g, iterator->data, item);
		iterator = iterator->next;
	}
	return 0;
}

//Adds an edge from source to destination. 
//If source or desination is not found in the graph returns -1.
//Otherwise it returns 0 ( even for trying to add a duplicate edge )
int graph_add_edge(graph_t * g, int source, int destination) {
	if (g == NULL) {
		exit(1);
	}
	int source_found = -1;
	int destination_found = -1;
	node_t* iterator = g->nodes;
	while (iterator != NULL) {
		if (iterator->data == source) {
			source_found = 0;
		}
		if (iterator->data == destination) {
			destination_found = 0;
		}
		iterator = iterator->next;
	}
	if (source_found == -1 || destination_found == -1) {
		return -1;
	}
	iterator = g->nodes;
	while (iterator != NULL) {
		if (iterator->data == source) {
			if (iterator->neighbor == NULL) {
				neighbor_t* temp = malloc(sizeof(neighbor_t));
				temp->data = destination;
				temp->next = NULL;
				iterator->neighbor = temp;
				g->numEdges++;
				return 0;
			}
			neighbor_t* neighbor_iterator = iterator->neighbor;
			while (neighbor_iterator->next != NULL) {
				if (neighbor_iterator->data == destination) {
					return 0;
				}
				neighbor_iterator = neighbor_iterator->next;
			}
			if (neighbor_iterator->data == destination) {
				return 0;
			}
			neighbor_t* temp = malloc(sizeof(neighbor_t));
			temp->data = destination;
			temp->next = NULL;
			neighbor_iterator->next = temp;
			g->numEdges++;
			return 0;
		}
		iterator = iterator->next;
	}
}

//Removes an edge from source to destination. 
//If source or desination is not found in the graph returns -1.
//If no such edge exists also returns -1.
//Otherwise it returns 0
int graph_remove_edge(graph_t * g, int source, int destination) {
	if (g == NULL) {
		exit(1);
	}
	int source_exist = -1;
	node_t* iterator = g->nodes;
	while (iterator != NULL) {
		if (iterator->data == source) {
			source_exist = 0;
			break;
		}
		iterator = iterator->next;
	}
	if (source_exist == -1) {
		return -1;
	}
	if (iterator->neighbor == NULL) {
		return -1;
	}
	if (iterator->neighbor->data == destination) {
		if (iterator->neighbor->next == NULL) {
			neighbor_t* temp = iterator->neighbor;
			iterator->neighbor = NULL;
			free(temp);
			g->numEdges--;
			return 0;
		}
		else {
			neighbor_t* temp = iterator->neighbor;
			iterator->neighbor = iterator->neighbor->next;
			free(temp);
			g->numEdges--;
			return 0;
		}
	}
	else {
		neighbor_t* previous_neighbor = iterator->neighbor;
		while (previous_neighbor->next != NULL && previous_neighbor->next->data != destination) {
			previous_neighbor = previous_neighbor->next;
		}
		if (previous_neighbor->next != NULL) {
			neighbor_t* temp = previous_neighbor->next;
			previous_neighbor->next = previous_neighbor->next->next;
			free(temp);
			g->numEdges--;
			return 0;
		}
	}
	return -1;
}

//Returns 1 if the node with value is in the graph, otherwise returns 0;
int contains_node(graph_t * g, int value) {
	if (g == NULL) {
		exit(1);
	}
	node_t* iterator = g->nodes;
	while (iterator != NULL) {
		if (iterator->data == value) {
			return 1;
		}
		iterator = iterator->next;
	}
	return 0;
}

//Returns 1 if an edge from source to destination exists, 0 otherwise.
int contains_edge(graph_t * g, int source, int destination) {
	if (g == NULL) {
		exit(1);
	}
	int source_exist = -1;
	node_t* iterator = g->nodes;
	while (iterator != NULL) {
		if (iterator->data == source) {
			source_exist = 0;
			break;
		}
		iterator = iterator->next;
	}
	if (source_exist == -1) {
		return 0;
	}
	if (iterator->neighbor == NULL) {
		return 0;
	}
	if (iterator->neighbor->data == destination) {
		return 1;
	}
	else {
		neighbor_t* neighbor_iterator = iterator->neighbor;
		while (neighbor_iterator != NULL) {
			if (neighbor_iterator->data == destination) {
				return 1;
			}
			neighbor_iterator = neighbor_iterator->next;
		}
	}
	return 0;
}
//Returns an int array of all the neighbors of the node with data=value.
int * getNeighbors(graph_t * g, int value) {
	node_t* iterator = g->nodes;
	while (iterator != NULL) {
		if (iterator->data == value) {
			break;
		}
		iterator = iterator->next;
	}
	neighbor_t* temp = iterator->neighbor;
	int num = 0;
	int i;
	while (temp != NULL) {
		num++;
		temp = temp->next;
	}
	int* neighbors_lst = malloc(sizeof(int) * num);
	temp = iterator->neighbor;
	for (i = 0; i < num; i++) {
		neighbors_lst[i] = temp->data;
		temp = temp->next;
	}
	return neighbors_lst;
}

// Returns the number of neighbors for value.
int numNeighbors(graph_t * g, int value) {
	if (g == NULL) {
		exit(1);
	}
	int source_exist = -1;
	node_t* iterator = g->nodes;
	while (iterator != NULL) {
		if (iterator->data == value) {
			source_exist = 0;
			break;
		}
		iterator = iterator->next;
	}
	if (source_exist == -1) {
		return -1;
	}
	if (iterator->neighbor == NULL) {
		return 0;
	}
	int num = 0;
	neighbor_t* neighbor_iterator = iterator->neighbor;
	while (neighbor_iterator != NULL) {
		num++;
		neighbor_iterator = neighbor_iterator->next;
	}
	return num;

}

// Prints the the graph using BFS
// For NULL or empty graph it should print nothing. 
void graph_print(graph_t * g) {
	if (g != NULL && graph_empty(g) == -1) {
		queue_t* q = create_queue(g->numNodes);
		int visited[g->numNodes];
		int visited_index = 0;
		int current_node;
		int temp_neighbor;
		int i;
		int counter = 0;
		neighbor_t* temp = NULL;
		node_t* iterator = g->nodes;
		queue_enqueue(q, g->nodes->data);
		while (queue_empty(q) == 0) {
			//printf("test1\n");
			current_node = queue_dequeue(q);
			for (i = 0; i < visited_index + 1; i++) {
				if (visited[i] == current_node) {
					counter = 1;
				}
			}
			if (counter == 0) {
				visited[visited_index] = current_node;
				visited_index++;
			}
			counter = 0;
			if (iterator != NULL) {
				temp = iterator->neighbor;
				while (temp != NULL) {
					for (i = 0; i < visited_index; i++) {
						if (visited[i] == temp->data) {
							counter = 1;
						}
					}
					if (counter == 0) {
						queue_enqueue(q, temp->data);
					}
					counter = 0;
					temp = temp->next;
				}
				iterator = iterator->next;
			}
		}
		iterator = g->nodes;
		while (iterator != NULL) {
			for (i = 0; i < visited_index; i++) {
				if (visited[i] == iterator->data) {
					counter = 1;
				}
			}
			if (counter == 0) {
				visited[visited_index] = iterator->data;
				visited_index++;
			}
			counter = 0;
			iterator = iterator->next;
		}
		printf("Graph print: ");
		for (i = 0; i < visited_index; i++) {
			printf("%d ", visited[i]);
		}
		printf("\n");
		free_queue(q);
	}
}

// Graph Size
// Returns the number of nodes in the graph
unsigned int graph_num_nodes(graph_t* g) {
	if (g == NULL) {
		exit(1);
	}
	return g->numNodes;
}

// Graph Size
// Returns the number of edges in the graph
unsigned int graph_num_edges(graph_t* g) {
	if (g == NULL) {
		exit(1);
	}
	return g->numEdges;
}

// Free graph
// Removes a graph and ALL of its elements from memory.
// This should be called before the proram terminates.
void free_graph(graph_t* g) {
	if (g == NULL) {
		exit(1);
	}
	node_t* temp = NULL;
	neighbor_t* temp_n = NULL;
	while (g->nodes != NULL) {
		while (g->nodes->neighbor != NULL) {
			temp_n = g->nodes->neighbor;
			g->nodes->neighbor = g->nodes->neighbor->next;
			free(temp_n);
		}
		temp = g->nodes;
		g->nodes = g->nodes->next;
		free(temp);
	}
	free(g);
}

// returns 0 if I can reach the destination from source, -1 otherwise(using BFS)
int is_reachable(graph_t * g, int source, int dest) {
	if (g == NULL) {
		exit(1);
	}
	node_t* iterator = g->nodes;
	while (iterator != NULL) {
		if (iterator->data == source) {
			break;
		}
		iterator = iterator->next;
	}
	neighbor_t* temp = NULL;
	int current_node;
	int visited[g->numNodes];
	int visited_index = 0;
	int i;
	int counter = 0;
	queue_t* q = create_queue(g->numNodes);
	queue_enqueue(q, iterator->data);
	while (queue_empty(q) == 0) {
		current_node = queue_dequeue(q);
		iterator = g->nodes;
		while (iterator != NULL) {
			if (iterator->data == current_node) {
				break;
			}
			iterator = iterator->next;
		}
		temp = iterator->neighbor;
		while (temp != NULL) {
			if (temp->data == dest) {
				free_queue(q);
				return 0;
			}
			for (i = 0; i < visited_index; i++) {
				if (visited[i] == temp->data) {
					counter = 1;
				}
			}
			if (counter == 0) {
				queue_enqueue(q, temp->data);
			}
			counter = 0;
			temp = temp->next;
		}
	}
	free_queue(q);
	return -1;
}

// returns 0 if there is a cycle in the graph, -1 otherwise(using BFS or DFS)
int has_cycle(graph_t * g) {
	if (g == NULL) {
		exit(1);
	}
	node_t* iterator = g->nodes;
	node_t* other_iterator = g->nodes;
	neighbor_t* temp = NULL;
	int current_node;
	int i;
	int counter;
	int visited[g->numNodes];
	int visited_index;
	int value;
	while (iterator != NULL) {
		value = iterator->data;
		visited_index = 0;
		counter = 0;
		queue_t* q = create_queue(100);
		queue_enqueue(q, iterator->data);
		while (queue_empty(q) == 0) {
			current_node = queue_dequeue(q);
			other_iterator = g->nodes;
			while (other_iterator != NULL) {
				if (other_iterator->data == current_node) {
					break;
				}
				other_iterator = other_iterator->next;
			}
			temp = other_iterator->neighbor;
			while (temp != NULL) {
				if (temp->data == value) {
					free_queue(q);
					return 0;
				}
				for (i = 0; i < visited_index; i++) {
					if (visited[i] == temp->data) {
						counter = 1;
					}
				}
				if (counter == 0) {
					queue_enqueue(q, temp->data);
				}
				counter = 0;
				temp = temp->next;
			}
		}
		iterator = iterator->next;
		free_queue(q);
	}
	return -1;
}

// Recursive function to help print path
void print_path_help(graph_t * g, int start, int end, int visited[], int visited_index, int path[], int path_index) {
	visited[visited_index] = start;
	visited_index++;
	path[path_index] = start;
	path_index++;
	int i;
	int counter = 0;
	if (start == end) {
		printf("Path: ");
		for (i = 0; i < path_index; i++) {
			printf("%d ", path[i]);
		}
		printf("\n");
	}
	else {
		node_t* iterator = g->nodes;
		while (iterator != NULL) {
			if (iterator->data == start) {
				break;
			}
			iterator = iterator->next;
		}
		neighbor_t* temp = iterator->neighbor;
		while (temp != NULL) {
			for (i = 0; i < visited_index; i++) {
				if (visited[i] == temp->data) {
					counter = 1;
				}
				if (counter == 0) {
					print_path_help(g, temp->data, end, visited, visited_index, path, path_index);
					break;
				}
			}
			temp = temp->next;
		}
	}
	path_index--;
	visited_index--;
}

// prints any path from source to destination if there exists one(Choose either BFS or DFS, typically DFS is much simpler)
void print_path(graph_t * g, int source, int dest) {
	int visited[g->numNodes];
	int path[g->numNodes];
	int path_index = 0;
	int i;
	int visited_index = 0;
	print_path_help(g, source, dest, visited, visited_index, path, path_index);
}

// Function to print graph and neighbors
void my_graph_print(graph_t* g) {
	if (g == NULL) {
		printf("Cannot print stack: graph is NULL\n");
	}
	else if (graph_empty(g) == 0) {
		printf("Empty Graph\n");
		printf("Nodes List: none\n");
		printf("numNodes: %d\n", g->numNodes);
		printf("numEdges: %d\n", g->numEdges);
	}
	else
	{
		printf("Nodes List:\n");
		node_t* iterator = g->nodes;
		neighbor_t* n_iterator = NULL;
		while (iterator != NULL) {
			printf("%d\n", iterator->data);
			n_iterator = iterator->neighbor;
			printf("\tNeighbors List: ");
			while (n_iterator != NULL) {
				printf("%d ", n_iterator->data);
				n_iterator = n_iterator->next;
			}
			printf("\n");
			iterator = iterator->next;
		}
		printf("\nnumNodes: %d\n", g->numNodes);
		printf("numEdges: %d\n\n", g->numEdges);
	}
}



#endif
