#include<iostream>
using namespace std;
int foo(int,int); 
int main() 
{
    int t;
    cin>>t;
    int m,n;
    while(t--)
    {
       cin>>m>>n;
       cout<<foo(m,n)<<endl;    
    }
    return 0;
}
int foo(int m,int n)
{
    if(m==0)return 1;
    if(n==1)return 1;
    if(m<n)return foo(m,m);
    if(m>=n)return foo(m,n-1)+foo(m-n,n);
}
