import sys
input = lambda: sys.stdin.readline().rstrip()
N=100101

n = int(input())

rand = [((i+12345)**3)%998244353 for i in range(N*2+20)]
al,ar,bl,br=[],[],[],[]
for _ in range(n):
    a,b,c,d=map(int,input().split())
    al.append(a)
    ar.append(b)
    bl.append(c)
    br.append(d)
def calk(l,r):
    ma={s:idx for idx,s in enumerate(sorted(list(set(l+r))))}
    hash=[0]*N*2
    for idx,v in enumerate(l):hash[ma[v]]+=rand[idx]
    for i in range(1,N*2):hash[i]+=hash[i-1]
    return sum([hash[ma[v]]*rand[idx] for idx,v in enumerate(r)])


print("YES" if calk(al, ar) == calk(bl, br) else "NO")

