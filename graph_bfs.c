#include<stdio.h>
#include<malloc.h>

//----------------------------------GRAPH----------------------------------------//
typedef struct edge {
    int node;
    struct edge *next;
}EDGE;

EDGE *newEdge, *tptr;

typedef struct AdjacencyList    {
    EDGE *head;
}ADJLIST;

typedef struct Graph    {
    int V;              //number of Vertex.
    ADJLIST *list;
}GRAPH;

GRAPH *newgraph;

EDGE *CreateEdge(int n) {
    newEdge = (EDGE*)malloc(sizeof(EDGE));
    newEdge->node = n;
    newEdge->next = NULL;

    return newEdge;
};

GRAPH *CreateGraph(int v)   {
    newgraph = (GRAPH*)malloc(sizeof(GRAPH));
    newgraph->V = v;
    newgraph->list = (ADJLIST*)malloc(v*sizeof(ADJLIST));
    int i;
    for(i=0; i<v; i++)
        newgraph->list[i].head = NULL;

    return newgraph;
};
//-------------------------------------------------------------------------//

typedef struct queue    {
    int node;
    struct queue *next;
}QUEUE;

QUEUE *front, *rear, *temp, *newqnode;

QUEUE *CreateQueue(int n)    {
    newqnode = (QUEUE*)malloc(sizeof(QUEUE));
    //newqnode->node =
    newqnode->node = n;
    newqnode->next = NULL;

    return newqnode;
};


//------------------------------------------------------------------------//

void addedge(GRAPH *graph , int e1, int e2) {
    newEdge = CreateEdge(e2);
    newEdge->next = graph->list[e1].head;
    graph->list[e1].head = newEdge;

    newEdge = CreateEdge(e1);
    newEdge->next = graph->list[e2].head;
    graph->list[e2].head = newEdge;
}

void enqueue(int n)   {
    newqnode = CreateQueue(n);

    if(front==NULL)
        front = rear = newqnode;
    else    {
        rear->next = newqnode;
        rear = newqnode;
    }
}

void displatbfs()   {
    for(temp=front; temp; temp=temp->next)  {
        printf("%d ",temp->node);
    }
}

void bfs(GRAPH *graph, int v)   {
    int i, n = graph->V;
    int arr[n];
    for(i=0; i<n; i++)  {
        arr[i] = 0;
    }
    enqueue(v);
    arr[v] = 1;
    temp = front;
    while(temp) {
            tptr = graph->list[temp->node].head;
        for( ; tptr; tptr=tptr->next)  {
            if(arr[tptr->node]!=1)  {
                enqueue(tptr->node);
                arr[tptr->node] = 1;
            }
        }
        temp = temp->next;
    }
    displatbfs();

}

int main()  {
    GRAPH *graph = CreateGraph(5);
    addedge(graph, 0, 1);
    addedge(graph, 0, 3);
    addedge(graph, 0, 4);
    addedge(graph, 1, 2);
    addedge(graph, 1, 3);
    addedge(graph, 3, 2);
    addedge(graph, 3, 4);
    bfs(graph, 0);
}





