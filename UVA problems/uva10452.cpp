#include<bits/stdc++.h>

using namespace std;

int X,Y;
int NumMoves = 3;
string grid[9];
int xMoves[] = {-1,0,1};
int yMoves[] = {0,-1,0};
string moveNames[] = {"left","forth","right"};
string output[7];
string Needed = "IEHOVA#";

bool GetToIt(int x,int y,int pos)
{
    if(grid[y][x]=='#')
    {
        int i;
        cout<<output[0];
        for(i=1;i<pos;i++)
        {
            cout<<" "<<output[i];
        }
        cout<<"\n";
        return true;
    }
    else if(pos==Needed.size())
        return false;
    int mov;
    for(mov=0;mov<NumMoves;mov++)
    {
        int newX=x+xMoves[mov],newY=y+yMoves[mov];
        if(newX>=0 && newX < X && newY>=0 && newY<Y && grid[newY][newX]==Needed[pos])
        {
            output[pos]=moveNames[mov];
            if(GetToIt(newX,newY,pos+1))
                return true;
        }
    }
    return false;
}
int main()
{
    int T,y,startX,startY,x;
    cin>>T;
    while(T--)
    {
        cin>>Y>>X;
        for(y=0;y<Y;y++)
        {
            cin>>grid[y];
            for(x=0;x<X;x++)
            {
                if(grid[y][x]=='@')
                {
                    startX=x;
                    startY=y;
                }
            }
        }
        GetToIt(startX,startY,0);
    }
}
