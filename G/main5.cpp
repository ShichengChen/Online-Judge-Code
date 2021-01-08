#include <bits/stdc++.h>
#include<ext/pb_ds/assoc_container.hpp>
typedef long long ll;
using namespace std;
using namespace __gnu_pbds;

template <class T>
class ptr_wrapper
{
public:
  ptr_wrapper() : ptr(nullptr) {}
  ptr_wrapper(T *ptr) : ptr(ptr) {}
  ptr_wrapper(const ptr_wrapper &other) : ptr(other.ptr) {}
  T &operator*() const { return *ptr; }
  T *operator->() const { return ptr; }
  T *get() const { return ptr; }
  void destroy() { delete ptr; }
  T &operator[](std::size_t idx) const { return ptr[idx]; }

private:
  T *ptr;
};
struct quadtree{
    int a;
};

int f2(quadtree *a){
    cout << a << '\n';
    return 1;
}
int f(ptr_wrapper<quadtree>a){
    cout << a.get() << '\n';
    return f2(a.get());

}
int main() {
    quadtree a;
    ptr_wrapper<quadtree>p=&a;
    f(p);
    return 0;
}
/*
 4
 3 3
 4 5 1
 0 0 0 0
 1 2 4
 0 0 0 0
 1 3 4
 0 0 0 0

  3 3
 5 3 1
 0 0 0 0
 1 2 4
 0 0 0 0
 1 3 4
 0 0 0 0

 3 3
 3 1 3
 0 0 0 0
 1 2 4
 0 0 0 0
 1 3 4
 0 0 0 0

 3 3
 1 2 2
 0 0 0 0
 1 2 4
 0 0 0 0
 1 3 4
 0 0 0 0


 1
 5 5
 1 3 4 5 6
 0 0 0 0
 1 1 1 1 1
 0 0 0 0
 1 1 1 1 1
 0 0 0 0

 * */