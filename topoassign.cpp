#include<bits/stdc++.h>
using namespace std;
const int maxn = 101;

vector<int> v[maxn];
bool vis[maxn];
int ans[maxn], cnt;

void dfs(int i)
{
	vis[i] = true;
	for (vector<int>::iterator iter = v[i].begin(); iter != v[i].end(); ++iter)
		if (!vis[*iter]) dfs(*iter);
	ans[cnt++] = i;
}

int main()
{
	int n, m, i, a, b;
	while (scanf("%d%d", &n, &m), n)
	{
		for (i = 1; i <= n; ++i) v[i].clear();
		while (m--)
		{
			scanf("%d%d", &a, &b);
			v[a].push_back(b);
		}
		memset(vis, 0, sizeof(vis));
		cnt = 0;
		for (i = 1; i <= n; ++i)
			if (!vis[i]) dfs(i);
		for (i = n - 1; i; --i){
                    if(i==1)
                    printf("CSE-2115 %d ", ans[i]);
                else if(i==2)
                    printf("CSE-3023 %d ", ans[i]);
                else if(i==3)
                    printf("CSE-1013 %d ", ans[i]);
                else if(i==4)
                    printf("CSE-1033 %d ", ans[i]);
                else if(i==5)
                 printf("CSE-2026 %d ", ans[i]);
                    else if(i==6)
                printf("CSE-4015 %d ", ans[i]);
                    else if(i==7)
                printf("CSE-3034 %d ", ans[i]);
                    else if(i==8)
                printf("CSE-1034 %d ", ans[i]);
                    else if(i==9)
                printf("CSE-2021 %d ", ans[i]);


                		}

	}
	return 0;
}
