#include <stdio.h>
#include <stdlib.h>

// Structure for a node in the adjacency list
struct Node {
    int data;
    struct Node* next;
};

// Structure for the adjacency list
struct Graph {
    int numVertices;
    struct Node** adjList;
};

// Function to create a new node
struct Node* createNode(int data) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->data = data;
    newNode->next = NULL;
    return newNode;
}

// Function to create a graph with a given number of vertices
struct Graph* createGraph(int numVertices) {
    struct Graph* graph = (struct Graph*)malloc(sizeof(struct Graph));
    graph->numVertices = numVertices;

    // Allocate memory for the array of adjacency lists
    graph->adjList = (struct Node**)malloc(numVertices * sizeof(struct Node*));

    // Initialize each adjacency list as empty by setting each head to NULL
    for (int i = 0; i < numVertices; ++i) {
        graph->adjList[i] = NULL;
    }

    return graph;
}

// Function to add an edge to the graph
void addEdge(struct Graph* graph, int src, int dest) {
    // Add an edge from src to dest
    struct Node* newNode = createNode(dest);
    newNode->next = graph->adjList[src];
    graph->adjList[src] = newNode;

    // For an undirected graph, add an edge from dest to src as well
    newNode = createNode(src);
    newNode->next = graph->adjList[dest];
    graph->adjList[dest] = newNode;
}

// Recursive function for DFS traversal
void DFSUtil(struct Graph* graph, int vertex, int* visited) {
    // Mark the current vertex as visited and print it
    visited[vertex] = 1;
    printf("%d ", vertex);

    // Traverse all adjacent vertices of the current vertex
    struct Node* temp = graph->adjList[vertex];
    while (temp != NULL) {
        int adjVertex = temp->data;
        if (!visited[adjVertex]) {
            // Recursively visit the adjacent vertex
            DFSUtil(graph, adjVertex, visited);
        }
        temp = temp->next;
    }
}

// Function to perform Depth-First Search on the graph
void DFS(struct Graph* graph, int startVertex) {
    // Create an array to keep track of visited vertices
    int* visited = (int*)malloc(graph->numVertices * sizeof(int));
    for (int i = 0; i < graph->numVertices; ++i) {
        visited[i] = 0; // Mark all vertices as not visited
    }

    // Perform DFS starting from the specified vertex
    DFSUtil(graph, startVertex, visited);

    // Free allocated memory
    free(visited);
}

int main() {
    // Create a sample graph
    struct Graph* graph = createGraph(6);
    addEdge(graph, 0, 1);
    addEdge(graph, 0, 2);
    addEdge(graph, 1, 3);
    addEdge(graph, 1, 4);
    addEdge(graph, 2, 4);
    addEdge(graph, 3, 5);
    addEdge(graph, 4, 5);

    // Perform DFS starting from vertex 0
    printf("Depth-First Traversal starting from vertex 0:\n");
    DFS(graph, 0);

    // Free allocated memory
    free(graph->adjList);
    free(graph);

    return 0;
}
