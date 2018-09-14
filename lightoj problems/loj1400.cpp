#include<cstdio>
#include<string.h>
#include<cmath>
#include<queue>
#include<iostream>
#include<algorithm>
using namespace std;
#define N 102

int bp[N][N];
int gp[N][N];
int n;
bool engaged[N];
int b_s[N];
int g_s[N];

int getRank(int boy,int girl)
{
    int i;
    for(i=0;i<n;i++)
    {
        if(gp[girl][i]==boy)
            return i;
    }
}
void engage(int boy,int girl)
{
    engaged[boy]=true;
    g_s[girl] = getRank(boy,girl);
}

int main()
{
    int test,cs=1,i,j,boy,girl;
    scanf("%d",&test);
    while(test--)
    {
        scanf("%d",&n);
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&bp[i][j]);
                bp[i][j]=bp[i][j]-(n+1);
            }
        }
        for(i=0;i<n;i++)
        {
            for(j=0;j<n;j++)
            {
                scanf("%d",&gp[i][j]);
                gp[i][j]=gp[i][j]-1;
            }
        }
        memset(engaged,0,sizeof(engaged));
        memset(b_s,-1,sizeof(b_s));
        memset(g_s,-1,sizeof(g_s));
        for(boy=0;boy<n;boy++)
        {
            if(engaged[boy])
                continue;
            int girl = bp[boy][++b_s[boy]];
            if(g_s[girl]==-1)
            {
                engage(boy,girl);
            }
            else
            {
                int dumped_boy = gp[girl][g_s[girl]];
                int curr_boy_rank = getRank(boy,girl);
                int prev_boy_rank = getRank(dumped_boy,girl);
                if(curr_boy_rank<prev_boy_rank)
                {
                    engaged[dumped_boy]=false;
                    engage(boy,girl);
                    boy = dumped_boy;
                    boy--;
                    continue;
                }
                else
                {
                    boy--;
                    continue;
                }
            }
        }
        printf("Case %d: ",cs++);
        for(i=0;i<n;i++)
        {
            printf("(%d %d)%c",i+1,bp[i][b_s[i]]+n+1,(i==n-1)?'\n':' ');
        }

    }
}
