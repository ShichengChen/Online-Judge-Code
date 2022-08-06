def solve():
    l = int(input())
    n=input()
    if(n[0]=='9'):
        s=['1']*(l+1)
        s=int(''.join(s))
        # print('s',s)
        # print('int(n)',int(n))
        # print('-',s-int(n))
        ans=s-int(n)
        print(ans)
        assert len(str(ans))==l
    else:
        s=['9']*(l)
        s=int(''.join(s))
        # print('s',s)
        # print('int(n)',int(n))
        # print('-',s-int(n))
        ans=s-int(n)
        print(ans)
        assert len(str(ans))==l


t = int(input())
for _ in range(t):
    solve()


'''
99
3
999
2
90
3
900
4
9999

3
0 4
1 2
3 5

'''