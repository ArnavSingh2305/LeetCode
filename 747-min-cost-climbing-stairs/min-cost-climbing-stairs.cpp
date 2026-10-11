class Solution {
public:
    int minCost(vector<int>&cost,vector<int>&dp,int ind){
        if(ind>=cost.size()){
            return 0;
        }
        if(dp[ind] != -1)
    return dp[ind];
        int take1 = cost[ind]+minCost(cost,dp,ind+1);
        int take2 = cost[ind] + minCost(cost,dp,ind+2);
        return dp[ind]= min(take1,take2);
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size()+1,-1);
        return min(minCost(cost,dp,0),minCost(cost,dp,1));
    }
};