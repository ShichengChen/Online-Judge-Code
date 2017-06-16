#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<cstring>
#include<cmath>
using namespace std;
#define MAX 1000
struct VOLUME
{
    int a,b;
    bool operator < (const VOLUME & vol)const
    {
            return fabs(vol.b - vol.a) < fabs(b - a);
    }
}vol[MAX];
int main()
{
        int V,N,T;scanf("%d",&T);
        while(T--)
        {
                scanf("%d%d",&V,&N);
                for(int i = 0;i < N;i++)
                        scanf("%d%d",&vol[i].a,&vol[i].b);
                sort(vol,vol + N);
                bool success = 0;
                for(int i = 0;i < N;i++)
                {
                        if(vol[i].b <= V)
                            V -= vol[i].a;
                        else
                            break;
                        if(i == N - 1)success = 1;
                }
                if(success)puts("Yes");
                else puts("No");
        }
}
