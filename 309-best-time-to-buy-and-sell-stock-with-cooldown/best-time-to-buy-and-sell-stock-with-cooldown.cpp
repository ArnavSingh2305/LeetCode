class Solution {
public:
    int f(vector<int>&prices,int i,int buy,vector<vector<int>>&dp){
        if(i>=prices.size()){
            return 0;
        }
        if(dp[i][buy] != -1) return dp[i][buy];
        if(buy==1){
            int take = -prices[i] + f(prices,i+1,0,dp);
            int nottake = f(prices,i+1,1,dp);
            return dp[i][buy]=max(take,nottake);
        }else{
            int sell = prices[i] + f(prices,i+2,1,dp);
            int notSell = f(prices,i+1,0,dp);
            return dp[i][buy]=max(sell,notSell);
        }

    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>>dp(prices.size(),vector<int>(2,-1));
        return f(prices,0,1,dp);
    }
};