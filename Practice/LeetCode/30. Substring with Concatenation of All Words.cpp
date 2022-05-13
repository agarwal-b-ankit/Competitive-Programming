class Solution {
private:
    vector<int> indices;
    void findSubstring(string s, unordered_map<string,int>& freq, int wordCnt, int wordLen, int start){
        unordered_map<string,int> temp;
        int used=0;
        for(int i=start;i<=s.length();i+=wordLen){
            string curr = s.substr(i,wordLen);
            if(freq.find(curr)==freq.end()){
                temp.clear();
                used=0;
                start=i+wordLen;
                continue;
            }
            used++;
            temp[curr]++;
            while(temp[curr]>freq[curr]){
                string first = s.substr(start,wordLen);
                temp[first]--;
                used--;
                start+=wordLen;
            }
            if(used==wordCnt)
                indices.push_back(start);
        }
    }
    
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        unordered_map<string,int> freq;
        int wordCnt = 0;
        for(auto word:words){
            freq[word]++;
            wordCnt++;
        }
        for(int i=0;i<words[0].length();i++)
            findSubstring(s, freq, wordCnt, words[0].length(), i);
        return indices;
    }
};