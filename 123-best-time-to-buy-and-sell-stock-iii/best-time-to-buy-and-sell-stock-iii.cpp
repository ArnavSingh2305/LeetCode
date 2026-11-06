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
        vector<vector<int>> prev(2, vector<int>(3, 0));
        vector<vector<int>> cur(2, vector<int>(3, 0));
            for(int i=prices.size()-1;i>=0;i--){
                for(int j=0;j<=1;j++){
                    for(int k=0;k<2;k++){
                        if(j==1){
                            int take = -prices[i]+prev[0][k];
                            int notBuy = prev[1][k];
                            cur[j][k]=max(take,notBuy);
                        }
                        else {
                            int sell = prices[i]+prev[1][k+1];
                            int notSell = prev[0][k];
                            cur[j][k]=max(sell,notSell);
                        }
                    }
                    prev = cur;
                }
            }
        return prev[1][0];
    }
};