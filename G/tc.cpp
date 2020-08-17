#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
using namespace std;
using namespace __gnu_pbds;
#define debug(x) cout << '>' << #x << ':' << (x) << endl;
#define debug2(y,z) cout << '>' << #y << ':' << (y) << " " << #z << ":" <<(z) << endl;
typedef long long ll;
class SquareCityWalking{
public:
    int d[30][30][110];
    int largestGCD(int n, vector <int> arr){
        memset(d,0, sizeof(d));
        d[0][0][arr[0]]=1;
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                if(!i && !j)continue;
                for (int k = 1; k <= 100; ++k) {
                    if(i && d[i-1][j][k])d[i][j][__gcd(arr[i*n+j],k)]=1;
                    if(j && d[i][j-1][k])d[i][j][__gcd(arr[i*n+j],k)]=1;
                }
            }
        }
        for (int i = 100; i >= 1; --i) {
            if(d[n-1][n-1][i])return i;
        }
        return 1;
    }

};
int main(){
    //cout << gcd(0,5) << endl;
    SquareCityWalking s;
    debug(s.largestGCD(3,{ 96, 42, 45, 32, 36, 27, 40, 54, 84 }))
    debug(s.largestGCD(3,{ 4, 9, 2, 3, 5, 7, 8, 1, 6 }))
    debug(s.largestGCD(4,{ 54, 81, 27, 36, 48, 64, 96, 72, 84, 60, 45, 99, 80, 90, 40, 63 }))
    debug(s.largestGCD(1,{ 47 }))
    debug(s.largestGCD(5,{ 100, 80, 64, 48, 36, 75, 10, 10, 10, 48, 50, 10, 10, 10, 64, 25, 10, 10, 10, 80, 5, 25, 50, 75, 100 }))
}
/*



 * */
