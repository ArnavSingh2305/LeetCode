class Solution {
public:
    int f(int ind1,int ind2,string & s,string & s1,vector<vector<int>>&dp){
        if(ind1<1 || ind2<1){
            return 0;
        }
        if(dp[ind1][ind2]!=-1) return dp[ind1][ind2];
        if(s[ind1-1]==s1[ind2-1]){
            return dp[ind1][ind2]= 1 + f(ind1-1,ind2-1,s,s1,dp);
        }

        return dp[ind1][ind2] = max(
            f(ind1-1, ind2, s, s1, dp),
            f(ind1, ind2-1, s, s1, dp)
        );

    }
    int f1(int ind1,int ind2,string & s,string & s1,vector<vector<int>>&dp){
        for(int i=0;i<=s.size();i++){
            dp[0][i]=0;
            dp[i][0]=0;
        }
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=s.size();j++){
                if(s[i-1]==s1[j-1]){
                    dp[i][j] = 1+ dp[i-1][j-1];
                }
                else{
                    dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
        }
        return dp[ind1][ind2];
    }
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s1.begin(),s1.end());
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        return f1(s.size(),s.size(),s,s1,dp);
    }
};