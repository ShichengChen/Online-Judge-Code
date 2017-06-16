#include<iostream>
#include<string> 
using namespace std;
void foo(string,string);
int main()
{
    string str1,str2;
    while(cin>>str1>>str2)    
    {foo(str1,str2);cout<<endl;}
    return 0;
}
void foo(string str1,string str2)
{
           if(str1[0]==NULL)return;
           int num=str2.find(str1[0]);
           int l=str1.length();
           foo(str1.substr(1,num),str2.substr(0,num));
           foo(str1.substr(num+1,l-num-1),str2.substr(num+1,l-num-1));
           cout<<str1[0];  
}
