class Solution {
public:
    int fib(int n ,vector<int>&dp){
        if(n<=1) return 1;
        if(dp[n]!=-1) return dp[n];
        return dp[n]=fib(n-1,dp)+fib(n-2,dp);
    }
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return fib(n,dp);
    }
};