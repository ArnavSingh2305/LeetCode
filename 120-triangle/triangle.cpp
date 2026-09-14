class Solution {
public:
    int f(int row,int col, vector<vector<int>>&triangle,vector<vector<int>>&dp){
        if(row==triangle.size()-1){
            return triangle[row][col];
        }
        if(dp[row][col]!=-1) return dp[row][col];
        int down = triangle[row][col]+ f(row+1,col,triangle,dp);
        int diagonal = triangle[row][col] + f(row+1,col+1,triangle,dp);
        return dp[row][col]=min(down,diagonal);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        if(triangle.size()==1) return triangle[0][0];
         int n = triangle.size();
        vector<vector<int>> dp(n, vector<int>(n, 0));
        for(int i=0;i<n;i++){
            dp[n-1][i] = triangle[n-1][i];
        }
        for(int row=n-2;row>=0;row--){
            for(int col=0;col<=row;col++){
                dp[row][col] = triangle[row][col] + min(dp[row+1][col],dp[row+1][col+1]);
            }
        }
        return dp[0][0];
    }
};