#include<stdio.h>
#include<algorithm>
#include<vector>
#include<bits/stdc++.h>
#define MAX 10005

using namespace std;
vector<int>graph[MAX];
int total;
bool visited[MAX];

void dfs(int u)
{
    total++;
    visited[u]=true;
    int v;
    for(v=0;v<graph[u].size();v++)
    {
        if(!visited[graph[u][v]])
            dfs(graph[u][v]);
    }
}
int main()
{
    int T,n,m,l,x,y,z,i;
    scanf("%d",&T);
    while(T--)
    {
        scanf("%d%d%d",&n,&m,&l);
        while(m--)
        {
            scanf("%d%d",&x,&y);
            graph[x].push_back(y);
        }
        while(l--)
        {
            scanf("%d",&z);
            if(!visited[z])
                dfs(z);
        }
        printf("%d\n",total);
        total=0;
        memset(visited,false,sizeof(visited));
        for(i=0;i<n;i++)
        {
            graph[i].clear();
        }
    }
    return 0;
}
