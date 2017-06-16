#include<iostream>
using namespace std;
//#define INF 10000;
int list[10000];//lastlist[10000];
int number,num,target,ex,lastindex,iterative;
bool search(int index,int lastindex,int target)
{
	int current=list[index];
	for(int i=0;i<=number-num+1;i++)
	{
		current*=2;
		if(current>target)return false;
	}
	return true;	
}
void dfs(int index,int target)
{
     if(num==number)return;//到边界阻止继续递归下去；
     if(search(index,lastindex,target)){ex=1;return;}//剪枝 
     for(int i=index;i>=0;i--)
     {
             list[index+1]=list[index]+list[i];
             if(list[index+1]==list[index-1]*2)break;//剪枝
             if(list[index+1]>target)continue;
             if(list[index+1]==target)
			 {
                        iterative=0;ex=1;lastindex=index+1;
                        break;
	         }
	         //for(int i=0;i<=index+1;i++)cout<<" ."<<list[i]<<".";
             if(list[index+1]<target)
             {
                        num++;
                        dfs(index+1,target);
                        num--; 
                        if(ex==1)return; //记住在退出递归的地方继续退出 
             }
     }
}
int main()
{
    while(cin>>target)
    {
                 iterative=1;number=3;    //对于number 和num这种预先控制边界的东西在写函数时一定要注意边界的选择最好和index保持一致 
                 list[0]=1;list[1]=2;
				 if(!target)break;
                 if(target==1){cout<<1<<endl;continue;}
                 else if(target==2){cout<<1<<" "<<2<<endl;continue;}//一定注意1.2这种的边界值 
                 while(iterative)
                 {
                                 num=1;number++; ex=0;
                                 dfs(1,target);  
                 }
                 for(int i=0;i<=lastindex;i++)
                 {
                         if(i==0)cout<<list[i];
                         else cout<<" "<<list[i];
                 }
                 cout<<endl;
    }
    return 0;
}
