#include<stdio.h>
#include<stdlib.h>

int i=0;

typedef struct AdjNodeList  {
    int node;
    struct AdjNodeList *next;
}ADJLISTNODE;

typedef struct AdjList  {
    ADJLISTNODE *head;
}ADJLIST;

typedef struct Graph    {
    int V;
    ADJLIST *arr;
}GRAPH;

ADJLISTNODE *CreateNode(int n)  {
    ADJLISTNODE *newNode = (ADJLISTNODE*)malloc(sizeof(ADJLISTNODE));
    newNode->node = n;
    newNode->next = NULL;

    return newNode;
};

GRAPH *CreateGraph(int v)   {
    GRAPH *newgraph = (GRAPH*)malloc(sizeof(GRAPH));
    newgraph->V = v;
    newgraph->arr = (ADJLIST*)malloc(sizeof(ADJLIST)*v);

    for(i=0; i<v; i++)  {
        newgraph->arr[i].head = NULL;
    }

    return newgraph;
};

void addedge(GRAPH *graph, int n1, int n2)  {
    ADJLISTNODE *newNode = CreateNode(n2);
    newNode->next = graph->arr[n1].head;
    graph->arr[n1].head = newNode;

    newNode = CreateNode(n1);
    newNode->next = graph->arr[n2].head;
    graph->arr[n2].head = newNode;
}

void printgraph(GRAPH *graph)   {
    ADJLISTNODE *temp;
    for(i=0; i<graph->V; i++)   {
        printf("Adjacency List of Vertex %d head",i);
        temp = graph->arr[i].head;
        while(temp) {
            printf("->%d",temp->node);
            temp = temp->next;
        }
        printf("\n");
    }
}


int main()  {
    int v, n, i, e1, e2;
    scanf("%d",&v);
    GRAPH *newgraph = CreateGraph(v);
    scanf("%d",&n);
    for(i=0; i<n; i++)  {
        printf("Connection %d->E1->E2 : ",i+1);
        scanf("%d %d",&e1,&e2);
        addedge(newgraph, e1, e2);
    }



    printgraph(newgraph);

return 0;
}
