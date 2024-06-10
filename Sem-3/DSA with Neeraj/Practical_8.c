/*
Write a program to perform Depth First Search (DFS) and Breadth First Search (BFS) traversal techniques on graph using adjacency matrix representation.
Author: Neeraj
Date: October 30, 2023
*/

#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

#define MAX_VERTICES 10

int adjacencyMatrix[MAX_VERTICES][MAX_VERTICES];
int visited[MAX_VERTICES];
int queue[MAX_VERTICES];
int front = -1, rear = -1;

void initializeGraph(int vertices) {
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
        for (int j = 0; j < vertices; j++) {
            adjacencyMatrix[i][j] = 0;
        }
    }
}

void addEdge(int start, int end) {
    adjacencyMatrix[start][end] = 1;
    adjacencyMatrix[end][start] = 1;
}

void DFS(int vertex, int vertices) {
    printf("%d ", vertex);
    visited[vertex] = 1;
    for (int i = 0; i < vertices; i++) {
        if (adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
            DFS(i, vertices);
        }
    }
}

void enqueue(int vertex) {
    if (rear == MAX_VERTICES - 1) {
        printf("Queue is full.\n");
    } else {
        if (front == -1) {
            front = 0;
        }
        rear++;
        queue[rear] = vertex;
    }
}

int dequeue() {
    int vertex;
    if (front == -1) {
        printf("Queue is empty.\n");
        return -1;
    } else {
        vertex = queue[front];
        front++;
        if (front > rear) {
            front = rear = -1;
        }
        return vertex;
    }
}

void BFS(int start, int vertices) {
    int vertex;
    printf("%d ", start);
    visited[start] = 1;
    enqueue(start);
    while (front != -1) {
        vertex = dequeue();
        for (int i = 0; i < vertices; i++) {
            if (adjacencyMatrix[vertex][i] == 1 && !visited[i]) {
                printf("%d ", i);
                visited[i] = 1;
                enqueue(i);
            }
        }
    }
}

int main() {
    int vertices, edges, start;
    
    printf("Enter the number of vertices: ");
    scanf("%d", &vertices);
    vertices++;
    initializeGraph(vertices);
    
    printf("Enter the number of edges: ");
    scanf("%d", &edges);
    
    for (int i = 0; i < edges; i++) {
        int start, end;
        printf("Enter edge (start end): ");
        scanf("%d %d", &start, &end);
        addEdge(start, end);
    }
    
    printf("Enter the starting vertex for traversal: ");
    scanf("%d", &start);
    
    printf("DFS Traversal: ");
    DFS(start, vertices);
    printf("\n");
    
    for (int i = 0; i < vertices; i++) {
        visited[i] = 0;
    }
    
    printf("BFS Traversal: ");
    BFS(start, vertices);
    printf("\n");
    
    printf("Adjacency Matrix:\n");
    for (int i = 0; i < vertices; i++) {
        for (int j = 0; j < vertices; j++) {
            printf("%d ", adjacencyMatrix[i][j]);
        }
        printf("\n");
    }
    
    return 0;
}