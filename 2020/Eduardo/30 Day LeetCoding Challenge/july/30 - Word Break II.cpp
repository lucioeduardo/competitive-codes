class Solution {
public:
    
    vector<string> res;
    vector<string> wordDict;
    unordered_map<string, vector<string>> dp;
    
    vector<string> solve(string s){
        if(dp.find(s) != dp.end())
            return dp[s];
        
        string word = "";
        vector<string> result;
        
        for(int i=0; i<s.length(); i++){
            word += s[i];
            string r = s.substr(i+1);
                        
            if(isInDict(word)){
                if(r.empty())
                    result.push_back(word);
                else{
                    for(string s: solve(r)){
                        result.push_back(word + ' ' + s);
                    }
                }
            }
        }
        
        dp[s] = result;
        return result;
    }
    
    vector<string> wordBreak(string s, vector<string>& wordDict) {
        sort(wordDict.begin(), wordDict.end());
        this->wordDict = wordDict;
    
        
        return solve(s);
    }
    
    bool isInDict(string word){
        return binary_search(wordDict.begin(), wordDict.end(), word);
    }
};