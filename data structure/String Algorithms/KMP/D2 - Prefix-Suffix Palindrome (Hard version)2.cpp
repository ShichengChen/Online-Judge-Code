#include <bits/stdc++.h>
using namespace std;
const int MAXN =2e6+20;
char s[MAXN],subs[MAXN],cps[MAXN];
int nxt[MAXN],slen;
void get_fail(char *p,int*f){
    int m=strlen(p);
    f[0]=f[1]=0;
    for (int i = 1; i < m; ++i) {
        int j=f[i];
        while (j && p[i]!=p[j])j=f[j];
        f[i+1]=p[i]==p[j]?j+1:0;
    }
}
int main()
{
    int _;cin>>_;
    while(_--){
        scanf("%s",s);
        slen=strlen(s);
        memset(nxt,0, sizeof(int)*(slen+5));
        int maxn0=-1;
        for (int i = 0; i < (slen+1)/2; ++i) {
            if(s[i]==s[slen-1-i]){
                maxn0=i;
            }
            else break;
        }
        if(maxn0+1==(slen+1)/2){
            printf("%s\n",s);
            continue;
        }
        //cout << maxn0 << " maxn0 " << endl;
        strncpy(cps, s, (slen));
        reverse(cps, cps + slen);
        strncpy(subs, s+maxn0+1, (slen-(maxn0+1)*2));
        //cout << subs << endl;
        get_fail(subs,nxt);
        int maxn1=0;
        for (int i = slen-(maxn0)-2,j=0; ; --i) {
            while (j&&subs[j]!=s[i])j=nxt[j];
            if(subs[j]==s[i])j++;
            //cout << s[i] << " s[i] " << i << endl;
            //cout << "j " << j << endl;
            if(j+maxn0+1==i){
                maxn1=j*2;
                break;
            }
            if(j+maxn0+2==i){
                maxn1=j*2+1;
                break;
            }
        }
        //cout << maxn1 << " maxn1 " << endl;
        memset(nxt,0, sizeof(int)*(slen+5));
        strncpy(subs, cps+maxn0+1, (slen-(maxn0+1)*2));
        //cout << subs << endl;
        get_fail(subs,nxt);
        int maxn2=0;
        for (int i = slen-(maxn0)-2,j=0; ; --i) {
            while (j&&subs[j]!=cps[i])j=nxt[j];
            if(subs[j]==cps[i])j++;
            //cout << cps[i] << " s[i] " << i << endl;
            //cout << "j " << j << endl;
            if(j+maxn0+1==i){
                maxn2=j*2;
                break;
            }
            if(j+maxn0+2==i){
                maxn2=j*2+1;
                break;
            }
        }
        //cout << maxn2 << " maxn2 " << endl;
        for (int i = 0; i <= maxn0; ++i) {
            cout << s[i];
        }
        if(maxn1>maxn2){
            for (int i = maxn0+1; i < maxn0+1+maxn1; ++i) {
                cout << s[i];
            }
        }
        else{
            for (int i = slen-maxn0-1-maxn2; i < slen-maxn0-1; ++i) {
                cout << s[i];
            }
        }
        for (int i = slen-maxn0-1; i < slen; ++i) {
            cout << s[i];
        }
        puts("");
 
    }
}
