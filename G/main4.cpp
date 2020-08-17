#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
typedef long long ll;
#define debug(x) cout << '>' << #x << ':' << x << endl;
#define debug2(y,z) cout << '>' << #y << ':' << y << " " << #z << ":" <<z << endl;
const int MAXN =1e5+50;
const int LOGMAXN = 18;
ll const MOD=1e9+7;
int arr[MAXN];
int main()
{
//    int _;cin>>_;
//    while (_--){
//
//    }
    int n,m,k;cin>>n>>m>>k;
    if(k>n*m*4-2*n-2*m)puts("NO"),exit(0);
    vector<string>ans;
    vector<int>num;
    int acc=0;
    for (int i = 0; i < n&&acc<k; ++i) {
        if(i)ans.push_back("D"),num.push_back(1),acc++;
        if(acc<k && m-1){
            num.push_back(min(k-acc,m-1));
            if(i%2==0)ans.push_back("R");
            else ans.push_back("L");
            acc+=num.back();
        }
    }
    for (int i = n-1; i >= 0&&acc<k; --i) {
        if(i!=n-1)ans.push_back("U"),num.push_back(1),acc++;
        if(acc<k && m-1){
            if(i==0){
                num.push_back(min(k-acc,m-1));
                ans.push_back("L");
                acc+=num.back();
            }
            else{
                int just=0;
                if((k-acc)/3>0){
                    num.push_back(min((k-acc)/3,m-1));
                    just=num.back();
                    if(i%2==0)ans.push_back("UDL");
                    else ans.push_back("UDR");
                    acc+=3*num.back();
                }
                //debug(just)
                //debug((k-acc))
                if(k-acc<=2 && k-acc>=0 && just<m-1){
                    string c[]={"U","D"};
                    for (int j = 0; j < (k-acc)%3; ++j) {
                        //debug(c[j])
                        ans.push_back(c[j]);
                        num.push_back(1);
                    }
                    acc=k;
                }
            }
        }
    }
    puts("YES");
    cout << ans.size() << "\n";
    for (int i = 0; i < ans.size(); ++i) {
        cout << num[i] << " " << ans[i] << "\n";
    }
}
/*
4 3
4 0
4 0
4 0
1 1
 */