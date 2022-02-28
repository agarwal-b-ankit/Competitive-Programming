class Solution {
    private int expand(String s, int l, int r){
        int ans = 0;
        while(l>=0 && r<s.length() && s.charAt(l)==s.charAt(r)){
            ans++;
            l--;
            r++;
        }
        return ans;
    }
    
    public String longestPalindrome(String s) {
        if(s==null || s.length()<1) return "";
        int start = 0, end = 0;
        for(int i = 0; i < s.length(); i++){
            int l1 = expand(s, i,i);
            int l2 = expand(s, i,i+1);
            if(2*l1-1>=end-start+1){
                start = i+1-l1;
                end = i-1+l1;
            }
            if(2*l2>=end-start+1){
                start = i+1-l2;
                end = i+l2;
            }
        }
        return s.substring(start,end+1);
    }
}