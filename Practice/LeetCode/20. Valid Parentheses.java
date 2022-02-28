class Solution {
    public boolean isValid(String s) {
        Stack<Character> st = new Stack<>();
        for(char c:s.toCharArray()){
            if(isClosingPar(c)){
                if(st.size()==0 || st.pop()!=getOpeningPar(c))
                    return false;
            } else{
                st.push(c);
            }
        }
        return st.size()==0;
    }
    
    private boolean isClosingPar(char c){
        return c==')' || c=='}' || c==']';
    }
    
    private char getOpeningPar(char c){
        if(c==')') return '(';
        else if(c=='}') return '{';
        else return '[';
    }
}