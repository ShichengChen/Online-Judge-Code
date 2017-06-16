#include<iostream>
using namespace std;
#define INF 10000;
int list[10000],lastlist[10000];
int lastindex;
bool search(int index,int lastindex,int target)
{
	int current=list[index];
	for(int i=0;i<lastindex-index;i++)
	{
		current*=2;
		if(current>target)return false;
	}
	//cout<<"currentfalse"<<current;
	return true;
	//cout<<"current"<<current;
	
}
void dfs(int index,int target)
{
     for(int i=index;i>=0;i--)
     {
             list[index+1]=list[index]+list[i];
             if(index+1>lastindex)break;   //¼ôÖ¦
             if(list[index+1]==list[index-1]*2)break;//¼ôÖ¦
             if(list[index+1]>target)continue;
             if(lastindex!=10000)if(search(index+1,lastindex,target))break;//¼ôÖ¦ 
             if(list[index+1]==target)
			 {
					if(index+1<lastindex)
					{
						lastindex=index+1;
						for(int i=0;i<=index+1;i++)
						{
							lastlist[i]=list[i];
						}
					}
					return;
			}
             if(list[index+1]<target)dfs(index+1,target);
     }
}
int main()
{
    int target;
    while(cin>>target)
    {
                 list[0]=1;list[1]=2;
                 lastindex=10000;
				 if(!target)break;
                 if(target==1){cout<<1<<endl;continue;}
                 else if(target==2){cout<<1<<" "<<2<<endl;continue;}
                 dfs(1,target);
                 for(int i=0;i<=lastindex;i++)
                 {
                         if(i==0)cout<<lastlist[i];
                         else cout<<" "<<lastlist[i];
                 }
                 cout<<endl;
    }
    return 0;
}
