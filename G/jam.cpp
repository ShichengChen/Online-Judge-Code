#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
typedef long long ll;
#define debug(x) cout << '>' << #x << ':' << (x) << endl;
#define debug2(y,z) cout << '>' << #y << ':' << (y) << " " << #z << ":" <<(z) << endl;
const int MAXN =5e5+50;
//ll const MOD=1e9+7;
ll const MOD=1e8+7;
void solve() {
    int a,b;cin>>a>>b;
    char dir[]={'E','W','N','S'};
    if(a<0){
        a=abs(a);
        swap(dir[0],dir[1]);
    }
    if(b<0){
        b=abs(b);
        swap(dir[2],dir[3]);
    }
    if(!a&&!b)return;
    string ans;
    for (int i = 0; i < 100; ++i) {
        if(!a&&!b){
            cout << ans << endl;
            return;
        }
        if((a%2+b%2)%2==0){
            puts("IMPOSSIBLE");
            return;
        }
        if(a+b==1){
            if(a)a--,ans+=dir[0];
            if(b)b--,ans+=dir[2];
        }
        else if(a%2){
            if((((a-1)/2)%2+(b/2)%2)%2){
                a--;
                ans+=dir[0];
            }
            else{
                a++;
                ans+=dir[1];
            }
        }
        else{
            if(((a/2)%2+((b-1)/2)%2)%2){
                b--;
                ans+=dir[2];
            }
            else{
                b++;
                ans+=dir[3];
            }
        }
        a/=2;b/=2;

    }
}
int main() {
//    ios::sync_with_stdio(0);
//    cin.tie(0);
    int t, i=1;
    cin >> t;
    while(t--) {
        cout << "Case #" << i << ": ";
        solve();
        ++i;
    }
    return 0;
}
/*
100
3 5 1 4 1 4
3 5 1 5 1 5
3 5 3 1 3 1
3 5 3 2 3 2
3 5 2 4 2 4
4 5 2 4 2 4
4 5 2 2 3 3
5 5 4 3 4 3
 * */