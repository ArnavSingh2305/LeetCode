class Solution {
public:
    int f(int ind,int total, vector<int>&nums,vector<vector<int>> &dp ){
        if(ind==0){
            if(total==0 && nums[0]==0) return 2;
            if(total==0 || total==nums[0]) return 1;
            else return 0;
        }
        if(dp[ind][total] != -1) return dp[ind][total];
        int notTake = f(ind-1,total,nums,dp);
        int Take = 0;
        if(nums[ind]<=total) Take = f(ind-1,total-nums[ind],nums,dp);
        return dp[ind][total] = notTake + Take;
    }
    int findTargetSumWays(vector<int>& nums, int target) {
      
        int total = 0;
        for(int x:nums){
            total+=x;
        }
        if(abs(target) > total || (total-target)%2 != 0)
        return 0;
        int requiredSum = (total - target) / 2;
  vector<vector<int>>dp (nums.size(),vector<int>(requiredSum+1,-1));
        return f(nums.size()-1,(total-target)/2,nums,dp);

    }
};