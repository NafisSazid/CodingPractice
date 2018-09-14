#include<bits/stdc++.h>
using namespace std;

map<string,string> route;
map<string,int> visited;

int bfs(string a,string b,map<string,vector<string> > graph)
{
    int i;
    queue<string>s;
    s.push(a);
    visited[a]=1;
    while(s.empty()==false){
        string top=s.front();
        s.pop();
        if(top==b)
            return visited[top];
        int size=graph[top].size();
        for(i=0;i<size;i++)
        {
            string n=graph[top][i];
            if(visited[n]==-1)
            {
                visited[n]=visited[top]+1;
                route[n]=top;
                s.push(n);
            }
        }
    }
    return -1;
}
void printPath(string end,string start)
{
    if(start==end)
        return;
    printPath(route[end],start);
    cout<<route[end]<<" "<<end<<endl;
}

int main()
{
    int i,n;
    bool out=false;
    while(scanf("%d",&n)!=EOF)
    {
        map<string,vector<string> > graph;
        string s1,s2,start,end;
        for(i=0;i<n;i++)
        {
            cin>>s1>>s2;
            graph[s1].push_back(s2);
            graph[s2].push_back(s1);
            visited[s1]=-1;
            visited[s2]=-1;
        }
        cin>>start>>end;
        if(out)
            printf("\n");
        out=true;
        if(bfs(start,end,graph)!=-1)
            printPath(end,start);
        else
            printf("No route\n");

    }
    return 0;
}
