- [General](#general)
- [XOR operation](#xor-operation)
- [Array A to Array B](#array-a-to-array-b)
- [Operations on an Array](#operations-on-an-array)
- [Segmentation Coverage Problem](#segmentation-coverage-problem)
- [Two types of elements very large weights Knapsack problem](#two-types-of-elements-very-large-weights-knapsack-problem)


# General
  - Before the whole process.
    - listen to instrumental songs only.
    - not sleepy
  - Solve problems
    - find the essentials in the problem instead of trying different samples
      - formulate the problem by math notations
      - changed variables vs unchanged variables
    - think from possible answers
      - dp? binary search? math? Flow network?
      - solving the problem from forward and backward directions.[Construct Target Array With Multiple Sums](https://leetcode.com/problems/construct-target-array-with-multiple-sums/)
  - Prepare to code
    - abstract the problem so that I write condensed code.
  - Code
  - Test
    - Edge cases
    - re-read the problem
    - re-read the code
      - go through each variable!
    - create some random samples
    - draw graphs!
    
  - After Accept (using equal amount of time for solving problems and summary)
    - learn from others
      - editorial
      - others' codes
      - YouTube videos
    - organize by myself
      - how could I solve the problem within 2 hours?
      - mind map
  



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

# Range GCD with limitations [Round B Kick Start 2021 Truck Delivery](https://codingcompetitions.withgoogle.com/kickstart/round/0000000000435a5b/000000000077a885#problem)
  - Segment tree can get GCD for multiple values with a certain range
  - Each road i has a toll which charges amount Ai if the weight of the load is greater than or equal to a load-limit Li. 
  - When Lq>=load>=Li,Lj,Lk, we need to get gcd(Ai,Aj,Ak).

# Use the biggest value to represent a group of values [Problem C: Quarantine](https://www.facebook.com/codingcompetitions/hacker-cup/2020/round-1/problems/C)
  - use one value to represent a group of values


# group array
 - binary search bound values