class Solution {
public:
    int f(int row,int col1,int col2,vector<vector<int>>& grid,vector<vector<vector<int>>> &dp){
        if(col1<0 || col1>=grid[0].size() || col2 < 0 || col2>=grid[0].size() ) return -1e9;
        if(row==grid.size()-1){
            if(col1!=col2) return grid[row][col1]+grid[row][col2];
            else return grid[row][col1];
        }
        if(dp[row][col1][col2]!=-1) return dp[row][col1][col2];
        int maxi=INT_MIN;
        int d[3] = {-1,0,1};
        for(int i=0;i<3;i++){
            for(int j=0;j<3;j++){
                if(col1==col2) {
                    maxi=max(maxi,grid[row][col1] + f(row+1,col1+d[i],col2+d[j],grid,dp));
                }
                else{
                    maxi=max(maxi,grid[row][col1] +grid[row][col2] + f(row+1,col1+d[i],col2+d[j],grid,dp));   
                }
            }
        }
        return dp[row][col1][col2]=maxi;
    }
    int cherryPickup(vector<vector<int>>& grid) {
        vector<vector<vector<int>>> dp(grid.size(),vector<vector<int>>(grid[0].size(),vector<int>(grid[0].size(),-1)));
        return f(0,0,grid[0].size()-1,grid,dp);
    }
};