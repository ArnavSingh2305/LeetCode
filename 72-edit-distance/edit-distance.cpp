class Solution {
public:
    int f(int i,int j ,string &word1,string &word2,vector<vector<int>>&dp){
        if(i==0){
            if(j>0){
                return j;
            }
            else return 0;
        }
        if(j==0){
            if(i>0) return i;
            else return 0;
        }
        if(dp[i][j] != -1) return dp[i][j];
        if(word1[i-1]==word2[j-1]){
         return   dp[i][j]=f(i-1,j-1,word1,word2,dp);
        }
        else{
            return dp[i][j]= min(min(1+f(i-1,j,word1,word2,dp),1+f(i,j-1,word1,word2,dp)),1+f(i-1,j-1,word1,word2,dp));
        }
    }
    int minDistance(string word1, string word2) {
        vector<vector<int>>dp(word1.size()+1,vector<int>(word2.size()+1,-1));
        return f(word1.size(),word2.size(),word1,word2,dp);
    }
};