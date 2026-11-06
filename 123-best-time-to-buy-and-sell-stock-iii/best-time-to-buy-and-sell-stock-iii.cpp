class Solution {
public:
     int f(int ind, int buy,int count,vector<int>&prices,vector<vector<vector<int>>>&dp){
        if(ind==prices.size()){
            return 0;
        }
        if(count==2) return 0;
        if(dp[ind][buy][count] !=-1) return dp[ind][buy][count];
        if(buy==1){
            int take = -prices[ind]+f(ind+1,0,count,prices,dp);
            int notBuy = f(ind+1,1,count,prices,dp);
            return dp[ind][buy][count]=max(take,notBuy);
        }
        else {
            int sell = prices[ind]+f(ind+1,1,count+1,prices,dp);
            int notSell = f(ind+1,0,count,prices,dp);
            return dp[ind][buy][count]=max(sell,notSell);
        }
    }
    int maxProfit(vector<int>& prices) {
        vector<vector<vector<int>>> dp(
            prices.size(),
            vector<vector<int>>(2, vector<int>(3, -1)));
                    return f(0,1,0,prices,dp);
    }
};