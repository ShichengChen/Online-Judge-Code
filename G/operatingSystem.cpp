#include "bits/stdc++.h"
using namespace  std;
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
#define debug5(x,y,z,h,i) printf("%s:%d:%s(): ->%s:%d ->%s:%d ->%s:%d ->%s:%d ->%s:%d\n", \
__FILE__,__LINE__,__func__,#x,x,#y,y,#z,z,#h,h,#i,i);
#define GET6(a, b, c, d,e,f, ...) f
#define d_bug(...) GET6(__VA_ARGS__, debug5, debug4, debug3, debug2, debug1)
#define debug(...) d_bug(__VA_ARGS__)(__VA_ARGS__)
struct LRUCache {
public:
    int cap,first,last,cnt;
    static const int MAXN=11000;
    int vis[MAXN];
    int info[MAXN];
    struct Node{int a,b;};
    Node list[MAXN];
    int NUL=-1;
    LRUCache(int capacity) {
        cap=capacity;
        first=last=NUL;
        cnt=0;
        memset(vis,0,sizeof vis);
        memset(list,NUL,sizeof list);
    }
    int get(int key) {
//        vector<int>arr;
//        for (int i = 0; i < cnt/2; ++i) {
//            arr.push_back(removelast());
//        }
//        reverse(arr.begin(),arr.end());
//        for (int i = 0; i < arr.size(); ++i) {
//            put(arr[i],info[arr[i]]);
//        }

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
        vis[key]=1;
        if(cnt==1){
            first=last=key;
            list[key].b=NUL;
            list[key].a=NUL;
            return;
        }
        assert(vis[last]);assert(list[last].b==NUL);
        list[last].b=key;
        list[key].a=last;
        list[key].b=NUL;
        last=key;

    }
    void update(int key){
        assert(vis[key]==1);
        removemid(key);
        appendlast(key);
    }
    int removemid(int key){
        assert(vis[key]);//must exist
        //if cap==1
        int removed=key;
        int pre=list[key].a;
        int nex=list[key].b;
        if(cnt==1){
            assert(pre==NUL && nex==NUL);
            first=last=NUL;
        }else if(first==key){
            assert(pre==NUL && nex!=NUL);
            list[nex].a=pre;
            first=nex;
        }else if(last==key){
            assert(pre!=NUL && nex==NUL);
            list[pre].b=nex;
            last=pre;
        }else{
            assert(pre!=NUL && nex!=NUL);
            list[pre].b=nex;
            list[nex].a=pre;
        }
        vis[key]=0;
        list[key]={NUL,NUL};
        cnt--;
        return removed;
    }
    int removelast(){
        //promote
        //last is the newest one
        assert(vis[last]);assert(list[last].b==NUL);
        int promoted=last;
        removemid(last);
        return promoted;
    }
    int removefirst(){
        //evict page
        assert(vis[first]);assert(list[first].a==NUL);
        int evicted=first;
        removemid(first);
        return evicted;
    }
    int evict(){return removefirst();}
    int promote(){return removelast();}
    int put(int key, int value) {
        info[key]=value;
        if(vis[key])update(key);
        else{
            if (cnt == cap) {
                int evicted = evict();
                appendlast(key);
                return evicted;
            } else {
                appendlast(key);
            }
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
    int checkSz(){
        int ans=0;
        FOR(5)ans+=(1<<i)*cnt[i];
        return ans;
    }
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
        assert(PAGENUM==v.checkSz()+cnt);
        cnt=0;
        merge();
    }
    void merge(){
        //time complexity is 2n=n+n/2+n/4+n/8+n/16
        //the worst time complexity is 5n
        //memset(maxn,0,sizeof maxn);
        for (int k = 2; k <= 16; k*=2)
            for (int i = 0; i < n; i+=k)
                if(arr[i]==k/2 && arr[i+k/2]==k/2){
                    arr[i]=k,arr[i+k/2]=0;
                    FOR(_,i+1,i+k)assert(arr[_]==0);
                    //arr[i]=maxn[i]=k;
                }
        v.clear();
        //FOR(n)if(maxn[i])v.push_back(ma[maxn[i]],i);
        FOR(n)if(arr[i]>0)v.push_back(ma[arr[i]],i);
        assert(PAGENUM==v.checkSz()+cnt);
    }
    int continousMalloc(int &msize,int *address,int &cadd){
        if(!msize)return 1;
        int order=-1;
        FOR(i,ma[msize],5)if(v.sz(i)){order=i;break;}
        if(order==-1)return 0;
        int block=(1<<order);
        //int left=(1<<order)-msize;
        int idx=v.pop_back(order);
        puts("continous");
        debug(order,block,idx,v.checkSz())
        //int endx=idx+(1<<order);
        assert(arr[idx]==block);
        FOR(_,idx,idx+msize)arr[_]=-1,address[cadd++]=_,cnt++;
        FOR(_,idx+msize,idx+block)v.push_back(0,_),arr[_]=1;//, debug(v.checkSz());
        msize=0;
        return 1;
    }
    void discontinuousMalloc(int &msize,int *address,int &cadd){
        if(!msize)return;
        puts("discontinuous");
        for (int i = 4; i >= 0; --i) {
            int block=(1<<i);
            debug(i,v.sz(i));
            while(msize-block>=0 && v.sz(i)){
                debug(i,msize,v.sz(i));
                msize-=block;
                int idx=v.pop_back(i);
                FOR(_,idx,idx+block)arr[_]=-1,address[cadd++]=_,cnt++;
            }
        }
    }
    void malloc(int msize,int *address){
        int cadd=0,osize=msize;
        if(!continousMalloc(msize,address,cadd))merge();
        continousMalloc(msize,address,cadd);
        discontinuousMalloc(msize,address,cadd);
        continousMalloc(msize,address,cadd);

        debug(msize,cadd,osize,cnt,v.checkSz())
        assert(PAGENUM==v.checkSz()+cnt);
        assert(cadd==osize);
    }
    void free(int idx){
        //debug(arr[idx])
        assert(arr[idx]==-1);
        arr[idx]=1;

        cnt--;
        v.push_back(0,idx);//since no merge, add directly
        assert(PAGENUM-cnt==v.checkSz());
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
    char c,cc;int seq,num;
    freopen("/home/csc/Downloads/A0215003A-assign4-input.dat", "r", stdin);
    int lines=0;
    while(scanf("%c   %d    %d",&c,&seq,&num)){
        printf("%c %d %d\n",c,seq,num);
        cc=getchar();//get '\n' char
        if(cc!='\n')break;
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
                assert(0);
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
        }else assert(0);
        //if(c=='X' && seq==282 && num==3)break;
    }

    Vector v=buddy.v;
    puts("buddy lists");
    FOR(5){
        printf("block size%d :",(1<<i));
        FOR(j,v.cnt[i])printf("%d ",v.vec[i][j]);
        printf("\n");
    }
    puts("active list\n key: ");
    for (int i = active.first; i != active.NUL; i=active.list[i].b) {
        printf("seqno:%d num:%d\n",i/multi,i%multi+1);
    }
    puts("inactive list\n key: ");
    for (int i = inactive.first; i != inactive.NUL; i=inactive.list[i].b) {
        printf("seqno:%d num:%d\n",i/multi,i%multi+1);
    }
}