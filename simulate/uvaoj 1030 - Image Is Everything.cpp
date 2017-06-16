#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
#define MAXN 12
#define F(i,n) for(int i = 0;i < (n);i++)
char view[6][MAXN][MAXN],pos[MAXN][MAXN][MAXN];
int x,y,z,n;
void get(int k,int i,int j,int l,int &x,int &y,int &z)
{
    if(k == 0){x = j,y = n - l - 1,z = n - i - 1;}
    else if(k == 1){x = l,y = j,z = n - i - 1;}
    else if(k == 2){x = n - j - 1,y = l,z = n - i - 1;}
    else if(k == 3){x = n - l - 1,y = n - j - 1,z = n - i - 1;}
    else if(k == 4){x = j,y = i,z = n - l - 1;}
    else {x = j,y = n - i - 1,z = l;}
}
char get_char()
{
    while(1)
    {
        char c = getchar();
        if((c >= 'A' && c <= 'Z') || c == '.')return c;
    }
}
int main()
{
    while(cin >> n && n)
    {
        F(i,n)F(k,6)F(j,n)view[k][i][j] = get_char();
        F(k,n)F(i,n)F(j,n)pos[k][i][j] = '#';
        F(k,6)F(i,n)F(j,n)if(view[k][i][j] == '.')F(l,n)
        {
            get(k,i,j,l,x,y,z);
            pos[z][y][x] = '.';
        }
        while(1)
        {
            bool done = true;
            F(k,6)F(i,n)F(j,n)if(view[k][i][j] != '.')F(l,n)
            {
                get(k,i,j,l,x,y,z);
                if(pos[z][y][x] == '.')continue;
                else if(pos[z][y][x] == '#')
                {
                    pos[z][y][x] = view[k][i][j];
                    break;
                }
                else if(pos[z][y][x] == view[k][i][j])break;
                else if(pos[z][y][x] != view[k][i][j])
                {
                    pos[z][y][x] = '.';
                    done = false;
                }
            }
            if(done)break;
        }
        int cnt = n * n * n;
        F(k,n)F(i,n)F(j,n)if(pos[k][i][j] == '.')cnt--;
        printf("Maximum weight: %d gram(s)\n",cnt);
    }
}
