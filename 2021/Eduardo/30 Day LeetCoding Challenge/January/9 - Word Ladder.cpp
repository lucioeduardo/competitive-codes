class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {        
        int n = wordList.size();
        unordered_set<string> words(wordList.begin(), wordList.end());
        
        queue<string> q;
        q.push(beginWord);
        int res=1;
        
        
        while(!q.empty()){
            int n = q.size();
            
            for(int j=0; j<n; j++){
                string s = q.front(); q.pop();
                if(s == endWord) return res;

                

                for(int i=0; i<s.length(); i++){
                    char aux = s[i];

                    for(char c = 'a'; c <= 'z'; c++){
                        if(c == aux) continue;
                        s[i]=c;

                        if(words.find(s) != words.end()){
                            q.push(s);
                            words.erase(s);
                        }
                    }

                    s[i]=aux;
                }
            }
            res++;
        }
        
        return 0;
    }
};