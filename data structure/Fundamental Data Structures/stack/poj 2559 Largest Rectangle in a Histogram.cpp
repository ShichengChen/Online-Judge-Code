#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
#define MAX 120000
int h[MAX],r[MAX],l[MAX];
stack<int>st;
int main()
{
    int n;
    while(scanf("%d",&n),n)
    {
        for(int i = 1;i <= n;i ++)scanf("%d",&h[i]);
        l[1] = 0; st.push(0);
        for(int i = 1;i <= n;i++)
        {
            while(st.top() != 0 && h[st.top()] >= h[i])st.pop();
            l[i] = st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();
        r[n] = n + 1; st.push(n + 1);
        for(int i = n;i >= 1;i--)
        {
            while(st.top() != n + 1 && h[st.top()] >= h[i])st.pop();
            r[i] = st.top();
            st.push(i);
        }
        while(!st.empty())st.pop();
        long long ans = 0;
        for(int i = 1;i <= n;i++)
            ans = max(ans,(long long)h[i] * (r[i] - l[i] - 1));
        printf("%lld\n",ans);
    }
}
