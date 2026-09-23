class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        HashMap<String,ArrayList<String>> mp = new HashMap<>();
        for(int i=0;i<strs.length;i++){
            String s = strs[i];
            char[] chars = s.toCharArray();
            Arrays.sort(chars);
            String key = new String(chars);
            mp.putIfAbsent(key,new ArrayList<>());
            mp.get(key).add(strs[i]); 
        }
        List<List<String>> ans = new ArrayList<>();
        for(ArrayList<String> list:mp.values()){
            ans.add(list);
        }
        return ans;
    }
}