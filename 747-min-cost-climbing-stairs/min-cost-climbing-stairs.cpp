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
        for(int i=2;i<cost.size();i++){
            cost[i] = cost[i] + min(cost[i-1],cost[i-2]); 
        }
        return min(cost[cost.size()-1],cost[cost.size()-2]);
    }
};