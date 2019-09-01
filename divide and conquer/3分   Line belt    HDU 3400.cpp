/*
if use x1,x2 to narrow the limit is wrong
i should use time to narrow
maybe the aim is time;only if i narrow time,
i can get exact time value
*/
#include<iostream>
#include<cstring>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<climits>
#include<string>
#include<cmath>
using namespace std;
#define eps 1e-9
#define INF (1 << 29)
struct Point
{
    double x,y;
}point[4];
double P,Q,R;
double dis(Point a,Point b)
{
     return sqrt((a.x - b.x) * (a.x - b.x) + (a.y - b.y) * (a.y - b.y));
}
double trisection(Point begin1,Point p1,Point p2)
{
    double time1 = INF,time2 = -INF;
    while(fabs(time1 - time2) > eps)
    //while(fabs(p1.x - p2.x) > eps || fabs(p1.y - p2.y) > eps)              //wrong answer
    {
        Point mid,midmid;
        mid.x = (p1.x+ p2.x) / 2;mid.y = (p1.y + p2.y) / 2;
        midmid.x = (p2.x + mid.x) / 2;midmid.y = (p2.y + mid.y) / 2;
        time1 = dis(point[3],mid) / Q + dis(begin1,mid) / R;
        time2 = dis(point[3],midmid) / Q + dis(begin1,midmid) / R;
        if(time1 < time2)
            p2 = midmid;
        else
            p1 = mid;
    }
    return time1;
}
double solve(Point p1,Point p2)
{
    double time1 = INF,time2 = -INF;
    while(fabs(time1 - time2) > eps)
    //while(fabs(p1.x - p2.x) > eps || fabs(p1.y - p2.y) > eps)      //wrong answer
    {
        Point mid,midmid;
        mid.x = (p1.x+ p2.x) / 2;mid.y = (p1.y + p2.y) / 2;
        midmid.x = (p2.x + mid.x) / 2;midmid.y = (p2.y + mid.y) / 2;
        time1 = trisection(mid,point[2],point[3]) + dis(point[0],mid) / P;
        time2 = trisection(midmid,point[2],point[3]) + dis(point[0],midmid) / P;
        if(time1 < time2)
            p2 = midmid;
        else
            p1 = mid;
    }
    return time1;
}
int main()
{
    int T ;
    scanf("%d",&T);
    while(T--)
    {
        for(int i = 0;i < 4;i++)scanf("%lf%lf",&point[i].x,&point[i].y);
        scanf("%lf%lf%lf",&P,&Q,&R);
        printf("%.2lf\n",solve(point[0],point[1]));
    }
}
