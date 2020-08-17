import sys

for _ in range(int(input())):
    a=input()
    ans,cnt,minn=len(a),0,0
    for i in range(len(a)):
        cnt += 1 if a[i]=='+' else -1
        if(cnt<minn):
            minn=cnt
            ans+=i+1
    print(ans)