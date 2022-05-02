class Solution {
private:
    /* State Machine(DFA approach). Below are the assumed states:
        0: start
        1: sign
        2: digit
        3: dot (not after number)
        4: dot (after num)
        5: digit (after dot)
        6: e
        7: sign (after e)
        8: digit (after e)
        9: invalid
        
        Below integer encoding represent each character:
        0: sign
        1: digit
        2: dot
        3: e
        4: other than above
    */
    int dfa[10][5];
    set<int> endState;
    
    void initStateMachine(){
        for(int i=0;i<10;i++)
            for(int j=0;j<5;j++)
                dfa[i][j]=9;
        
        dfa[0][0]=1;
        dfa[0][1]=2;
        dfa[0][2]=3;
        dfa[1][1]=2;
        dfa[1][2]=3;
        dfa[2][1]=2;
        dfa[2][2]=4;
        dfa[2][3]=6;
        dfa[3][1]=5;
        dfa[4][1]=5;
        dfa[4][3]=6;
        dfa[5][1]=5;
        dfa[5][3]=6;
        dfa[6][0]=7;
        dfa[6][1]=8;
        dfa[7][1]=8;
        dfa[8][1]=8;
        
        endState.insert(2);
        endState.insert(4);
        endState.insert(5);
        endState.insert(8);
    }
    
    int encode(char c){
        if(c=='+' || c=='-') return 0;
        else if(c>='0' && c<='9') return 1;
        else if(c=='.') return 2;
        else if(c=='e' || c=='E') return 3;
        else return 4;
    }
    
    int transition(char c, int state){
        return dfa[state][encode(c)];
    }
    
public:
    bool isNumber(string s) {
        initStateMachine();
        int state=0;
        for(int i=0;i<s.size();i++){
            state=transition(s[i],state);
            if(state==9) return false;
        }
        return (endState.find(state)!=endState.end());
    }
};