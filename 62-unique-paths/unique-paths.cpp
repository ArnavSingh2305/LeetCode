class Solution {
public:
    int f(int row,int col,vector<vector<int>>&dp){
        if(row==0 && col==0) return 1;
        int above = 0, left = 0;
        if(dp[row][col]!=-1) return dp[row][col];
        if(row > 0)
            above = f(row - 1, col,dp);

        if(col > 0)
            left = f(row, col - 1,dp);

        return dp[row][col]=above + left;
    }
    int uniquePaths(int m, int n) {
        vector<int> dp(n,1);
        for(int row = 1;row<m;row++){
            for(int col=0;col<n;col++){
                if(col==0){
                    continue;
                }
                dp[col] = dp[col] + dp[col-1];
            }
        }
        return dp[n-1];
    }
};