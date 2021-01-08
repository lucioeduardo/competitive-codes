class Solution {
public:
    bool arrayStringsAreEqual(vector<string>& word1, vector<string>& word2) {
        int x1=0, y1=0;
        int x2=0, y2=0;
        
        while(x1 < word1.size() && x2 < word2.size()){
            if(word1[x1][y1] != word2[x2][y2]) return false;
            
            y1++;
            y2++;
            
            if(y1 == word1[x1].length()){
                x1++;
                y1=0;
            }
            
            if(y2 == word2[x2].length()){
                x2++;
                y2=0;
            }
        }
        
        return (x1 == word1.size() && x2 == word2.size());
    }
};