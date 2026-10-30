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
        vector<vector<int>>dp ( s.size()+1,vector<int>(p.size()+1,-1));
        return f(s,p,s.size(),p.size(),dp);
    }
};