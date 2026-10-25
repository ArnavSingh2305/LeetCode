class Solution {
public:
    int f(int ind,int amount,vector<int>&coins,vector<vector<int>>&dp){
        if(ind==0){
            if(amount%coins[ind]==0) return 1;
            else return 0;
        }
        if(dp[ind][amount]!=-1) return dp[ind][amount];
        int notTake = f(ind-1,amount,coins,dp);
        int take =0;
        if(amount>=coins[ind]) take = f(ind,amount-coins[ind],coins,dp);
        return dp[ind][amount]=notTake+take;
    }
    int f1(int ind,int amount,vector<int>&coins,vector<vector<long long>>&dp){
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0){
                dp[0][i]=1;
            }
            else{
                dp[0][i]=0;
            }
        }
        for(int i=1;i<coins.size();i++){
            for(int j=0;j<=amount;j++){
                long long notTake = dp[i-1][j];
                long long take =0;
                if(j>=coins[i]) take = dp[i][j-coins[i]];
                long long ways = (long long)notTake + take;
                dp[i][j]= min(ways,(long long)INT_MAX);
            }
        }
         return (int)dp[coins.size()-1][amount];
    }
    int change(int amount, vector<int>& coins) {
        int gcdValue =0;
        for(int coin:coins){
            gcdValue = gcd(gcdValue,coin);
        }
        if(amount%gcdValue!=0){
            return 0;
        }
        vector<int> prev(amount+1,0);
        vector<int> cur(amount+1,0);
        for(int i=0;i<=amount;i++){
            if(i%coins[0]==0){
                prev[i]=1;
            }
            else{
                prev[i]=0;
            }
        }
        cur = prev;
        for(int i=1;i<coins.size();i++){
            for(int j=0;j<=amount;j++){
                long long notTake = prev[j];
                long long take =0;
                if(j>=coins[i]) take = cur[j-coins[i]];
                long long ways = (long long)notTake + take;
                cur[j]= min(ways,(long long)INT_MAX);
            }
            prev = cur;
        }
        return prev[amount];
    }
};