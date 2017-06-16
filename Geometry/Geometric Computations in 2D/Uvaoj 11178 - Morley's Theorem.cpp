#include<cstdio>
#include<cmath>

struct Point {
  double x, y;
  Point(double x=0, double y=0):x(x),y(y) { }
};

typedef Point Vector;

Vector operator + (const Vector& A, const Vector& B) { return Vector(A.x+B.x, A.y+B.y); }
Vector operator - (const Point& A, const Point& B) { return Vector(A.x-B.x, A.y-B.y); }
Vector operator * (const Vector& A, double p) { return Vector(A.x*p, A.y*p); }
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

Point read_point() {
  double x, y;
  scanf("%lf%lf", &x, &y);
  return Point(x,y);
}
Point getp(Point a,Point b,Point c)
{
    double rad = Angle(b - a,c - a);
    Vector v = Rotate(c - a,rad / 3);
    rad = Angle(b - c,a - c);
    Vector v1 = Rotate(a - c,-rad / 3);
    return GetLineIntersection(a,v,c,v1);
}
int main() {
  int T;
  Point a, b, c, d, e, f;
  scanf("%d", &T);
  while(T--) {
    a = read_point();
    b = read_point();
    c = read_point();
    d = getp(b, a, c);
    e = getp(c, b, a);
    f = getp(a, c, b);
    printf("%.6f %.6f %.6f %.6f %.6f %.6f\n", d.x, d.y, e.x, e.y, f.x, f.y);
  }
  return 0;
}
