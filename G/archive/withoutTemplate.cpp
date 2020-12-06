#include<iostream>
#include<cstdio>
#include<cstring>
#include<algorithm>
#include<cmath>
#include <assert.h>
using namespace std;
int n,m,dis[20][20];
int t;
int dp[20][100000];
int nextedge[21][220000];

void floyd(){//球最短路
    for(int k=0;k<n;++k)
        for(int i=0;i<n;++i)
            for(int j=0;j<n;++j)
                dis[i][j]=min(dis[i][k]+dis[k][j],dis[i][j]);
}
int main(){
    cin>>t;
    for(int k=1;k<=t;++k){
        cin>>n>>m;
        memset(dis,0x3f,sizeof(dis));
        memset(dp,0x3f,sizeof(dp));
        for(int i = 1;i<=m;i++) {
            int a,b,c;
            scanf("%d %d %d",&a,&b,&c); a--;b--;
            dis[a][b]=min(dis[a][b],c);
            dis[b][a]=dis[a][b];
        }
        if(n==1){
            puts("0");
            continue;
        }
        for(int i=0;i<n;i++) dis[i][i]=0;
        floyd();
        dp[0][(1<<n)-1]=0;
        for(int s=(1<<n)-2;s>=0;--s)
            for(int i=0;i<n;++i)
                for(int j=0;j<n;++j)
                    if(!(s>>j & 1) && i!=j && ((s==0 && i==0) || (s && (s>>i & 1)))){
                        dp[i][s]=min(dp[i][s],dp[j][s|(1<<j)]+dis[i][j]);
                        nextedge[i][s]=j;
                    }
        for (int i = 0,u=0,s=0; i < n-1; ++i) {
            //print(u);
            int v=nextedge[u][s];
            //print(v,bitdp[u][s],w[u][v]);
            //cout << v << " " << dp[u][s] << " " << dis[u][v] << endl;
            assert(!(s>>v & 1));
            if((s>>v & 1))cout << "1111";
            s|=(1<<v);
            u=v;
            if(i==n-2){
                //print(0,bitdp[u][s],w[u][0]);
                //cout << "0 " << dp[u][s] << " " << dis[u][0] << endl;
            }
        }
        cout<<dp[0][0]<<endl;
    }
}
/*
 99
4 6
1 2 1
1 3 1
1 4 1
2 3 1
 2 4 1
3 4 1
 * */