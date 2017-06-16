#include<iostream>
#include<cstring>
#include<cstdio>
#include<string>
using namespace std;
int dfs(string s1,string s2)
{
    int len = s1.length();
    if(len == 1)return 1;
    for(int i = 0;;i++)
        if(s2[i] == s1[1])
            if(i == len - 2)
                return 2 * dfs(s1.substr(1,i + 1),s2.substr(0,i + 1));
            else
                return dfs(s1.substr(1,i + 1),s2.substr(0,i + 1))
                 * dfs(s1.substr(i + 2,len - i - 2),s2.substr(i + 1,len - i - 2));
}
int main()
{
    string s1,s2;
    while(cin >> s1 >> s2)
    {
        int ans = dfs(s1,s2);
        printf("%d\n",ans);
    }
}
