class Solution {
public:
    int uniqueMorseRepresentations(vector<string>& words) {
        string morse[26] = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
        
        set<string> res;
        
        for(string word: words){
            string converted="";
            for(char c: word){
                converted += morse[c-'a'];
            }
            res.insert(converted);
        }
        
        return res.size();
    }
};