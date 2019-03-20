#include<bits/stdc++.h>
using namespace std;
int graph[100][100],color[100],dist[100];
struct node
{
    int  u, w;
};
int main()
{
    freopen ("in.txt","r",stdin);
    int n, m;
    cin>> n >> m ;
    for(int i=1; i<=m; i++)
    {
        int u , v ;
        cin>>  u >>  v ;
        graph[u][v] = graph[v][u] = 1;
    }
    int s,d;
    cin>> s >> d;
    queue< node>Q;
    Q.push({s,0});
    while (Q.size()!=0)
    {
        int u =Q.front().u;
        int w = Q.front().w;
        Q.pop();
        for(int i=1; i<=n;i++)
        {
            if (graph[u][i]==1 &&color[i]==0)
            {
                Q.push({i,w+1});
                color[i]=1;
                dist[i]= w+1;
            }
        }
    }
    cout<< dist[d]<< endl;
    return 0;
}
