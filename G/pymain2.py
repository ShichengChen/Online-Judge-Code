import sys
import numpy as np
# sys.stdin = open('/home/csc/Downloads/weak_typing_chapter_3_input.txt', 'r')
# sys.stdout = open('/home/csc/Downloads/output.txt', 'w')
from itertools import chain, combinations

input = sys.stdin.readline

############ ---- Input Functions ---- ############
def inp():
    return(int(input()))
def inlt():
    return(list(map(int,input().split())))
def insr():
    s = input()
    return(list(s[:len(s) - 1]))
def invr():
    return(map(int,input().split()))




def solve():
    n = inp()
    arr=inlt()
    arr.sort()
    #print(arr)
    j=0
    for i in range(n):
        if(arr[i]>=j+1):j+=1
    print(j)

if __name__ == "__main__":
    #t=1
    t=inp()
    for i in range(t):
        print("Case #"+str(i+1)+": ", end ="")
        solve()