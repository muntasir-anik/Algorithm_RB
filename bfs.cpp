#include<bits/stdc++.h>
using namespace std;

int graph[15][15];
int arr[1000], a[1000];

void clr()
{
    for(int i = 0; i <= 14; i++)
        for(int j = 0; j <= 14; j++)
            graph[i][j] = -1;

}

int BFS(int s, int d)
{
    bool color[15] ;
    for(int i = 0; i <= 14; i++)
        color[i] = false;
    queue < pair<int,int> > Q;
    Q.push({s, 0});
    color[s] = true;
    a[s] = -1;
    while( !Q.empty())
    {
        int u = Q.front().first;
        int c = Q.front().second;

        if(u == d)
            return c;
        Q.pop();

        for(int i = 1; i <= 14; i++)
        {
            if(graph[u][i] == 1 && color[i] == false)
            {
                Q.push({i,c+1});
                color[i] = true;
                a[i] = u;
            }
        }
    }
    return -1;
}

void PrintPath(int d)
{
    int j = -1;
    for(int i = d; i != -1; i = a[i])
    {
        arr[++j] = i;
    }
    for(int i = j; i >= 0; i--)
    {
        cout << arr[i] << " ";
    }
}

int main()
{
    clr();
    freopen("bfsinput.txt","r",stdin);
    int v, e;
    cin >> v >> e;

    for(int i = 1; i <= e; i++)
    {
        int a, b;
        cin >> a >> b;
        graph[a][b] = graph[b][a] = 1;
    }

    int source, destination;
    cin >> source >> destination;

    cout << BFS(source, destination) << endl;

    PrintPath(destination);

    cout << endl;

    return 0;
}
