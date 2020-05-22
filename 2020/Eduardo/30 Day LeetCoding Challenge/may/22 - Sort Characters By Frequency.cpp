typedef pair<char,int> pci;

int freq[260];
    
bool compare(pci a, pci b){
    return a.second > b.second;
}

class Solution {
public:
    string frequencySort(string s) {
        memset(freq,0,sizeof(freq));
        
        for(char c: s){
            freq[c]++;
        }
        
        vector<pair<char,int>> chars;
        
        for(int i=0;i<260; i++){
            if(!freq[i]) continue;
            chars.push_back({i,freq[i]});
            
        }
        
        sort(chars.begin(), chars.end(), compare);
        
        string res = "";
        
        for(pci p: chars){
            char c = p.first;
            while(p.second--) res += c;
        }
        
        return res;
    }
};