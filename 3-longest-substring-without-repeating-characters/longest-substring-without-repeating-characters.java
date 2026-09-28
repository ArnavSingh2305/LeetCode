class Solution {
    public int lengthOfLongestSubstring(String s) {
        char[] array = s.toCharArray();
        HashMap<Character,Integer> mp = new HashMap<>();
        int res=0;
        int j=0;
        for(int i=0;i<array.length;i++){
            mp.put(array[i],mp.getOrDefault(array[i],0)+1);
            while(mp.get(array[i])>1){
                mp.put(array[j],mp.getOrDefault(array[j],0)-1);
                j++;
            }
            int len = i-j+1;
            res= Math.max(len,res);
        }
        return res;
    }
}