class Solution {
public:
    int maxProduct(vector<int>& nums) {
        if(nums.size()==0) return -1;
        int ans=nums[0];
        int mini=nums[0];
        int maxi= nums[0];
        for(int i=1;i<nums.size();i++){
            int prevMin = mini;
            int prevMax = maxi;
            maxi = max(nums[i],max(prevMin*nums[i],prevMax*nums[i]));
            mini = min(nums[i],min(prevMin*nums[i],prevMax*nums[i]));
            ans = max(ans,maxi);
        }
        return ans;
    }
};