#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
typedef pair<int,int> data;
stack<data>st;
int main()
{
    int n,x,y,len;
    while(scanf("%d",&n) and n != -1)
    {
            int maxn = 0;
            for(int i = 0;i < n;i++)
            {
                    scanf("%d%d",&x,&y);
                    if(st.empty() || st.top().second <= y)
                    {
                        st.push(data(x,y));
                        continue;
                    }
                    len = 0;
                    while(!st.empty() && st.top().second > y)
                    {
                        len += st.top().first;
                        maxn = max(maxn,len * st.top().second);
                        st.pop();
                    }
                    st.push(data(x + len,y));  /**need be concerned**/
            }
            len = 0;
            while(!st.empty())
            {
                    len += st.top().first;
                    maxn = max(maxn,len * st.top().second);
                    st.pop();
            }
            printf("%d\n",maxn);
    }
    return 0;
}
