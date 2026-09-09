class Solution {
public:
    long long countCommas(long long n) {
        long long lb = 1000;
        if(n<lb) return 0;
        long long ans =0;
        int count=1;
        while(lb<=n){
            long long ub = (lb*1000) -1;
            long countn = min(ub,n)-lb+1;
            ans += countn*count;
            lb *= 1000;
            count++;
        }
        return ans;
    }
};