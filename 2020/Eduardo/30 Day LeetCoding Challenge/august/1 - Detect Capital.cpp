class Solution {
public:
    bool detectCapitalUse(string word) {
        int nC=0, nL=0;
        
        for(char c: word){
            if((c - 'A') < 26)
                nC++;
            else
                nL++;
        }
        
        cout << nC << " " << nL << endl;
        
        if((nC == 1 && word[0] - 'A' < 26) || nC == word.length() || nC == 0)
            return true;
        return false;
    }
};