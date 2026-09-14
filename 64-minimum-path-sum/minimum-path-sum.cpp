class Solution {
public:
    int f(vector<vector<int>> & grid, int row,int col,vector<vector<int>>&dp){
        if(row ==0 && col ==0) return grid[row][col];
        int above = INT_MAX;
        int left =INT_MAX;
        if(dp[row][col]!=-1) return dp[row][col];
        if(row>0){
            above = grid[row][col]+f(grid,row-1,col,dp);
        }
        if(col>0){
            left = grid[row][col] + f(grid,row,col-1,dp);
        }
        return dp[row][col]=min(above,left);
    }
    int minPathSum(vector<vector<int>>& grid) {
        vector<vector<int>> dp(grid.size(),vector<int>(grid[0].size(),-1));
        dp[0][0]=grid[0][0];
        for(int row=0;row<grid.size();row++){
            for(int col=0;col<grid[0].size();col++){
                if(row==0 && col==0) continue;
                int above = INT_MAX;
                int left = INT_MAX;
                if(row>0){
                    above = grid[row][col]+dp[row-1][col];
                }
                if(col>0){
                    left = grid[row][col]+dp[row][col-1];
                }
                dp[row][col] = min(above,left);
            }
        }
        return dp[grid.size()-1][grid[0].size()-1];
    }
};