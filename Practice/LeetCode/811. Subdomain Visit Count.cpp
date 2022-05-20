class Solution {
public:
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string,int> m;
        string domain;
        int cnt;
        for(string cpdomain:cpdomains){
            stringstream ss(cpdomain);
            ss>>cnt>>domain;
            int i=0;
            while(true){
                m[domain.substr(i)]+=cnt;
                if(domain.find(".",i)==string::npos) break;
                i=domain.find(".",i)+1;
            }
        }
        vector<string> result;
        for(auto val:m)
            result.push_back(to_string(val.second)+" "+val.first);
        return result;
    }
};