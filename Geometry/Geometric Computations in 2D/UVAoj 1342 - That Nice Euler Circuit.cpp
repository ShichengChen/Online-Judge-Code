#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
using namespace std;
struct Point {
  double x, y;
  Point(double x=0, double y=0):x(x),y(y) { }
};
const double eps = 1e-10;
int dcmp(double x) {
  if(fabs(x) < eps) return 0; else return x < 0 ? -1 : 1;
}
typedef Point Vector;

Vector operator + (const Vector& A, const Vector& B) { return Vector(A.x+B.x, A.y+B.y); }
Vector operator - (const Point& A, const Point& B) { return Vector(A.x-B.x, A.y-B.y); }
Vector operator * (const Vector& A, double p) { return Vector(A.x*p, A.y*p); }
bool operator < (const Point& a, const Point& b) {
  return a.x < b.x || (a.x == b.x && a.y < b.y);
}
bool operator == (const Point& a, const Point &b) {
  return dcmp(a.x-b.x) == 0 && dcmp(a.y-b.y) == 0;
}
bool operator != (const Point& a, const Point &b) {
  return !(a == b);
}
double Dot(const Vector& A, const Vector& B) { return A.x*B.x + A.y*B.y; }
double Length(const Vector& A) { return sqrt(Dot(A, A)); }
double Angle(const Vector& A, const Vector& B) { return acos(Dot(A, B) / Length(A) / Length(B)); }
double Cross(const Vector& A, const Vector& B) { return A.x*B.y - A.y*B.x; }
Point GetLineIntersection(const Point& P, const Point& v, const Point& Q, const Point& w) {
  Vector u = P-Q;
  double t = Cross(w, u) / Cross(v, w);
  return P+v*t;
}
Vector Rotate(const Vector& A, double rad) {
  return Vector(A.x*cos(rad)-A.y*sin(rad), A.x*sin(rad)+A.y*cos(rad));
}
bool SegmentProperIntersection(const Point& a1, const Point& a2, const Point& b1, const Point& b2) {
  double c1 = Cross(a2-a1,b1-a1), c2 = Cross(a2-a1,b2-a1),
  c3 = Cross(b2-b1,a1-b1), c4=Cross(b2-b1,a2-b1);
  return dcmp(c1)*dcmp(c2)<0 && dcmp(c3)*dcmp(c4)<0;
}
bool OnSegment(const Point& p, const Point& a1, const Point& a2) {
  return dcmp(Cross(a1-p, a2-p)) == 0 && dcmp(Dot(a1-p, a2-p)) < 0;
}
bool _OnSegment(const Point& p, const Point& a1, const Point& a2) {
  return dcmp(Cross(a1-p, a2-p)) == 0 && dcmp(Dot(a1-p, a2-p)) < 0
         && p != a1 && p != a2;
}
Point read_point(){
  double x, y;
  scanf("%lf%lf", &x, &y);
  return Point(x,y);
}
#define MAXN 305
int n,e,cnt;
Point p[MAXN],v[MAXN * MAXN];
set<Point>se;
int main()
{
    int kcas = 0;
    while(scanf("%d",&n) && n)
    {
        e = n - 1;
        for(int i = 0;i < n;i++)
            v[i] = p[i] = read_point();
        cnt = n;
        for(int i = 2;i < n - 1;i++)
            for(int u = 0;u < i - 1;u++)
                if(SegmentProperIntersection(p[i],p[i + 1],p[u],p[u + 1]))
                    v[cnt++] = GetLineIntersection(p[i],p[i + 1] - p[i],p[u],p[u + 1] - p[u]);
        sort(v,v + cnt);
        cnt = unique(v,v + cnt) - v;
        for(int i = 0;i < n - 1;i++)
            for(int j = 0;j < cnt;j++)
                if(OnSegment(v[j],p[i],p[i + 1]))
                    e++;
        printf("Case %d: There are %d pieces.\n",++kcas,e + 2 - cnt);
    }
}
