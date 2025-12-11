#include<bits/stdc++.h>
using namespace std;

class Solution {
public:
    bool splitArraySameAverage(vector<int>& nums) {
        int n=nums.size();
        int sum=0;
        for(int i=0; i<n; i++)
        {
            sum+=nums[i];
        }
        vector<int>dp(sum+1,0);
        dp[0]=1;
        for(int i=0; i<n; i++)
        {
            for(int j=sum-nums[i]; j>=0; j--)
            {
                dp[j+nums[i]] |= (dp[j]<<1);
            }
        }
        for(int len=1; len<n; len++)
        {
            int required=sum*len;
            if(required%n!=0)continue;
            else{
                required/=n;
            }
          
if ((dp[required] & (1 << len))) return true;


            
        }
        return false;


    }
};