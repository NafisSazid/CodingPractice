#include <cstdio>
#include <cctype>
#include <algorithm>
#include <cstring>
#include <iostream>
#include <cmath>
#include <stack>
#include <string>
#include <map>
#include <set>
#include <list>
#include <queue>
#include <utility>

#define SIZE 105
#define MOD 200071027

using namespace std;
int n,m;
list<int> adj[SIZE];
bool visited[SIZE];
int time1[SIZE];
int time2[SIZE];

void bfs(int node,int *time)
{
    queue<int>q;
    visited[node]=true;
    q.push(node);
    time[node]=0;
    while(!q.empty())
    {
        node = q.front();
        q.pop();
        for(list<int>::iterator it=adj[node].begin();it!=adj[node].end();it++)
        {
            if(!visited[*it])
            {
                visited[*it]=true;
                time[*it]=time[node]+1;
                q.push(*it);
            }
        }
    }
}
int main()
{
    int i,j,k,l,sum=0,tc,t,a,b;
    bool flag;
    scanf("%d",&tc);
    for(t=1;t<=tc;t++)
    {
        scanf("%d%d",&n,&m);
        for(i=0;i<n;i++)
        {
            adj[i].clear();
        }
        for(i=0;i<m;i++)
        {
            scanf("%d%d",&a,&b);
            adj[a].push_back(b);
            adj[b].push_back(a);
        }
        scanf("%d%d",&a,&b);
        memset(visited,0,sizeof(visited));
        bfs(a,time1);
        memset(visited,0,sizeof(visited));
        bfs(b,time2);
        int mx=0;
        for(i=0;i<n;i++)
        {
            mx=max(mx,time1[i]+time2[i]);
        }
        printf("Case %d: %d\n",t,mx);
    }
    return 0;
}
