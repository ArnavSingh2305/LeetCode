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
    int longestPalindromeSubseq(string s) {
        string s1 = s;
        reverse(s1.begin(),s1.end());
        vector<vector<int>>dp(s.size()+1,vector<int>(s.size()+1,-1));
        return f(s.size(),s.size(),s,s1,dp);
    }
};