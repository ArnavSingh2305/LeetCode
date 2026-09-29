class Solution {
public:
    string generate(string s){
        int freq[26]={0};
        for(int i=0;i<s.size();i++){
            freq[s[i]-'a']++;
        }
        string res ="";
        for(int i=0;i<26;i++){
            int fre = freq[i];
            if(fre>0){
                res += string(fre,i+'a'); 
            }
        }
        return res;
    }
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        unordered_map<string,vector<string>> mp;
        for(int i=0;i<strs.size();i++){
            string word = strs[i];
            string new_word = generate(word);
            mp[new_word].push_back(word);
        }
        vector<vector<string>> result;
        for(auto &it:mp){
            result.push_back(it.second);
        }
        return result;
    }
};