//#include "bits/stdc++.h"
#include "stdio.h"
#include "string.h"
#include "assert.h"
typedef long long ll;
#define F_OR(i, a, b, s) for (int (i)=(a); (s)>0?(i)<(b):(i)>(b); (i)+=(s))
#define F_OR1(e) F_OR(i, 0, e, 1)
#define F_OR2(i, e) F_OR(i, 0, e, 1)
#define F_OR3(i, b, e) F_OR(i, b, e, 1)
#define F_OR4(i, b, e, s) F_OR(i, b, e, s)
#define GET5(a, b, c, d, e, ...) e
#define F_ORC(...) GET5(__VA_ARGS__, F_OR4, F_OR3, F_OR2, F_OR1)
#define FOR(...) F_ORC(__VA_ARGS__)(__VA_ARGS__)
#define debug1(x) printf("%s:%d:%s(): ->%s:%d\n",__FILE__,__LINE__,__func__,#x,x);
#define debug2(x,y) printf("%s:%d:%s(): ->%s:%d ->%s:%d\n",__FILE__,__LINE__,__func__,#x,x,#y,y);
#define debug3(x,y,z) printf("%s:%d:%s(): ->%s:%d ->%s:%d ->%s:%d\n", \
__FILE__,__LINE__,__func__,#x,x,#y,y,#z,z);
#define debug4(x,y,z,h) printf("%s:%d:%s(): ->%s:%d ->%s:%d ->%s:%d ->%s:%d\n", \
__FILE__,__LINE__,__func__,#x,x,#y,y,#z,z,#h,h);
#define GET4(a, b, c, d,e, ...) e
#define d_bug(...) GET4(__VA_ARGS__, debug4, debug3, debug2, debug1)
#define debug(...) d_bug(__VA_ARGS__)(__VA_ARGS__)
struct LRUCache {
public:
    int cap,first,last,cnt;
    static const int MAXN=11000;
    bool vis[MAXN];
    int info[MAXN];
    struct Node{int a,b;};
    Node list[MAXN];
    int NUL=-2,UNUSED=-1;
    LRUCache(int capacity) {
        cap=capacity;
        first=last=UNUSED;
        cnt=0;
        memset(vis,false,sizeof vis);
        memset(list,UNUSED,sizeof list);
    }
    int get(int key) {
        if(vis[key]){
            update(key);
            return info[key];
        }
        else return -1;
    }

    //last is the newest one
    //first one is the one for evicted
    void appendlast(int key) {
        cnt++;
        if(first==UNUSED){
            first=last=key;
            vis[key]=true;
            list[key].b=NUL;
            list[key].a=NUL;
            return;
        }
        assert(list[last].a!=UNUSED);assert(list[last].b==NUL);
        list[last].b=key;
        list[key].a=last;
        list[key].b=NUL;
        last=key;

    }
    void update(int key){
        if(key==last || cap==1)return;
        if(first==key)first=list[key].b;
        removemid(key);
        appendlast(key);
    }
    void removemid(int key){
        int pre=list[key].a;
        int nex=list[key].b;
        if(pre>=0)list[pre].b=nex;
        if(nex>=0)list[nex].a=pre;
        list[key]={UNUSED,UNUSED};
        cnt--;
    }
    int removelast(){
        //promote
        //last is the newest one
        cnt--;
        assert(list[last].b!=UNUSED);assert(list[last].b==NUL);
        int promoted=last;
        if(first==last){first=last=UNUSED;}
        else{
            int llast=list[last].a;
            list[llast].b=NUL;
            last=llast;
        }
        vis[promoted]=false;
        list[promoted]={UNUSED,UNUSED};
        //info[evicted]=UNUSED; keep info[evicted], no harm
        return promoted;
    }
    int removefirst(){
        cnt--;
        assert(list[first].a!=UNUSED);assert(list[first].a==NUL);
        int evicted=first;
        if(first==last){first=last=UNUSED;}
        else{
            int nfirst=list[first].b;
            list[nfirst].a=NUL;
            first=nfirst;
        }
        vis[evicted]=false;
        list[evicted]={UNUSED,UNUSED};
        info[evicted]=UNUSED;
        return evicted;
    }
    int put(int key, int value) {
        info[key]=value;
        if(cnt==cap){
            if(!vis[key]){
                int evicted=removefirst();

                appendlast(key);
                vis[key]=true;
                return evicted;
            }else{
                update(key);
                vis[key]=true;
            }
        }else{
            if(vis[key])update(key);
            else appendlast(key);
            vis[key]=true;
        }
        return -1;
    }
};
const int PAGENUM=512;
struct Vector{
    //v1,v2,v4,v8,v16;
    int vec[5][PAGENUM],cnt[5];
    Vector(){ memset(cnt,0,sizeof cnt);}
    void check(int i){ assert(i<5);assert(i>=0);}
    void push_back(int i,int v){ check(i);vec[i][cnt[i]++]=v;}
    int pop_back(int i){check(i);return vec[i][--cnt[i]];}
    int sz(int i){check(i); return cnt[i];}
    void clear(){memset(cnt,0,sizeof cnt);}
};
struct BuddyList{
    Vector v;
    //since the biggest size of requested blocks is no more than 11,
    //so we do not need bigger list for our buddy allocator.
    int arr[PAGENUM],n,maxn[PAGENUM],cnt;
    //----------0,1,2,3,4,5,6,7,8,9,0,1,2,3,4,5,6
    int ma[17]={0,0,1,2,2,3,3,3,3,4,4,4,4,4,4,4,4};
    int up[17]={0,1,2,4,4,8,8,8,8,16,16,16,16,16,16,16,16};
    BuddyList(){
        n=PAGENUM;
        //initialize all blocks to one
        FOR(n)arr[i]=1;
        FOR(n)v.push_back(0,i);
        cnt=0;
        //merge();
    }
    void merge(){
        //time complexity is 2n=n+n/2+n/4+n/8+n/16
        //the worst time complexity is 5n
        memset(maxn,0,sizeof maxn);
        for (int k = 2; k <= 16; k*=2)
            for (int i = 0; i < n; i+=k)
                if(arr[i]==k/2 && arr[i+k/2]==k/2){
                    FOR(_,i,i+k)arr[_]=k,maxn[_]=0;
                    maxn[i]=k;
                }
        FOR(n)if(maxn[i])v.push_back(ma[maxn[i]],i);
    }
    void malloc(int msize,int *address){
        int cadd=0,osize=msize;
        int order=-1;
        FOR(i,ma[msize],5)if(v.sz(i)){order=i;break;}
        //if(order==-1)merge();
        FOR(i,ma[msize],5)if(v.sz(i)){order=i;break;}
        if(order!=-1){

            //continous malloc
            int block=(1<<order);
            //int left=(1<<order)-msize;
            int idx=v.pop_back(order);
            //int endx=idx+(1<<order);
            FOR(_,idx,idx+msize)arr[_]=-1,address[cadd++]=_,cnt++;
            FOR(_,idx+msize,idx+block)v.push_back(0,_),arr[_]=1;
        }else{
            //discontinuous malloc
            for (int i = 3; i >= 0; --i) {
                int block=(1<<i);
                while(msize-block>=0 && v.sz(i)){
                    //debug(i,msize,v.sz(i));
                    msize-=block;
                    int idx=v.pop_back(i);
                    FOR(_,idx,idx+block)arr[_]=-1,address[cadd++]=_,cnt++;
                }
            }
        }
        //debug(cadd,osize,cnt)
        assert(cadd==osize);
    }
    void free(int idx){
        //debug(arr[idx])
        assert(arr[idx]==-1);
        arr[idx]=1;

        cnt--;
        v.push_back(0,idx);//since no merge, add directly
        //merge();
    }
};
LRUCache active(250),inactive(250);
BuddyList buddy;
const int multi=10;
int malloced[multi];
enum pageType{unused=0,inact=1,act=2,disk=3};
int const REQUESTPAGE=11000;

int pageLocation[REQUESTPAGE],pageAdd[REQUESTPAGE];
void evicted2disk(int key){
    if(key==-1)return;
    //debug(key,pageAdd[key]);
    printf("evite F %d %d\n",key/multi,key%multi);
    buddy.free(pageAdd[key]);
    pageAdd[key]=-1;
    pageLocation[key]=disk;
}
int main(){
    char c;int seq,num;
    freopen("/home/csc/Downloads/A0215003A-assign4-input.dat", "r", stdin);
    int lines=0;
    while(scanf("%c   %d    %d\n",&c,&seq,&num)){
        printf("%c %d %d\n",c,seq,num);
        //X	282	3
        lines++;
        debug(active.cnt,inactive.cnt,buddy.cnt,lines);
        assert(buddy.cnt==active.cnt+inactive.cnt);
        if(c=='A'){

            buddy.malloc(num,malloced);
            FOR(num){
                int key=seq*multi+i;
                int memoryIdx=malloced[i];
                int evicted = inactive.put(key,1);
                evicted2disk(evicted);
                pageLocation[key]=inact;
                pageAdd[key]=memoryIdx;
            }
        }else if(c=='X'){
            assert(num<=multi);
            int key=seq*multi+num;
            if(pageLocation[key]==disk){
                int evicted = inactive.put(key,1);
                evicted2disk(evicted);
                buddy.malloc(1,malloced);
                pageLocation[key]=inact;
                pageAdd[key]=malloced[0];
            }else if(pageLocation[key]==inact){
                inactive.update(key);
                inactive.removelast();
                pageLocation[key]=act;
                int evicted = active.put(key,1);
                if(evicted!=-1){
                    pageLocation[evicted]=inact;
                    int nevicted=inactive.put(evicted,1);
                    assert(nevicted==-1);
                }
            }else if(pageLocation[key]==act){
                active.update(key);
            }else{
                assert(pageLocation[key]!=unused);
                assert(false);
            }
        }else if(c=='F'){
            assert(num<=multi);
            int key=seq*multi+num;
            if(pageLocation[key]==act){
                active.update(key);
                active.removelast();
                buddy.free(pageAdd[key]);
                printf("active F %d %d\n",key/multi,key%multi);
            }else if(pageLocation[key]==inact){
                inactive.update(key);
                inactive.removelast();
                buddy.free(pageAdd[key]);
                printf("inactive F %d %d\n",key/multi,key%multi);
            }else if(pageLocation[key]==disk){}
            pageLocation[key]=unused;
        }else assert(false);
        if(c=='X' && seq==282 && num==3)break;
    }

    Vector v=buddy.v;
    puts("buddy lists");
    FOR(5){
        printf("block size%d :",(1<<i));
        FOR(j,v.cnt[i])printf("%d ",v.vec[i][j]);
        printf("\n");
    }
    puts("active list\n key: ");
    for (int i = active.first; i != active.NUL && i!=active.UNUSED; i=active.list[i].b) {
        printf("seqno:%d num:%d\n",i/multi,i%multi+1);
    }
    puts("inactive list\n key: ");
    for (int i = inactive.first; i != inactive.NUL && i!=inactive.UNUSED; i=inactive.list[i].b) {
        printf("seqno:%d num:%d\n",i/multi,i%multi+1);
    }
}