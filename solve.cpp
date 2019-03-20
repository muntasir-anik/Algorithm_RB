#include<bits/stdc++.h>
using namespace std;

struct Node
{
    int u , w; // u->vertex . w-> cost;
};


class cmp
{
public:
    bool operator() (Node &a, Node &b)
    {
        return a.w > b.w;
    }
};

int N,  e, graph[10] [10] ; // N= num of vertex ; e = edge;

void clr()
{
    for(int i=0;i<10; i++)
        for(int j=0; j<10; j++)
          graph[i][j] = -1;
}


int Dijkstra(int s, int d)
  {
      bool color[10];
      for(int i=0; i<10; i++)
        color[i]= false;

      priority_queue<Node, vector <Node>, cmp>PQ;
      PQ.push({s,0});

      while(PQ.size() != 0)
      {
          Node x = PQ.top() ;
          PQ.pop();

          int u= x.u , w= x.w;
          if(color[u]==true) continue;
          if(u==d) return w;
          color[u] = true;

          for(int i=0; i<10; i++)
          {
              if(graph[u][i] != -1)
              PQ.push({i, w+graph[u][i]});
          }
      }
  }


int main()
{
freopen("input.txt", "r", stdin);
clr();

cin>>N>>e;

for(int i=1; i<=e; i++)
{
    int u, v, w; // u-> v, cost=w;
    cin>>u>>v>>w;
    graph[u][v] = w ;
}

int s, d;
cin>>s >>d;

cout<< Dijkstra(s,d) <<endl;


    return 0;
}
