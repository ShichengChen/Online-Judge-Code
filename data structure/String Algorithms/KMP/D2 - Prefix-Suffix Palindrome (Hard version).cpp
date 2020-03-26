#include <bits/stdc++.h>
using namespace std;
const int MAXN =2e6+20;
int pre[MAXN];
string solve_p(const string& s){
    string a=s;
    reverse(a.begin(),a.end());
    a=s+"#"+a;
    int c=0;
    for(int i = 1;i < a.size();i++){
        while(c && a[i]!=a[c]){
            c=pre[c-1];
        }
        if(a[i]==a[c])c++;
        pre[i]=c;
    }
    return a.substr(0,c);
}
int main()
{
    int _;
    cin >> _;
    while (_--){
        string t;
        cin>>t;
        int l=0;
        for (; l < t.size(); ++l) {
            if(t[l]!=t[t.size()-1-l]){
                break;
            }
        }
        if(l)cout << t.substr(0,l);
        if(l*2<t.size()){
            string st=t.substr(l,t.size()-2*l);
            string a=solve_p(st);
            reverse(st.begin(),st.end());
            string b=solve_p(st);
            if(a.size()<b.size())swap(a,b);
            cout << a;
        }
        if(l && l*2<t.size())cout << t.substr(t.size()-l,l);
        puts("");
    }

}
/*
 7 3
 2 7 3 1 5 6 4
 * */
