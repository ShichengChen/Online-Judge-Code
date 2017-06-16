#include<iostream>
#include<cstdio>
#include<cstring>
#include<vector>
#include<cmath>
using namespace std;
#define MAXN 20
#define MAXM 10
#define INF 0x3f3f3f3f
int deck[MAXN * 2],n;
char s[MAXM];
const int UP = 0,FLOOR = 1,DOWN = 2;
struct State
{
    int type[MAXN],card[MAXN],hold[2];
    int pos,score;
    State()
    {
        for(int i = 0;i < 8;i++)
        {
            card[i] = deck[i];
            if(i & 1)type[i] = DOWN;
            else type[i] = UP;
        }
        pos = 8;
        hold[0] = hold[1] = score = 0;
    }
    State child()const
    {
        State s(*this);
        s.pos++;
        return s;
    }
    void expand(vector<State> & vec,int player)const
    {
        int cur = deck[pos];
        if(!hold[player])
        {
            State s = child();
            s.hold[player] = cur;
            vec.push_back(s);
        }
        for(int i = 0;i < 7;i++)if(type[i] == DOWN && type[i + 1] == UP)
        {
            State s = child();
            s.score += getScore(card[i],card[i + 1],cur);
            s.type[i] = s.type[i + 1] = FLOOR;
            s.card[i] = s.card[i + 1] = cur;
            vec.push_back(s);

            if(hold[player])
            {
                State s = child();
                s.score += getScore(card[i],card[i + 1],hold[player]);
                s.type[i] = s.type[i + 1] = FLOOR;
                s.card[i] = s.card[i + 1] = hold[player];
                s.hold[player] = cur;
                vec.push_back(s);
            }
        }
        if(!hold[player])return;
        for(int i = 0;i < 7;i++)if(type[i] == FLOOR && type[i + 1] == FLOOR && card[i] == card[i + 1])
        {
            State s = child();
            s.score += getScore(card[i],cur,hold[player]);
            s.type[i] = UP;s.type[i + 1] = DOWN;
            s.card[i] = cur;s.card[i + 1] = hold[player];
            s.hold[player] = 0;
            vec.push_back(s);

            swap(s.card[i],s.card[i + 1]);
            vec.push_back(s);
        }
    }
    int getScore(int a,int b,int c)const
    {
        int cur = abs(a) + abs(b) + abs(c);
        int cnt = (a > 0 ? 1 : -1) + (b > 0 ? 1 : -1) + (c > 0 ? 1 : -1);
        return cnt > 0 ? cur : -cur;
    }
    bool isfind()
    {
        if(pos == n * 2)
        {
            score += hold[0] + hold[1];
            hold[0] = hold[1] = 0;
            return true;
        }
        return false;
    }
};
int alphabeta(State& s,int player,int alpha,int beta)
{
    if(s.isfind())return s.score;
    vector<State>vec;
    s.expand(vec,player);
    for(int i = 0;i < vec.size();i++)
    {
        int v = alphabeta(vec[i],!player,alpha,beta);
        if(!player)alpha = max(v,alpha);
        else beta = min(v,beta);
        if(beta <= alpha)break;
    }
    return !player ? alpha : beta;
}
int main()
{
    int kase = 0;
    while(scanf("%s",s) && s[0] != 'E')
    {
        scanf("%d",&n);
        for(int i = 0;i < 2 * n;i++)
        {
            char ch;
            scanf("%d%c",&deck[i],&ch);
            if(ch == 'B')deck[i] = -deck[i];
        }
        int player = deck[0] > 0 ? 0 : 1;
        State init;
        int score = alphabeta(init,player,-INF,INF);
        if(s[0] == 'B')score = -score;
        printf("Case %d: ", ++kase);
        if(score == 0)puts("Axel and Birgit tie");
        else if(score > 0)printf("%s wins %d\n",s,score);
        else printf("%s loses %d\n",s,-score);
    }
}
