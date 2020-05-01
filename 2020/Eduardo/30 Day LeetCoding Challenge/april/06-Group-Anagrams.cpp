
class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string>& strs) {
        map<string, vector<string> > anagrams;
        
        vector<vector<string>> res;
        
        for(string s: strs){
            string v = s;
            sort(v.begin(), v.end());
            
            if(anagrams.find(v) == anagrams.end()){
                vector<string> lista;
                lista.push_back(s);
                anagrams[v] = lista;
            }else{
                anagrams[v].push_back(s);
            }
        }
        
        for(map<string,vector<string>>::iterator it = anagrams.begin(); it != anagrams.end(); it++){
            res.push_back(it->second);
        }
        
        return res;
    }
};