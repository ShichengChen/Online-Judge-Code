#include <cstdio>
using namespace std;
#define MAXN 20005;
int main()
{
	int _,n,cur;
	scanf("%d",&_);
	while(_--)
    {
		scanf("%d", &n);
		bool flag = 0;
		for (int i = 0; i < n;i++)
		{
			scanf("%d", &cur);
			if(cur > 1)
               flag = 1;
		}
		if (!flag && n % 2 == 0)puts("piloop");
		else puts("poopi");
	}
}
