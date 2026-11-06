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
            prices.size()+1,
            vector<vector<int>>(2, vector<int>(3, -1)));
            for(int j=0;j<=1;j++){
                for(int k=0;k<=2;k++){
                    dp[prices.size()][j][k]=0;
                }
            }
            for(int i=prices.size()-1;i>=0;i--){
                for(int j=0;j<=1;j++){
                    dp[i][j][2]=0;
                }
            }
            for(int i=prices.size()-1;i>=0;i--){
                for(int j=0;j<=1;j++){
                    for(int k=0;k<2;k++){
                        if(j==1){
                            int take = -prices[i]+dp[i+1][0][k];
                            int notBuy = dp[i+1][1][k];
                             dp[i][j][k]=max(take,notBuy);
                        }
                        else {
                            int sell = prices[i]+dp[i+1][1][k+1];
                            int notSell = dp[i+1][0][k];
                             dp[i][j][k]=max(sell,notSell);
                        }
                    }
                }
            }
        return dp[0][1][0];
    }
};