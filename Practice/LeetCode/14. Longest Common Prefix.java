class Solution {
    private int len(String[] strs){
        for(int i=0;i<strs[0].length();i++){
            for(int j=1;j<strs.length;j++){
                if(i>=strs[j-1].length() || i>=strs[j].length() || strs[j-1].charAt(i)!=strs[j].charAt(i)){
                    return i;
                }
            }
        }
        return strs[0].length();
    }
    
    public String longestCommonPrefix(String[] strs) {
        return strs[0].substring(0,len(strs));
    }
}