#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
struct GraphNode
{
    char value;
    int visited;
    struct GraphNode *next;
};
struct GraphNode *createNode(char value)
{
    struct GraphNode *newNode = (struct GraphNode *)malloc(sizeof(struct GraphNode));
    newNode->value = value;
    newNode->visited = 0;
    newNode->next = NULL;
    return newNode;
}
void addEdge(struct GraphNode *graph[], char src, char dest)
{
    struct GraphNode *newNode = createNode(dest);
    newNode->next = graph[src - 'A'];
    graph[src - 'A'] = newNode;
    newNode = createNode(src);
    newNode->next = graph[dest - 'A'];
    graph[dest - 'A'] = newNode;
}
void BFS(struct GraphNode *graph[], int numNodes, char startNode)
{
    int visited[26] = {0};
    printf("BFS Traversal: ");
    struct GraphNode *queue[26];
    int front = 0, rear = 0;
    visited[startNode - 'A'] = 1;
    printf("%c ", startNode);
    queue[rear++] = graph[startNode - 'A'];
    while (front != rear)
    {
        struct GraphNode *currentNode = queue[front++];
        while (currentNode)
        {
            char c = currentNode->value;
            if (!visited[c - 'A'])
            {
                printf("%c ", c);
                visited[c - 'A'] = 1;
                queue[rear++] = graph[c - 'A'];
            }
            currentNode = currentNode->next;
        }
    }
    printf("\n");
}
void DFSUtil(struct GraphNode *graph[], char node, int visited[])
{
    visited[node - 'A'] = 1;
    printf("%c ", node);
    struct GraphNode *currentNode = graph[node - 'A'];
    while (currentNode)
    {
        if (!visited[currentNode->value - 'A'])
        {
            DFSUtil(graph, currentNode->value, visited);
        }
        currentNode = currentNode->next;
    }
}
void DFS(struct GraphNode *graph[], int numNodes, char startNode)
{
    int visited[26] = {0};
    printf("DFS Traversal: ");
    DFSUtil(graph, startNode, visited);
    printf("\n");
}
int main()
{
    int numNodes;
    char startNode;
    printf("Enter the number of nodes: ");
    scanf("%d", &numNodes);
    struct GraphNode *graph[26] = {NULL};
    printf("Enter the edges in the form of nodes:\n");
    char src, dest;
    while (numNodes--)
    {
        scanf(" %c %c", &src, &dest);
        addEdge(graph, src, dest);
    }
    printf("Enter the starting node for traversal: ");
    scanf(" %c", &startNode);
    int exit = 1, choice;
    while (exit == 1)
    {
        printf("\nEnter a choice:\n1. BFS traversal\n2. DFS traversal\n3. Exit Program\n");
        scanf("%d", &choice);
        switch (choice)
        {
        case 1:
            BFS(graph, 26, startNode);
            break;
        case 2:
            DFS(graph, 26, startNode);
            break;
        case 3:
            exit = 0;
            break;
        deafult:
            printf("\nEnter Valid Choice\n");
        }
    }
    for (int i = 0; i < 26; i++)
    {
        struct GraphNode *current = graph[i];
        while (current)
        {
            struct GraphNode *temp = current;
            current = current->next;
            free(temp);
        }
    }
    return 0;
}
