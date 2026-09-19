class Solution {
public:
    bool f(int ind,vector<int>& nums, int  target,vector<vector<int>>&dp){
        if(target == 0 ) return true;
        if(ind ==0) return (nums[0] == target);
        if(dp[ind][target]!=-1) return dp[ind][target];
        bool notTake = f(ind-1,nums,target,dp);
        bool take = false;
            if(nums[ind]<=target){
               take = f(ind-1,nums,target-nums[ind],dp);
            }
        return dp[ind][target]=take || notTake;
    }
    bool canPartition(vector<int>& nums) {
        int sum =0;
        for(int x:nums){
            sum+=x;
        }
        if(sum%2!=0) return false;
        int total = sum / 2;
        vector<vector<int>> dp(nums.size(),vector<int>(total+1,-1));
        return f(nums.size()-1,nums,total,dp);
    }
};