class Solution {
public:
    int f(int ind, int buy,vector<int>&prices,vector<vector<int>>&dp){
        if(ind==prices.size()){
            return 0;
        }
        if(dp[ind][buy] !=-1) return dp[ind][buy];
        if(buy==1){
            int take = -prices[ind]+f(ind+1,0,prices,dp);
            int notBuy = f(ind+1,1,prices,dp);
            return dp[ind][buy]=max(take,notBuy);
        }
        else {
            int sell = prices[ind]+f(ind+1,1,prices,dp);
            int notSell = f(ind+1,0,prices,dp);
            return dp[ind][buy]=max(sell,notSell);
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(), vector<int>(2, -1));
        return f(0,1,prices,dp);
    }
};