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
        vector<vector<int>>dp(obstacleGrid.size(),vector<int>(obstacleGrid[0].size(),-1));
        return f(obstacleGrid.size()-1,obstacleGrid[0].size()-1,obstacleGrid,dp);
    }
};