class Solution {
public:
    int bagOfTokensScore(vector<int>& tokens, int P) {
        sort(tokens.begin(), tokens.end());
        
        int n = tokens.size();
        int l=0, r=n;
        
        int score=0;
        
        while(l < r){
            while(l < r && P >= tokens[l]){
                score++;
                P-=tokens[l];
                l++;
            }
            
            if(r > l){
                if(score == 0 || r==l+1) break;
                P += tokens[--r];
                score--;
            }
        }
        
        return score;
    }
};