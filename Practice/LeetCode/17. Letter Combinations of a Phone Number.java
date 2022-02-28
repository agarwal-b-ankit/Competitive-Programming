class Solution {
    List<String> ans = new ArrayList<>();
    Map<Character,char[]> ch = new HashMap<>();
    
    private void prepare(){
        ch.put('2',new char[]{'a','b','c'});
        ch.put('3',new char[]{'d','e','f'});
        ch.put('4',new char[]{'g','h','i'});
        ch.put('5',new char[]{'j','k','l'});
        ch.put('6',new char[]{'m','n','o'});
        ch.put('7',new char[]{'p','q','r','s'});
        ch.put('8',new char[]{'t','u','v'});
        ch.put('9',new char[]{'w','x','y','z'});
    }
    
    private void res(String digits, String curr, int ind){
        if (ind==digits.length()){
            ans.add(curr);
            return;
        }
        char c = digits.charAt(ind);
        for(char val: ch.get(c)){
            res(digits,curr+val,ind+1);
        }
    }
    
    public List<String> letterCombinations(String digits) {
        if(digits.length()==0) return new ArrayList<>();
        prepare();
        res(digits,"",0);
        return ans;
    }
}