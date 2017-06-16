#include<cstdio>
#include<cmath>
#include<iostream>
#include<cstring>
#include<algorithm>
#include<vector>
#include<set>
struct Point {
  double x, y;
  Point(double x=0, double y=0):x(x),y(y) { }
};
const double eps = 1e-8;
const double PI = acos(-1.0);
int dcmp(double x) {
  if(fabs(x) < eps) return 0; else return x < 0 ? -1 : 1;
}
typedef Point Vector;

Vector operator + (const Vector& A, const Vector& B) { return Vector(A.x+B.x, A.y+B.y); }
Vector operator - (const Point& A, const Point& B) { return Vector(A.x-B.x, A.y-B.y); }
Vector operator * (const Vector& A, double p) { return Vector(A.x*p, A.y*p); }
Vector operator / (const Vector& A, double p) { return Vector(A.x/p, A.y/p); }
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
double DistanceToSegment(const Point& P, const Point& A, const Point& B) {
  if(A == B) return Length(P-A);
  Vector v1 = B - A, v2 = P - A, v3 = P - B;
  if(dcmp(Dot(v1, v2)) < 0) return Length(v2);
  else if(dcmp(Dot(v1, v3)) > 0) return Length(v3);
  else return fabs(Cross(v1, v2)) / Length(v1);
}
Point read_point(){
  double x, y;
  scanf("%lf%lf", &x, &y);
  return Point(x,y);
}
#define MAXN 60
using namespace std;
Point a[MAXN],b[MAXN];
int main()
{
    int _,n1,n2;
    cin >> _;
    for(int kcas = 1;kcas <= _;kcas++)
    {
        cin >> n1 >> n2;
        for(int i = 0;i < n1;i++)a[i] = read_point();
        for(int i = 0;i < n2;i++)b[i] = read_point();
        double len1 = 0,len2 = 0;
        for(int i = 1;i < n1;i++)len1 += Length(a[i] - a[i - 1]);
        for(int i = 1;i < n2;i++)len2 += Length(b[i] - b[i - 1]);
        Point u1 = a[0],u2 = b[0];
        int i = 1,j = 1;
        double maxn = -1e9,minn = 1e9;
        while(i < n1 && j < n2)
        {
            double la = Length(a[i] - u1);
            double lb = Length(b[j] - u2);
            double p = min(la / len1,lb / len2);
            Vector d1 = (a[i] - u1) / la * p * len1;
            Vector d2 = (b[j] - u2) / lb * p * len2;
            maxn = max(maxn,Length(u2 - u1));
            maxn = max(maxn,Length((u2 + d2 - d1) - u1));
            minn = min(minn,DistanceToSegment(u1,u2,u2 + d2 - d1));
            u1 = u1 + d1;
            u2 = u2 + d2;
            if(u1 == a[i])i++;
            if(u2 == b[j])j++;
        }
        //cout << (i == j) << endl;
        printf("Case %d: %.0lf\n",kcas,maxn - minn);
    }
}
