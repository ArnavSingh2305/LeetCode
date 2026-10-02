class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int,int> mp;
        mp[0]=1;
        int n=nums.size();
        int odd=0;
        int result=0;
        for(int i=0;i<n;i++){
            odd +=(nums[i]%2);
            if(mp.find(odd-k)!=mp.end()){
                result+=mp[odd-k];
            }
            mp[odd]++;
        }
        return result;
    }
};