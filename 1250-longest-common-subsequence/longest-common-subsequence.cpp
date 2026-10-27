class Solution {
public:
    int f(int ind1,int ind2,string & text1,string & text2,vector<vector<int>>&dp){
        if(ind1<1 || ind2<1){
            return 0;
        }
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(text1[ind1-1]==text2[ind2-1]){
            return dp[ind1][ind2]= 1 + f(ind1-1,ind2-1,text1,text2,dp);
        }

        return dp[ind1][ind2] = max(
            f(ind1-1, ind2, text1, text2, dp),
            f(ind1, ind2-1, text1, text2, dp)
        );

    }
    int f1(int ind1,int ind2,string & text1,string & text2,vector<vector<int>>&dp){
       for(int i=0;i<=text1.size();i++){
        dp[i][0]=0;
       }
       for(int i=0;i<=text2.size();i++){
        dp[0][i]=0;
       }
       for(int i=1;i<=text1.size();i++){
        for(int j=1;j<=text2.size();j++){
            if(text1[i-1]==text2[j-2]){
                dp[i][j]= 1+ dp[i-1][j-1];
            }
            else{
                dp[i][j]=max(dp[i-1][j],dp[i][j-1]);
            }
        }

       }
       return dp[text1.size()][text2.size()];
    }
    int longestCommonSubsequence(string text1, string text2) {
        vector<vector<int>>dp(text1.size()+1,vector<int>(text2.size()+1,-1));
        return f(text1.size(),text2.size(),text1,text2,dp);
    }
};