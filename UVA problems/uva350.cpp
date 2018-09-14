#include<bits/stdc++.h>

using namespace std;

int main()
{
    int Z,I,M,L,x1,x2,m,n;
    int caseNo=1;
    while(1)
    {
        scanf("%d%d%d%d",&Z,&I,&M,&L);
        if(M==0)
            break;
        x1=L;
        x2=L;
        m=0;
        do{
            x1=(x1*Z+I)%M;
            x2=(x2*Z+I)%M;
            x2=(x2*Z+I)%M;
            m++;
        }while(x1!=x2);
        x2=x1;
        n=0;
        do{
            x2=(x2*Z+I)%M;
            n++;
        }while(x1!=x2);
        printf("Case %d: %d\n",caseNo,n);
        caseNo++;
    }
    return 0;
}
