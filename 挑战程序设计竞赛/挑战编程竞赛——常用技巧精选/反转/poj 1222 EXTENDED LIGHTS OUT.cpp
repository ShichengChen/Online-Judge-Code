#include<iostream>
#include<cstring>
#include<cstdio>
using namespace std;
bool map[5][6],cur[5][6],ans[5][6];
int dir[4][2] = {{0,1},{1,0},{-1,0},{0,-1}};
void reversal(int y,int x)
{
    cur[y][x] = (!cur[y][x]);
    for(int i = 0;i < 4;i++)
    {
        int yy= y + dir[i][0],xx = x + dir[i][1];
        if(yy < 5 && yy >= 0 && xx < 6 && xx >= 0)
            cur[yy][xx] = (!cur[yy][xx]);
    }
    ans[y][x] = true;
}
void search()
{
    memcpy(cur,map,sizeof(map));
    for(int i = 0;i < 5;i++)
        for(int j = 0;j < 6;j++)
            if((i == 0 && ans[i][j]) || (i && cur[i - 1][j]))
                reversal(i,j);
}
void run()
{
    for(int i = 0;i < (1 << 6);i++)
    {
        memset(ans,0,sizeof(ans));
        for(int j = 0;j < 6;j++)
            if(i >> j & 1)ans[0][j] = 1;
        search();
        bool fail = false;
        for(int j = 0;j < 6;j++)
            if(cur[4][j])fail = true;
        if(!fail)break;
    }
}
int main()
{
    int _;
    for(int kcas = scanf("%d",&_);kcas <= _;kcas++)
    {
        printf("PUZZLE #%d\n",kcas);
        for(int i = 0;i < 5;i++)
            for(int j = 0;j < 6;j++)
             cin >> map[i][j];
        run();
        for(int i = 0;i < 5;i++)
            for(int j = 0;j < 6;j++)
                if(j == 5)cout << ans[i][j] << endl;
                else cout << ans[i][j] << " ";
    }
}
