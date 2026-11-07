class Solution {
public:
    int f(int i,int prev,vector<int>&nums,vector<vector<int>>&dp){
        if(i<0){
            return 0;
        }
        if(dp[i][prev+1]!=-1){
            return dp[i][prev+1];
        }
        long long notTake = f(i-1,prev,nums,dp);
        long long take =0;
        if(prev==-1 || nums[i]<nums[prev] ){
            take = 1+ f(i-1,i,nums,dp);
        }
        return dp[i][prev+1]=(long long)max(notTake,take);
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<vector<int>>dp(nums.size(),vector<int>(nums.size()+1,-1));
        return f(nums.size()-1,-1,nums,dp);
    }
};