Problem link-[Split Array With Same Average (LeetCode)](https://leetcode.com/problems/split-array-with-same-average/description/?envType=problem-list-v2&envId=bitmask)

Observations:
1) first of all deduce the problem we need to get avg(a1)==avg(a2)
2) avg(a1) will be equal to avg(a)
3) now you have to get average a1 such that sum(a1)=sum(a)*len(a1)/a;
4) now travel dp[len][sum] can we use any subset size of length==len and form sum==sum
5) now think how can you do it on your own
6) now optimise it using bitmask
7) dp[sum] it will store how many subset of size l will form this sum 
  lets say it will be formed by len=1 or len=2 then we can turn on the bits dp[sum]=11
  

