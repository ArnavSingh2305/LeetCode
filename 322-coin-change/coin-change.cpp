class Solution {
public:
    int f(vector<int>&coins , int amount , int ind,vector<vector<int>>&dp){
        if(ind == 0){
            if(amount% coins[0] ==0){
                return amount/coins[0] ;
            }
            else{
                return 1e9;
            }
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int notTake = f(coins,amount,ind-1,dp);
        int take = 1e9;
        if(amount>= coins[ind]){ 
        take = 1+ f(coins,amount-coins[ind],ind,dp);}
        return min(notTake,take);
    }
    int coinChange(vector<int>& coins, int amount) {
        vector<int> prev(amount+1);
        vector<int> cur(amount+1);
        for(int i=0;i<amount+1;i++){
            if(i%coins[0]==0){
                prev[i] = i/coins[0];
            }
            else{
                prev[i]=1e9;
            }
        }
        cur = prev;
        for(int i=1;i<coins.size();i++){
            for(int j=0;j<amount+1;j++){
                int notTake = prev[j];
                int take = 1e9;
                if(j>=coins[i]){
                    take = 1+ cur[j-coins[i]];
                }
                cur[j]= min(notTake,take);
            }
            prev = cur;
        }
        if(prev[amount] >= 1e9) return -1;
        else return prev[amount];
    }
};