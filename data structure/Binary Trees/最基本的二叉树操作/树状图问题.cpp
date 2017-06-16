#include<iostream>
#include<string>
using namespace std;
void f(string a,string b)
{

    int j,k;
    j=b.find(a[0]);
    if(a.size()==0)
    {
        cout<<a;
        return;
    }
    f(a.substr(1,j),b.substr(0,j));
    f(a.substr(j+1),b.substr(j+1));
    cout<<a[0];
}

int main()
{
    string a,b;
    while(cin>>a>>b)
    {
        f(a,b);
        cout<<endl;
    }
    return 0;
}
