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
        vector<int>prev(grid[0].size(),0);
        for(int row=0;row<grid.size();row++){
            for(int col=0;col<grid[0].size();col++){
                if(row==0 && col==0) {
                    prev[col] = grid[row][col];
                    continue;
                }
                if(row==0){
                    prev[col] = grid[row][col]+prev[col-1];
                    continue;
                }
                if(col==0){
                    prev[col] = grid[row][col] + prev[col];
                }
                else{
                    prev[col]=grid[row][col] + min(prev[col],prev[col-1]);
                }
            }
        }
        return prev[grid[0].size()-1];
    }
};