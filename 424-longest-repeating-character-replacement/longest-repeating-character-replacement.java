class Solution {
    public int characterReplacement(String s, int k) {
        int i=0;
        int j=0;
        int maxocc=0;
        int[] arr = new int[26];
        int len =0;
        int maxlen=0;
        while(j<s.length()){
            arr[s.charAt(j)-'A']++;
            maxocc = Math.max(maxocc,arr[s.charAt(j)-'A']);
            while((j-i+1)-maxocc >k){
                arr[s.charAt(i)-'A']--;
                i++;
            }
            len = (j-i)+1;
            maxlen = Math.max(maxlen,len);
            j++;
        }
        return maxlen;
    }
}