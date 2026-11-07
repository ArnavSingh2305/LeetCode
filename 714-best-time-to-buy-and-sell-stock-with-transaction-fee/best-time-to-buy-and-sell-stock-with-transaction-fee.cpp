class Solution {
public:
    int f(vector<int>&prices,int fee,int i,int buy,vector<vector<int>>&dp){
        if(i==prices.size()){
            return 0;
        }
        if(dp[i][buy]!=-1) return dp[i][buy];
        if(buy==1){
            int take = -prices[i] + f(prices,fee,i+1,0,dp);
            int nottake = f(prices,fee,i+1,1,dp);
            return dp[i][buy]=max(take,nottake);
        }else{
            int sell = prices[i]-fee + f(prices,fee,i+1,1,dp);
            int notSell = f(prices,fee,i+1,0,dp);
            return dp[i][buy]=max(sell,notSell);
        }

    }
    int maxProfit(vector<int>& prices, int fee) {
        vector<vector<int>> dp(prices.size()+1,vector<int>(2,-1));
        dp[prices.size()][0]=0;
        dp[prices.size()][1]=0;
        for(int i=prices.size()-1;i>=0;i--){
            for(int buy=0;buy<=1;buy++){
                if(buy==1){
                    int take = -prices[i] + dp[i+1][0];
                    int nottake = dp[i+1][1];
                    dp[i][buy]=max(take,nottake);
                }else{
                    int sell = prices[i]-fee + dp[i+1][1];
                    int notSell = dp[i+1][0];
                    dp[i][buy]=max(sell,notSell);
                }
            }
        }
        return dp[0][1];
    }
};