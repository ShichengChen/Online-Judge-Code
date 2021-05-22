- [XOR operation](#xor-operation)
- [Array A to Array B](#array-a-to-array-b)
- [Operations on an Array](#operations-on-an-array)
- [Segmentation Coverage Problem](#segmentation-coverage-problem)
- [Two types of elements very large weights Knapsack problem](#two-types-of-elements-very-large-weights-knapsack-problem)

# General
  - dp? binary search? math?
  - find the essentials in the problem instead of trying different samples
  - solving the problem from forward and backward directions.[Construct Target Array With Multiple Sums](https://leetcode.com/explore/featured/card/may-leetcoding-challenge-2021/599/week-2-may-8th-may-14th/3737/)
  - abstract the problem so that I write condensed code.
  - changed variables vs unchanged variables
  - formulate the problem by math notations


# XOR operation
  - think the problem one byte by one byte.[GameGame](https://codeforces.com/contest/1383/problem/B)
  - manipulation formulas.
  
# Array A to Array B
  - how to make A become B (thinking from A)
  - how to get B from A (thinking from B). [String Transformation 1](https://codeforces.com/contest/1383/problem/A)
  
# Operations on an Array
  - try to iterate the array from the first index to the end.
  - list different forms of equations.[C. Good Subarrays](https://codeforces.com/contest/1398/problem/C)
  - have for different indices 1<=i<j<k<l<=n, try iterate over (i,j),(i,k),(i,l),(j,k),(j,l) or (k,l)[D. Zigzags](https://codeforces.com/contest/1400/problem/D)  

# Segmentation Coverage Problem
   - compress coordinate [Yet Another Segments Subset](https://codeforces.com/contest/1399/problem/F)
   - enumerate all situations
  
# Two types of elements very large weights Knapsack problem
  - cannot use dp, enumerate the number of first elements and find corresponding number of second elements

# Implementation Problem
  - list all sitations!! and then write code. 