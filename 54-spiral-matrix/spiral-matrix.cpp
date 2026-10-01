class Solution {
public:
    vector<int> spiralOrder(vector<vector<int>>& matrix) {
        int m = matrix.size();
        int n = matrix[0].size();
        if(m==0 || n==0) return {};
        vector<int>ans;
        int top = 0;
        int bottom = m-1;
        int right = matrix[0].size()-1;
        int left =0;
        while(top<=bottom && left <= right){
            //print till right
            for(int col=left;col<=right;col++){
                ans.push_back(matrix[top][col]);
            }
            top++;
            //print down
            for(int row=top;row<=bottom;row++){
                ans.push_back(matrix[row][right]);
            }
            right--;
            //print left
            if(top<=bottom){
            for(int col=right;col>=left;col--){
                ans.push_back(matrix[bottom][col]);
            }
            }
            if(left<=right){
            bottom--;
            for(int row=bottom;row>=top;row--){
                ans.push_back(matrix[row][left]);
            }
            left++;
            }
        }
        return ans;
    }
};