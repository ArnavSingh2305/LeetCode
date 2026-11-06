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
        vector<vector<int>> dp(prices.size()+1, vector<int>(2, -1));
        dp[prices.size()][0]=0;
        dp[prices.size()][1]=0;
        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j==1){
                    int take = -prices[i]+dp[i+1][0];
                    int notBuy = dp[i+1][1];
                     dp[i][j]=max(take,notBuy);
                }
                else {
                    int sell = prices[i]+dp[i+1][1];
                    int notSell = dp[i+1][0];
                     dp[i][j]=max(sell,notSell);
                }
            }
        }
        return dp[0][1];
    }
};