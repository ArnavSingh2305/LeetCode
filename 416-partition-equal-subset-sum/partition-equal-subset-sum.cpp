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
        vector<bool>prev (total+1,0);
        vector<bool>curr (total+1,0);
        prev[0] = true;
        if(nums[0]<= total) prev[nums[0]]=true;
        curr[0]=true;
        for(int i=1;i<nums.size();i++){
            for(int target =1;target<=total;target++){
                        bool notTake = prev[target];
                        bool take = false;
                            if(nums[i]<=target){
                            take = prev[target-nums[i]];
                            }
                        curr[target]=take || notTake;
            }
            prev = curr;
        }
        return prev[total];
    }
};