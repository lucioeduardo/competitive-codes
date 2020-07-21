int sX[4] = {1,-1,0,0};
int sY[4] = {0,0,1,-1};


class Solution {
public:
    
    vector<vector<char>> b;
    string word;
    bool used[210][210];
    
    bool solve(int n, int i, int j){        
        if(n == word.length())
            return true;
        
        if(i < 0 || i >= b.size() || j >= b[i].size() || j < 0 || used[i][j])
            return false;
        
        
        
        if(b[i][j] != word[n])
            return false;
        
        
        used[i][j]=true;
        for(int k=0; k<4; k++){
            int nX = i+sX[k], nY = j+sY[k];
            
            if(solve(n+1,nX,nY))
                return true;
        }
        used[i][j]=false;
        
            
        return false;
    }
    
    
    bool exist(vector<vector<char>>& board, string word) {
        b = board;
        this->word = word;
        
        for(int i=0; i<board.size(); i++){
            for(int j=0; j<board[i].size(); j++){
                if(solve(0,i,j))
                    return true;
            }
        }
        
        return false;
    }
};