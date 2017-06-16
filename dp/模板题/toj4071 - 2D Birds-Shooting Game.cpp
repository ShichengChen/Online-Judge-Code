#include<iostream>
#include<string>
#include<fstream>
#include<cstring>
#include<cstdio>
#include<algorithm>
using namespace std;
struct point
{
  int x;int y;
  bool operator < (const point & p)const
  {
      if(x != p.x)return x<p.x;
      else if(x == p.x)return y<p.y;
  }
}arr[100010];
int cur[100010];
int main()
{
    int T;cin>>T;
    while(T--)
    {
        int N;cin>>N;
        for(int i=0;i<N;i++)
        {
            int xx,yy;
            cin>>xx>>yy;
            arr[i].x=xx;
            arr[i].y=yy;
        }
        sort(arr,arr+N);
        int length=1;
        cur[0]=arr[0].y;
        for(int i=1;i<N;i++)
        {
            int * pp= upper_bound(cur,cur+length,arr[i].y);
            int currentlength = pp-cur;
            if(currentlength==length)
            {
                   cur[length++]=arr[i].y;
            }
            else if(currentlength!=length)
            {
               if(*pp > arr[i].y)
               {
                      *pp = arr[i].y;
               }
            }
        }
        cout<<length<<endl;
    }
    return 0;
}
