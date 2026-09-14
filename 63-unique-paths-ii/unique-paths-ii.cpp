class Solution {
public:
    int f(int row,int col,vector<vector<int>> & obstacleGrid,vector<vector<int>>&dp){
        if(obstacleGrid[row][col]==1) return 0;
        if(row==0 && col ==0) return 1;
        if(dp[row][col] != -1)
            return dp[row][col];
        int above =0;
        int left =0;
        if(row>0){
            above = f(row-1,col,obstacleGrid,dp);
        }
        if(col>0){
            left = f(row,col-1,obstacleGrid,dp);
        }
        return dp[row][col]= above+left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
        if(obstacleGrid[0][0]==1) return 0;
        vector<int>dp(obstacleGrid[0].size(),0);
        dp[0]=1;
        for(int row=0;row<obstacleGrid.size();row++){
            for(int col=0;col<obstacleGrid[0].size();col++){
                if(obstacleGrid[row][col]==1){
                    dp[col]=0;
                    continue;
                }
                if(row==0 && col ==0) continue;
                int left =0;
                if(col>0){
                    left=dp[col-1];
                }
                dp[col]=dp[col] + left;
            }
        }
        return dp[obstacleGrid[0].size()-1];
    }
};