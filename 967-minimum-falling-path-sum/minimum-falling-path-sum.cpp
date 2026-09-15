class Solution {
public:
    int f(vector<vector<int>>& matrix,int row,int col,vector<vector<int>>&dp){
        if(col<0 || col>= matrix[0].size()) return 1e9;
        if(row==matrix.size()-1) return matrix[row][col];
        if(dp[row][col]!=INT_MAX) return dp[row][col];
        int left = matrix[row][col] + f(matrix,row+1,col-1,dp);
        int center = matrix[row][col] + f(matrix,row+1,col,dp);
        int right = matrix[row][col] + f(matrix,row+1,col+1,dp);
        return dp[row][col]=min(left,min(right,center));
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int mini = INT_MAX;
        vector<int> prev(matrix[0].size());
        vector<int> curr(matrix[0].size());
        for(int i=0;i<matrix[0].size();i++){
            prev[i]=matrix[0][i]; 
        }
        for(int row=1;row<matrix.size();row++){
            for(int col=0;col<matrix[0].size();col++){
                int left=INT_MAX;
                int center=INT_MAX;
                int right =INT_MAX;
                if(col>0){
                    left = matrix[row][col] + prev[col-1];
                }
                center= matrix[row][col]+prev[col];
                if(col<matrix[0].size()-1){
                    right = matrix[row][col] + prev[col+1];
                }
                curr[col] = min(left,min(center,right));
            }
            prev = curr;
        }
         mini = *min_element(prev.begin(),prev.end());
        return mini;
    }
};