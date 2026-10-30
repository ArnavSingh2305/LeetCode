class Solution {
public:
    bool f(string &s,string &p , int i ,int j,vector<vector<int>>& dp){
        if(i==0){
            if(j==0){
                return true;
            }
            else{
                bool isTrue = true;
                for(int m=0;m<j;m++){
                    if(p[m]!= '*'){
                        isTrue = false;
                    }
                }
                return isTrue;
            }
        }
        if(dp[i][j]!=-1) return dp[i][j];
        if(j==0){
            return false;
        }
        if(s[i-1]==p[j-1] || p[j-1]=='?'){
            return dp[i][j]=f(s,p,i-1,j-1,dp);
        }
        else if (p[j-1]=='*') {
            return dp[i][j]=f(s,p,i-1,j,dp) || f(s,p,i,j-1,dp);
        }
        else{
            return dp[i][j]=false;
        }

    }
    bool isMatch(string s, string p) {
        vector<vector<bool>>dp ( s.size()+1,vector<bool>(p.size()+1,false));
        dp[0][0] = true;
        for(int i=1;i<=p.size();i++){
            if(p[i-1]!='*'){
                dp[0][i] = false;
            }
            else{
                dp[0][i]=dp[0][i-1];
            }
        }
        for(int j=1;j<=s.size();j++){
            dp[j][0]= false;
        }
        for(int i=1;i<=s.size();i++){
            for(int j=1;j<=p.size();j++){
                if(s[i-1]==p[j-1] || p[j-1]=='?'){
                    dp[i][j] = dp[i-1][j-1];
                }
                else if(p[j-1]=='*'){
                    dp[i][j] = dp[i-1][j] || dp[i][j-1];
                }
                else{
                    dp[i][j]= false;
                }
            }
        }
        return dp[s.size()][p.size()];
    }
};