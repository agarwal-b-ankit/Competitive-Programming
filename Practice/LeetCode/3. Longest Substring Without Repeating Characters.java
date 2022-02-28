class Solution {
    public int lengthOfLongestSubstring(String s) {
        int left = 0, curr = 0, ans = 0;
        Integer[] m = new Integer[128];
        while(curr < s.length()){
            char ch = s.charAt(curr);
            Integer ind = m[ch];
            if(ind!=null && ind>=left){
                left = ind+1;
            }
            ans = Math.max(ans, curr-left+1);
            m[ch]=curr;
            curr++;
        }
        return ans;
    }
}