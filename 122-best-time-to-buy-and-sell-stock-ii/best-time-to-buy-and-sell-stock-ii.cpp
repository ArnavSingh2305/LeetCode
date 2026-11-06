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
        vector<int> prev(2,0);
        vector<int>cur(2,0);
        for(int i=prices.size()-1;i>=0;i--){
            for(int j=0;j<=1;j++){
                if(j==1){
                    int take = -prices[i]+prev[0];
                    int notBuy = prev[1];
                    cur[j]=max(take,notBuy);
                }
                else {
                    int sell = prices[i]+prev[1];
                    int notSell = prev[0];
                    cur[j]=max(sell,notSell);
                }
            }
            prev = cur;
        }
        return prev[1];
    }
};