class Solution {
public:
    string minWindow(string s, string t) {
        int hash[256]={0};
        int n = s.size();
        int m = t.size();
        if(n<m) return "";
        int minl = INT_MAX;
        int start =-1;
        int l=0;
        int r=0;
        int cnt=0;
        for(int i=0;i<m;i++){
            hash[t[i]]++;
        }
        while(r<n){
            if(hash[s[r]] > 0){
                cnt++;
            }
             hash[s[r]]--;
            while(cnt == m){
                if((r-l+1) < minl){
                    minl = r-l+1;
                    start = l;
                }
                hash[s[l]]++;
                if(hash[s[l]] > 0) cnt--;
                l++;
            }
            r++;
        }
        return start==-1? "":s.substr(start,minl);
    }
};