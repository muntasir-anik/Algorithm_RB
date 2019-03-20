#include<bits/stdc++.h>
using namespace std;

class Graph
{
    int V;
    list<int> *adj;

    void topologicalSortUtil(int v, bool visited[], stack<int> &Stack);
public:
    Graph(int V);
    void cse(int v, int w);
    void topologicalSort();
};

Graph::Graph(int V)
{
    this->V = V;
    adj = new list<int>[V];
}

void Graph::cse(int v, int w)
{
    adj[v].push_back(w);
}
void Graph::topologicalSortUtil(int v, bool visited[],
                                stack<int> &Stack)
{
    visited[v] = true;

    list<int>::iterator i;
    for (i = adj[v].begin(); i != adj[v].end(); ++i)
        if (!visited[*i])
            topologicalSortUtil(*i, visited, Stack);
    Stack.push(v);
}


void Graph::topologicalSort()
{
    stack<int> Stack;

    bool *visited = new bool[V];
    for (int i = 0; i < V; i++)
        visited[i] = false;

    for (int i = 0; i < V; i++)
      if (visited[i] == false)
        topologicalSortUtil(i, visited, Stack);

    while (Stack.empty() == false)
    {
        cout << Stack.top() << " ";
        Stack.pop();
    }
}

int main()
{
    Graph g(3);
    g.cse(1013,1012);
    g.cse(2026,2021);
    g.cse(1033,1034);


    cout << "Topological Sort n";
    g.topologicalSort();

    return 0;
}
