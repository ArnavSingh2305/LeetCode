class Solution {
    public String reverseOnlyLetters(String s) {
        StringBuilder sb = new StringBuilder(s);
        int i = 0;
        int j = s.length()-1;
        while(i<j){
            char ch1 = sb.charAt(i);
            char ch2 = sb.charAt(j);
            if(Character.isLetter(ch1) && Character.isLetter(ch2)){
                char temp = sb.charAt(i);
                sb.setCharAt(i,sb.charAt(j));
                sb.setCharAt(j,temp);
                i++;
                j--;
            }
            else if(!Character.isLetter(ch1) && Character.isLetter(ch2)){
                i++;
            }
            else{
                j--;
            }
        }
        return sb.toString();

    }
}